// TersePrinter class is derived from gtest sample9_unittest.cc.
// It prints only failed test cases and set-up and tear-down information.
// To activate run the test program with the command argument --terse_printer.

#include "TersePrinter.h"

// This will have a value after OnTestIterationEnd is called.
int g_test_to_run = 0;

// TersePrinter class.
// Provides alternative output mode which displays only
// the failed tests but in an enhanced form.

// Fired before each iteration of tests starts.
void TersePrinter::OnTestIterationStart(const UnitTest& unit_test, int /*iteration*/)
{
#ifdef __BORLANDC__
	ColoredPrintf(COLOR_YELLOW, "%s", "No mock tests.\n");
#endif
#if !GTEST_HAS_DEATH_TEST || LEAK_FINDER
	ColoredPrintf(COLOR_YELLOW, "%s", "No death tests.\n");
#endif
	ColoredPrintf(COLOR_GREEN, "%s", "Using terse printer.\n");
	ColoredPrintf(COLOR_GREEN, "%s", "[==========] ");
	printf("Running %d tests from %d test cases.\n",
	       unit_test.test_to_run_count(),
	       unit_test.test_case_to_run_count());
	fflush(stdout);
}

// Fired before environment set-up for each iteration of tests starts.
void TersePrinter::OnEnvironmentsSetUpStart(const UnitTest& /*unit_test*/)
{
	ColoredPrintf(COLOR_GREEN, "%s", "[----------] ");
	printf("Global test environment set-up.\n\n");
	fflush(stdout);
}

// Fired before the test starts.
// Save information for the failure message.
// The test start information is actually printed by
// OnTestPartResult() and prints the failures only.
void TersePrinter::OnTestStart(const TestInfo& test_info)
{
	test_header_printed_ = false;
	test_case_name_ = test_info.test_case_name();
	test_info_name_ = test_info.name();
}

// Called after a failed assertion or a SUCCESS().
// Print the test header for the first error or
// a continuation line for additional errors.
// Then print the failed test summary.
void TersePrinter::OnTestPartResult(const TestPartResult& test_part_result)
{
	if (test_part_result.failed() )
	{
		if (!test_header_printed_)
		{
			test_header_printed_ = true;
			// print the message header
			ColoredPrintf(COLOR_YELLOW, "%s", "[  RUN     ] ");
			printf("%s.%s", test_case_name_.c_str(), test_info_name_.c_str());
			// remove directory information from the file path
			string file_name = test_part_result.file_name();
			size_t dir_end = file_name.find_last_of("\\/");
			if (dir_end != string::npos)
				file_name = file_name.substr(dir_end + 1);
			// print the test name
			printf("  %s:(%d)\n",
			       file_name.c_str(),
			       test_part_result.line_number());
		}
		else
		{
			ColoredPrintf(COLOR_YELLOW, "%s", "[          ]\n");
		}
		// print the failed test summary
		PrintFailedTestSummary(string(test_part_result.summary()));
		fflush(stdout);
	}
}

// Fired after the test ends.
// Print a summary only if the test failed.
void TersePrinter::OnTestEnd(const TestInfo& test_info)
{
	if (!test_info.result()->Passed())
	{
		ColoredPrintf(COLOR_RED, "%s", "[  FAILED  ] ");
		printf("%s.%s", test_case_name_.c_str(), test_info_name_.c_str());
		string filler;
		size_t name_length = test_case_name_.length() + test_info_name_.length() + 1;
		int filler_adjust = 60 - static_cast<int>(name_length);
		if (filler_adjust < 0)
			filler_adjust = 0;
		filler.append(filler_adjust, '-');
		printf("  %s\n\n", filler.c_str());
		fflush(stdout);
	}
}

// Fired before environment tear-down for each iteration of tests starts.
void TersePrinter::OnEnvironmentsTearDownStart(const UnitTest& /*unit_test*/)
{
	ColoredPrintf(COLOR_GREEN, "%s", "[----------] ");
	printf("Global test environment tear-down.\n");
	fflush(stdout);
}

// Fired after each iteration of tests finishes.
void TersePrinter::OnTestIterationEnd(const UnitTest& unit_test, int /*iteration*/)
{
	g_test_to_run = unit_test.test_to_run_count();
	ColoredPrintf(COLOR_GREEN, "%s", "[==========] ");
	printf("%d tests from %d test cases ran.",
	       unit_test.test_to_run_count(),
	       unit_test.test_case_to_run_count());
	float time_in_ms = static_cast<float>(unit_test.elapsed_time());
	printf(" (%1.2f seconds total)\n", time_in_ms / 1000);
	// Print total passed.
	ColoredPrintf(COLOR_GREEN, "%s", "[  PASSED  ] ");
	printf("%d tests.\n", unit_test.successful_test_count());
	// Print total failed.
	int num_failures = unit_test.failed_test_count();
	if (num_failures)
	{
		ColoredPrintf(COLOR_RED, "%s", "[  FAILED  ] ");
		printf("%d tests, listed below:\n", num_failures);
		PrintFailedTestsList(unit_test);
		printf("\n%2d FAILED TESTS\n", num_failures);
	}
	// Print total disabled.
	int num_disabled = unit_test.disabled_test_count();
	if (num_disabled)
	{
		if (!num_failures)
		{
			printf("\n");  // Add a spacer if no FAILURE banner is displayed.
		}
		ColoredPrintf(COLOR_YELLOW, "  YOU HAVE %d DISABLED TESTS\n", num_disabled);
	}
	// Ensure that Google Test output is printed before, e.g., heapchecker output.
	fflush(stdout);
}

// Internal helper for printing the TestPartResult summary variable
// with color enhancement.
void TersePrinter::PrintFailedTestSummary(string summary) const
{
	// Separate the summary message into lines.
	vector<string> line;		// vector for storing print lines
	size_t prev_i = 0;			// i value of the previous \n
	for (size_t i = 1; i < summary.length(); i++)
	{
		// end the line when the previous char is the last \n in a sequence
		if (summary[i-1] != '\n' || summary[i] == '\n')
			continue;
		line.push_back(summary.substr(prev_i, i - prev_i));
		prev_i = i;
	}
	// Write the last line and append a return.
	if (prev_i < (summary.length()))
	{
		line.push_back(summary.substr(prev_i));
		int last_char = static_cast<int>(line.back().length()) - 1;
		if (last_char > 0 && line.back()[last_char] != '\n')
			line.back().append("\n");
	}
	// Print the lines with added color.
	for (size_t j = 0; j < line.size(); j++)
	{
		if (line[j].compare(0, 9, "  Actual:") == 0
		        || line[j].compare(0, 9, "Which is:") == 0
		        || line[j].compare(0, 9, "Value of:") == 0)
		{
			// Header portion is not colored.
			printf("%s", line[j].substr(0, 10).c_str());
			ColoredPrintf(COLOR_CYAN, "%s", line[j].substr(10).c_str());
		}
		else if (line[j].compare(0, 9, "Expected:") == 0)
		{
			// Header portion is not colored.
			printf("%s", line[j].substr(0, 10).c_str());
			size_t iPrint = 10;
			// Check for another header.
			size_t iHeading = line[j].find(", actual:");
			if (iHeading != string::npos)
			{
				ColoredPrintf(COLOR_CYAN, "%s", line[j].substr(iPrint, iHeading - iPrint).c_str());
				iPrint = iHeading;
				// Break the line at actual and reposition.
				line[j].replace(iHeading, 2, "\n  ");
				// Header portion is not colored.
				printf("%s", line[j].substr(iHeading, 10).c_str());
				iPrint += 10;
			}
			ColoredPrintf(COLOR_CYAN, "%s", line[j].substr(iPrint).c_str());
		}
		else if (line[j].compare(0, 11, "Death test:") == 0
		         || line[j].compare(0, 11, "    Result:") == 0
		         || line[j].compare(0, 11, "  Expected:") == 0
		         || line[j].compare(0, 11, "Actual msg:") == 0
		         || line[j].compare(0, 11, " Error msg:") == 0)
		{
			// Header portion is not colored.
			printf("%s", line[j].substr(0, 12).c_str());
			ColoredPrintf(COLOR_CYAN, "%s", line[j].substr(12).c_str());
		}
		else
		{
			ColoredPrintf(COLOR_CYAN, "%s", line[j].c_str());
		}
	}
}

// Internal helper for printing the list of failed tests at end of run.
void TersePrinter::PrintFailedTestsList(const UnitTest& unit_test) const
{
	const int failed_test_count = unit_test.failed_test_count();
	if (failed_test_count == 0)
		return;
	for (int i = 0; i < unit_test.total_test_case_count(); ++i)
	{
		const TestCase& test_case = *unit_test.GetTestCase(i);
		if (!test_case.should_run() || (test_case.failed_test_count() == 0))
			continue;
		for (int j = 0; j < test_case.total_test_count(); ++j)
		{
			const TestInfo& test_info = *test_case.GetTestInfo(j);
			if (!test_info.should_run() || test_info.result()->Passed())
				continue;
			ColoredPrintf(COLOR_RED, "%s", "[  FAILED  ] ");
			printf("%s.%s\n", test_case.name(), test_info.name());
		}
	}
}

// Internal helper to return the next non-whitespace character.
char TersePrinter::PeekNextChar(const string& line, int i) const
{
	char ch = ' ';
	size_t peekNum = line.find_first_not_of(" \t", i + 1);
	if (peekNum == string::npos)
		return ch;
	ch = line[peekNum];
	return ch;
}

// Static function to print the test total.
// Called from the "main" test program at end of job.
void TersePrinter::PrintTestTotals(int all_test_total_check, const char* file, int line)
{
	// Get the file name.
	string file_path(file);
	size_t start = file_path.find_last_of("/\\");
	if (start == string::npos)
		start = 0;
	else
		start++;
	string file_name = file_path.substr(start);
	// Check the totals.
	if (g_test_to_run < all_test_total_check - 9)
	{
		ColoredPrintf(COLOR_YELLOW,
		              "\nMISSING TESTS: %d (%d)  %s(%d)\n",
		              all_test_total_check, g_test_to_run, file_name.c_str(), line);
	}
	else if (g_test_to_run > all_test_total_check + 9)
	{
		ColoredPrintf(COLOR_YELLOW,
		              "\nUpdate test variable: %d (%d)  %s(%d)\n",
		              all_test_total_check, g_test_to_run, file_name.c_str(), line);
	}
	else
		ColoredPrintf(COLOR_GREEN, "%s", "\nAll tests run.\n");
}

#ifdef _WIN32

// Windows print colored string to stdout.
void ColoredPrintf(ConsoleColor color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
//	if (!use_color_)
//	{
//		vprintf(fmt, args);
//		va_end(args);
//		return;
//	}
	const HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Gets the current text color.
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	GetConsoleScreenBufferInfo(stdout_handle, &buffer_info);
	const WORD old_color_attrs = buffer_info.wAttributes;
	// We need to flush the stream buffers into the console before each
	// SetConsoleTextAttribute call lest it affect the text that is already
	// printed but has not yet reached the console.
	fflush(stdout);
	SetConsoleTextAttribute(stdout_handle,
	                        GetColorAttribute(color)
	                        | static_cast<WORD>(FOREGROUND_INTENSITY));
	vprintf(fmt, args);
	fflush(stdout);
	// Restores the text color.
	SetConsoleTextAttribute(stdout_handle, old_color_attrs);
	va_end(args);
}

// Windows return the character attribute for the given color.
WORD GetColorAttribute(ConsoleColor color)
{
	switch (color)
	{
	case COLOR_RED:
		return FOREGROUND_RED;
	case COLOR_GREEN:
		return FOREGROUND_GREEN;
	case COLOR_BLUE:
		return FOREGROUND_BLUE;
	case COLOR_YELLOW:
		return FOREGROUND_RED | FOREGROUND_GREEN;
	case COLOR_MAGENTA:
		return FOREGROUND_RED | FOREGROUND_BLUE;
	case COLOR_CYAN:
		return FOREGROUND_GREEN | FOREGROUND_BLUE;
	case COLOR_WHITE:
		return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	default:
		return 0;
	}
}

#else

// Linux print colored string to stdout.
void ColoredPrintf(ConsoleColor color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
//	if (!use_color_)
//	{
//		vprintf(fmt, args);
//		va_end(args);
//		return;
//	}
	string color_code = GetAnsiColorCode(color);
	printf("%s", color_code.c_str());
	vprintf(fmt, args);
	printf("%s", "\033[m");	// reset the terminal to default.
	va_end(args);
}

// Linux return the ANSI color code for the given color.
string GetAnsiColorCode(ConsoleColor color)
{
	switch (color)
	{
	case COLOR_RED:
		return "\033[1;31m";
	case COLOR_GREEN:
		return "\033[1;32m";
	case COLOR_YELLOW:
		return "\033[1;33m";
	case COLOR_BLUE:
		return "\033[1;34m";
	case COLOR_MAGENTA:
		return "\033[1;35m";
	case COLOR_CYAN:
		return "\033[1;36m";
	case COLOR_WHITE:
		return "\033[1;37m";
	default:
		return "\033[1;39m";
	}
}

// Linux return true if colors should be in output terminal.
bool ShouldUseColor(bool stdoutIsTty)
{
	// use the TERM variable.
	const char* const term = getenv("TERM");
	if (term == NULL) return false;
	const bool termSupportsColor = strcmp(term, "xterm") == 0
	                               || strcmp(term, "xterm-color") == 0
	                               || strcmp(term, "xterm-256color") == 0
	                               || strcmp(term, "linux") == 0
	                               || strcmp(term, "cygwin") == 0;
	return stdoutIsTty && termSupportsColor;
}

#endif	// _WIN32
