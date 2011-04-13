// AStyleTestCon tests the ASConsole class only. This class is used only in
// the console build. It also tests the parseOption function for options used
// by only by the console build (e.g. recursive, preserve-date, verbose). It
// does not explicitely test the ASStreamIterator class or any other part
// of the program.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <time.h>
#include "AStyleTestCon.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//----------------------------------------------------------------------------
// AStyle processOptions() for console and file options
// test vectors excludeVector, excludeHitsVector, fileNameVector, optionsVector, fileOptionsVector
//----------------------------------------------------------------------------

TEST(ProcessOptions, ExcludeVector)
// test processOptions for excludeVector
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build excludeVector
	vector<string> excludesIn;
	excludesIn.push_back("--exclude=../test/prog1.cpp");
	excludesIn.push_back("--exclude=../test\\prog2.cpp");
	excludesIn.push_back("--exclude=../test/prog3.cpp");
	excludesIn.push_back("--exclude=prog4.cpp");
	excludesIn.push_back("--exclude=/prog5.cpp");
	excludesIn.push_back("--exclude=\\prog6.cpp");
	excludesIn.push_back("--exclude=../testdir1/");
	excludesIn.push_back("--exclude=..\\testdir2");
	excludesIn.push_back("--exclude=../testdir3\\");
	excludesIn.push_back("--exclude=testdir4");
	excludesIn.push_back("--exclude=/testdir5");
	excludesIn.push_back("--exclude=\\testdir6");
	g_console->processOptions(excludesIn);
	// build vector for checking results
	vector<string> excludes;
	for (size_t i = 0; i < excludesIn.size(); i++)
	{
		excludes.push_back(excludesIn[i].substr(10));
		g_console->standardizePath(excludes[i], true);
	}
	// check excludeVector
	vector<string> excludeVector = g_console->getExcludeVector();
	ASSERT_EQ(excludesIn.size(), excludeVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < excludeVector.size(); i++)
		EXPECT_EQ(excludes[i], excludeVector[i]);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, ExcludeHitsVector)
// test processOptions for excludeHitsVector
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build excludeHitsVector
	vector<string> excludesIn;
	excludesIn.push_back("--exclude=../test/prog1.cpp");
	excludesIn.push_back("--exclude=../test\\prog2.cpp");
	excludesIn.push_back("--exclude=../test/prog3.cpp");
	excludesIn.push_back("--exclude=../testdir1/");
	excludesIn.push_back("--exclude=..\\testdir2");
	excludesIn.push_back("--exclude=../testdir3\\");
	g_console->processOptions(excludesIn);
	// check excludeHitsVector
	vector<bool> excludeHitsVector = g_console->getExcludeHitsVector();
	ASSERT_EQ(excludesIn.size(), excludeHitsVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < excludeHitsVector.size(); i++)
		EXPECT_FALSE(excludeHitsVector[i]);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileNameVector)
// test processOptions for fileNameVector
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build fileNameVector
	vector<string> fileNameIn;
	fileNameIn.push_back("../..\\..\\srccon/*.cpp");
	g_console->processOptions(fileNameIn);
	vector<string> fileName;
	fileName.push_back("../../../srccon/*.cpp");
	g_console->standardizePath(fileName.back());
	// check fileNameVector
	vector<string> fileNameVector = g_console->getFileNameVector();
	ASSERT_EQ(fileName.size(), fileNameVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileNameVector.size(); i++)
		EXPECT_EQ(fileName[i], fileNameVector[i]);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, OptionsVector)
// test processOptions for optionsVector
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsVector
	vector<string> optionsIn;
	optionsIn.push_back("--style=allman");
	optionsIn.push_back("--indent-classes");
	optionsIn.push_back("-OoP");
	optionsIn.push_back("-Ewc");
	optionsIn.push_back("--align-pointer=type");
	g_console->processOptions(optionsIn);
	// check optionsVector
	vector<string> optionsVector = g_console->getOptionsVector();
	ASSERT_EQ(optionsIn.size(), optionsVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < optionsVector.size(); i++)
		EXPECT_EQ(optionsIn[i], optionsVector[i]);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector)
// test processOptions for fileOptionsVector with --options=###
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	char fileIn[] =
		"# this line is a comment\n"
		"--brackets=attach   # this is a line-end comment\n"
		"\n"
		"# long options can be written without the preceding '--'\n"
		"indent-switches     # cannot do this on the command line\n"
		"\n"
		"# short options must have the preceding '-'\n"
		"-t -p\n"
		"\n"
		"# short options can be concatenated together\n"
		"-M65Ucv\n"
		"\n"
		"# options can be separated with commas\n"
		"indent-classes,-K\n";
	vector<string> fileOptions;
	fileOptions.push_back("--brackets=attach");
	fileOptions.push_back("indent-switches");
	fileOptions.push_back("-t");
	fileOptions.push_back("-p");
	fileOptions.push_back("-M65Ucv");
	fileOptions.push_back("indent-classes");
	fileOptions.push_back("-K");
	// write the options file
	string optionsFileName = getTestDirectory() + "/astylerc.txt";
	g_console->standardizePath(optionsFileName);
	if (!writeOptionsFile(optionsFileName, fileIn))
		return;
	// build fileOptionsVector
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	g_console->processOptions(optionsIn);
	// check fileOptionsVector
	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	ASSERT_EQ(fileOptions.size(), fileOptionsVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileOptionsVector.size(); i++)
		EXPECT_EQ(fileOptions[i], fileOptionsVector[i]);
	removeTestFile(optionsFileName);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_EnvironmentVariable)
// test processOptions for fileOptionsVector
//     with ARTISTIC_STYLE_OPTIONS enviromnent variable
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes\n";
	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-classes");
	// set the new environment variable
	string envFilePath =  getTestDirectory() + "/astylexx";
	string envValue = "ARTISTIC_STYLE_OPTIONS=" + envFilePath;
	g_console->standardizePath(envFilePath);
	g_console->standardizePath(envValue);
	int isError = putenv(const_cast<char*>(envValue.c_str()));
	if (isError)
	{
		systemPause("Cannot set ARTISTIC_STYLE_OPTIONS environment variable");
		return;
	}
	// write the options file
	if (!writeOptionsFile(envFilePath.c_str(), fileIn))
		return;
	// build fileOptionsVector
	vector<string> optionsIn;
	g_console->processOptions(optionsIn);
	// check fileOptionsVector
	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	ASSERT_EQ(fileOptions.size(), fileOptionsVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileOptionsVector.size(); i++)
		EXPECT_EQ(fileOptions[i], fileOptionsVector[i]);
	// clear the environment variable
	string envClear = "ARTISTIC_STYLE_OPTIONS=";
	putenv(const_cast<char*>(envClear.c_str()));
	// cleanup
	removeTestFile(envFilePath);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_Home)
// test processOptions for fileOptionsVector with $HOME options
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes\n";
	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-classes");
	// write the file
#ifdef _WIN32
	char* env = getenv("USERPROFILE");
	char name[] = "/astylerc";
#else
	char* env = getenv("HOME");
	char name[] = "/.astylerc";
#endif
	if (env == NULL)
	{
		systemPause("Cannot get $HOME directory");
		return;
	}
	// write the options file
	string optionsFileName = string(env) + name;
	g_console->standardizePath(optionsFileName);
	if (!writeOptionsFile(optionsFileName, fileIn))
		return;
	// build fileOptionsVector
	vector<string> optionsIn;
	g_console->processOptions(optionsIn);
	// check fileOptionsVector
	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	ASSERT_EQ(fileOptions.size(), fileOptionsVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileOptionsVector.size(); i++)
		EXPECT_EQ(fileOptions[i], fileOptionsVector[i]);
	removeTestFile(optionsFileName);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_None)
// test processOptions for fileOptionsVector with --options=none
// should not process the astylerc file
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes\n";
	// write the file
#ifdef _WIN32
	char* env = getenv("USERPROFILE");
	char name[] = "/astylerc";
#else
	char* env = getenv("HOME");
	char name[] = "/.astylerc";
#endif
	if (env == NULL)
	{
		systemPause("Cannot get $HOME directory");
		return;
	}
	string optionsFileName = string(env) + name;
	g_console->standardizePath(optionsFileName);
	if (!writeOptionsFile(optionsFileName, fileIn))
		return;
	// build fileOptionsVector
	vector<string> optionsIn;
	optionsIn.push_back("--options=none");
	g_console->processOptions(optionsIn);
	// check fileOptionsVector
	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	EXPECT_TRUE(fileOptionsVector.size() == 0);
	removeTestFile(optionsFileName);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_NoLineEnd)
// test processOptions for fileOptionsVector with --options=###
//    and NO final line end
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes";		// *** no final line end ***
	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-classes");
	// write the options file
	string optionsFileName = getTestDirectory() + "/astylerc";
	g_console->standardizePath(optionsFileName);
	if (!writeOptionsFile(optionsFileName, fileIn))
		return;
	// build fileOptionsVector
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	g_console->processOptions(optionsIn);
	// check fileOptionsVector
	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	ASSERT_EQ(fileOptions.size(), fileOptionsVector.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileOptionsVector.size(); i++)
		EXPECT_EQ(fileOptions[i], fileOptionsVector[i]);
	removeTestFile(optionsFileName);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_Error)
// test processOptions for file option errors
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--invalid1\n"
		"--invalid2\n"
		"--invalid3\n"
		"--indent-classes\n";
	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--invalid1");
	fileOptions.push_back("--invalid2");
	fileOptions.push_back("--invalid3");
	fileOptions.push_back("--indent-classes");
	// write options the file
	string optionsFileName = getTestDirectory() + "/astylerc.txt";
	g_console->standardizePath(optionsFileName);
	if (!writeOptionsFile(optionsFileName, fileIn))
		return;
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	optionsIn.push_back("--ascii");		// output in English
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions with invalid file options
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"Invalid option file options:\n"
				"invalid1\n"
				"invalid2\n"
				"invalid3\n\n"
				"For help on options type 'astyle -h'");
#endif
	removeTestFile(optionsFileName);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_FileError1)
// test processOptions with an options file error
// input with --options=###
// invalidrc.txt is not a valid file
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	string optionsFileName = "../../srccon/invalidrc.txt";
	g_console->standardizePath(optionsFileName);
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	optionsIn.push_back("--ascii");		// output in English
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions with options file error
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"Cannot open options file");
#endif
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, FileOptionsVector_FileError2)
// test processOptions with an options file error
// input with --options= (no filename)
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--options=");
	optionsIn.push_back("--ascii");		// output in English
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions with options file error
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"Cannot open options file");
#endif
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, GetCurrentDirectory)
// test getCurrentDirectory function
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	g_console->setNoBackup(true);
	g_console->setIsQuiet(true);		// change this to see results
	char textIn[] = "void foo(){}\n";
	// a file without a path will call the g_console->getCurrentDirectory
	string testFile = "/testGetCurrentDirectory.cpp";
	string testFilePath = getCurrentDirectory() + testFile;
	g_console->standardizePath(testFilePath);
	// write the output file to the current directory
	ofstream fout(testFilePath.c_str(), ios::binary | ios::trunc);
	if (!fout)
	{
		systemPause("Cannot open output file: " + testFilePath);
		return;
	}
	fout << textIn;
	fout.close();
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(testFilePath);
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(testFilePath, fileName[0]);
	removeTestFile(testFilePath);
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, OtherOptions)
// test processOptions for other options
// the "lineend" option is tested separately
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// set console options
	vector<string> optionsIn;
	optionsIn.push_back("--suffix=none");
	optionsIn.push_back("--suffix=.old");
	optionsIn.push_back("--recursive");
	optionsIn.push_back("--verbose");
	optionsIn.push_back("--formatted");
	optionsIn.push_back("--quiet");
	optionsIn.push_back("--errors-to-stdout");
	optionsIn.push_back("--preserve-date");
	g_console->processOptions(optionsIn);
	// check console options
	EXPECT_TRUE(g_console->getNoBackup());
	EXPECT_EQ(string(".old"), g_console->getOrigSuffix());
	EXPECT_TRUE(g_console->getIsRecursive());
	EXPECT_TRUE(g_console->getIsVerbose());
	EXPECT_TRUE(g_console->getIsFormattedOnly());
	EXPECT_TRUE(g_console->getIsQuiet());
	EXPECT_TRUE(_err == &cout);
	EXPECT_TRUE(g_console->getPreserveDate());
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, OtherOptions_Short)
// test processOptions for short other options
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// set console options
	vector<string> optionsIn;
	optionsIn.push_back("-n");	// suffix=none
	optionsIn.push_back("-r");	// recursive
	optionsIn.push_back("-R");	// recursive
	optionsIn.push_back("-v");	// verbose
	optionsIn.push_back("-Q");	// formatted
	optionsIn.push_back("-q");	// quiet
	optionsIn.push_back("-X");	// errors-to-stdout
	optionsIn.push_back("-Z");	// preserve-date
	g_console->processOptions(optionsIn);
	// check console options
	EXPECT_TRUE(g_console->getNoBackup());
	EXPECT_TRUE(g_console->getIsRecursive());
	EXPECT_TRUE(g_console->getIsVerbose());
	EXPECT_TRUE(g_console->getIsFormattedOnly());
	EXPECT_TRUE(g_console->getIsQuiet());
	EXPECT_TRUE(_err == &cout);
	EXPECT_TRUE(g_console->getPreserveDate());
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, ConsoleOptions_Error)
// test processOptions for command line options errors
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--style=allman");
	optionsIn.push_back("-OoP");
	optionsIn.push_back("--invalid1");
	optionsIn.push_back("--invalid2");
	optionsIn.push_back("--invalid3");
	optionsIn.push_back("--indent-classes");
	optionsIn.push_back("--ascii");		// output in English
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions with invalid command line options
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"Invalid command line options:\n"
				"invalid1\n"
				"invalid2\n"
				"invalid3\n\n"
				"For help on options type 'astyle -h'");
#endif
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle ascii, help and version options
//----------------------------------------------------------------------------

TEST(ProcessOptions, AsciiOption)
// test processOptions for ascii option
// For a complete test the user locale should something besides English.
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--ascii");
	g_console->processOptions(optionsIn);
	string langID = g_console->getLanguageID();
	EXPECT_EQ(langID, "en");
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, AsciiOption_Short)
// test processOptions for ascii short option -I
// For a complete test the user locale should something besides English.
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("-I");
	g_console->processOptions(optionsIn);
	// test the language
	string langID = g_console->getLanguageID();
	EXPECT_EQ(langID, "en");
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, HelpOption)
// test processOptions for help option display
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--help");
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions for help option display
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_SUCCESS),
				"Bracket Style Options:");
#endif
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, HelpOption_Short1)
// test processOptions for help short option -h display
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("-h");
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions for help option display
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_SUCCESS),
				"Bracket Style Options:");
#endif
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, HelpOption_Short2)
// test processOptions for help short option -? display
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("-?");
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions for help option display
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_SUCCESS),
				"Bracket Style Options:");
#endif
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, VersionOption)
// test processOptions for version option display
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--version");
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions for version option display
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_SUCCESS),
				"Artistic Style Version ");
#endif
	deleteConsoleGlobalObject();
}

TEST(ProcessOptions, VersionOption_Short)
// test processOptions for version short option display
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("-V");
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions for version option display
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_SUCCESS),
				"Artistic Style Version ");
#endif
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle file suffix option
//----------------------------------------------------------------------------

struct FileSuffixF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	// build fileNames vector and write the output files
	FileSuffixF()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		fileNames.push_back(getTestDirectory() + "/suffix1.cpp");
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
		}
	}

	~FileSuffixF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(FileSuffixF, None)
// test suffix=none option on files
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);		// test variable
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// all files should be formatted
	ASSERT_EQ((int)fileNames.size(), g_console->getFilesFormatted());
	// check for .orig file on disk
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string origFileName = fileNames[0] + ".orig";
		struct stat stBuf;
		// display error if file is present
		if (stat(origFileName.c_str(), &stBuf) != -1)
			EXPECT_STREQ("\"no file\"", origFileName.c_str());
	}
}

TEST_F(FileSuffixF, DotOld)
// test suffix=.old option on files (with dot)
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setOrigSuffix(".old"); 	// test variable (with dot)
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// all files should be formatted
	EXPECT_TRUE(fileNames.size() > 0);
	ASSERT_EQ((int)fileNames.size(), g_console->getFilesFormatted());
	// check for .old file on disk
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string origFileName = fileNames[0] + ".old";
		struct stat stBuf;
		// display error if file is not present
		if (stat(origFileName.c_str(), &stBuf) == -1)
			EXPECT_STREQ(origFileName.c_str(), "\"no file\"");
	}
}

TEST_F(FileSuffixF, SansDot)
// test suffix=xxx option on files (no dot)
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setOrigSuffix("xxx"); 	// test variable (no dot)
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// all files should be formatted
	EXPECT_TRUE(fileNames.size() > 0);
	ASSERT_EQ((int)fileNames.size(), g_console->getFilesFormatted());
	// check for xxx file on disk
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string origFileName = fileNames[0] + "xxx";
		struct stat stBuf;
		// display error if file is not present
		if (stat(origFileName.c_str(), &stBuf) == -1)
			EXPECT_STREQ(origFileName.c_str(), "\"no file\"");
	}
}

//----------------------------------------------------------------------------
// AStyle stringEndsWith function
//----------------------------------------------------------------------------

TEST(StringEndsWith, FileExtension_True)
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	bool result1 = g_console->stringEndsWith("fileName.cpp", string(".cpp"));
	EXPECT_TRUE(result1);
	deleteConsoleGlobalObject();
}

TEST(StringEndsWith, FileExtension_False)
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	bool result2 = g_console->stringEndsWith("fileName.cpp", string(".xxx"));
	EXPECT_FALSE(result2);
	deleteConsoleGlobalObject();
}

TEST(StringEndsWith, SansFileExtension)
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	bool result3 = g_console->stringEndsWith("fileNamenoextension", string("noextension"));
	EXPECT_TRUE(result3);
	deleteConsoleGlobalObject();
}

TEST(StringEndsWith, WholeName)
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	bool result4 = g_console->stringEndsWith("wholename", string("wholename"));
	EXPECT_TRUE(result4);
	deleteConsoleGlobalObject();
}

TEST(StringEndsWith, TestLongerThanName)
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	bool result5 = g_console->stringEndsWith("long", string("xlong"));
	EXPECT_FALSE(result5);
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle preserve-date option
//----------------------------------------------------------------------------

struct PreserveDateF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;
	struct utimbuf ut;

	// build fileNames vector and write the output files with an old date
	PreserveDateF()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		// Jan 1, 2008
		struct tm t;
		t.tm_mday  = 1;		// day of the month	1-31
		t.tm_mon   = 0;		// months since January	0-11
		t.tm_year  = 108;	// years since 1900
		t.tm_hour  = 0;
		t.tm_min   = 0;
		t.tm_sec   = 0;
		t.tm_isdst = 0;
		ut.actime = ut.modtime = mktime(&t);
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		fileNames.push_back(getTestDirectory() + "/PreserveDate1.cpp");
		fileNames.push_back(getTestDirectory() + "/PreserveDate2.cpp");
		// write files and change the date
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
			utime(fileNames[i].c_str(), &ut);
		}
	}

	~PreserveDateF()
	{
		deleteConsoleGlobalObject();
	}

	// get the date from time_t
	string getMDY(time_t dateIn)
	{
		string date = ctime(&dateIn);
		string dateMDY = date.erase(11,9);	// remove the time
		// cout << dateMDY << endl;
		return dateMDY;
	}
};

TEST_F(PreserveDateF, True)
// test formatting with preserve-date option
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	g_console->setPreserveDate(true);
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// loop thru fileNames vector checking the dates
	// difference is added in preserveFileDate() in astyle_main
	struct stat s;
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		stat(fileNames[i].c_str(), &s);
		EXPECT_EQ(10, difftime(s.st_mtime, ut.modtime));
	}
}

TEST_F(PreserveDateF, False)
// test formatting without preserve-date option
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	g_console->setPreserveDate(false);
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// loop thru fileNames vector checking the dates
	string currMDY = getMDY(time(NULL));
	struct stat s;
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		stat(fileNames[i].c_str(), &s);
		string fileMDY = getMDY(s.st_mtime);
		EXPECT_EQ(currMDY, fileMDY);
	}
}

//----------------------------------------------------------------------------
// AStyle checksum procedure
//----------------------------------------------------------------------------

struct ChecksumF : public ::testing::Test
{
	ASFormatter formatter;
	string fileName;
	size_t textChecksum;

	// build fileNames vector and write the output file
	ChecksumF()
	{
		textChecksum = 9699;
		char textIn[] =
			"\n#include <stdio.h>\n"
			"\n"
			"void foo(int a)\n"
			"{\n"
			"    int i = 10;\n"
			"    int i2 = 12;\n"
			"    int i3 = i + i2;\n"
			"    printf(\"i3 = %d\", i3);\n"
			"    // for add-brackets test\n"
			"    if (a == 0)\n"
			"        x = 0;\n"
			"}";
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		fileName = getTestDirectory() + "/TestChecksum.cpp";
		createTestFile(fileName, textIn);
	}

	~ChecksumF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(ChecksumF, NoAdds)
// test checksum procedure
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// verify the checksums
	size_t checksumIn = formatter.getChecksumIn();
	size_t checksumOut = formatter.getChecksumOut();
#ifdef NDEBUG
	EXPECT_EQ(0U, checksumIn);
	EXPECT_EQ(0U, checksumOut);
#else
	EXPECT_EQ(textChecksum, checksumIn);
	EXPECT_EQ(textChecksum, checksumOut);
#endif
	EXPECT_TRUE(formatter.getChecksumDiff() == 0);
}

TEST_F(ChecksumF, AddBrackets)
// test checksum procedure with add-brackets
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back("--add-brackets");
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// verify the checksums
	textChecksum += '{' + '}';
	size_t checksumIn = formatter.getChecksumIn();
	size_t checksumOut = formatter.getChecksumOut();
#ifdef NDEBUG
	EXPECT_EQ(0U, checksumIn);
	EXPECT_EQ(0U, checksumOut);
#else
	EXPECT_EQ(textChecksum, checksumIn);
	EXPECT_EQ(textChecksum, checksumOut);
#endif
	EXPECT_TRUE(formatter.getChecksumDiff() == 0);
}

TEST_F(ChecksumF, AddOneLineBrackets)
// test checksum procedure with add-one-line-brackets
{
	ASSERT_TRUE(g_console != NULL) << "Console object not initialized.";
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	// call astyle processOptions()
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back("--add-one-line-brackets");
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	// call astyle processFiles()
	g_console->processFiles();
	// verify the checksums
	textChecksum += '{' + '}';
	size_t checksumIn = formatter.getChecksumIn();
	size_t checksumOut = formatter.getChecksumOut();
#ifdef NDEBUG
	EXPECT_EQ(0U, checksumIn);
	EXPECT_EQ(0U, checksumOut);
#else
	EXPECT_EQ(textChecksum, checksumIn);
	EXPECT_EQ(textChecksum, checksumOut);
#endif
	EXPECT_TRUE(formatter.getChecksumDiff() == 0);
}

//----------------------------------------------------------------------------
// AStyle ASResource operator vectors sequence
//----------------------------------------------------------------------------

TEST(OperatorVectorSequence, BuildOperators)
// check the sequence of ASResource::buildOperators
{
	// build the operators vector
	ASResource resource;
	vector<const string*> operators;
	resource.buildOperators(&operators);
	// test the operators vector sequence
	// vector sequence is descending length of the operators
	size_t prevOperatorLength = 9;
	for (size_t i = 0; i < operators.size(); i++)
	{
		EXPECT_TRUE(prevOperatorLength >= (*operators[i]).length());
		prevOperatorLength = (*operators[i]).length();
	}
}

TEST(OperatorVectorSequence, BuildAssignmentOperators)
// check the sequence of ASResource::buildAssignmentOperators
{
	// build the assignmentOperators vector
	ASResource resource;
	vector<const string*> assignmentOperators;
	resource.buildAssignmentOperators(&assignmentOperators);
	// test the assignmentOperators vector sequence
	// vector sequence is descending length of the operators
	size_t prevOperatorLength = 9;
	for (size_t i = 0; i < assignmentOperators.size(); i++)
	{
		EXPECT_TRUE(prevOperatorLength >= (*assignmentOperators[i]).length());
		prevOperatorLength = (*assignmentOperators[i]).length();
	}
}

TEST(OperatorVectorSequence, BuildNonAssignmentOperators)
// check the sequence of ASResource::buildNonAssignmentOperators
{
	// build the nonAssignmentOperators vector
	ASResource resource;
	vector<const string*> nonAssignmentOperators;
	resource.buildNonAssignmentOperators(&nonAssignmentOperators);
	// test the nonAssignmentOperators vector sequence
	// vector sequence is descending length of the operators
	size_t prevOperatorLength = 9;
	for (size_t i = 0; i < nonAssignmentOperators.size(); i++)
	{
		EXPECT_TRUE(prevOperatorLength >= (*nonAssignmentOperators[i]).length());
		prevOperatorLength = (*nonAssignmentOperators[i]).length();
	}
}

//----------------------------------------------------------------------------
// AStyle ASResource header vectors sequence
//----------------------------------------------------------------------------

TEST(HeaderVectorSequence, BuildCastOperators)
// check the sequence of ASResource::buildCastOperators
{
	// build the castOperators vector
	ASResource resource;
	vector<const string*> castOperators;
	resource.buildCastOperators(&castOperators);
	// test the castOperators vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < castOperators.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*castOperators[i]));
		prevHeader = (*castOperators[i]);
	}
}

TEST(HeaderVectorSequence, BuildHeaders)
// check the sequence of ASResource::buildHeaders
{
	// build the headers vector
	ASResource resource;
	vector<const string*> headers;
	resource.buildHeaders(&headers, SHARP_TYPE, true);
	// test the headers vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < headers.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*headers[i]));
		prevHeader = (*headers[i]);
	}
}

TEST(HeaderVectorSequence, BuildIndentableHeaders)
// check the sequence of ASResource::buildIndentableHeaders
{
	// build the indentableHeaders vector
	ASResource resource;
	vector<const string*> indentableHeaders;
	resource.buildIndentableHeaders(&indentableHeaders);
	// test the indentableHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < indentableHeaders.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*indentableHeaders[i]));
		prevHeader = (*indentableHeaders[i]);
	}
}

TEST(HeaderVectorSequence, BuildNonParenHeaders)
// check the sequence of ASResource::buildNonParenHeaders
{
	// build the nonParenHeaders vector
	ASResource resource;
	vector<const string*> nonParenHeaders;
	resource.buildNonParenHeaders(&nonParenHeaders, SHARP_TYPE, true);
	// test the nonParenHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < nonParenHeaders.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*nonParenHeaders[i]));
		prevHeader = (*nonParenHeaders[i]);
	}
}

TEST(HeaderVectorSequence, BuildPreBlockStatements)
// check the sequence of ASResource::buildPreBlockStatements
{
	// build the preBlockStatements vector
	ASResource resource;
	vector<const string*> preBlockStatements;
	resource.buildPreBlockStatements(&preBlockStatements, SHARP_TYPE);
	// test the preBlockStatements vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < preBlockStatements.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*preBlockStatements[i]));
		prevHeader = (*preBlockStatements[i]);
	}
}

TEST(HeaderVectorSequence, BuildPreCommandHeaders)
// check the sequence of ASResource::buildPreCommandHeaders
{
	// build the preCommandHeaders vector
	ASResource resource;
	vector<const string*> preCommandHeaders;
	resource.buildPreCommandHeaders(&preCommandHeaders, SHARP_TYPE);
	// test the preCommandHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < preCommandHeaders.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*preCommandHeaders[i]));
		prevHeader = (*preCommandHeaders[i]);
	}
}

TEST(HeaderVectorSequence, BuildPreDefinitionHeaders)
// check the sequence of ASResource::buildPreDefinitionHeaders
{
	// build the preDefinitionHeaders vector
	ASResource resource;
	vector<const string*> preDefinitionHeaders;
	resource.buildPreDefinitionHeaders(&preDefinitionHeaders, SHARP_TYPE);
	// test the preDefinitionHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < preDefinitionHeaders.size(); i++)
	{
		EXPECT_TRUE(prevHeader < (*preDefinitionHeaders[i]));
		prevHeader = (*preDefinitionHeaders[i]);
	}
}

//----------------------------------------------------------------------------
// AStyle Removed Options release 2.02
//----------------------------------------------------------------------------

TEST(RemovedOptions_V202, AllOptions)
// test that removed options are rejected with a message
{
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// build optionsIn
	vector<string> optionsIn;
	optionsIn.push_back("--brackets=horstmann");
	optionsIn.push_back("--indent-brackets");
	optionsIn.push_back("--indent-blocks");
	optionsIn.push_back("-B");
	optionsIn.push_back("-G");
	optionsIn.push_back("--ascii");		// output in English
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	// test processOptions with invalid command line options
	EXPECT_EXIT(g_console->processOptions(optionsIn),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"Invalid command line options:\n"
				"brackets=horstmann\n"
				"indent-brackets\n"
				"indent-blocks\n"
				"B\n"
				"G\n");
#endif
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------

}  // namespace

