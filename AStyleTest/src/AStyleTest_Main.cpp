//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Memory Leak Test
// uses Memory(-Leak) and Exception Trace from
// http://www.codeproject.com/KB/applications/leakfinder.aspx
//
// instantiate leak-finder
#if defined(LEAK_FINDER) && defined(_DEBUG) && defined(_MSC_VER)
// instantiate leak-finder:
#define INIT_LEAK_FINDER
// additional, use the XML-Output-File to analyse with "MemLeakAnalyse.exe"
// #define XML_LEAK_FINDER
#pragma warning(disable: 4100)  // unreferenced formal parameter from leakfinder.h
#include "leakfinder.h"
#endif
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

// global variables
int errorHandler2Calls;

// run all tests
int main(int /*argc*/, char** /*argv*/)
{
	int retval = UnitTest::RunAllTests();
//	system("pause");		// sometimes needed for debug
	return retval;
}

//----------------------------------------------------------------------------
// AStyleMain callback functions
//----------------------------------------------------------------------------

// Error handler for the Artistic Style formatter
// Pause so the error will be noticed
// Linux calls "sh -c", not bash
void  STDCALL errorHandler(int errorNumber, char* errorMessage)
{
	cout << "AStyle error " << errorNumber << ".\n" << errorMessage << endl;
#ifdef _WIN32
	system("pause");
#else
	cout << "Press ENTER to continue." << endl;
	system("read x");
#endif
}

// Error handler 2 just adds to an error count
// It is used to test error conditions
void  STDCALL errorHandler2(int, char*)
{
	errorHandler2Calls++;
}

// return errorHandler2Calls global variable
int getErrorHandler2Calls()
{
	return errorHandler2Calls;
}

// Allocate memory for the Artistic Style formatter
char* STDCALL memoryAlloc(unsigned long memoryNeeded)
{
	// error condition is checked after return from AStyleMain
	// UnitTest++ will catch an allocation error
	char* buffer = new(nothrow) char [memoryNeeded];
	return buffer;
}
