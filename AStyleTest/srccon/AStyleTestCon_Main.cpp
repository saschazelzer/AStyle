//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define min(a, b)  (((a) < (b)) ? (a) : (b))	// as defined in windows.h
#endif

#include "AStyleTestCon.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// To add a test, simply put the following code in the a .cpp file of your choice:
//
// =================================
// Simple Test
// =================================
//
//  TEST(YourTestName)
//  {
//  }
//
// The TEST macro contains enough machinery to turn this slightly odd-looking syntax into legal C++,
// and automatically register the test in a global list.
// This test list forms the basis of what is executed by RunAllTests().
//
// If you want to re-use a set of test data for more than one test, or provide setup/teardown for
// tests, you can use the TEST_FIXTURE macro instead. The macro requires that you pass it a class
// name that it will instantiate, so any setup and teardown code should be in its constructor and
// destructor.
//
//  struct SomeFixture
//  {
//    SomeFixture() { /* some setup */ }
//    ~SomeFixture() { /* some teardown */ }
//
//    int testData;
//  };
//
//  TEST_FIXTURE(SomeFixture, YourTestName)
//  {
//    int temp = testData;
//  }
//
// =================================
// Test Suites
// =================================
//
// Tests can be grouped into suites, using the SUITE macro. A suite serves as a namespace for test names,
// so that the same test name can be used in two difference contexts.
//
//  SUITE(YourSuiteName)
//  {
//    TEST(YourTestName)
//    {
//    }
//
//    TEST(YourOtherTestName)
//    {
//    }
//  }
//
// This will place the tests into a C++ namespace called YourSuiteName, and make the suite name
// available to UnitTest++.
// RunAllTests() can be called for a specific suite name, so you can use this to build named
// groups of tests to be run together.
// Note how members of the fixture are used as if they are a part of the test, since the
// macro-generated test class derives from the provided fixture class.
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int /*argc*/, char** /*argv*/)
// run all tests
{
	int retval = UnitTest::RunAllTests();
//	system("pause");		// sometimes needed for debug
	return retval;
}

//----------------------------------------------------------------------------
// support functions
//----------------------------------------------------------------------------

char** buildArgv(const vector<string>& argIn)
// build an array of pointers to be used as argv variable in function calls
// argc will equal (argIn.size() + 1)
{
	// build argv array of pointers for input
	int argc = argIn.size() + 1;

	char** argv = new char* [sizeof(char*) * argc];
	argv[0] = (char*)"AStyleTestCon.exe";	// first value is the program name
	if (argIn.size() > 0)
		for (int i = 1; i < argc; i++)		// next are the options
			argv[i] = const_cast<char*>(argIn[i-1].c_str());
//	for (int i = 0; i < argc; i++)
//		cout << argv[i] << endl;
	return argv;
}

//bool changeCurrentDirectory(string path)
//// change the current working directory
//{
//#ifdef _WIN32
////	LPCTSTR lpPathName = path.c_str();
//	BOOL directoryChanged = SetCurrentDirectory(path.c_str());
//#else
//	bool directoryChanged = true;
//	if (chdir(path.c_str()) == -1)
//		directoryChanged = false;
//#endif
//	if (!directoryChanged)
//	{
//		systemPause("cannot change directory: " + path);
//		return false;
//	}
//	return true;
//}

void createConsoleGlobalObject()
// creates the g_console object
{
	if (g_console)
	{
		systemPause("global object not deleted");
		deleteConsoleGlobalObject();
	}
	g_console = new ASConsole;
}

void deleteConsoleGlobalObject()
// deletes the g_console object
{
	delete g_console;
	g_console = NULL;
	// check global error display
	if (_err != &cerr)
		systemPause("_err ostream not replaced");
	_err = &cerr;
}

string getCurrentDirectory()
// get the current working directory
{
	bool gotDirectory = true;
	string currentDirectory;
#ifdef _WIN32
	char currdir[MAX_PATH];
	currdir[0] = '\0';
	if (GetCurrentDirectory(sizeof(currdir), currdir))
		currentDirectory = currdir;
	else
		gotDirectory = false;
	
#else
	char *currdir = getenv("PWD");
	if (currdir != NULL)
		currentDirectory = currdir;
	else
		gotDirectory = false;
#endif
	if (!gotDirectory)
		systemPause("cannot get current directory");
	return currentDirectory;
}

//string getFileSeparator()
//// get the current working directory
//{
//#ifdef _WIN32
//	string separator = "\\";
//#else
//	string separator = "/";
//#endif
//	return separator;
//}

//size_t min(size_t a, size_t b)
//// returns the minimum of two values
//{
//	return (a < b ? a : b);
//}

void removeOptionsFile(const string& optionsFileName)
// remove a test options file
{
	errno = 0;
	remove(optionsFileName.c_str());
	if (errno)
		systemPause("cannot remove options test file: " + optionsFileName);
}

void systemPause(const string& message)
// accept keyboadr input to continue
// assures a console messageis noticed
{
	cout << message << endl;
#ifdef _WIN32
	system("pause");
#else
	cout << "Press ENTER to continue." << endl;
	system("read x");
#endif
}

bool writeOptionsFile(const char* fileIn, const string& optionsFileName)
// write a test options file
{
	struct stat statbuf;
	errno = 0;

	// check for pre-existing file
	if (stat(optionsFileName.c_str(), &statbuf) != -1)
	{
		systemPause("options test file already exists: " + optionsFileName);
		return false;
	}

	// write the file
	ofstream fileOut(optionsFileName.c_str(), ios::binary);
	if (!fileOut)
	{
		systemPause("cannot open options test file: " + optionsFileName);
		return false;
	}
	fileOut << fileIn;
	fileOut.close();
	return true;
}
