
#ifndef ASTYLE_INTERFACE_H
#define ASTYLE_INTERFACE_H

#include <string>

// allow for different calling conventions in Linux and Windows
#ifdef _WIN32
#define STDCALL __stdcall
#else
#define STDCALL
#endif

// external functions calls in Artistic Style shared or static library
extern "C" {
    char* STDCALL  AStyleGetVersion();
    char* STDCALL  AStyleMain(const char* textIn,
                              const char* options,
                              void(STDCALL *errorHandler)(int, char*),
                              char*(STDCALL *memoryAlloc)(unsigned long));
}

/**
 * The AStyleInterface class contains the variables and methods to call the
 * Artistic Style shared library to format a source file.
 */

class AStyleInterface
{
public:
    // NOTE: enumerators are always static

    // bracketFormatMode valid bracket modes
    enum BracketMode { BRACKETS_NONE,
                       BRACKETS_ATTACH,
                       BRACKETS_BREAK,
                       BRACKETS_LINUX,
                       BRACKETS_STROUSTRUP
                     };

    // indentType valid indent types
    enum IndentType { INDENT_SPACES,
                      INDENT_TABS,
                      INDENT_FTABS
                    };

    // predefinedStyle valid predefined styles
    enum PredefinedStyle  { STYLE_NONE,
                            STYLE_ALLMAN,
                            STYLE_JAVA,
                            STYLE_KandR,
                            STYLE_STROUSTRUP,
                            STYLE_WHITESMITH,
                            STYLE_BANNER,
                            STYLE_GNU,
                            STYLE_LINUX
                          };

    // fileMode variable file modes
    enum FileMode { FILEMODE_CPP,
                    FILEMODE_JAVA,
                    FILEMODE_SHARP
                  };

public:
    // public functions
    AStyleInterface();
    char* formatSource(const char* textIn);
    char* formatSource(const char* textIn, const char* fileName);
    char* formatSource(const char* textIn, FileMode fileModeArg);
    void  setFileMode(std::string fileName);
    void  setTestOptions();

private:
    // option variable names are ALMOST the same as Artistic Style
    // the initial value is the default value in Artistic Style
    // comments are the command line option used to set the variable

    // predefined style option
    PredefinedStyle predefinedStyle;    // --style=?

    // tabs/spaces options
    int  indentLength;                  // --indent=? --indent=force-tab=#
    IndentType indentType;              // --indent=? --indent=force-tab=#

    // brackets options
    BracketMode bracketFormatMode;      // --brackets= none, break, attach, linux

    // indentation options
    bool classIndent;                   // --indent-classes
    bool switchIndent;                  // --indent-switches
    bool caseIndent;                    // --indent-cases
    bool blockIndent;                   // --indent-blocks
    bool bracketIndent;                 // --indent-brackets
    bool namespaceIndent;               // --indent-namespaces
    bool labelIndent;                   // --indent-labels
    bool preprocessorIndent;            // --indent-preprocessor
    int  maxInStatementIndent;          // --max-instatement-indent=#
    int  minConditionalIndent;          // --min-conditional-indent=#

    // formatting options
    bool breakHeaderBlocks;             // --break-blocks, --break-blocks=all
    bool breakClosingBlocks;            // --break-blocks=all
    bool breakClosingBrackets;          // --break-closing-brackets
    bool breakElseIfs;                  // --break-elseifs
    bool deleteEmptyLines;              // --delete-empty-lines
    bool padOperators;                  // --pad-oper
    bool padParensOutside;              // --pad-paren, --pad-paren-out
    bool padParensInside;               // --pad-paren, --pad-paren-in
    bool unpadParens;                   // --unpad-paren
    bool breakOneLineStatements;        // --keep-one-line-statements
    bool breakOneLineBlocks;            // --keep-one-line-blocks
    bool convertTabs;                   // --convert-tabs
    bool fillEmptyLines;                // --fill-empty-lines

    // file mode option
    FileMode fileMode;                  // --mode=?

    // default values for integer variables, saved by constructor
    int defaultIndentLength;            // default indentLength
    int defaultMaxInStatementIndent;    // default maxInStatementIndent
    int defaultMinConditionalIndent;    // default minConditionalIndent

private:
    // private functions
    static void  displayErrorMessage(std::string errorMessage);
    std::string getOptions() const;
    static std::string intToString(int intValue);
    // callback functions for Artistic Style
    static void  STDCALL errorHandler(int errorNumber, char* errorMessage);
    static char* STDCALL memoryAlloc(unsigned long memoryNeeded);

};  // class AStyleInterface

#endif      // closes ASTYLE_INTERFACE_H
