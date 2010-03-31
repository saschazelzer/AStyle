#ifndef ASTYLE_TEST_H
#define ASTYLE_TEST_H

//-------------------------------------------------------------------------
// headers
//-------------------------------------------------------------------------

#include <gtest/gtest.h>
#include <stdlib.h>
#include <iostream>  // for cout

#include "astyle.h"

//-------------------------------------------------------------------------
// declarations
//-------------------------------------------------------------------------

// AStyleMain callback function declarations
void  STDCALL errorHandler(int errorNumber, const char* errorMessage);
char* STDCALL memoryAlloc(unsigned long memoryNeeded);

// errorHandler2 functions
void  STDCALL errorHandler2(int, const char*);
int   getErrorHandler2Calls();

//-------------------------------------------------------------------------

#endif // closes ASTYLE_TEST_H
