//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <UnitTest++.h>
#include <iostream>  // for cout

#include "astyle.h"

//-----------------------------------------------------------------------------
// declarations
//-----------------------------------------------------------------------------

// AStyleMain callback function declarations
void  STDCALL errorHandler(int errorNumber, char* errorMessage);
char* STDCALL memoryAlloc(unsigned long memoryNeeded);


//-----------------------------------------------------------------------------
// AStyle Tab Options
//-----------------------------------------------------------------------------

TEST(TabDefault)
{
	// test default indent of 4 spaces per tab
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "    if (isFoo)\n"
	    "    {\n"
	    "        bar();\n"
	    "    }\n"
	    "    else\n"
	    "        anotherBar();\n"
	    "}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabSpaces8)
{
	// test indent of 8 spaces per tab
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "        if (isFoo)\n"
	    "        {\n"
	    "                bar();\n"
	    "        }\n"
	    "        else\n"
	    "                anotherBar();\n"
	    "}\n";
	char options[] = "indent=spaces=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabSpacesShort8)
{
	// test indent of 8 spaces per tab
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "        if (isFoo)\n"
	    "        {\n"
	    "                bar();\n"
	    "        }\n"
	    "        else\n"
	    "                anotherBar();\n"
	    "}\n";
	char options[] = "s8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabTabDefault)
{
	// test default tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 8 spaces
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "	        && isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabTabDefaultShort)
{
	// test default tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 8 spaces
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "	        && isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "t";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabTab8)
{
	// test tab indent of 8 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 16 spaces
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "	                && isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "indent=tab=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabTab8Short)
{
	// test tab indent of 8 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 16 spaces
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "	                && isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "t8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabForceTabDefault)
{
	// test default force tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tabs instead of 8 spaces
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "			&& isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "indent=force-tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabForceTabDefaultShort)
{
	// test default force tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tabs instead of 8 spaces
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "			&& isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "T";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabForceTab8)
{
	// test default force tab indent of 8 spaces per tab
	// the result of this test is the same as the default option
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "			&& isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "indent=force-tab=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(TabForceTab8Short)
{
	// test default force tab indent of 8 spaces per tab
	// the result of this test is the same as the default option
	char text[] =
	    "\nvoid Foo(bool isFoo)\n"
	    "{\n"
	    "	if (isFoo\n"
	    "			&& isBar)\n"
	    "	{\n"
	    "		bar();\n"
	    "	}\n"
	    "	else\n"
	    "		anotherBar();\n"
	    "}\n";
	char options[] = "T8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

