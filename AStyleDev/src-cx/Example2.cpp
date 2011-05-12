// Example2.cpp

/* This program calls the Artistic Style GUI formatter (AStyleMain)
 * to format the astyle source files in a test-c directory.
 */

#include "AStyleInterface.h"

#include <string.h>         // need both string and string.h for GCC
#include <stdlib.h>
#include <fstream>
#include <iostream>

// function declarations
void error(const char* why, const char* what = "");
string getProjectDirectory(string& subPath);
char* getText(string& filePath);
void  setText(const char* textOut, string& filePathStr);
void setOptionValues(AStyleInterface& as);


int main(int, char**)
{   // options to pass to AStyle
    string fileName[] = { "AStyleDev/test-c/ASBeautifier.cpp",
                          "AStyleDev/test-c/ASFormatter.cpp" ,
                          "AStyleDev/test-c/astyle.h"
                        };
    size_t arraySize = sizeof(fileName) / sizeof(fileName[0]);

    // create an object
    AStyleInterface astyle;

    // set test values for the options
    astyle.setTestOptions();

    // get Artistic Style version
    char* version = AStyleGetVersion();
    cout << "Example2 C++ - AStyle " << version << endl;

    // process the input files
    for (size_t i = 0; i < arraySize; i++)
    {   // get the text to format
        string filePath = getProjectDirectory(fileName[i]);
        char* textIn = getText(filePath);

        // call the Artistic Style formatting function
        char* textOut = astyle.formatSource(textIn, filePath);

        // NULL pointer is an error - restore the original file
        // an error message has been displayed by the error handler
        if (textOut == NULL)
        {   cout << "Cannot format " << filePath << endl;
            return 0;
        }

        // return the formatted text
        cout << "Formatted " << fileName[i] << endl;
        setText(textOut, filePath);

        // must delete the temporary buffers
        delete [] textIn;
        delete [] textOut;
    }
#ifdef __MINGW32__
    system("pause");
#endif
}

// Error message function for this example
void error(const char* why, const char* what)
{   cout << why << ' ' << what << endl;
    cout << "The program has terminated!" << endl;
    exit(1);
}

// Prepend the project directory to the subpath
// This may need to be changed for your directory structure
string getProjectDirectory(string& subPath)
{
#ifdef _WIN32
    char* homeDirectory = getenv("USERPROFILE");
#else
    char* homeDirectory = getenv("HOME");
#endif
    if (!homeDirectory)
        error("Cannot find HOME directory");
    string projectPath = string(homeDirectory) + "/Projects/" + subPath;
    return projectPath;
}

// Get the text to be formatted
// Usually the text would be obtained from an edit control
char* getText(string& filePath)
{   // open input file
    ifstream in(filePath.c_str());
    if (!in)
        error("Cannot open input file", filePath.c_str());

    // get length of buffer
    const int bufferSizeIn = 131072;     // 128 KB

    // allocate memory
    char* bufferIn = new(nothrow) char [bufferSizeIn];
    if (bufferIn == NULL)
    {   in.close();
        error("Memory allocation failure on input");
    }

    // read data as a block
    in.read(bufferIn, bufferSizeIn);
    // get actual size - must be smaller than buffer size
    int textSizeIn = static_cast<int>(in.gcount());
    if (textSizeIn == bufferSizeIn)
    {   in.close();
        error("Read buffer is too small");
    }
    bufferIn[textSizeIn] = '\0';
    in.close();

    return bufferIn;
}

// Return the formatted text
// Usually the text would be returned to an edit control
void setText(const char* textOut, string& filePathStr)
{   // create a backup file
    const char* filePath = filePathStr.c_str();
    string origfilePathStr = filePathStr + ".orig";
    const char* origfilePath = origfilePathStr.c_str();
    remove(origfilePath);              // remove a pre-existing file

    if (rename(filePath, origfilePath) < 0)
        error("Cannot open input file", filePath);

    // open the output file
    ofstream out(filePath);
    if (!out)
        error("Cannot open output file", filePath);

    // write the text
    int textSizeOut = strlen(textOut);
    out.write(textOut, textSizeOut);
    out.close();
}
