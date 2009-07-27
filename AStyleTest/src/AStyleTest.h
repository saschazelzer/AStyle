#ifndef ASTYLE_TEST_H
#define ASTYLE_TEST_H

//-------------------------------------------------------------------------
// headers
//-------------------------------------------------------------------------

#include <UnitTest++.h>
#include <stdlib.h>
#include <iostream>  // for cout

#include "astyle.h"

//-------------------------------------------------------------------------
// declarations
//-------------------------------------------------------------------------

// AStyleMain callback function declarations
void  STDCALL errorHandler(int errorNumber, char* errorMessage);
char* STDCALL memoryAlloc(unsigned long memoryNeeded);

// errorHandler2 functions
void  STDCALL errorHandler2(int, char*);
int   getErrorHandler2Calls();

//-------------------------------------------------------------------------

#endif // closes ASTYLE_TEST_H
