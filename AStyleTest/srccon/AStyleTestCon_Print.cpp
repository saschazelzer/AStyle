//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <algorithm>
#include "AStyleTestCon.h"
#ifdef _WIN32
#include <windows.h>
#endif

//----------------------------------------------------------------------------
// global variables
//----------------------------------------------------------------------------

#if defined(_MSC_VER) || defined(__BORLANDC__)
// MSVC and C++Builder do not provide a definition of STDERR_FILENO.
const int g_stdOutFileno = 1;
const int g_stdErrFileno = 2;
#else
const int g_stdOutFileno = STDOUT_FILENO;
const int g_stdErrFileno = STDERR_FILENO;
#endif  // _MSC_VER

// defined in astyle_main.cpp
namespace astyle
{
extern const char* g_version;
}

//----------------------------------------------------------------------------
// AStyle PrintF Class
//----------------------------------------------------------------------------

class PrintF : public ::testing::Test
// The PrintF class captures the stdout output stream and redirects it to a file.
// The file is used to verify the Artistic Style console build print format.
// The functions were "borrowed" from the CapturedStream class in gtest-port.cc
// of Google Test (gtest).
{
	public:
		ASFormatter formatter;		// required formatter object
		vector<string> fileNames;	// files created for test
		size_t filesExcluded;		// number of files excluded from formatting

		// variables for redirecting stdout
		int fd_;					// stream to capture
		int uncaptured_fd_;			// stdout stream
		string filename_;			// temporary file holding the stdout output

	public:
		PrintF();

		~PrintF();

		// make adjustments to expected text
		void adjustText(string &text);

		// make adjustments to textOut
		void adjustTextOut(string &textOut);

		// buildExcludeVector() is called by the test functions
		void buildExcludeVector();

		// redirect the stdout stream to a temporary file
		void redirectStream();

		// restore the stdout stream and return the captured text
		string restoreStream();

	private:
		// called by the constructor to build the test files
		void createTestFiles();

		// called by restoreStream() to read the entire content of a file as a string
		string readEntireFile(FILE* file);
};

PrintF::PrintF()
{
	// initialize variables
	fd_ = g_stdOutFileno;
	uncaptured_fd_ = dup(g_stdOutFileno);
	filesExcluded = 0;
	// create test objects
	createConsoleGlobalObject(formatter);
	createTestFiles();
}

PrintF::~PrintF()
{
	if (uncaptured_fd_ != -1)
	{
		// the stream must be restored first
		restoreStream();
		systemPause("\nCaptured fd_ was not restored.");
	}
	remove(filename_.c_str());
	deleteConsoleGlobalObject();
}

void PrintF::adjustText(string &text)
// make adjustments to expected text
{
	// replace first line with the current version number
	if (text.compare(0, 14, "Artistic Style") == 0)
	{
		size_t verStart = text.find("<version>");
		if (verStart != string::npos)
			text.replace(verStart, 9, string(g_version));
	}

	// insert linefeed as first character for readability
	text.insert(0, "\n");

	// replace <test_directory> with the actual directory
	for (size_t i = 0; i < text.length(); i++)
	{
		i = text.find("<test_directory>", i);
		if (i == string::npos)
			break;
		text.replace(i, 16, getTestDirectory());
	}

	// replace backslashes in file paths
	for (size_t i = 0; i < text.length(); i++)
	{
		i = text.find('\\', i);
		if (i == string::npos)
			break;
		text[i] = '/';
	}
}

void PrintF::adjustTextOut(string &textOut)
// make adjustments to textOut
{
	// insert linefeed as first character for readability
	textOut.insert(0, "\n");

	// replace backslashes in file paths
	for (size_t i = 0; i < textOut.length(); i++)
	{
		i = textOut.find('\\', i);
		if (i == string::npos)
			break;
		textOut[i] = '/';
	}
}

void PrintF::buildExcludeVector()
// buildExcludeVector() is called by the test functions
{
	char textExcluded[] = "\nvoid foo() { bar(); }\n";
	// add files to fileNames vector
	fileNames.push_back(getTestDirectory() + "/fileExcluded.cpp");
	g_console->standardizePath(fileNames.back());
	createTestFile(fileNames.back(), textExcluded);
	// build exclude vector
	g_console->updateExcludeVector("fileExcluded.cpp");
	filesExcluded += 1;
}

void PrintF::createTestFiles()
// called by the constructor to build the test files
{
	char textFormatted[] =
		"\nvoid foo()\n"
		"{\n"
		"bar();\n"
		"}\n";

	char textUnchanged[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";

	cleanTestDirectory(getTestDirectory());
	fileNames.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->standardizePath(fileNames.back());
	createTestFile(fileNames.back(), textFormatted);
	fileNames.push_back(getTestDirectory() + "/fileUnchanged.cpp");
	g_console->standardizePath(fileNames.back());
	createTestFile(fileNames.back(), textUnchanged);
}

string PrintF::readEntireFile(FILE* file)
// called by restoreStream() to read the entire content of a file as a string
{
	fseek(file, 0, SEEK_END);
	const size_t file_size = ftell(file);
	char* const buffer = new char[file_size];

	size_t bytes_last_read = 0;  // # of bytes read in the last fread()
	size_t bytes_read = 0;       // # of bytes read so far

	fseek(file, 0, SEEK_SET);

	// Keeps reading the file until we cannot read further or the
	// pre-determined file size is reached.
	do
	{
		bytes_last_read = fread(buffer+bytes_read, 1, file_size-bytes_read, file);
		bytes_read += bytes_last_read;
	}
	while (bytes_last_read > 0 && bytes_read < file_size);

	const string textOut(buffer, bytes_read);
	delete[] buffer;

	return textOut;
}

void PrintF::redirectStream()
// redirect the stdout stream to a temporary file
{
#ifdef _WIN32
	char temp_dir_path[MAX_PATH + 1] = { '\0' };
	char temp_file_path[MAX_PATH + 1] = { '\0' };

	::GetTempPathA(sizeof(temp_dir_path), temp_dir_path);
	const UINT success = ::GetTempFileNameA(temp_dir_path,
											"gtest_redir",
											0,  // Generate unique file name.
											temp_file_path);
	if (success == 0)
		ASTYLE_ABORT("Unable to create a temporary file in " + string(temp_dir_path));
	const int captured_fd = creat(temp_file_path, _S_IREAD | _S_IWRITE);
	if (captured_fd == -1)
		ASTYLE_ABORT("Unable to open temporary file " + string(temp_file_path));
	filename_ = temp_file_path;
#else
	// There's no guarantee that a test has write access to the
	// current directory, so we create the temporary file in the /tmp
	// directory instead.
	char name_template[] = "/tmp/captured_stream.XXXXXX";
	const int captured_fd = mkstemp(name_template);
	filename_ = name_template;
#endif
	fflush(NULL);
	dup2(captured_fd, fd_);
	close(captured_fd);
}

string PrintF::restoreStream()
// restore the stdout stream and return the captured text
{
	if (uncaptured_fd_ != -1)
	{
		// restore the original stream
		fflush(NULL);
		dup2(uncaptured_fd_, fd_);
		close(uncaptured_fd_);
		uncaptured_fd_ = -1;
	}
	FILE* const file = fopen(filename_.c_str(), "r");
	const string content = readEntireFile(file);
	fclose(file);
	return content;
}

//----------------------------------------------------------------------------
// AStyle print tests
//----------------------------------------------------------------------------

TEST_F(PrintF, DefaultWildcard)
// test print wildcard with no options
{
	assert(g_console != NULL);

	// expected text
	string text =
		"--------------------------------------------------\n"
		"directory <test_directory>/*.cpp\n"
		"--------------------------------------------------\n"
		"formatted  fileFormatted.cpp\n"
		"unchanged* fileUnchanged.cpp\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size(), fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, DefaultWildcard_Exclude)
// test print wildcard with an exclude
{
	assert(g_console != NULL);

	// expected text
	string text =
		"--------------------------------------------------\n"
		"directory <test_directory>/*.cpp\n"
		"exclude fileExcluded.cpp\n"
		"--------------------------------------------------\n"
		"formatted  fileFormatted.cpp\n"
		"unchanged* fileUnchanged.cpp\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);

	// add exclude files
	buildExcludeVector();

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size() - filesExcluded, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, FormattedWildcard)
// test print with "formatted" wildcard
{
	assert(g_console != NULL);
	g_console->setIsFormattedOnly(true);		// test variable

	// expected text
	string text =
		"--------------------------------------------------\n"
		"directory <test_directory>/*.cpp\n"
		"--------------------------------------------------\n"
		"formatted  fileFormatted.cpp\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, VerboseWildcard_OptionsFile)
// test print with "verbose" wildcard
{
	assert(g_console != NULL);
	g_console->setIsVerbose(true);		// test variable

	// expected text
	string text =
		"Artistic Style <version>\n"
		"Using default options file <test_directory>/astylerc.txt\n"
		"--------------------------------------------------\n"
		"directory <test_directory>/*.cpp\n"
		"--------------------------------------------------\n"
		"formatted  fileFormatted.cpp\n"
		"unchanged* fileUnchanged.cpp\n"
		"--------------------------------------------------\n"
		"1 formatted, 1 unchanged, 0 seconds, 12 lines\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);

	// add options file
	g_console->setOptionsFileName(getTestDirectory() + "/astylerc.txt");

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size() - filesExcluded, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, VerboseFormattedWildcard)
// test print with "verbose" and "formatted" wildcard
{
	assert(g_console != NULL);
	g_console->setIsVerbose(true);			// test variable
	g_console->setIsFormattedOnly(true);		// test variable

	// expected text
	string text =
		"Artistic Style <version>\n"
		"--------------------------------------------------\n"
		"directory <test_directory>/*.cpp\n"
		"--------------------------------------------------\n"
		"formatted  fileFormatted.cpp\n"
		"--------------------------------------------------\n"
		"1 formatted, 1 unchanged, 0 seconds, 12 lines\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size() - filesExcluded, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, DefaultSingleFile)
// test print single file with no options
{
	assert(g_console != NULL);

	// expected text
	string text =
		"formatted  <test_directory>/fileFormatted.cpp\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->processOptions(astyleOptionsVector);

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ((size_t) 1, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, FormattedSingleFile)
// test print with "formatted" single file
{
	assert(g_console != NULL);
	g_console->setIsFormattedOnly(true);		// test variable

	// expected text
	string text =
		"formatted  <test_directory>/fileFormatted.cpp\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->processOptions(astyleOptionsVector);

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ((size_t) 1, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, VerboseSingleFile_OptionsFile)
// test print with "verbose" single file
{
	assert(g_console != NULL);
	g_console->setIsVerbose(true);		// test variable

	// expected text
	string text =
		"Artistic Style <version>\n"
		"Using default options file <test_directory>/astylerc.txt\n"
		"formatted  <test_directory>/fileFormatted.cpp\n"
		"1 formatted, 0 unchanged, 0 seconds, 6 lines\n";
	adjustText(text);

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->processOptions(astyleOptionsVector);

	// add options file
	g_console->setOptionsFileName(getTestDirectory() + "/astylerc.txt");

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ((size_t) 1, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

TEST_F(PrintF, Quiet_AllOptions)
// test print with "quiet" and all other options
{
	assert(g_console != NULL);
	g_console->setIsFormattedOnly(true);
	g_console->setIsVerbose(true);
	g_console->setIsQuiet(true);		// test variable

	// expected text
	string text = "\n";

	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);

	// add options and exclude files
	g_console->setOptionsFileName(getTestDirectory() + "/astylerc.txt");
	buildExcludeVector();

	// redirect stdout and get the report
	redirectStream();
	g_console->processFiles();
	string textOut = restoreStream();
	adjustTextOut(textOut);

	// check entries in the fileNameVector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size() - filesExcluded, fileName.size())
			<< "Print format was not checked.";

	// check the report content
	EXPECT_EQ(text, textOut);
}

