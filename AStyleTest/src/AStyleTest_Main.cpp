//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "gtest/gtest.h"
#include "TersePrinter.h"
#include "AStyleTest.h"

//----------------------------------------------------------------------------
// global variables
//----------------------------------------------------------------------------

int errorHandler2Calls;

//----------------------------------------------------------------------------
// main function
//----------------------------------------------------------------------------

int main(int argc, char** argv)
{
	// parse command line BEFORE InitGoogleTest
	bool useTersePrinter = false;
	bool useColor = true;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--terse_printer") == 0 )
			useTersePrinter = true;
		else if (strcmp(argv[i], "--gtest_color=no") == 0 )
			useColor = false;
	}
	// do this after parsing the command line but before changing printer
	testing::InitGoogleTest(&argc, argv);
	// change to TersePrinter
	if (useTersePrinter)
	{
		UnitTest& unit_test = *UnitTest::GetInstance();
		TestEventListeners& listeners = unit_test.listeners();
		delete listeners.Release(listeners.default_result_printer());
		listeners.Append(new TersePrinter(useColor));
	}
	// run the tests
	int retval = RUN_ALL_TESTS();
	// Verify that all tests were run. This can occur if a source file
	// is missing from the project. The UnitTest reflection API in
	// example 9 will not work here because of user modifications.
	// Change the following value to the number of tests (within 10).
	if (useTersePrinter)
//		TersePrinter::PrintTestTotals(1325, __FILE__, __LINE__);
		TersePrinter::PrintTestTotals(1373, __FILE__, __LINE__);
#ifdef __WIN32
	printf("%c", '\n');
#endif
//	system("pause");		// sometimes needed for debug
	return retval;
}

//----------------------------------------------------------------------------
// AStyleMain callback functions
//----------------------------------------------------------------------------

// Error handler for the Artistic Style formatter
// Pause so the error will be noticed
// Linux calls "sh -c", not bash
void  STDCALL errorHandler(int errorNumber, const char* errorMessage)
{
	cout << "AStyle error " << errorNumber << ".\n" << errorMessage << endl;
#ifdef _WIN32
	system("pause");
#else
	cout << "Press ENTER to continue." << endl;
	if (system("read x") > 0)
		cout << "Bad return from 'system' call." << endl;
#endif
}

// Error handler 2 just adds to an error count
// It is used to test error conditions
void  STDCALL errorHandler2(int, const char*)
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
