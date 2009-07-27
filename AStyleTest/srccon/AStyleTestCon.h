#ifndef ASTYLE_TESTCON_H
#define ASTYLE_TESTCON_H

//-------------------------------------------------------------------------
// headers
//-------------------------------------------------------------------------

#include <UnitTest++.h>
#include <stdlib.h>
#include <vector>
#include <iostream>  // for cout
#include <fstream>
#include <errno.h>
using namespace std;
#include "astyle_main.h"
using namespace astyle;

//-------------------------------------------------------------------------
// extern global variables in astyle_main.cpp
//-------------------------------------------------------------------------

// global variables in astyle_main.cpp
namespace astyle
{
extern ASConsole* g_console;
extern ostream* _err;
}

//-------------------------------------------------------------------------
// declarations
//-------------------------------------------------------------------------

// functions in AStyleTestCon_Main.cpp
char** buildArgv(const vector<string>& argIn);
//bool changeCurrentDirectory(string path);
void createConsoleGlobalObject();
void deleteConsoleGlobalObject();
string getCurrentDirectory();
//string getFileSeparator();
//size_t min(size_t a, size_t b);
void removeOptionsFile(const string& optionsFileName);
void systemPause(const string& message);
bool writeOptionsFile(const char* fileIn, const string& optionsFileName);

//-------------------------------------------------------------------------

#endif // closes ASTYLE_TESTCON_H
