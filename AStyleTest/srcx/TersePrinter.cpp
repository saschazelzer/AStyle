// TersePrinter class is derived from gtest sample9_unittest.cc.
// It prints only failed test cases and set-up and tear-down information.

#include <vector>
#include "TersePrinter.h"


// TersePrinter class.
// Provides alternative output mode which displays only
// the failed tests but in an enhanced form.

// Fired before each iteration of tests starts.
void TersePrinter::OnTestIterationStart(const UnitTest& unit_test, int /*iteration*/)
{
	ColoredPrint(COLOR_YELLOW, "Using terse printer.\n");
	ColoredPrint(COLOR_GREEN, "[==========] ");
	printf("Running %d tests from %d test cases.\n",
	       unit_test.test_to_run_count(),
	       unit_test.test_case_to_run_count());
	fflush(stdout);
}

// Fired before environment set-up for each iteration of tests starts.
void TersePrinter::OnEnvironmentsSetUpStart(const UnitTest& /*unit_test*/)
{
	ColoredPrint(COLOR_GREEN, "[----------] ");
	printf("Global test environment set-up.\n\n");
	fflush(stdout);
}

// Fired before the test starts.
void TersePrinter::OnTestStart(const TestInfo& test_info)
{
	// Saves information for the failure message.
	// The test start information is printed by
	// OnTestPartResult() to print the failures only.
	test_case_name_ = test_info.test_case_name();
	test_info_name_ = test_info.name();
	test_info_comment_ == test_info.comment();
}

// Called after a failed assertion or a SUCCESS().
void TersePrinter::OnTestPartResult(const TestPartResult& test_part_result)
{
	if (test_part_result.failed() )
	{
		ColoredPrint(COLOR_GREEN, "[  RUN     ] ");
		printf("%s.%s", test_case_name_.c_str(), test_info_name_.c_str());
		fprintf(stdout,
		        " %s:(%d)\n",
		        test_part_result.file_name(),
		        test_part_result.line_number());
		PrintFailedTestSummary(string(test_part_result.summary()));
		ColoredPrint(COLOR_RED, "[  FAILED  ] ");
		printf("%s.%s\n\n", test_case_name_.c_str(), test_info_name_.c_str());

		fflush(stdout);
	}
}

// Fired before environment tear-down for each iteration of tests starts.
void TersePrinter::OnEnvironmentsTearDownStart(const UnitTest& /*unit_test*/)
{
	ColoredPrint(COLOR_GREEN, "[----------] ");
	printf("Global test environment tear-down.\n");
	fflush(stdout);
}

// Fired after each iteration of tests finishes.
void TersePrinter::OnTestIterationEnd(const UnitTest& unit_test, int /*iteration*/)
{
	ColoredPrint(COLOR_GREEN, "[==========] ");
	printf("%d tests from %d test cases ran.",
	       unit_test.test_to_run_count(),
	       unit_test.test_case_to_run_count());
	float time_in_ms = static_cast<float>(unit_test.elapsed_time());
	printf(" (%1.2f seconds total)\n", time_in_ms / 1000);

	// Print total passed.
	ColoredPrint(COLOR_GREEN, "[  PASSED  ] ");
	printf("%d tests.\n", unit_test.successful_test_count());

	// Print total disabled.
	int num_disabled = unit_test.disabled_test_count();
	if (num_disabled)
	{
		ColoredPrint(COLOR_YELLOW, "[ DISABLED ] ");
		printf("%d tests.\n", num_disabled);
	}

	// Print total failed.
	int num_failures = unit_test.failed_test_count();
	if (num_failures)
	{
		ColoredPrint(COLOR_RED, "[  FAILED  ] ");
		printf("%d tests, listed below:\n", num_failures);
		PrintFailedTestsList(unit_test);
	}

	printf("\n");
	fflush(stdout);
}

// Internal helper for printing the TestPartResult summary variable
// with color enhancement.
void TersePrinter::PrintFailedTestSummary(string summary) const
{
	// Separate the summary message into lines.
	vector<string> line;		// vector for storing print lines
	size_t prev_i = 0;			// i value of the previous \n
	for (size_t i = 0; i < summary.length(); i++)
	{
		if (summary[i] != '\n')
			continue;
		line.push_back(summary.substr(prev_i, i - prev_i));
		prev_i = i;
	}
	// Write the last line and append a return.
	line.push_back(summary.substr(prev_i));
	line.push_back("\n");

	// Print the lines with added color.
	for (size_t j = 0; j < line.size(); j++)
	{
		if (line[j].find("  Actual:") != string::npos
		        || line[j].find("Which is:") != string::npos
		        || line[j].find("Value of:") != string::npos
		        || line[j].find("Expected:") != string::npos)
		{
			// Header portion is not colored.
			printf("%s", line[j].substr(0, 10).c_str());
			ColoredPrint(COLOR_CYAN, line[j].substr(10).c_str());
		}
		else
		{
			ColoredPrint(COLOR_CYAN, line[j].c_str());
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
			printf("%s.%s\n", test_case.name(), test_info.name());
		}
	}
}

// Internal helper to return the next non-whitespace character.
char TersePrinter::PeekNextChar(const string &line, int i) const
{
	char ch = ' ';
	size_t peekNum = line.find_first_not_of(" \t", i + 1);
	if (peekNum == string::npos)
		return ch;
	ch = line[peekNum];
	return ch;
}

#ifdef _WIN32

// Windows print colored string to stdout.
void TersePrinter::ColoredPrint(ConsoleColor color, const char* fmt) const
{
	if (!use_color_)
	{
		printf("%s", fmt);
		return;
	}

	const HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

	// get the current text color
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(stdoutH, &bufferInfo);
	const WORD oldColorAttrs = bufferInfo.wAttributes;

	SetConsoleTextAttribute(stdoutH, 
							GetColorAttribute(color) 
							| static_cast<WORD>(FOREGROUND_INTENSITY));
	printf(fmt);

	// restore the text color.
	SetConsoleTextAttribute(stdoutH, oldColorAttrs);
}

// Windows return the character attribute for the given color.
WORD TersePrinter::GetColorAttribute(ConsoleColor color) const
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
void TersePrinter::ColoredPrint(ConsoleColor color, const char* fmt) const
{
	static const bool in_color_mode =
	    ShouldUseColor(isatty(fileno(stdout)) != 0);
	bool use_color_print = in_color_mode && use_color_;

	if (!use_color_print)
	{
		printf("%s", fmt);
		return;
	}
	string color_code = GetAnsiColorCode(color);
	printf("%s", color_code.c_str());
	printf("%s", fmt);
	printf("%s", "\033[m");	// reset the terminal to default.
}

// Linux return the ANSI color code for the given color.
// TODO: how to make it bold??
string TersePrinter::GetAnsiColorCode(ConsoleColor color) const
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
bool TersePrinter::ShouldUseColor(bool stdoutIsTty) const
{
	// use the TERM variable.
	const char* const term = getenv("TERM");
	const bool termSupportsColor = strcmp(term, "xterm") == 0
	                               || strcmp(term, "xterm-color") == 0
	                               || strcmp(term, "xterm-256color") == 0
	                               || strcmp(term, "linux") == 0
	                               || strcmp(term, "cygwin") == 0;
	return stdoutIsTty && termSupportsColor;
}

#endif	// _WIN32
