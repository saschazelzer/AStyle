#include "AStyleInterface.h"
#include <iostream>
#include <sstream>

/*
* The constructor sets the variable default values.
**/
AStyleInterface::AStyleInterface()
{
    // predefined style options
    predefinedStyle = STYLE_NONE;           // --style=?

    // tabs/spaces options
    indentLength = 4;                       // --indent=?, --force-indent=tab=#
    indentType   = INDENT_SPACES;           // --indent=?, --force-indent=tab=#

    // brackets options
    bracketFormatMode    = BRACKETS_NONE;   // --brackets= none, break, attach, linux
    breakClosingBrackets = false;           // --brackets=break-closing

    // indentation options
    classIndent        = false;             // --indent-classes
    switchIndent       = false;             // --indent-switches
    caseIndent         = false;             // --indent-cases
    blockIndent        = false;             // --indent-blocks
    bracketIndent      = false;             // --indent-brackets
    namespaceIndent    = false;             // --indent-namespaces
    labelIndent        = false;             // --indent-labels
    preprocessorIndent = false;             // --indent-preprocessor
    maxInStatementIndent = 40;              // --max-instatement-indent=#
    minConditionalIndent = indentLength * 2;  // --min-conditional-indent=#

    // formatting options
    breakHeaderBlocks  = false;             // --break-blocks, --break-blocks=all
    breakClosingBlocks = false;             // --break-blocks=all
    breakElseIfs       = false;             // --break-elseifs
    deleteEmptyLines   = false;             // --delete-empty-lines
    padOperators       = false;             // --pad=oper
    padParensOutside   = false;             // --pad=paren, --pad=paren-out
    padParensInside    = false;             // --pad=paren, --pad=paren-in
    unpadParens        = false;             // --unpad=paren
    breakOneLineStatements = true;          // --one-line=keep-statements
    breakOneLineBlocks     = true;          // --one-line=keep-blocks
    convertTabs        = false;             // --convert-tabs
    fillEmptyLines     = false;             // --fill-empty-lines

    // file mode option
    fileMode = FILEMODE_CPP;                // --mode=?

    // save integer default values
    defaultIndentLength         = indentLength;
    defaultMaxInStatementIndent = maxInStatementIndent;
    defaultMinConditionalIndent = minConditionalIndent;
}

/**
* Display error messages for the class.
* This method should be changed to display messages in a manner consistent
* with the rest of the user program (e.g. a message box).
*
* @param  errorMessage   The error message to be displayed.
*/
void AStyleInterface::displayErrorMessage(std::string errorMessage)
{
    std::cout << errorMessage << std::endl;
}

/**
* Build a string of options from the current option variables.
* An option is generated only if the current value is different
* than the default value.
* If an option variable is invalid, invalid text is sent to
* Artistic Style so the private ErrorHandler method will be called.
*
* @return    A string containing the options for Artistic Style.
*/
std::string AStyleInterface::getOptions() const
{
    std::string options;                     // options to Artistic Style
    options.reserve(50);
    std::string separator = "\n";            // can be new-line, tab, space, or comma

    // predefined style will override other options
    if (predefinedStyle != STYLE_NONE) {
        if (predefinedStyle == STYLE_ALLMAN)
            options.append("style=allman");
        else if (predefinedStyle == STYLE_JAVA)
            options.append("style=java");
        else if (predefinedStyle == STYLE_KandR)
            options.append("style=k&r");
        else if (predefinedStyle == STYLE_STROUSTRUP)
            options.append("style=stroustrup");
        else if (predefinedStyle == STYLE_WHITESMITH)
            options.append("style=whitesmith");
        else if (predefinedStyle == STYLE_BANNER)
            options.append("style=banner");
        else if (predefinedStyle == STYLE_GNU)
            options.append("style=gnu");
        else if (predefinedStyle == STYLE_LINUX)
            options.append("style=linux");
        else
            options.append("invalid-predefinedStyle="      // force an error message
                           + intToString(predefinedStyle));
        options.append(separator);
    }
    // begin indent check
    if (indentType == INDENT_SPACES) {             // space is the default
        if (!(indentLength == defaultIndentLength
                || predefinedStyle == STYLE_GNU
                || predefinedStyle == STYLE_LINUX)) {
            options.append("indent=spaces=" + intToString(indentLength));
            options.append(separator);
        }
    } else if (indentType == INDENT_TABS) {         // tab is not the default
        // check conditions to use default tab setting
        if (indentLength == defaultIndentLength
                && predefinedStyle != STYLE_GNU
                && predefinedStyle != STYLE_LINUX)
            options.append("indent=tab");
        else
            options.append("indent=tab=" + intToString(indentLength));
        options.append(separator);
    } else if (indentType == INDENT_FTABS) {
        options.append("indent=force-tab=" + intToString(indentLength));
        options.append(separator);
    } else {
        options.append("invalid-indentType="       // force an error message
                       + intToString(indentType));
        options.append(separator);
    }
    // end indent check
    if (bracketFormatMode != BRACKETS_NONE) {
        if (bracketFormatMode == BRACKETS_ATTACH)
            options.append("brackets=attach");
        else if (bracketFormatMode == BRACKETS_BREAK)
            options.append("brackets=break");
        else if (bracketFormatMode == BRACKETS_LINUX)
            options.append("brackets=linux");
        else if (bracketFormatMode == BRACKETS_STROUSTRUP)
            options.append("brackets=stroustrup");
        else
            options.append("invalid-bracketFormatMode="    // force an error message
                           + intToString(bracketFormatMode));
        options.append(separator);
    }
    if (classIndent) {
        options.append("indent-classes");
        options.append(separator);
    }
    if (switchIndent) {
        options.append("indent-switches");
        options.append(separator);
    }
    if (caseIndent) {
        options.append("indent-cases");
        options.append(separator);
    }
    if (bracketIndent) {
        options.append("indent-brackets");
        options.append(separator);
    }
    if (blockIndent) {
        options.append("indent-blocks");
        options.append(separator);
    }
    if (namespaceIndent) {
        options.append("indent-namespaces");
        options.append(separator);
    }
    if (labelIndent) {
        options.append("indent-labels");
        options.append(separator);
    }
    if (preprocessorIndent) {
        options.append("indent-preprocessor");
        options.append(separator);
    }
    if (maxInStatementIndent != defaultMaxInStatementIndent) {
        options.append("max-instatement-indent="
                       + intToString(maxInStatementIndent));
        options.append(separator);
    }
    if (minConditionalIndent != defaultMinConditionalIndent) {
        options.append("min-conditional-indent="
                       + intToString(minConditionalIndent));
        options.append(separator);
    }
    // begin break-blocks check
    if (breakClosingBlocks) {
        options.append("break-blocks=all");
        options.append(separator);
    } else if (breakHeaderBlocks) {
        options.append("break-blocks");
        options.append(separator);
    }
    // end break-blocks check
    if (breakClosingBrackets) {
        options.append("break-closing-brackets");
        options.append(separator);
    }
    if (breakElseIfs) {
        options.append("break-elseifs");
        options.append(separator);
    }
    if (deleteEmptyLines) {
        options.append("delete-empty-lines");
        options.append(separator);
    }
    if (padOperators) {
        options.append("pad-oper");
        options.append(separator);
    }
    // begin pad parens check
    if (padParensOutside && padParensInside) {
        options.append("pad-paren");
        options.append(separator);
    } else if (padParensOutside) {
        options.append("pad-paren-out");
        options.append(separator);
    } else if (padParensInside) {
        options.append("pad-paren-in");
        options.append(separator);
    }
    // end pad parens check
    if (unpadParens) {
        options.append("unpad-paren");
        options.append(separator);
    }
    if (! breakOneLineStatements) {          // default = true
        options.append("keep-one-line-statements");
        options.append(separator);
    }
    if (! breakOneLineBlocks) {              // default = true
        options.append("keep-one-line-blocks");
        options.append(separator);
    }
    if (convertTabs) {
        options.append("convert-tabs");
        options.append(separator);
    }
    if (fillEmptyLines) {
        options.append("fill-empty-lines");
        options.append(separator);
    }

    // add the file mode, default is C++
    if (fileMode == FILEMODE_CPP) {
        if (options.length() > 0)                  // delete the last separator
            options.erase(options.length() - 1);
    } else if (fileMode == FILEMODE_JAVA)
        options.append("mode=java");
    else if (fileMode == FILEMODE_SHARP)
        options.append("mode=cs");
    else
        options.append("invalid-fileMode="         // force an error message
                       + intToString(fileMode));

    return options;
}

/**
* Static method to convert int to a string.
* Not all compilers support the function itoa() (e.g. GCC).
*
* @param  intValue  The int to be converted.
*/
std::string AStyleInterface::intToString(int intValue)
{
    std::ostringstream stringValue;
    stringValue << intValue;
    return stringValue.str();
}

/**
* Set the fileMode variable from the input file extension.
*
* @param  fileName   The name of the file, path may be included.
*/
void AStyleInterface::setFileMode(std::string fileName)
{
    fileMode = FILEMODE_CPP;            // set the default
    size_t i = fileName.find_last_of('.');
    if (i != std::string::npos) {
        std::string fileExtension = fileName.substr(i);
        if (fileExtension == ".java")
            fileMode = FILEMODE_JAVA;
        else if (fileExtension == ".cs")
            fileMode = FILEMODE_SHARP;
    }
}

/**
* Set options for testing.
* For test program only.
* This will not be used by an actual program.
*/
void AStyleInterface::setTestOptions()
{
    // predefined Style options
    // will have precedence over conflicting options
//    predefinedStyle = STYLE_ALLMAN;

    // tabs / spaces options
    indentLength = 3;
    indentType = INDENT_TABS;

    // brackets option
    bracketFormatMode = BRACKETS_ATTACH;

    // indentation options
    classIndent          = true;
    switchIndent         = true;
    caseIndent           = true;
    blockIndent          = true;
    bracketIndent        = true;
    namespaceIndent      = true;
    labelIndent          = true;
    preprocessorIndent   = true;
    maxInStatementIndent = 50;
    minConditionalIndent = 10;

    // formatting options
    breakHeaderBlocks    = true;
    breakClosingBlocks   = true;
    breakClosingBrackets = true;
    breakElseIfs         = true;
    deleteEmptyLines     = true;
    padOperators         = true;
    padParensOutside     = true;
    padParensInside      = true;
    unpadParens          = true;
    breakOneLineStatements = false;
    breakOneLineBlocks     = false;
    convertTabs          = true;
    fillEmptyLines       = true;

    // generate some errors
    /*    predefinedStyle    = (AStyleInterface::PredefinedStyle) 10;
        bracketFormatMode  = (AStyleInterface::BracketMode) 7;
        maxInStatementIndent = 90;
        minConditionalIndent = 50;
        // cannot have both invalid indentLength and invalid indentType
    //    indentLength     = 21;
        indentType         = (AStyleInterface::IndentType) 6;  */
}

// functions to call Artistic Style ---------------------------------------------------------------

/**
* Call the AStyleMain function in Artistic Style.
*
* @param   textIn  A pointer to the source code to be formatted.
* @return  A pointer to the formatted source from Artistic Style.
*/
char* AStyleInterface::formatSource(const char* textIn)
{
    std::string options = getOptions();
//	displayErrorMessage("--------------------");
//	displayErrorMessage(options);
//	displayErrorMessage("--------------------");
    char* textOut = AStyleMain(textIn,
                               options.c_str(),
                               errorHandler,
                               memoryAlloc);
    return textOut;
}

/**
* Set fileMode and call the AStyleMain function in Artistic Style.
*
* @param   textIn  A pointer to the source code to be formatted.
* @param   fileName  A pointer to the name of the file being formatted.
* @return  A char pointer to the formatted source from Artistic Style.
*/
char* AStyleInterface::formatSource(const char* textIn, const char* fileName)
{
    // set file mode before formatting source
    setFileMode(fileName);
    char* textOut = formatSource(textIn);
    return textOut;
}

/**
* Set fileMode and call the AStyleMain function in Artistic Style.
*
* @param   textIn  A pointer to the source code to be formatted.
* @param   fileModeArg  A FileMode enum of the file being formatted.
* @return  A char pointer to the formatted source from Artistic Style.
*/
char* AStyleInterface::formatSource(const char* textIn, FileMode fileModeArg)
{
    // set file mode before formatting source
    fileMode = fileModeArg;
    char* textOut = formatSource(textIn);
    return textOut;
}

/**
* Static method to handle error messages from messages from Artistic Style.
* This method is called only if there are errors when AStyleMain is called.
* This is for debugging and there should be no errors when the calling
* parameters are correct.
*
* @param  errorNumber   The error number from Artistic Style.
* @param  errorMessage  The error message from Artistic Style.
*/
void STDCALL AStyleInterface::errorHandler(int errorNumber, char* errorMessage)
{
    displayErrorMessage(std::string("astyle error "
                                    + intToString(errorNumber)
                                    + "\n" + errorMessage));
}

/**
* Allocate memory for the Artistic Style formatter.
* This method is called when Artistic Style needs to allocate memory.
* for the formatted file.
* The calling program is responsible for freeing the memory.
*
* @param  memoryNeeded  The amount of memory needed by Artistic Style.
*/
char* STDCALL AStyleInterface::memoryAlloc(unsigned long memoryNeeded)
{
    // error condition should be checked by calling procedure
    char* buffer = new(std::nothrow) char [memoryNeeded];
    return buffer;
}
