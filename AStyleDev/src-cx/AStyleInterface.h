
#ifndef ASTYLE_INTERFACE_H
#define ASTYLE_INTERFACE_H

#include <string>
using namespace std;

// allow for different calling conventions in Linux and Windows
#ifdef _WIN32
#define STDCALL __stdcall
#else
#define STDCALL
#endif

// external functions calls in Artistic Style shared or static library
extern "C"
{   char* STDCALL  AStyleGetVersion();
    char* STDCALL  AStyleMain(const char* textIn,
                              const char* options,
                              void(STDCALL* errorHandler)(int, const char*),
                              char*(STDCALL* memoryAlloc)(unsigned long));
}

/**
 * The AStyleInterface class contains the variables and methods to call the
 * Artistic Style shared library to format a source file.
 */

class AStyleInterface
{
public:
    // NOTE: enumerators are always static

    enum IndentType { INDENT_SPACES,
                      INDENT_TABS,
                      INDENT_FTABS
                    };

    enum BracketStyle  { STYLE_NONE,
                         STYLE_ALLMAN,
                         STYLE_JAVA,
                         STYLE_KandR,
                         STYLE_STROUSTRUP,
                         STYLE_WHITESMITH,
                         STYLE_BANNER,
                         STYLE_GNU,
                         STYLE_LINUX,
                         STYLE_HORSTMANN,
                         STYLE_1TBS,
                         STYLE_PICO,
                         STYLE_LISP
                       };

    enum PointerAlign { ALIGN_NONE,
                        ALIGN_TYPE,
                        ALIGN_MIDDLE,
                        ALIGN_NAME
                      };

    enum MinConditional { MINCOND_ZERO = 0,
                          MINCOND_ONE = 1,
                          MINCOND_TWO = 2,
                          MINCOND_ONEHALF = 3,
                          MINCOND_END
                        };

    enum FileMode { FILEMODE_CPP,
                    FILEMODE_JAVA,
                    FILEMODE_SHARP
                  };

public:
    // public functions
    AStyleInterface();
    char* formatSource(const char* textIn);
    char* formatSource(const char* textIn, string& filePath);
    char* formatSource(const char* textIn, FileMode fileModeArg);
    void  setFileMode(string fileName);
    void  setTestOptions();

private:
    // option variable names are ALMOST the same as Artistic Style
    // the initial value is the default value in Artistic Style
    // comments are the command line option used to set the variable

    // bracket style option
    BracketStyle bracketStyle;			// --style=?

    // tabs/spaces options
    int  indentLength;                  // --indent=? --indent=force-tab=#
    IndentType indentType;              // --indent=? --indent=force-tab=#

    // indentation options
    bool classIndent;                   // --indent-classes
    bool switchIndent;                  // --indent-switches
    bool caseIndent;                    // --indent-cases
    bool namespaceIndent;               // --indent-namespaces
    bool labelIndent;                   // --indent-labels
    bool preprocessorIndent;            // --indent-preprocessor
    bool col1CommentIndent;             // --indent-col1-comments
    int  maxInStatementIndent;          // --max-instatement-indent=#
    int  minConditionalOption;          // --min-conditional-indent=#

    // padding options
    bool breakHeaderBlocks;             // --break-blocks, --break-blocks=all
    bool breakClosingBlocks;            // --break-blocks=all
    bool padOperators;                  // --pad-oper
    bool padParensOutside;              // --pad-paren, --pad-paren-out
    bool padParensInside;               // --pad-paren, --pad-paren-in
    bool padHeaders;                    // --pad-header
    bool unpadParens;                   // --unpad-paren
    bool deleteEmptyLines;              // --delete-empty-lines
    bool fillEmptyLines;                // --fill-empty-lines

    // formatting options
    bool breakCloseBrackets;            // --break-closing-brackets
    bool breakElseIfs;                  // --break-elseifs
    bool addBrackets;                   // --add-brackets
    bool addOneLineBrackets;            // --add-one-line-brackets
    bool breakOneLineStmts;             // --keep-one-line-statements
    bool breakOneLineBlocks;            // --keep-one-line-blocks
    bool convertTabs;                   // --convert-tabs
    PointerAlign alignPointers;         // --align-pointer= none, type, middle, name

    // file mode option
    FileMode fileMode;                  // --mode=?

    // default values for integer variables, saved by constructor
    int defaultIndentLength;            // default indentLength
    int defaultMaxInStatementIndent;    // default maxInStatementIndent
    int defaultMinConditionalOption;    // default minConditionalIndent

private:
    // private functions
    static void  displayErrorMessage(string errorMessage);
    string getOptions() const;
    static string intToString(int intValue);
    // callback functions for Artistic Style
    static void  STDCALL errorHandler(int errorNumber, const char* errorMessage);
    static char* STDCALL memoryAlloc(unsigned long memoryNeeded);

};  // class AStyleInterface

#endif      // closes ASTYLE_INTERFACE_H
