// This module tests the non-ascii files and directories on disk.
//
// AStyleTestI18n tests the internationalization component of the ASConsole
// class only. It uses the following source files from AStyleTestCon and
// AStyleTest: AStyleTestCon.h, TersePrinter.h AStyleTestCon_Main.cpp,
// AStyleTest_leakFinder.cpp, and TersePrinter.cpp.

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

// indicates i18n test
extern bool g_isI18nTest;
// for i18n tests in Windows
extern bool g_testedJapanese;
extern bool g_testedGreek;
extern bool g_testedRussian;
extern bool g_testedMultiLanguage;
extern bool g_testedCodepage1252;

//-------------------------------------------------------------------------
// declarations for this module only
//-------------------------------------------------------------------------

namespace astyle
{
extern char g_fileSeparator;
}

string convertToMultiByte(const wstring& wideStr);
string createLocaleDirectory(wstring subDirectory);
bool setGlobalLocale(const string& localeName);
void standardizePath(string& path);

//----------------------------------------------------------------------------
// support functions
//----------------------------------------------------------------------------

string convertToMultiByte(const wstring& wideStr)
// convert wchar_t to a multibyte string using the currently assigned locale
{
	// get length of the output excluding the NULL and validate the parameters
	size_t mbLen = wcstombs(NULL, wideStr.c_str(), 0);
	if (mbLen == string::npos)
		systemAbort("Bad char in wide character string");
	// convert the characters
	char* mbStr = new(nothrow) char[mbLen+1];
	if (mbStr == NULL)
		systemAbort("Bad memory alloc for multi-byte string");
	wcstombs(mbStr, wideStr.c_str(), mbLen+1);
	// return the string
	string returnStr = mbStr;
	delete [] mbStr;
	return returnStr;
}

string createLocaleDirectory(wstring subDirectory)
// create a directory in the language of the current locale
// the locale must be set before calling this function
{
	string subdir = convertToMultiByte(subDirectory);
	string dirpath  = getTestDirectory() + subdir;
	standardizePath(subdir);
	// create directory
	createTestDirectory(dirpath);
	return subdir;
}

bool setGlobalLocale(const string& localeName)
// set the global locale and verify the result
{
	g_isI18nTest = true;	// this is the i18n test module
	char* locName = setlocale(LC_ALL, localeName.c_str());
	if (locName == NULL)
		return false;
	return true;
}

void standardizePath(string& path)
// make sure file separators are correct type (Windows or Linux)
{
	// make sure separators are correct type (Windows or Linux)
	for (size_t i = 0; i < path.length(); i++)
	{
		i = path.find_first_of("/\\", i);
		if (i == string::npos)
			break;
		path[i] = g_fileSeparator;
	}
}

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//----------------------------------------------------------------------------
// AStyle test i18n processing with multi-byte Japanese language
//----------------------------------------------------------------------------

struct JapaneseF : public ::testing::Test
{
	ASFormatter formatter;		// formatter object
	string japanese;			// the locale to test
	bool isValidLocale;			// the locale is set
	vector<string> fileNames;	// filenames written to disk
	// sub directories in multi-byte Japanese
	string subdir1;				// multi-byte sub-directory name
	string subdir1a;			// multi-byte sub-directory name
	string subdir1b;			// multi-byte sub-directory name
	string subdir2;				// multi-byte sub-directory name
	// text out data
	string textOutStr;			// text out source file
	const char* textOut;		// text out source file

	// c'tor - build fileNames vector and write the output files
	JapaneseF()
	{
#ifdef _WIN32
		// The language of the system local should be Japanese.
		// The system default locale is set from the Windows Control Panel,
		//     Region and Language, Administrative, Change system locale...
		// LCID is from http://msdn.microsoft.com/en-us/library/0h88fahh%28VS.85%29.aspx
		// 1041 - Japanese
		// Must compare LCIDs, not names
		LCID lcid = GetSystemDefaultLCID();
		if (lcid != 1041)
		{
			g_testedJapanese = false;
			isValidLocale = false;
			return;
		}
		isValidLocale = setGlobalLocale("japanese");
		if (!isValidLocale)
			return;
#else
		// Linux can use the native UTF-8 locale
		isValidLocale = setGlobalLocale("");
		if (!isValidLocale)
			return;
#endif
		// set textOut variables
		textOutStr =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		textOut = textOutStr.c_str();
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		// Japanese symbols are copied from http://www.alanwood.net/unicode/katakana.html
		// subdir1  = L"/\u30a2\u30a4\u30a6\u30aa";
		// subdir1a = subdir1 + L"/\u30ab\u30ad\u30af";
		// subdir1b = subdir1 + L"/\u30b1\u30b3\u30b5";
		// subdir2  = L"/\u30b9\u30bb\u30bf\u30c1";
		subdir1  = createLocaleDirectory(L"/アイウオ");
		subdir1a = createLocaleDirectory(L"/アイウオ/カキク");
		subdir1b = createLocaleDirectory(L"/アイウオ/ケコサ");
		subdir2  = createLocaleDirectory(L"/スセタチ");
		// create fileNames vector
		string testdir =  getTestDirectory();
		fileNames.push_back(testdir + "/recursive1.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive2.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive3.cpp");
		fileNames.push_back(testdir + subdir1a + "/recursive4.cpp");
		fileNames.push_back(testdir + subdir1a + "/recursive5.cpp");
		fileNames.push_back(testdir + subdir1b + "/recursive6.cpp");
		fileNames.push_back(testdir + subdir1b + "/recursive7.cpp");
		fileNames.push_back(testdir + subdir2  + "/recursive8.cpp");
		fileNames.push_back(testdir + subdir2  + "/recursive9.cpp");
		// write the test files
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textOut);
		}
		// sort test strings for alpha compare
		sort(fileNames.begin(), fileNames.end());
	}	// end c'tor

	~JapaneseF()
	{
		deleteConsoleGlobalObject();
		setGlobalLocale("C");
	}
};

TEST_F(JapaneseF, Recursive1)
// test multi-byte recursive option
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(JapaneseF, Recursive2)
// test multi-byte recursive option with a multi-byte directory in the options
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// erase the entries that are not in the path
	for (int i = 0; i < static_cast<int>(fileNames.size()); i++)
	{
		if (fileNames[i].find("recursive1.cpp") != string::npos
				|| fileNames[i].find("recursive8.cpp") != string::npos
				|| fileNames[i].find("recursive9.cpp") != string::npos)
			fileNames.erase(fileNames.begin() + i--);
	}
	// run the test
	vector<string> astyleOptionsVector;
	// format subdir1 only
	astyleOptionsVector.push_back(getTestDirectory() + subdir1 + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(JapaneseF, Recursive3)
// test multi-byte recursive option with a multi-byte filename and extension
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// write the multi-byte filename and extension
	// filenameJ = L"/\u30c4\u30c6\u30cc\u30cd";
	// fileExt   = L"/\u30db\u30de";
	string fileNameJ = convertToMultiByte(L"/ツテヌネ");
	string fileExtJ  = convertToMultiByte(L".ホマ");
	string testFilePath = getTestDirectory() + subdir1  + fileNameJ + fileExtJ;
	g_console->standardizePath(testFilePath);
	createTestFile(testFilePath, textOut);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*" + fileExtJ);
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(1U, fileName.size());
	EXPECT_EQ(testFilePath, fileName[0]);
}

TEST_F(JapaneseF, RecursiveExclude)
// test multi-byte recursive option with multi-byte excludes
{
	// check valid locale
	if (!isValidLocale)
		return;
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// build the excludeVector
	vector<string> astyleOptionsVector;
	// file
	astyleOptionsVector.push_back("--exclude=recursive1.cpp");
	// directory - subdir1a, 2nd directory
	size_t lastSep = subdir1a.find_last_of("\\/");
	astyleOptionsVector.push_back("--exclude=" + subdir1a.substr(lastSep));
	// sub directory
	astyleOptionsVector.push_back("--exclude=" + subdir1b);
	// full path file
	string filePath9 = getTestDirectory() + subdir2 + "/recursive9.cpp";
	astyleOptionsVector.push_back("--exclude=" + filePath9);
	// erase the excluded entries
	for (int i = 0; i < static_cast<int>(fileNames.size()); i++)
	{
		if (fileNames[i].find("recursive1.cpp") != string::npos
				|| fileNames[i].find("recursive4.cpp") != string::npos
				|| fileNames[i].find("recursive5.cpp") != string::npos
				|| fileNames[i].find("recursive6.cpp") != string::npos
				|| fileNames[i].find("recursive7.cpp") != string::npos
				|| fileNames[i].find("recursive9.cpp") != string::npos)
			fileNames.erase(fileNames.begin() + i--);
	}
	// run the test
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(JapaneseF, RecursiveSuffix)
// test multi-byte recursive option with multi-byte backup suffix
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);			// change this to see results
	g_console->setIsRecursive(true);
	// build the optionsVector
	// L"\u30e9\u30eb\u30f0";
	vector<string> astyleOptionsVector;
	string fileSuffixJ = convertToMultiByte(L".ラルヰ");
	astyleOptionsVector.push_back("--suffix=" + fileSuffixJ);
	// run the test
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the backup file
	struct stat stBuf;
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string backupFile = fileNames[i] + fileSuffixJ;
		int backupFileStat = stat(backupFile.c_str(), &stBuf);
		EXPECT_EQ(0, backupFileStat) << ("Cannot stat backup file: " + backupFile);
	}
}

//----------------------------------------------------------------------------
// AStyle test i18n processing with single-byte Greek language
//----------------------------------------------------------------------------

struct GreekF : public ::testing::Test
{
	ASFormatter formatter;		// formatter object
	string greek;				// the locale to test
	bool isValidLocale;			// the locale is set
	vector<string> fileNames;	// filenames written to disk
	// sub directories in single-byte Greek
	string subdir1;				// single-byte sub-directory name
	string subdir1a;			// single-byte sub-directory name
	string subdir1b;			// single-byte sub-directory name
	string subdir2;				// single-byte sub-directory name
	// text out data
	string textOutStr;			// text out source file
	const char* textOut;		// text out source file

	// c'tor - build fileNames vector and write the output files
	GreekF()
	{
#ifdef _WIN32
		// The language of the system local should be Greek.
		// The system default locale is set from the Windows Control Panel,
		//     Region and Language, Administrative, Change system locale...
		// LCID is from http://msdn.microsoft.com/en-us/library/0h88fahh%28VS.85%29.aspx
		// 1032 - Greek
		// Must compare LCIDs, not names
		LCID lcid = GetSystemDefaultLCID();
		if (lcid != 1032)
		{
			g_testedGreek = false;
			isValidLocale = false;
			return;
		}
		isValidLocale = setGlobalLocale("greek");
		if (!isValidLocale)
			return;
#else
		// Linux can use the native UTF-8 locale
		isValidLocale = setGlobalLocale("");
		if (!isValidLocale)
			return;
#endif
		// set textOut variables
		textOutStr =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		textOut = textOutStr.c_str();
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		// Greek symbols are copied from
		subdir1  = createLocaleDirectory(L"/ΓΔΘΛ");
		subdir1a = createLocaleDirectory(L"/ΓΔΘΛ/αβγλ");
		subdir1b = createLocaleDirectory(L"/ΓΔΘΛ/ξπρσ");
		subdir2  = createLocaleDirectory(L"/ΞΦΨΩ");
		// create fileNames vector
		string testdir =  getTestDirectory();
		fileNames.push_back(testdir + "/recursive1.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive2.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive3.cpp");
		fileNames.push_back(testdir + subdir1a + "/recursive4.cpp");
		fileNames.push_back(testdir + subdir1a + "/recursive5.cpp");
		fileNames.push_back(testdir + subdir1b + "/recursive6.cpp");
		fileNames.push_back(testdir + subdir1b + "/recursive7.cpp");
		fileNames.push_back(testdir + subdir2  + "/recursive8.cpp");
		fileNames.push_back(testdir + subdir2  + "/recursive9.cpp");
		// write the test files
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textOut);
		}
		// sort test strings for alpha compare
		sort(fileNames.begin(), fileNames.end());
	}	// end c'tor

	~GreekF()
	{
		deleteConsoleGlobalObject();
		setGlobalLocale("C");
	}
};

TEST_F(GreekF, Recursive1)
// test single-byte recursive option
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
#ifdef __BORLANDC__
	// The Embarcadero FindNextFile() function in Artistic Style
	// doesn't follow locale sort sequence for Greek.
	sort(fileName.begin(), fileName.end());
#endif
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GreekF, Recursive2)
// test single-byte recursive option with a single-byte directory in the options
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// delete the entries that are not in the path
	for (int i = 0; i < static_cast<int>(fileNames.size()); i++)
	{
		if (fileNames[i].find("recursive1.cpp") != string::npos
				|| fileNames[i].find("recursive8.cpp") != string::npos
				|| fileNames[i].find("recursive9.cpp") != string::npos)
			fileNames.erase(fileNames.begin() + i--);
	}
	// run the test
	vector<string> astyleOptionsVector;
	// format subdir1 only
	astyleOptionsVector.push_back(getTestDirectory() + subdir1 + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GreekF, Recursive3)
// test single-byte recursive option with a single-byte filename and extension
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// write the single-byte filename and extension
	string fileNameR = convertToMultiByte(L"/ΠΖΣΧ");
	string fileExtR  = convertToMultiByte(L".μςφ");
	string testFilePath = getTestDirectory() + subdir1  + fileNameR + fileExtR;
	g_console->standardizePath(testFilePath);
	createTestFile(testFilePath, textOut);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*" + fileExtR);
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(1U, fileName.size());
	EXPECT_EQ(testFilePath, fileName[0]);
}

TEST_F(GreekF, RecursiveExclude)
// test single-byte recursive option with multi-byte excludes
{
	// check valid locale
	if (!isValidLocale)
		return;
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// build the excludeVector
	vector<string> astyleOptionsVector;
	// file
	astyleOptionsVector.push_back("--exclude=recursive1.cpp");
	// directory - subdir1a, 2nd directory
	size_t lastSep = subdir1a.find_last_of("\\/");
	astyleOptionsVector.push_back("--exclude=" + subdir1a.substr(lastSep));
	// full path directory
	astyleOptionsVector.push_back("--exclude=" + subdir1b);
	// full path file
	string filePath9 = getTestDirectory() + subdir2 + "/recursive9.cpp";
	astyleOptionsVector.push_back("--exclude=" + filePath9);
	// delete the excluded entries
	for (int i = 0; i < static_cast<int>(fileNames.size()); i++)
	{
		if (fileNames[i].find("recursive1.cpp") != string::npos
				|| fileNames[i].find("recursive4.cpp") != string::npos
				|| fileNames[i].find("recursive5.cpp") != string::npos
				|| fileNames[i].find("recursive6.cpp") != string::npos
				|| fileNames[i].find("recursive7.cpp") != string::npos
				|| fileNames[i].find("recursive9.cpp") != string::npos)
			fileNames.erase(fileNames.begin() + i--);
	}
	// run the test
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
#ifdef __BORLANDC__
	// The Embarcadero FindNextFile() function in Artistic Style
	// doesn't follow locale sort sequence for Greek.
	sort(fileName.begin(), fileName.end());
#endif
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(GreekF, RecursiveSuffix)
// test single-byte recursive option with single-byte backup suffix
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);			// change this to see results
	g_console->setIsRecursive(true);
	// build the optionsVector
	vector<string> astyleOptionsVector;
	string fileSuffixJ = convertToMultiByte(L".μθτη");
	astyleOptionsVector.push_back("--suffix=" + fileSuffixJ);
	// run the test
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the backup file
	struct stat stBuf;
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string backupFile = fileNames[i] + fileSuffixJ;
		int backupFileStat = stat(backupFile.c_str(), &stBuf);
		EXPECT_EQ(0, backupFileStat) << ("Cannot stat backup file: " + backupFile);
	}
}

//----------------------------------------------------------------------------
// AStyle test i18n processing with single-byte Russian language
//----------------------------------------------------------------------------

struct RussianF : public ::testing::Test
{
	ASFormatter formatter;		// formatter object
	string russian;				// the locale to test
	bool isValidLocale;			// the locale is set
	vector<string> fileNames;	// filenames written to disk
	// sub directories in single-byte Russian
	string subdir1;				// single-byte sub-directory name
	string subdir1a;			// single-byte sub-directory name
	string subdir1b;			// single-byte sub-directory name
	string subdir2;				// single-byte sub-directory name
	// text out data
	string textOutStr;			// text out source file
	const char* textOut;		// text out source file

	// c'tor - build fileNames vector and write the output files
	RussianF()
	{
#ifdef _WIN32
		// The language of the system local should be Russian.
		// The system default locale is set from the Windows Control Panel,
		//     Region and Language, Administrative, Change system locale...
		// LCID is from http://msdn.microsoft.com/en-us/library/0h88fahh%28VS.85%29.aspx
		// 1049 - Russian
		// Must compare LCIDs, not names
		LCID lcid = GetSystemDefaultLCID();
		if (lcid != 1049)
		{
			g_testedRussian = false;
			isValidLocale = false;
			return;
		}
		isValidLocale = setGlobalLocale("russian");
		if (!isValidLocale)
			return;
#else
		// Linux can use the native UTF-8 locale
		isValidLocale = setGlobalLocale("");
		if (!isValidLocale)
			return;
#endif
		// set textOut variables
		textOutStr =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		textOut = textOutStr.c_str();
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		// Russian symbols are copied from http://en.wikipedia.org/wiki/Russian_alphabet
		subdir1  = createLocaleDirectory(L"/АБВГ");
		subdir1a = createLocaleDirectory(L"/АБВГ/ДЕЁЖ");
		subdir1b = createLocaleDirectory(L"/АБВГ/ЗИЙК");
		subdir2  = createLocaleDirectory(L"/ЛПФЦ");
		// create fileNames vector
		string testdir =  getTestDirectory();
		fileNames.push_back(testdir + "/recursive1.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive2.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive3.cpp");
		fileNames.push_back(testdir + subdir1a + "/recursive4.cpp");
		fileNames.push_back(testdir + subdir1a + "/recursive5.cpp");
		fileNames.push_back(testdir + subdir1b + "/recursive6.cpp");
		fileNames.push_back(testdir + subdir1b + "/recursive7.cpp");
		fileNames.push_back(testdir + subdir2  + "/recursive8.cpp");
		fileNames.push_back(testdir + subdir2  + "/recursive9.cpp");
		// write the test files
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textOut);
		}
		// sort test strings for alpha compare
		sort(fileNames.begin(), fileNames.end());
	}	// end c'tor

	~RussianF()
	{
		deleteConsoleGlobalObject();
		setGlobalLocale("C");
	}
};

TEST_F(RussianF, Recursive1)
// test single-byte recursive option
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(RussianF, Recursive2)
// test single-byte recursive option with a single-byte directory in the options
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// delete the entries that are not in the path
	for (int i = 0; i < static_cast<int>(fileNames.size()); i++)
	{
		if (fileNames[i].find("recursive1.cpp") != string::npos
				|| fileNames[i].find("recursive8.cpp") != string::npos
				|| fileNames[i].find("recursive9.cpp") != string::npos)
			fileNames.erase(fileNames.begin() + i--);
	}
	// run the test
	vector<string> astyleOptionsVector;
	// format subdir1 only
	astyleOptionsVector.push_back(getTestDirectory() + subdir1 + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(RussianF, Recursive3)
// test single-byte recursive option with a single-byte filename and extension
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// write the single-byte filename and extension
	string fileNameR = convertToMultiByte(L"/ЧШЪЫ");
	string fileExtR  = convertToMultiByte(L".ЭЮЯ");
	string testFilePath = getTestDirectory() + subdir1  + fileNameR + fileExtR;
	g_console->standardizePath(testFilePath);
	createTestFile(testFilePath, textOut);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*" + fileExtR);
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(1U, fileName.size());
	EXPECT_EQ(testFilePath, fileName[0]);
}

TEST_F(RussianF, RecursiveExclude)
// test single-byte recursive option with multi-byte excludes
{
	// check valid locale
	if (!isValidLocale)
		return;
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// build the excludeVector
	vector<string> astyleOptionsVector;
	// file
	astyleOptionsVector.push_back("--exclude=recursive1.cpp");
	// directory - subdir1a, 2nd directory
	size_t lastSep = subdir1a.find_last_of("\\/");
	astyleOptionsVector.push_back("--exclude=" + subdir1a.substr(lastSep));
	// full path directory
	astyleOptionsVector.push_back("--exclude=" + subdir1b);
	// full path file
	string filePath9 = getTestDirectory() + subdir2 + "/recursive9.cpp";
	astyleOptionsVector.push_back("--exclude=" + filePath9);
	// delete the excluded entries
	for (int i = 0; i < static_cast<int>(fileNames.size()); i++)
	{
		if (fileNames[i].find("recursive1.cpp") != string::npos
				|| fileNames[i].find("recursive4.cpp") != string::npos
				|| fileNames[i].find("recursive5.cpp") != string::npos
				|| fileNames[i].find("recursive6.cpp") != string::npos
				|| fileNames[i].find("recursive7.cpp") != string::npos
				|| fileNames[i].find("recursive9.cpp") != string::npos)
			fileNames.erase(fileNames.begin() + i--);
	}
	// run the test
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

TEST_F(RussianF, RecursiveSuffix)
// test single-byte recursive option with single-byte backup suffix
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);			// change this to see results
	g_console->setIsRecursive(true);
	// build the optionsVector
	vector<string> astyleOptionsVector;
	string fileSuffixJ = convertToMultiByte(L".фыюя");
	astyleOptionsVector.push_back("--suffix=" + fileSuffixJ);
	// run the test
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the backup file
	struct stat stBuf;
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string backupFile = fileNames[i] + fileSuffixJ;
		int backupFileStat = stat(backupFile.c_str(), &stBuf);
		EXPECT_EQ(0, backupFileStat) << ("Cannot stat backup file: " + backupFile);
	}
}

//----------------------------------------------------------------------------
// AStyle test i18n processing with two languages, Japanese and Russian
// ok for Linux but not for Windows
//----------------------------------------------------------------------------

struct MultiLanguageF : public ::testing::Test
{
	ASFormatter formatter;		// formatter object
	bool isValidLocale;			// the locale is set
	vector<string> fileNames;	// filenames written to disk
	// text out data
	string textOutStr;			// text out source file
	const char* textOut;		// text out source file

	// c'tor - build fileNames vector and write the output files
	MultiLanguageF()
	{
#ifdef _WIN32
		// Windows cannot do multi language.
		// LCID is from http://msdn.microsoft.com/en-us/library/0h88fahh%28VS.85%29.aspx
		LCID lcid = GetSystemDefaultLCID();
		if (lcid != 9999)		// will not compare true
		{
			g_testedMultiLanguage = false;
			isValidLocale = false;
			return;
		}
#endif
		// Linux can use the native UTF-8 locale
		isValidLocale = setGlobalLocale("");
		if (!isValidLocale)
			return;
		// set textOut variables
		textOutStr =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		textOut = textOutStr.c_str();
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		// Japanese symbols are copied from http://www.alanwood.net/unicode/katakana.html
		// subdir1  = L"/\u30a2\u30a4\u30a6\u30aa";
		string subdir1 = createLocaleDirectory(L"/アイウオ");
		// create fileNames vector
		string testdir =  getTestDirectory();
		fileNames.push_back(testdir + "/recursive1.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive2.cpp");
		fileNames.push_back(testdir + subdir1  + "/recursive3.cpp");
		// write the Japanese test files
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textOut);
		}
		// create a directory and files in Russian
		// Russian symbols are copied from http://en.wikipedia.org/wiki/Russian_alphabet
		wstring subdir2 = L"\\ЗИФЫЫЯ";
		string russianPath = getTestDirectory() + convertToMultiByte(subdir2);
		g_console->standardizePath(russianPath);
		createTestDirectory(russianPath);
		// files are created for Linux only
		fileNames.push_back(russianPath  + "/recursive4.cpp");
		createTestFile(fileNames.back(), textOut);
		fileNames.push_back(russianPath  + "/recursive5.cpp");
		createTestFile(fileNames.back(), textOut);
		// sort test strings for alpha compare
		sort(fileNames.begin(), fileNames.end());
	}	// end c'tor

	~MultiLanguageF()
	{
		deleteConsoleGlobalObject();
		setGlobalLocale("C");
	}
};

TEST_F(MultiLanguageF, Recursive1)
// test multi-language recursive option
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

//----------------------------------------------------------------------------
// AStyle test i18n processing with codepage 1252
// Coddepage 1252 contains Danish, Dutch, English, Finnish, French, German,
// Icelandic, Italian, Norwegian, Portuguese, Spanish, Swedish
//----------------------------------------------------------------------------

struct Codepage1252F : public ::testing::Test
{
	ASFormatter formatter;		// formatter object
	bool isValidLocale;			// the locale is set
	vector<string> fileNames;	// filenames written to disk
	// text out data
	string textOutStr;			// text out source file
	const char* textOut;		// text out source file

	// c'tor - build fileNames vector and write the output files
	Codepage1252F()
	{
#ifdef _WIN32
		// Windows must check for codepage 1252.
		// get buffer for codepage
		int bufSize = GetLocaleInfo(LOCALE_SYSTEM_DEFAULT, LOCALE_IDEFAULTANSICODEPAGE,
									NULL, 0);
		char* value = new(nothrow) char[bufSize];
		if (value == NULL)
			systemAbort("Bad memory alloc for GetLocaleInfo in Codepage1252F");
		// get codepage
		GetLocaleInfo(LOCALE_SYSTEM_DEFAULT, LOCALE_IDEFAULTANSICODEPAGE,
					  value, sizeof(value) / sizeof(char));
		int codepage = atoi(value);
		delete [] value;
		if (codepage != 1252)
		{
			g_testedCodepage1252 = false;
			isValidLocale = false;
			return;
		}
#endif
		// Linux can use the UTF-8 locale for all languages
		isValidLocale = setGlobalLocale("");
		if (!isValidLocale)
			return;
		// set textOut variables
		textOutStr =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";
		textOut = textOutStr.c_str();
		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject(formatter);
		// create fileNames vector
		// create a directory and files in English
		// German symbols are the same as English
		string englishPath = getTestDirectory() + "/english";
		createTestDirectory(englishPath);
		fileNames.push_back(englishPath + "/english1.cpp");
		// create a directory and files in French
		// French symbols are copied from http://french.typeit.org/
		string frenchPath = getTestDirectory() + "/french ùûüÿàâçéèêëïîôœ";
		createTestDirectory(frenchPath);
		fileNames.push_back(frenchPath + "/french1.cpp");
		// create a directory and files in Spanish
		// Spanish symbols are copied from http://www.studyspanish.com/pronunciation/alphabet.htm
		string spanishPath = getTestDirectory() + "/spanish Ññ";
		createTestDirectory(spanishPath);
		fileNames.push_back(spanishPath + "/spanish1.cpp");
		// create a directory and files in Danish
		// Spanish symbols are copied from http://users.cybercity.dk/~nmb3879/tree.html
		string danishPath = getTestDirectory() + "/danish æøå";
		createTestDirectory(danishPath);
		fileNames.push_back(danishPath + "/danish1.cpp");
		// create a directory and files in Sweedish
		// Sweedish symbols are copied from http://www.omniglot.com/writing/swedish.htm
		string sweedishPath = getTestDirectory() + "/sweedish åäö";
		createTestDirectory(sweedishPath);
		fileNames.push_back(sweedishPath + "/sweedish1.cpp");
		// create a directory and files in Icelandic
		// Icelandic symbols are copied from http://www.omniglot.com/writing/icelandic.htm
		string icelandicPath = getTestDirectory() + "/icelandic ðéóúæö";
		createTestDirectory(icelandicPath);
		fileNames.push_back(icelandicPath + "/icelandic1.cpp");
		// write the test files
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textOut);
		}
		// sort test strings for alpha compare
		sort(fileNames.begin(), fileNames.end());
	}	// end c'tor

	~Codepage1252F()
	{
		deleteConsoleGlobalObject();
		setGlobalLocale("C");
	}
};

TEST_F(Codepage1252F, Recursive1)
// test codepage 1252 recursive option
{
	// check valid locale
	if (!isValidLocale)
		return;
	// set processing variables
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setIsRecursive(true);
	// run the test
	vector<string> astyleOptionsVector;
	astyleOptionsVector.push_back(getTestDirectory() + "/*.cpp");
	g_console->processOptions(astyleOptionsVector);
	g_console->processFiles();
	// check the fileName vector
	vector<string> fileName = g_console->getFileName();
	ASSERT_EQ(fileNames.size(), fileName.size());
	for (size_t i = 0; i < fileNames.size(); i++)
		EXPECT_EQ(fileNames[i], fileName[i]);
}

//----------------------------------------------------------------------------
// AStyle test i18n other options
//----------------------------------------------------------------------------

#ifdef _WIN32
TEST(Other, GetNumberFormat)
// WINDOWS test the getNumberFormat method in ASConsole.
{
	// WINDOWS make sure the C++ locale is not set.
	locale::global(locale("C"));
	// WINDOWS substantiate objects
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// WINDOWS variables
	string result;
	string number;
	// WINDOWS English locale 0133 - for other formats change the user locale
	result = "123,456,789";
	number = g_console->getNumberFormat(123456789, 1033);
	EXPECT_EQ(result, number) << "english locale (assumes default formatting)";
	// WINDOWS German locale 1031 - for other formats change the user locale
	result = "123.456.789";
	number = g_console->getNumberFormat(123456789, 1031);
	EXPECT_EQ(result, number) << "german locale (assumes default formatting)";
	// WINDOWS French locale 1036 - for other formats change the user locale
	result = "123 456 789";
	result[3] = result[7] = static_cast<int>(-96);		// non-breaking space
	number = g_console->getNumberFormat(123456789, 1036);
	EXPECT_EQ(result, number) << "french locale (assumes default formatting)";
	// WINDOWS French Swiss locale 4018 - for other formats change the user locale
	result = "123'456'789";
	number = g_console->getNumberFormat(123456789, 4108);
	EXPECT_EQ(result, number) << "french swiss locale (assumes default formatting)";
	deleteConsoleGlobalObject();
}

#else

TEST(Other, GetNumberFormat)
// LINUX test the getNumberFormat method in ASConsole.
{
	// LINUX make sure the C++ locale is not set.
	locale::global(locale("C"));
	// LINUX substantiate objects
	ASFormatter formatter;
	createConsoleGlobalObject(formatter);
	// for testing --------------------------------------------------
//	setlocale(LC_ALL, "english");
//	struct lconv* lcInfo;
//	lcInfo = localeconv();
//	printf("Decimal point: %s\n", lcInfo->decimal_point);
//	printf("Thousands separator: %s\n", lcInfo->thousands_sep);
//	printf("Grouping string: ");
//	for (size_t i = 0; i < 3; i++)
//		printf("%d-", lcInfo->grouping[i]);
//	cout << endl;
//	printf ("Local Currency Symbol: %s\n",lcInfo->currency_symbol);
//	printf ("International Currency Symbol: %s\n",lcInfo->int_curr_symbol);
	// --------------------------------------------------------------
	// LINUX variables
	const char* grouping;
	const char* separator;
	string result;
	string number;
	// LINUX group 3 (odd) with comma
	grouping  = "\3";
	separator = ",";
	result = "1,234,567,890";
	number = g_console->getNumberFormat(1234567890, grouping, separator);
	EXPECT_EQ(result, number) << "group 3 (odd) with comma";
	// LINUX group 3 (even) with dot
	grouping  = "\3";
	separator = ".";
	result = "123.456.789";
	number = g_console->getNumberFormat(123456789, grouping, separator);
	EXPECT_EQ(result, number) << "group 3 (even) with dot";
	// LINUX group 3,2 (odd) with space
	grouping  = "\3\2";
	separator = " ";
	result = "1 23 45 67 890";
	number = g_console->getNumberFormat(1234567890, grouping, separator);
	EXPECT_EQ(result, number) << "group 3,2 (odd) with space";
	// LINUX group 3,2 (even) with quote
	grouping  = "\3\2";
	separator = "'";
	result = "12'34'56'789";
	number = g_console->getNumberFormat(123456789, grouping, separator);
	EXPECT_EQ(result, number) << "group 3,2 (even) with quote";
	// LINUX group 3,CHAR_MAX
	grouping  = "\3\127";
	separator = ",";
	result = "123456,789";
	number = g_console->getNumberFormat(123456789, grouping, separator);
	EXPECT_EQ(result, number) << "group 3,CHAR_MAX";
	// LINUX no grouping
	grouping  = "";
	separator = ".";
	result = "123456789";
	number = g_console->getNumberFormat(123456789, grouping, separator);
	EXPECT_EQ(result, number) << "no grouping";
	// LINUX format zero
	grouping  = "3";
	separator = ".";
	result = "0";
	number = g_console->getNumberFormat(0, grouping, separator);
	EXPECT_EQ(result, number) << "format zero";
	// LINUX English locale
	bool enOk = setGlobalLocale("en_US.UTF-8");
	ASSERT_TRUE(enOk) << "Cannot set English locale";
	result = "123,456,789";
	number = g_console->getNumberFormat(123456789);
	EXPECT_EQ(result, number) << "english locale (assumes default formatting)";
	// LINUX French locale
	bool frOk = setGlobalLocale("fr_FR.UTF-8");
	ASSERT_TRUE(frOk) << "Cannot set French locale";
	result = "123 456 789";
	number = g_console->getNumberFormat(123456789);
	EXPECT_EQ(result, number) << "french locale (assumes default formatting)";
	// LINUX German locale
	bool deOk = setGlobalLocale("de_DE.UTF-8");
	ASSERT_TRUE(deOk) << "Cannot set German locale";
	result = "123.456.789";
	number = g_console->getNumberFormat(123456789);
	EXPECT_EQ(result, number) << "german locale (assumes default formatting)";
	// LINUX French Swiss locale
	// Linux currently does not have a Swiss locale
	deleteConsoleGlobalObject();
}

#endif	// _WIN32

TEST(Other, LanguageStrings)
// WINDOWS test the language strings for a compiler
// the language strings are from http://msdn.microsoft.com/en-us/library/39cwe7zf.aspx
// do NOT use the short language strings for Embarcadero
// do NOT use the language strings other than the ones indicated for Embarcadero
{
	// Linux uses different names and will not have all these locales
#ifdef _WIN32
	const char* language[] =
	{
		"chinese",
		"chinese-simplified",
		"chinese-traditional",
		"czech",
		"danish",
		"dutch",
		"belgian",
		"english",
		"english-aus",          // don't use australian
		"english-can",          // don't use canadian
		"english-nz",
		"english-uk",
		"english-us",			// don't use anything else
		"finnish",
		"french",
		"french-belgian",
		"french-canadian",
		"french-swiss",
		"german",
		"german-austrian",
		"german-swiss",          // don't use swiss
		"greek",
		"hungarian",
		"icelandic",
		"italian",
		"italian-swiss",
		"japanese",
		"korean",
		"norwegian",
		"norwegian-bokmal",
		"norwegian-nynorsk",
		"polish",
		"portuguese",
		"portuguese-brazilian",
		"russian",
		"slovak",
		"spanish",
		"spanish-mexican",
		"spanish-modern",
		"swedish",
		"turkish",
	};
	// WINDOWS test language strings
	size_t langSize = sizeof(language) / sizeof(language[0]);
	for (size_t i = 0; i < langSize; i++)
	{
		bool ok = setGlobalLocale(language[i]);
		EXPECT_TRUE(ok) << "Unsupported language: " << language[i];
#ifdef __BORLANDC__
		// Embarcadero 6.20 fails this test for Chinese
		if (ok && strncmp(language[i], "chinese", 7) == 0)
			EXPECT_FALSE(ok) << "EMBARCADERO NOW SUPPORTS: " << language[i];
#endif	// __BORLANDC__
	}
#endif	// WIN32
}

TEST(Other, SetCLocale)
// test setting the C program locale when the C++ global locale is set
// NOTE: MinGW 4.5 fails this test
// NOTE: AStyle uses the C locale functions (setlocale) instead of C++
{
	// set the C locale to the classic locale
	char* localeC = setlocale(LC_ALL, "C");
	if (localeC == NULL)
		FAIL() << "Bad return from setlocale";
	ASSERT_STREQ("C", setlocale(LC_ALL, NULL)) << "Failed to set C locale";
	// set the C++ locale to the native locale
	locale::global(locale(""));
	// the C++ locale should not be the classic locale
	string localeName = locale().name();
	ASSERT_NE("C", localeName) << "This compiler does not support C++ locales";
#ifndef __BORLANDC__
	// Embarcadero is OK, just the display sequence is different
	// the C++ local should also set the C locale
	EXPECT_EQ(locale().name(), setlocale(LC_ALL, NULL));
#endif
	// Force an error if MinGW now supports C++ locales.
	// Does it support wide character streams also?
	// If it does, conversion to Unicode may be possible.
#ifdef __MINGW32__
	FAIL() << "MINGW NOW SUPPORTS C++ LOCALES";
#endif
}

TEST(Other, CppImbue)
// is imbue() supported by this compiler
// NOTE: MinGW 4.5 fails this test
// NOTE: Embarcadero 6.20 fails this test
{
	locale::global(locale("C"));
	// test the formatting of "cout" for numbers
	// a stringstream is tested instead of the "cout" ostream
	stringstream test;
	try
	{
		test.imbue(locale(""));
	}
	catch (exception)
	{
		FAIL() << "Cannot find native locale";
	}
	test << 123456;
	string testNumber = test.str();
	// is the number unformatted
	EXPECT_NE("123456", testNumber) << "This compiler does not support imbue()";
}

//----------------------------------------------------------------------------

}  // namespace
