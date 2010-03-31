// TersePrinter test program.
// The output must be inspected visually.

#include "gtest/gtest.h"
#include "TersePrinter.h"

TEST(TestCase1, SUCCEED)
{
	SUCCEED() << "SUCCEED() has been invoked from here";
}

TEST(TestCase1, Equal_Succeeds)
{
	EXPECT_EQ(1, 1);
}

TEST(TestCase2, Equal_Fails)
{
	EXPECT_EQ(1, 2) << "EXPECT_EQ failure.";
}

TEST(TestCase2, STREQ1_Fails)
{
	char expected_str[] =
	    "\nvoid foo() {\n"
	    "    isBar = true;\n"
	    "    bar();\n"
	    "}";
	char actual_str[] =
	    "\nvoid foo() {\n"
	    "    isBar = true;\n"
	    "     bar();\n"
	    "}";
	EXPECT_STREQ(expected_str, actual_str);
}

TEST(TestCase2, STREQ2_Fails)
{
	char expected_str[] =
	    "\nvoid foo() {\n"
	    "    bar();\n"
	    "}";
	char actual_str[] =
	    "\nvoid foo() {\n"
	    "     bar();\n"
	    "}";
	EXPECT_STREQ(expected_str, actual_str) << "EXPECT_STREQ 2 failure.";
}

TEST(TestCase2, TrueFalse_Fails)
{
	int process_return = 1;
	int CONTINUE = 0;
	EXPECT_TRUE(process_return == CONTINUE) << "EXPECT_TRUE failure.";;
}

TEST(DISABLED_TestCase2, Disabled)
{
}


int main(int argc, char **argv)
{
	// Parse command line BEFORE testing::InitGoogleTest.
	bool use_terse_printer = false;
	bool use_color = true;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--terse_printer") == 0 )
			use_terse_printer = true;
		else if (strcmp(argv[i], "--gtest_color=no") == 0 )
			use_color = false;
	}
	if (!use_terse_printer)
		printf("%s\n", "Run this program with --terse_printer to change the way "
		       "it prints its output.");

	// Do this after parsing the command line but before changing printer.
	testing::InitGoogleTest(&argc, argv);

	// If we are given the --terse_printer command line flag, suppresses the
	// standard output and attaches own result printer.
	if (use_terse_printer)
	{
		UnitTest& unit_test = *UnitTest::GetInstance();
		testing::TestEventListeners& listeners = unit_test.listeners();

		// Removes the default console output listener from the list so it will
		// not receive events from Google Test and won't print any output. Since
		// this operation transfers ownership of the listener to the caller we
		// have to delete it as well.
		delete listeners.Release(listeners.default_result_printer());

		// Adds the custom output listener to the list. It will now receive
		// events from Google Test and print the alternative output. We don't
		// have to worry about deleting it since Google Test assumes ownership
		// over it after adding it to the list.
		listeners.Append(new TersePrinter(use_color));
	}
	return RUN_ALL_TESTS();
}
