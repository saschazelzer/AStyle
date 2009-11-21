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

struct testFilePaths
{
	vector<string> fileNames;

	// build fileNames vector and write the output files
	testFilePaths()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();
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

	~testFilePaths()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testFilePaths, getFilePaths1)
// test fileName vector and getFilePaths with *.cpp
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNames.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testFilePaths, getFilePaths2)
// test fileName vector and getFilePaths with *.c??
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.c??");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);	// initialize variables

	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNames.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testFilePaths, getFilePaths3)
// test fileName vector and getFilePaths with getFilePaths*.cpp
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/getFilePaths*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNames.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testFilePaths, getFilePaths4)
// test fileName vector and getFilePaths with *.c*
// * at the end WITH remaining data allows complete coverage of wildcmp function
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.c*");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNames.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testFilePaths, getFilePaths5)
// test fileName vector and getFilePaths with *.cpp*
// * at the end WITHOUT remaining data allows complete coverage of wildcmp function
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp*");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNames.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testFilePaths, getFilePathsError)
// test fileName vector and getFilePaths with bad path
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results
	// do not display error message
	_err = new stringstream;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/AStyleError*");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK(g_console->fileName.size() == 0);

	delete _err;
	_err = &cerr;
}

//----------------------------------------------------------------------------
// AStyle test getFileType() - C_TYPE, JAVA_TYPE, SHARP_TYPE
//----------------------------------------------------------------------------
struct testFileType
{
	vector<string> fileNames;

	// build fileNames vector and write the output files
	testFileType()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"    bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();
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

	~testFileType()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testFileType, fileTypeC)
// test getFileType with *.cpp
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(formatter.getFileType(), C_TYPE);
}

TEST_FIXTURE(testFileType, fileTypeJave)
// test getFileType with *.java
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.java");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(formatter.getFileType(), JAVA_TYPE);
}

TEST_FIXTURE(testFileType, fileTypeSharp)
// test getFileType with *.cs
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cs");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(formatter.getFileType(), SHARP_TYPE);
}

TEST_FIXTURE(testFileType, fileTypeError)
// test getFileType with an invalid type, should return C_TYPE
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.error");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(formatter.getFileType(), C_TYPE);
}

//----------------------------------------------------------------------------
// AStyle test recursive option - getFilePaths(), wildcmp(), and fileName vector
//----------------------------------------------------------------------------

struct testRecursive
{
	vector<string> fileNames;

	// build fileNames vector and write the output files
	testRecursive()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();

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

	~testRecursive()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testRecursive, recursive)
// test recursive option
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results
	g_console->isRecursive = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());
	sort(fileNames.begin(), fileNames.end());
	for (size_t i = 0; i < fileNames.size(); i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testRecursive, recursiveSans)
// test *.cpp WITHOUT recursive
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results
	g_console->isRecursive = false;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

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
	CHECK(fileNames.size() > 0);
	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());
	sort(fileNames.begin(), fileNames.end());
	for (size_t i = 0; i < fileNames.size(); i++)
		CHECK_EQUAL(fileNames[i], g_console->fileName[i]);
}

TEST_FIXTURE(testRecursive, recursiveExclude)
// test recursive option with exclude
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results
	g_console->isRecursive = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

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
	g_console->processFiles(formatter);

	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());
}

TEST_FIXTURE(testRecursive, recursiveExcludeErrors)
// test recursive option with exclude
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results
	g_console->isRecursive = true;

	// capture the error message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// build exclude vector
	// partial match on file
	g_console->updateExcludeVector("ecursive1.cpp");
	// partial match on directory
	g_console->updateExcludeVector("ubdir1a");

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// display error message if not rejected
	string errMsg1 = "Unmatched exclude ecursive1.cpp";
	size_t result1 = msgOut->str().find(errMsg1);
	if (result1 == string::npos)
		CHECK_EQUAL(errMsg1, "\"not found\"");
	string errMsg2 = "Unmatched exclude ubdir1a";
	size_t result2 = msgOut->str().find(errMsg2);
	if (result2 == string::npos)
		CHECK_EQUAL(errMsg2, "\"not found\"");

	delete msgOut;
	_err = &cerr;
}

TEST_FIXTURE(testRecursive, recursiveHiddenFiles)
// test recursive option with hidden files
{
	assert(g_console != NULL);
	g_console->isQuiet = true;		// change this to see results
	g_console->isRecursive = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

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
	g_console->processFiles(formatter);

	// hidden files should not be in g_console vector
	CHECK_EQUAL(fileNames.size(), g_console->fileName.size());

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
// the file output is checked in AStyleTest
//----------------------------------------------------------------------------

struct testLineEndsFormatted
{
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string fileLinux;
	string fileWindows;
	string fileMacOld;

	// build fileNames vector and write the output files
	testLineEndsFormatted()
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
		createConsoleGlobalObject();

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		fileLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(fileLinux);
		createTestFile(fileLinux, textLinux);
		fileWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(fileWindows);
		createTestFile(fileWindows, textWindows);
		fileMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(fileMacOld);
		createTestFile(fileMacOld, textMacOld);
	}

	~testLineEndsFormatted()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testLineEndsFormatted, lineEndWindowsFormatted)
// test if lineend=windows formats the file
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileWindows);
	g_console->standardizePath(g_console->fileNameVector.back());

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=windows");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileWindows + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		CHECK_EQUAL(origFileName.c_str(), "\"no file\"");
}

TEST_FIXTURE(testLineEndsFormatted, lineEndLinuxFormatted)
// test if lineend=linux formats the file
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileLinux);
	g_console->standardizePath(g_console->fileNameVector.back());

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=linux");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileLinux + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		CHECK_EQUAL(origFileName.c_str(), "\"no file\"");
}

TEST_FIXTURE(testLineEndsFormatted, lineEndMacOldFormatted)
// test if lineend=macold formats the file
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileMacOld);
	g_console->standardizePath(g_console->fileNameVector.back());

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=macold");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileMacOld + ".orig";
	struct stat stBuf;
	// display error if file is not present
	if (stat(origFileName.c_str(), &stBuf) == -1)
		CHECK_EQUAL(origFileName.c_str(), "\"no file\"");
}

//----------------------------------------------------------------------------
// AStyle line ends unchanged
// tests if an unchanged line end leaves the file unchanged
// the file output is checked in AStyleTest
//----------------------------------------------------------------------------

struct testLineEndsUnchanged
{
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string fileLinux;
	string fileWindows;
	string fileMacOld;

	// build fileNames vector and write the output files
	testLineEndsUnchanged()
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
		createConsoleGlobalObject();

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		fileLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(fileLinux);
		createTestFile(fileLinux, textLinux);
		fileWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(fileWindows);
		createTestFile(fileWindows, textWindows);
		fileMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(fileMacOld);
		createTestFile(fileMacOld, textMacOld);
	}

	~testLineEndsUnchanged()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testLineEndsUnchanged, lineEndWindowsUnchanged)
// test if lineend=windows leaves the file unchanged
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileWindows);
	g_console->standardizePath(g_console->fileNameVector.back());

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=windows");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileWindows + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		CHECK_EQUAL( "\"no file\"", origFileName.c_str());
}

TEST_FIXTURE(testLineEndsUnchanged, lineEndLinuxUnchanged)
// test if lineend=linux leaves the file unchanged
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileLinux);
	g_console->standardizePath(g_console->fileNameVector.back());

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=linux");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileLinux + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		CHECK_EQUAL( "\"no file\"", origFileName.c_str());
}

TEST_FIXTURE(testLineEndsUnchanged, lineEndMacOldUnchanged)
// test if lineend=macold leaves the file unchanged
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileMacOld);
	g_console->standardizePath(g_console->fileNameVector.back());

	// build argv array of options
	vector<string> optionsIn;
	optionsIn.push_back("--lineend=macold");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileMacOld + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		CHECK_EQUAL( "\"no file\"", origFileName.c_str());
}

//----------------------------------------------------------------------------
// AStyle default line ends
// tests if default line end leaves the file unchanged
// the file output is checked in AStyleTest
//----------------------------------------------------------------------------

struct testLineEndsDefault
{
	vector<string> fileNames;

	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	string fileLinux;
	string fileWindows;
	string fileMacOld;

	// build fileNames vector and write the output files
	testLineEndsDefault()
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
		createConsoleGlobalObject();

		// build text strings
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();

		// create test files
		fileLinux = getTestDirectory() + "/textLinux.cpp";
		g_console->standardizePath(fileLinux);
		createTestFile(fileLinux, textLinux);
		fileWindows = getTestDirectory() + "/textWindows.cpp";
		g_console->standardizePath(fileWindows);
		createTestFile(fileWindows, textWindows);
		fileMacOld = getTestDirectory() + "/textMac.cpp";
		g_console->standardizePath(fileMacOld);
		createTestFile(fileMacOld, textMacOld);
	}

	~testLineEndsDefault()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testLineEndsDefault, lineEndWindowsDefault)
// test if default line end leaves a windows file unchanged
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileWindows);
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileWindows + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		CHECK_EQUAL( "\"no file\"", origFileName.c_str());
}

TEST_FIXTURE(testLineEndsDefault, lineEndLinuxDefault)
// test if default line end leaves a linux file unchanged
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileLinux);
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileLinux + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		CHECK_EQUAL( "\"no file\"", origFileName.c_str());
}

TEST_FIXTURE(testLineEndsDefault, lineEndMacOldDefault)
// test if default line end leaves a macold file unchanged
{
	assert(g_console != NULL);
	g_console->isQuiet = true;

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(fileMacOld);
	g_console->standardizePath(g_console->fileNameVector.back());

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// check for .orig file
	string origFileName = fileMacOld + ".orig";
	struct stat stBuf;
	// display error if file is present
	if (stat(origFileName.c_str(), &stBuf) != -1)
		CHECK_EQUAL( "\"no file\"", origFileName.c_str());
}

//----------------------------------------------------------------------------
// AStyle test print options for VISUAL checking - must define ASTYLECON_PRINT
//----------------------------------------------------------------------------
#ifdef ASTYLECON_PRINT
struct testPrint
{
	vector<string> fileNames;
	size_t filesExcluded;

	// build fileNames vector and write the output files
	testPrint() : filesExcluded(0)
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
		createConsoleGlobalObject();
		fileNames.push_back(getTestDirectory() + "/fileFormatted.cpp");
		g_console->standardizePath(fileNames.back());
		createTestFile(fileNames.back(), textFormatted);
		fileNames.push_back(getTestDirectory() + "/fileUnchanged.cpp");
		g_console->standardizePath(fileNames.back());
		createTestFile(fileNames.back(), textUnchanged);
	}

	~testPrint()
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

TEST_FIXTURE(testPrint, printWildcard)
// test print wildcard with no options
{
	assert(g_console != NULL);

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "DEFAULT WILDCARD" << endl;

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printWildcardExclude)
// test print wildcard with an exclude
{
	assert(g_console != NULL);

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "DEFAULT WILDCARD with exclude" << endl;
	buildExcludeVector();

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printFormattedWildcard)
// test print with "formatted" wildcard
{
	assert(g_console != NULL);
	g_console->isFormattedOnly = true;		// test variable

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "FORMATTED WILDCARD" << endl;

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printVerboseWildcard)
// test print with "verbose" wildcard
{
	assert(g_console != NULL);
	g_console->isVerbose = true;		// test variable

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "VERBOSE WILDCARD with options file" << endl;

	// add options file
	g_console->optionsFileName = getTestDirectory() + "/astylerc.txt";

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printVerboseFormattedWildcard)
// test print with "verbose" and "formatted" wildcard
{
	assert(g_console != NULL);
	g_console->isVerbose = true;			// test variable
	g_console->isFormattedOnly = true;		// test variable

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "VERBOSE FORMATTED WILDCARD" << endl;

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printSingleFile)
// test print single file with no options
{
	assert(g_console != NULL);

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "DEFAULT SINGLE FILE" << endl;

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL((size_t) 1, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printFormattedSingleFile)
// test print with "formatted" single file
{
	assert(g_console != NULL);
	g_console->isFormattedOnly = true;		// test variable

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "FORMATTED SINGLE FILE" << endl;

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL((size_t) 1, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printVerboseSingleFile)
// test print with "verbose" single file
{
	assert(g_console != NULL);
	g_console->isVerbose = true;		// test variable

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/fileFormatted.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "VERBOSE SINGLE FILE with options file" << endl;

	// add options file
	g_console->optionsFileName = getTestDirectory() + "/astylerc.txt";

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL((size_t) 1, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}

TEST_FIXTURE(testPrint, printQuiet)
// test print with "quiet" and all other options
{
	assert(g_console != NULL);
	g_console->isFormattedOnly = true;
	g_console->isVerbose = true;
	g_console->isQuiet = true;			// test variable

	// initialize objects
	ASFormatter formatter;
	g_console->fileNameVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->standardizePath(g_console->fileNameVector.back());

	// the results must be checked visually
	cout << "QUIET with all options (including exclude and options file)" << endl;

	// add options and exclude files
	g_console->optionsFileName = getTestDirectory() + "/astylerc.txt";
	buildExcludeVector();

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	CHECK_EQUAL(fileNames.size() - filesExcluded, g_console->fileName.size());

	// the results must be checked visually
	cout << "END" << endl;
}
#endif	// ASTYLECON_PRINT

// TODO: test waitForRemove function - line 1925
// TODO: check automatic line-end characters IN OTHER TEST MODULE
