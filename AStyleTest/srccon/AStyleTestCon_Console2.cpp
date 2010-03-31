// AStyleTestCon tests the ASConsole class only. This class is used only in
// the console build. It also tests the parseOption function for options used
// by only by the console build (e.g. recursive, preserve-date, verbose). It
// does not explicitely test the ASStreamIterator class or any other part
// of the program.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <algorithm>
#include "AStyleTestCon.h"
#ifdef _WIN32
#include <windows.h>
#endif

//----------------------------------------------------------------------------
// AStyle test getFilePaths(), wildcmp(), and fileName vector
//----------------------------------------------------------------------------

struct GetFilePathsF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	// build fileNames vector and write the output files
	GetFilePathsF()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		fileNames.push_back(getTestDirectory() + "/getFilePaths1.cpp");
		fileNames.push_back(getTestDirectory() + "/getFilePaths2.cpp");
		fileNames.push_back(getTestDirectory() + "/getFilePaths3.cpp");
		fileNames.push_back(getTestDirectory() + "/getFilePaths4.cpp");

		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
		}
	}

	~GetFilePathsF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(GetFilePathsF, FilePaths1)
// test fileName vector and getFilePaths with *.cpp
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileName.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GetFilePathsF, FilePaths2)
// test fileName vector and getFilePaths with *.c??
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.c??", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();	// initialize variables
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileName.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GetFilePathsF, FilePaths3)
// test fileName vector and getFilePaths with getFilePaths*.cpp
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/getFilePaths*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileName.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GetFilePathsF, FilePaths4)
// test fileName vector and getFilePaths with *.c*
// * at the end WITH remaining data allows complete coverage of wildcmp function
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.c*", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileName.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GetFilePathsF, FilePaths5)
// test fileName vector and getFilePaths with *.cpp*
// * at the end WITHOUT remaining data allows complete coverage of wildcmp function
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp*", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size()) << "Vector sizes not equal.";
	for (size_t i = 0; i < fileName.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GetFilePathsF, FilePathsError)
// test fileName vector and getFilePaths with bad path
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	// do not display error message
	_err = new stringstream;

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/AStyleError*", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_TRUE(fileName.size() == 0);

	delete _err;
	_err = &cerr;
}

//----------------------------------------------------------------------------
// AStyle test getFileType() - C_TYPE, JAVA_TYPE, SHARP_TYPE
//----------------------------------------------------------------------------
struct GetFileTypeF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	// build fileNames vector and write the output files
	GetFileTypeF()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"    bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		fileNames.push_back(getTestDirectory() + "/getFileType1.cpp");
		fileNames.push_back(getTestDirectory() + "/getFileType2.java");
		fileNames.push_back(getTestDirectory() + "/getFileType3.cs");
		fileNames.push_back(getTestDirectory() + "/getFileType4.error");

		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
		}
	}

	~GetFileTypeF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(GetFileTypeF, FileTypeC)
// test getFileType with *.cpp
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	EXPECT_EQ(formatter.getFileType(), C_TYPE);
}

TEST_F(GetFileTypeF, FileTypeJave)
// test getFileType with *.java
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.java", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	EXPECT_EQ(formatter.getFileType(), JAVA_TYPE);
}

TEST_F(GetFileTypeF, FileTypeSharp)
// test getFileType with *.cs
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cs", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	EXPECT_EQ(formatter.getFileType(), SHARP_TYPE);
}

TEST_F(GetFileTypeF, FileTypeError)
// test getFileType with an invalid type, should return C_TYPE
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.error", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	EXPECT_EQ(formatter.getFileType(), C_TYPE);
}

//----------------------------------------------------------------------------
// AStyle test recursive option - getFilePaths(), wildcmp(), and fileName vector
//----------------------------------------------------------------------------

struct RecursiveF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	// build fileNames vector and write the output files
	RecursiveF()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);

		// create directories
		string sub1  = getTestDirectory() + "/subdir1";
		string sub1a = getTestDirectory() + "/subdir1/subdir1a";
		string sub1b = getTestDirectory() + "/subdir1/subdir1b";
		string sub2  = getTestDirectory() + "/subdir2";
		g_console->standardizePath(sub1);
		g_console->standardizePath(sub1a);
		g_console->standardizePath(sub1b);
		g_console->standardizePath(sub2);
		createTestDirectory(sub1);
		createTestDirectory(sub1a);
		createTestDirectory(sub1b);
		createTestDirectory(sub2);

		// create test files
		fileNames.push_back(getTestDirectory() + "/recursive1.cpp");
		fileNames.push_back(getTestDirectory() + "/recursive2.cpp");
		fileNames.push_back(sub1 + "/recursive3.cpp");
		fileNames.push_back(sub1 + "/recursive4.cpp");
		fileNames.push_back(sub1a + "/recursive5.cpp");
		fileNames.push_back(sub1a + "/recursive6.cpp");
		fileNames.push_back(sub1b + "/recursive7.cpp");
		fileNames.push_back(sub1b + "/recursive8.cpp");
		fileNames.push_back(sub2 + "/recursive9.cpp");
		fileNames.push_back(sub2 + "/recursive10.cpp");

		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
		}
	}

	~RecursiveF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(RecursiveF, Default)
// test recursive option
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size(), fileName.size());
	sort(fileNames.begin(), fileNames.end());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(RecursiveF, Sans)
// test *.cpp WITHOUT recursive
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(false);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// delete sub directory files from the fileName vector
	size_t searchStart = getTestDirectory().length() + 1;
	for (int i = 0; i < (int) fileNames.size(); i++)
	{
		if (fileNames[i].find_first_of("\\/", searchStart) != string::npos)
		{
			// cout << fileNames[i] << endl;
			vector<string>::iterator iter = fileNames.begin() + i;
			fileNames.erase(iter);
			i--;
			continue;
		}
	}
	// check the files
	EXPECT_TRUE(fileNames.size() > 0);
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size(), fileName.size());
	sort(fileNames.begin(), fileNames.end());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(RecursiveF, Exclude)
// test recursive option with exclude
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build exclude vector
	size_t filesExcluded = 0;
	// file
	g_console->updateExcludeVector("recursive1.cpp");
	filesExcluded += 1;
	// directory
	g_console->updateExcludeVector("subdir1a");
	filesExcluded += 2;
	// full path file
	g_console->updateExcludeVector(getTestDirectory() + "/subdir2/recursive9.cpp");
	filesExcluded += 1;
	// full path directory
	g_console->updateExcludeVector(getTestDirectory() + "/subdir1/subdir1b");
	filesExcluded += 2;

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());
}

TEST_F(RecursiveF, ExcludeErrors)
// test recursive option with exclude
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);

	// capture the error message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build exclude vector
	// partial match on file
	g_console->updateExcludeVector("ecursive1.cpp");
	// partial match on directory
	g_console->updateExcludeVector("ubdir1a");

	// process entries in the fileNameVector
	g_console->processFiles();

	// display error message if not rejected
	string errMsg1 = "Unmatched exclude ecursive1.cpp";
	size_t result1 = msgOut->str().find(errMsg1);
	if (result1 == string::npos)
		EXPECT_EQ(errMsg1, "\"not found\"");
	string errMsg2 = "Unmatched exclude ubdir1a";
	size_t result2 = msgOut->str().find(errMsg2);
	if (result2 == string::npos)
		EXPECT_EQ(errMsg2, "\"not found\"");

	delete msgOut;
	_err = &cerr;
}

TEST_F(RecursiveF, HiddenFiles)
// test recursive option with hidden files
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// write the hidden files
	char textIn[] = "void foo(){}\n";
	// hidden on Linux and Windows
	string dirOut1 = getTestDirectory() + "/.hidden";
	g_console->standardizePath(dirOut1);
	createTestDirectory(dirOut1);
	string fileOut1 = getTestDirectory() + "/.hidden/hidden1.cpp";
	g_console->standardizePath(fileOut1);
	createTestFile(fileOut1, textIn);
	string fileOut2 = getTestDirectory() + "/.hidden2.cpp";
	g_console->standardizePath(fileOut2);
	createTestFile(fileOut2, textIn);
	// hidden on Windows only
#ifdef _WIN32
	string dirOut1w = getTestDirectory() + "/readonlywin";
	g_console->standardizePath(dirOut1w);
	createTestDirectory(dirOut1w);
	SetFileAttributes(dirOut1w.c_str(), FILE_ATTRIBUTE_READONLY	);
	string fileOut1w = getTestDirectory() + "/readonlywin/readonly1win.cpp";
	g_console->standardizePath(fileOut1w);
	createTestFile(fileOut1w, textIn);
	string fileOut2w = getTestDirectory() + "/hidden2win.cpp";
	g_console->standardizePath(fileOut2w);
	createTestFile(fileOut2w, textIn);
	SetFileAttributes(fileOut2w.c_str(), FILE_ATTRIBUTE_HIDDEN);
	string fileOut3w = getTestDirectory() + "/readonly2win.cpp";
	g_console->standardizePath(fileOut3w);
	createTestFile(fileOut3w, textIn);
	SetFileAttributes(fileOut3w.c_str(), FILE_ATTRIBUTE_READONLY);
#endif

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	// hidden files should not be in g_console vector
	EXPECT_EQ(fileNames.size(), fileName.size());

#ifdef _WIN32
	// reset file attributes
	SetFileAttributes(dirOut1w.c_str(), FILE_ATTRIBUTE_NORMAL);
	SetFileAttributes(fileOut2w.c_str(), FILE_ATTRIBUTE_NORMAL);
	SetFileAttributes(fileOut3w.c_str(), FILE_ATTRIBUTE_NORMAL);
#endif
}

//----------------------------------------------------------------------------
// AStyle line ends formatted
// tests if a line end change formats the file
//----------------------------------------------------------------------------

struct LineEndsFormattedF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string pathLinux;
	string pathWindows;
	string pathMacOld;

	// build fileNames vector and write the output files
	LineEndsFormattedF()
	{
		textLinuxStr =			// has macold line ends
			"\rvoid foo()\r"
			"{\r"
			"    bar()\r"
			"}\r";
		textWindowsStr =		// has linux line ends
			"\nvoid foo()\n"
			"{\n"
			"    bar()\n"
			"}\n";
		textMacOldStr =			// has windows line ends
			"\r\nvoid foo()\r\n"
			"{\r\n"
			"    bar()\r\n"
			"}\r\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		pathLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(pathLinux);
		createTestFile(pathLinux, textLinux);
		pathWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(pathWindows);
		createTestFile(pathWindows, textWindows);
		pathMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(pathMacOld);
		createTestFile(pathMacOld, textMacOld);
	}

	~LineEndsFormattedF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(LineEndsFormattedF, LineEndWindows)
// test if lineend=windows formats the file
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileWindows = pathWindows.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileWindows, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=windows");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	processReturn = g_console->processOptions(argc, argv);
	ASSERT_TRUE(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	EXPECT_EQ(optionsIn.size(), optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathWindows + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ(origFileName.c_str(), "\"no file\"");

	delete [] argv;
}

TEST_F(LineEndsFormattedF, LineEndLinux)
// test if lineend=linux formats the file
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileLinux = pathLinux.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileLinux, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=linux");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	processReturn = g_console->processOptions(argc, argv);
	ASSERT_TRUE(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	EXPECT_EQ(optionsIn.size(), optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathLinux + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ(origFileName.c_str(), "\"no file\"");

	delete [] argv;
}

TEST_F(LineEndsFormattedF, LineEndMacOld)
// test if lineend=macold formats the file
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileMacOld = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileMacOld, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=macold");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	processReturn = g_console->processOptions(argc, argv);
	ASSERT_TRUE(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	EXPECT_EQ(optionsIn.size(), optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathMacOld + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ(origFileName.c_str(), "\"no file\"");

	delete [] argv;
}

//----------------------------------------------------------------------------
// AStyle line ends unchanged
// tests if an unchanged line end leaves the file unchanged
//----------------------------------------------------------------------------

struct LineEndsUnchangedF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string pathLinux;
	string pathWindows;
	string pathMacOld;

	// build fileNames vector and write the output files
	LineEndsUnchangedF()
	{
		textLinuxStr =			// has linux line ends
			"\nvoid foo()\n"
			"{\n"
			"    bar()\n"
			"}\n";
		textWindowsStr =		// has windows line ends
			"\r\nvoid foo()\r\n"
			"{\r\n"
			"    bar()\r\n"
			"}\r\n";
		textMacOldStr =			// has macold line ends
			"\rvoid foo()\r"
			"{\r"
			"    bar()\r"
			"}\r";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		pathLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(pathLinux);
		createTestFile(pathLinux, textLinux);
		pathWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(pathWindows);
		createTestFile(pathWindows, textWindows);
		pathMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(pathMacOld);
		createTestFile(pathMacOld, textMacOld);
	}

	~LineEndsUnchangedF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(LineEndsUnchangedF, LineEndWindows)
// test if lineend=windows leaves the file unchanged
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileWindows = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileWindows, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=windows");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	processReturn = g_console->processOptions(argc, argv);
	ASSERT_TRUE(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	EXPECT_EQ(optionsIn.size(), optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathWindows + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		EXPECT_EQ( "\"no file\"", origFileName.c_str());

	delete [] argv;
}

TEST_F(LineEndsUnchangedF, LineEndLinux)
// test if lineend=linux leaves the file unchanged
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileLinux = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileLinux, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=linux");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	processReturn = g_console->processOptions(argc, argv);
	ASSERT_TRUE(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	EXPECT_EQ(optionsIn.size(), optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathLinux + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		EXPECT_EQ( "\"no file\"", origFileName.c_str());

	delete [] argv;
}

TEST_F(LineEndsUnchangedF, LineEndMacOld)
// test if lineend=macold leaves the file unchanged
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileMacOld = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileMacOld, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=macold");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	processReturn = g_console->processOptions(argc, argv);
	ASSERT_TRUE(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	EXPECT_EQ(optionsIn.size(), optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathMacOld + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		EXPECT_EQ( "\"no file\"", origFileName.c_str());

	delete [] argv;
}

//----------------------------------------------------------------------------
// AStyle default line ends
// tests if default line end leaves the file unchanged
//----------------------------------------------------------------------------

struct LineEndsDefaultF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string pathLinux;
	string pathWindows;
	string pathMacOld;

	// build fileNames vector and write the output files
	LineEndsDefaultF()
	{
		textLinuxStr =			// has linux line ends
			"\nvoid foo()\n"
			"{\n"
			"    bar()\n"
			"}\n";
		textWindowsStr =		// has windows line ends
			"\r\nvoid foo()\r\n"
			"{\r\n"
			"    bar()\r\n"
			"}\r\n";
		textMacOldStr =			// has macold line ends
			"\rvoid foo()\r"
			"{\r"
			"    bar()\r"
			"}\r";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		pathLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(pathLinux);
		createTestFile(pathLinux, textLinux);
		pathWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(pathWindows);
		createTestFile(pathWindows, textWindows);
		pathMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(pathMacOld);
		createTestFile(pathMacOld, textMacOld);
	}

	~LineEndsDefaultF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(LineEndsDefaultF, LineEndWindows)
// test if default line end leaves a windows file unchanged
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileWindows = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileWindows, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathWindows + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		EXPECT_EQ( "\"no file\"", origFileName.c_str());
}

TEST_F(LineEndsDefaultF, LineEndLinux)
// test if default line end leaves a linux file unchanged
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileLinux = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileLinux, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathLinux + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		EXPECT_EQ( "\"no file\"", origFileName.c_str());
}

TEST_F(LineEndsDefaultF, LineEndMacOld)
// test if default line end leaves a macold file unchanged
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileMacOld = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileMacOld, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathMacOld + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		EXPECT_EQ( "\"no file\"", origFileName.c_str());
}

//----------------------------------------------------------------------------
// AStyle line ends formatted
// tests if default line ends calls the convertLineEnds() function when needed
//----------------------------------------------------------------------------
struct LineEndsDefaultMixedF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string pathLinux;
	string pathWindows;
	string pathMacOld;

	// build fileNames vector and write the output files
	LineEndsDefaultMixedF()
	{
		textLinuxStr =
			"\r\nvoid foo()\r\n"	// not a linux line end
			"{\n"
			"    bar1()\n"
			"    bar2()\n"
			"}\n";
		textWindowsStr =
			"\rvoid foo()\r"		// not a windows line end
			"{\r\n"
			"    bar1()\r\n"
			"    bar2()\r\n"
			"}\r\n";
		textMacOldStr =
			"\r\nvoid foo()\r\n"	// not a macold line end
			"{\r"
			"    bar1()\r"
			"    bar2()\r"
			"}\r";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		pathLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(pathLinux);
		createTestFile(pathLinux, textLinux);
		pathWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(pathWindows);
		createTestFile(pathWindows, textWindows);
		pathMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(pathMacOld);
		createTestFile(pathMacOld, textMacOld);
	}

	~LineEndsDefaultMixedF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(LineEndsDefaultMixedF, LineEndWindows)
// test if default line ends outputs windows line ends by calling convertLineEnds()
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileWindows = pathWindows.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileWindows, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathWindows + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ("\"no file\"", origFileName.c_str());
	// check that convertLineEnds is called
	EXPECT_TRUE(g_console->getLineEndsMixed());
	// the line ends must be checked manually
//	systemPause("Check Windows Line Ends");
}

TEST_F(LineEndsDefaultMixedF, LineEndLinux)
// test if default line ends outputs linux line ends by calling convertLineEnds()
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileLinux = pathLinux.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileLinux, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathLinux + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ("\"no file\"", origFileName.c_str());
	// check that convertLineEnds is called
	EXPECT_TRUE(g_console->getLineEndsMixed());
	// the line ends must be checked manually
//	systemPause("Check Linux Line Ends");
}

TEST_F(LineEndsDefaultMixedF, LineEndMacOld)
// test if default line ends outputs linux line ends by calling convertLineEnds()
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileMacOld = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileMacOld, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathMacOld + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ("\"no file\"", origFileName.c_str());
	// check that convertLineEnds is called
	EXPECT_TRUE(g_console->getLineEndsMixed());
	// the line ends must be checked manually
//	systemPause("Check MacOld Line Ends");
}

//----------------------------------------------------------------------------
// AStyle line ends formatted
// tests that default line ends does NOT call the convertLineEnds() function when not needed
//----------------------------------------------------------------------------

struct LineEndsDefaultMixedSansF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string pathLinux;
	string pathWindows;
	string pathMacOld;

	// build fileNames vector and write the output files
	LineEndsDefaultMixedSansF()
	{
		textLinuxStr =
			"\nvoid foo()\n"
			"{\n"
			"    bar()\r\n"		// not a linux line end
			"}\n";
		textWindowsStr =
			"\r\nvoid foo()\r\n"
			"{\r\n"
			"    bar()\r"		// not a windows line end
			"}\r\n";
		textMacOldStr =
			"\rvoid foo()\r"
			"{\r"
			"    bar()\r\n"		// not a macold line end
			"}\r";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		pathLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(pathLinux);
		createTestFile(pathLinux, textLinux);
		pathWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(pathWindows);
		createTestFile(pathWindows, textWindows);
		pathMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(pathMacOld);
		createTestFile(pathMacOld, textMacOld);
	}

	~LineEndsDefaultMixedSansF()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_F(LineEndsDefaultMixedSansF, LineEndWindows)
// test if default line ends outputs windows line ends without calling convertLineEnds()
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileWindows = pathWindows.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileWindows, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathWindows + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ("\"no file\"", origFileName.c_str());
	// check that convertLineEnds is NOT called
	EXPECT_FALSE(g_console->getLineEndsMixed());
	// the line ends must be checked manually
//	systemPause("Check Windows Line Ends");
}

TEST_F(LineEndsDefaultMixedSansF, LineEndLinux)
// test if default line ends outputs linux line ends without calling convertLineEnds()
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileLinux = pathLinux.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileLinux, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathLinux + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ("\"no file\"", origFileName.c_str());
	// check that convertLineEnds is NOT called
	EXPECT_FALSE(g_console->getLineEndsMixed());
	// the line ends must be checked manually
//	systemPause("Check Linux Line Ends");
}

TEST_F(LineEndsDefaultMixedSansF, LineEndMacOld)
// test if default line ends outputs linux line ends without calling convertLineEnds()
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	vector<string> fileNameVector;
	string fileMacOld = pathMacOld.substr(getTestDirectory().length());
	int processReturn = buildFileNameVector(fileMacOld, fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles();

	// check for .orig file
	string origFileName = pathMacOld + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		EXPECT_EQ("\"no file\"", origFileName.c_str());
	// check that convertLineEnds is NOT called
	EXPECT_FALSE(g_console->getLineEndsMixed());
	// the line ends must be checked manually
//	systemPause("Check MacOld Line Ends");
}

//----------------------------------------------------------------------------
// AStyle test print options for VISUAL checking - must define ASTYLECON_PRINT
//----------------------------------------------------------------------------
#ifdef ASTYLECON_PRINT
struct PrintF : public ::testing::Test
{
	ASFormatter formatter;
	vector<string> fileNames;
	size_t filesExcluded;

	// build fileNames vector and write the output files
	PrintF() : filesExcluded(0)
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

		// build fileNames vector
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		fileNames.push_back(getTestDirectory() + "/fileFormatted.cpp");
		g_console->standardizePath(fileNames.back());
		createTestFile(fileNames.back(), textFormatted);
		fileNames.push_back(getTestDirectory() + "/fileUnchanged.cpp");
		g_console->standardizePath(fileNames.back());
		createTestFile(fileNames.back(), textUnchanged);
	}

	~PrintF()
	{
		cout << endl;
		deleteConsoleGlobalObject();
	}

	void buildExcludeVector()
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
};

TEST_F(PrintF, DefaultWildcard)
// test print wildcard with no options
{
	assert(g_console != NULL);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "DEFAULT WILDCARD" << endl;

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, DefaultWildcard_Exclude)
// test print wildcard with an exclude
{
	assert(g_console != NULL);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "DEFAULT WILDCARD with exclude" << endl;
	buildExcludeVector();

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, FormattedWildcard)
// test print with "formatted" wildcard
{
	assert(g_console != NULL);
	g_console->setIsFormattedOnly(true);		// test variable

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "FORMATTED WILDCARD" << endl;

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, VerboseWildcard_OptionsFile)
// test print with "verbose" wildcard
{
	assert(g_console != NULL);
	g_console->setIsVerbose(true);		// test variable

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "VERBOSE WILDCARD with options file" << endl;

	// add options file
	g_console->setOptionsFileName(getTestDirectory() + "/astylerc.txt");

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, VerboseFormattedWildcard)
// test print with "verbose" and "formatted" wildcard
{
	assert(g_console != NULL);
	g_console->setIsVerbose(true);			// test variable
	g_console->setIsFormattedOnly(true);		// test variable

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "VERBOSE FORMATTED WILDCARD" << endl;

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, DefaultSingleFile)
// test print single file with no options
{
	assert(g_console != NULL);

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/fileFormatted.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "DEFAULT SINGLE FILE" << endl;

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ((size_t) 1, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, FormattedSingleFile)
// test print with "formatted" single file
{
	assert(g_console != NULL);
	g_console->setIsFormattedOnly(true);		// test variable

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/fileFormatted.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "FORMATTED SINGLE FILE" << endl;

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ((size_t) 1, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, VerboseSingleFile_OptionsFile)
// test print with "verbose" single file
{
	assert(g_console != NULL);
	g_console->setIsVerbose(true);		// test variable

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/fileFormatted.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "VERBOSE SINGLE FILE with options file" << endl;

	// add options file
	g_console->setOptionsFileName(getTestDirectory() + "/astylerc.txt");

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ((size_t) 1, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_F(PrintF, Quiet_AllOptions)
// test print with "quiet" and all other options
{
	assert(g_console != NULL);
	g_console->setIsFormattedOnly(true);
	g_console->setIsVerbose(true);
	g_console->setIsQuiet(true);		// test variable

	// build the fileNameVector
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector);
	ASSERT_TRUE(processReturn == CONTINUE);

	// the results must be checked visually
	cout << "QUIET with all options (including exclude and options file)" << endl;

	// add options and exclude files
	g_console->setOptionsFileName(getTestDirectory() + "/astylerc.txt");
	buildExcludeVector();

	// process entries in the fileNameVector
	g_console->processFiles();
	vector<string> fileName = g_console->getFileName();
	EXPECT_EQ(fileNames.size() - filesExcluded, fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}
#endif	// ASTYLECON_PRINT

// TODO: test waitForRemove function - line 1925
