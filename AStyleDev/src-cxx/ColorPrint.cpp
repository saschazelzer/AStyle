
#ifdef _WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

enum ConsoleColor
{
    COLOR_DEFAULT,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE
};


#ifdef _WIN32
WORD getColorAttribute(ConsoleColor color);
#else
string getAnsiColorCode(ConsoleColor color);
bool shouldUseColor(bool stdoutIsTty);
#endif

#ifdef _WIN32
// windows print colored strings to stdout
void coloredCout(ConsoleColor color, const char* fmt)
{
    const bool useColor = true;

    if (!useColor)
    {
        cout << fmt << endl;
        return;
    }

    const HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

    // get the current text color
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(stdoutH, &bufferInfo);
    const WORD oldColorAttrs = bufferInfo.wAttributes;
 
    SetConsoleTextAttribute(stdoutH, getColorAttribute(color) | FOREGROUND_INTENSITY);
    cout << fmt;
 
    // restore the text color.
    SetConsoleTextAttribute(stdoutH, oldColorAttrs);
}
 
// return the character attribute for the given color
WORD getColorAttribute(ConsoleColor color)
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
#endif
 
#ifndef _WIN32
// linux print colored strings to stdout
void coloredCout(ConsoleColor color, const char* fmt)
{
    static const bool in_color_mode =
        shouldUseColor(isatty(fileno(stdout)) != 0);
    bool useColor = in_color_mode && (color != COLOR_DEFAULT);
 
    if (!useColor)
    {
        cout << fmt;
        return;
    }
    string colorCode = getAnsiColorCode(color);
    cout << colorCode;
    cout << fmt;
    cout << "\033[m";  // reset the terminal to default.
}
 
// return the ANSI color code for the given color
// TODO: how to make it bold??
string getAnsiColorCode(ConsoleColor color)
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
 
// return true if colors should be in output terminal
bool shouldUseColor(bool stdoutIsTty)
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
#endif
 
int main(int /*argc*/, char** /*argv*/)
{
//	coloredCout(COLOR_RED, "COLOR_RED    ");
//	cout << "  some more stuff" << endl;
//	coloredCout(COLOR_GREEN, "COLOR_GREEN  ");
//	cout << "  some more stuff" << endl;
//	coloredCout(COLOR_BLUE, "COLOR_BLUE   ");
//	cout << "  some more stuff" << endl;
//	coloredCout(COLOR_YELLOW, "COLOR_YELLOW ");
//	cout << "  some more stuff" << endl;
//	coloredCout(COLOR_MAGENTA, "COLOR_MAGENTA");
//	cout << "  some more stuff" << endl;
//	coloredCout(COLOR_CYAN, "COLOR_CYAN   ");
//	cout << "  some more stuff" << endl;
//	coloredCout(COLOR_WHITE, "COLOR_WHITE  ");
//	cout << "  some more stuff" << endl;
 
    cout << endl << endl;
 
    coloredCout(COLOR_WHITE,  "Artistic Style 1.25\n");
    coloredCout(COLOR_WHITE,  "-----------------------------------------------------\n");
    coloredCout(COLOR_GREEN,  "directory   :");
    coloredCout(COLOR_CYAN,   " C:/Users/jp/Projects/directory/*.cpp\n");
    coloredCout(COLOR_GREEN,  "options file:");
    cout << " C:/Users/jp/AppData/Roaming/astylerc\n";
    coloredCout(COLOR_GREEN,  "options file:");
    cout << " -tapOU\n";
    coloredCout(COLOR_GREEN,  "command line:");
    cout << " --exclude=lua\n";
    coloredCout(COLOR_GREEN,  "exclude     :");
    cout << " plugins/contrib/lua\n";
    coloredCout(COLOR_WHITE,  "-----------------------------------------------------\n");
    coloredCout(COLOR_WHITE, "formatted ");
    coloredCout(COLOR_CYAN, " file/directory/filename1.cpp\n");
    cout << "unchanged*";
    cout << " file/directory/filename2.cpp"	<< endl;
    coloredCout(COLOR_RED, "**********");
    coloredCout(COLOR_RED, " error message\n");
    coloredCout(COLOR_WHITE, "formatted ");
    coloredCout(COLOR_CYAN, " file/directory/filename3.cpp\n");
    coloredCout(COLOR_WHITE,  "-----------------------------------------------------\n");
    cout << "1559 formatted, 24 unchanged, 3 min 26 sec, 442942 lines" << endl << endl;
 
    //	system("pause");
    return 0;
}
 
 
