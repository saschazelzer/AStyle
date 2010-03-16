//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// AStyle C++ text for style tests
//----------------------------------------------------------------------------

struct cppStyleText
{
	string textStr;
	const char* textIn;

	cppStyleText()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo)\n"
			"    {\n"
			"        bar();\n"
			"    }\n"
			"    else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";

		textIn = textStr.c_str();
	}
};

//----------------------------------------------------------------------------
// AStyle C++ Allman Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleAllman)
{
	// test allman style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=allman";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleAllman_Ansi)
{
	// test allman style ANSI option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=ansi";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleAllman_BSD)
{
	// test allman style BSD option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=bsd";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleAllman_Short)
{
	// test allman style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A1";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleAllman_Brackets)
{
	// test allman style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=allman, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleAllman_BlockIndent)
{
	// test allman style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=allman, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleAllman_BracketIndent)
{
	// test allman style option with indent brackets
	// brackets should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=allman, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_SpaceIndent)
{
	// test allman style with space indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"      if (isFoo\n"
		"                  && isBar)\n"
		"      {\n"
		"            bar();\n"
		"      }\n"
		"      else\n"
		"            anotherBar();\n"
		"}\n";
	char options[] = "style=allman, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_Tab)
{
	// test allman style with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
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
	char options[] = "style=allman, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_TabIndent)
{
	// test allman style with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	            && isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=allman, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_ForceTab)
{
	// test allman style with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
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
	char options[] = "style=allman, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_ForceTabIndent)
{
	// test allman style with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
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
	char options[] = "style=allman, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_MinConditionalIndent1)
{
	// allman should use a default setting of MINCOND_TWO
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "style=allman";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleAllman_MinConditionalIndent2)
{
	// test allman style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"        && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "style=allman, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Java Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleJava)
{
	// test java style option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleJava_Short)
{
	// test java style short option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A2";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleJava_Brackets)
{
	// test java style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=java, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleJava_BlockIndent)
{
	// test java style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=java, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleJava_BracketIndent)
{
	// test java style option with indent brackets
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=java, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_SpaceIndent)
{
	// test java style option with space indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"      if (isFoo\n"
		"                  && isBar) {\n"
		"            bar();\n"
		"      } else\n"
		"            anotherBar();\n"
		"}\n";
	char options[] = "style=java, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_Tab)
{
	// test java style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"	        && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=java, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_TabIndent)
{
	// test java style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"	            && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=java, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_ForceTab)
{
	// test java style option with force tab
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=java, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_ForceTabIndent)
{
	// test java style option with force tab
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=java, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_MinConditionalIndent1)
{
	// java should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo\n"
		"            && isBar) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "style=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleJava_MinConditionalIndent2)
{
	// test java style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo\n"
		"        && isBar) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "style=java, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ K & R Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleKR)
{
	// test k&r style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=kr";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleKR_Alt1)
{
	// test k&r style alternate kr option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=k&r";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleKR_Alt2)
{
	// test k&r style alternate k/r option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=k/r";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleKR_Short)
{
	// test k&r style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A3";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleKR_Brackets)
{
	// test k&r style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=kr, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleKR_BlockIndent)
{
	// test k&r style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=kr, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleKR_BracketIndent)
{
	// test k&r style option with indent brackets
	// brackets shoud NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=kr, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_SpaceIndent)
{
	// test k&r style option with space indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"      if (isFoo\n"
		"                  && isBar) {\n"
		"            bar();\n"
		"      } else\n"
		"            anotherBar();\n"
		"}\n";
	char options[] = "style=kr, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_Tab)
{
	// test k&r style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	        && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=kr, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_TabIndent)
{
	// test k&r style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	            && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=kr, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_ForceTab)
{
	// test k&r style option with force tab
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=kr, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_ForceTabIndent)
{
	// test k&r style option with force tab
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=kr, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_MinConditionalIndent1)
{
	// k&r should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "style=kr";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleKR_MinConditionalIndent2)
{
	// test k&r style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"        && isBar) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "style=kr, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Stroustrup Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleStroustrup)
{
	// test stroustrup style option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"     bool var1;\n"
		"     void func1();\n"
		"protected:\n"
		"     bool var2;\n"
		"     void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleStroustrup_Short)
{
	// test stroustrup style short option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"     bool var1;\n"
		"     void func1();\n"
		"protected:\n"
		"     bool var2;\n"
		"     void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A4";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleStroustrup_Brackets)
{
	// test stroustrup style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"     bool var1;\n"
		"     void func1();\n"
		"protected:\n"
		"     bool var2;\n"
		"     void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=stroustrup, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleStroustrup_BlockIndent)
{
	// test stroustrup style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"     bool var1;\n"
		"     void func1();\n"
		"protected:\n"
		"     bool var2;\n"
		"     void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=stroustrup, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST_FIXTURE(cppStyleText, CppStyleStroustrup_BracketIndent)
{
	// test stroustrup style option with indent brackets
	// brackets should NOT be indented
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"private:\n"
		"     bool var1;\n"
		"     void func1();\n"
		"protected:\n"
		"     bool var2;\n"
		"     void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=stroustrup, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleStroustrup_SpaceIndent)
{
	// test stroustrup style option with space indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"      if (isFoo\n"
		"                  && isBar) {\n"
		"            bar();\n"
		"      } else\n"
		"            anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleStroustrup_Tab)
{
	// test stroustrup style option with tab indent
	// default indent is 5
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	          && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleStroustrup_TabIndent)
{
	// test stroustrup style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	            && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleStroustrup_ForceTab)
{
	// test stroustrup style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleStroustrup_ForceTabIndent)
{
	// test stroustrup style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(CppStyleStroustrup_MinConditionalIndent1)
{
	// stroustrup should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo\n"
		"               && isBar) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleStroustrup_MinConditionalIndent2)
{
	// test stroustrup style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"     if (isFoo\n"
		"         && isBar) {\n"
		"          bar();\n"
		"     } else\n"
		"          anotherBar();\n"
		"}\n";
	char options[] = "style=stroustrup, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Whitesmith Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleWhitesmith)
{
	// test whitesmith style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"    {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"    {\n"
		"    if (isFoo)\n"
		"        {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=whitesmith";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleWhitesmith_Short)
{
	// test whitesmith style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"    {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"    {\n"
		"    if (isFoo)\n"
		"        {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A5";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleWhitesmith_Brackets)
{
	// test whitesmith style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"    {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"    {\n"
		"    if (isFoo)\n"
		"        {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=whitesmith, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleWhitesmith_BlockIndent)
{
	// test whitesmith style option with indent-blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"    {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"    {\n"
		"    if (isFoo)\n"
		"        {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=whitesmith, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_SpaceIndent)
{
	// test whitesmith style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"      {\n"
		"      if (isFoo\n"
		"                  && isBar)\n"
		"            {\n"
		"            bar();\n"
		"            }\n"
		"      else\n"
		"            anotherBar();\n"
		"      }\n";
	char options[] = "style=whitesmith, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_Tab)
{
	// test whitesmith style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"	{\n"
		"	if (isFoo\n"
		"	        && isBar)\n"
		"		{\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=whitesmith, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_TabIndent)
{
	// test whitesmith style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"	{\n"
		"	if (isFoo\n"
		"	            && isBar)\n"
		"		{\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=whitesmith, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_ForceTab)
{
	// test whitesmith style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"	{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"		{\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=whitesmith, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_ForceTabIndent)
{
	// test whitesmith style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"	{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"		{\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=whitesmith, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_MinConditionalIndent1)
{
	// whitesmith should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"    {\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"        {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n";
	char options[] = "style=whitesmith";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_MinConditionalIndent2)
{
	// test whitesmith style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"    {\n"
		"    if (isFoo\n"
		"        && isBar)\n"
		"        {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n";
	char options[] = "style=whitesmith, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleWhitesmith_SwitchBlockIndent)
{
	// test whitesmith style with switch blocks
	char text[] =
		"\nvoid Foo(int fooBar)\n"
		"    {\n"
		"    switch (fooBar)\n"
		"        {\n"
		"        case 1:\n"
		"            fooBar = 1;\n"
		"            break;\n"
		"        case 2:\n"
		"            {\n"
		"            fooBar = 2;\n"
		"            }\n"
		"        break;\n"
		"        default:\n"
		"            break;\n"
		"        }\n"
		"    int bar = true;\n"
		"    }\n";
	char options[] = "style=whitesmith";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Banner Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleBanner)
{
	// test banner style option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=banner";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleBanner_Short)
{
	// test banner style short option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleBanner_BracketIndent)
{
	// test banner style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=banner, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleBanner_BlockIndent)
{
	// test banner style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"class FooClass {\n"
		"    private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=banner, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_SpaceIndent)
{
	// test banner style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"      if (isFoo\n"
		"                  && isBar) {\n"
		"            bar();\n"
		"            }\n"
		"      else\n"
		"            anotherBar();\n"
		"      }\n";
	char options[] = "style=banner, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_Tab)
{
	// test banner style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"	        && isBar) {\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=banner, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_TabIndent)
{
	// test banner style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"	            && isBar) {\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=banner, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_ForceTab)
{
	// test banner style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=banner, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_ForceTabIndent)
{
	// test banner style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"	}\n";
	char options[] = "style=banner, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_MinConditionalIndent1)
{
	// banner should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo\n"
		"            && isBar) {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n";
	char options[] = "style=banner";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleBanner_MinConditionalIndent2)
{
	// test banner style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo\n"
		"        && isBar) {\n"
		"        bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n";
	char options[] = "style=banner, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(CppStyleBanner_SwitchBlockIndent)
{
	// test banner style with switch blocks
	char text[] =
		"\nvoid Foo(int fooBar) {\n"
		"    switch (fooBar) {\n"
		"        case 1:\n"
		"            fooBar = 1;\n"
		"            break;\n"
		"        case 2: {\n"
		"            fooBar = 2;\n"
		"            }\n"
		"        break;\n"
		"        default:\n"
		"            break;\n"
		"        }\n"
		"    int bar = true;\n"
		"    }\n";
	char options[] = "style=banner";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Gnu Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleGnu)
{
	// test gnu style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"  bool var1;\n"
		"  void func1();\n"
		"protected:\n"
		"  bool var2;\n"
		"  void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"  if (isFoo)\n"
		"    {\n"
		"      bar();\n"
		"    }\n"
		"  else\n"
		"    anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=gnu";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleGnu_Short)
{
	// test gnu style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"  bool var1;\n"
		"  void func1();\n"
		"protected:\n"
		"  bool var2;\n"
		"  void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"  if (isFoo)\n"
		"    {\n"
		"      bar();\n"
		"    }\n"
		"  else\n"
		"    anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A7";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleGnu_Brackets)
{
	// test gnu style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"  bool var1;\n"
		"  void func1();\n"
		"protected:\n"
		"  bool var2;\n"
		"  void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"  if (isFoo)\n"
		"    {\n"
		"      bar();\n"
		"    }\n"
		"  else\n"
		"    anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=gnu, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleGnu_BracketIndent)
{
	// test gnu style option with indent brackets
	// brackets should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"  bool var1;\n"
		"  void func1();\n"
		"protected:\n"
		"  bool var2;\n"
		"  void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"  if (isFoo)\n"
		"    {\n"
		"      bar();\n"
		"    }\n"
		"  else\n"
		"    anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=gnu, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_SpaceIndent)
{
	// test gnu style option with space indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"   if (isFoo\n"
		"         && isBar)\n"
		"      {\n"
		"         bar();\n"
		"      }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n";
	char options[] = "style=gnu, indent=spaces=3";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_Tab)
{
	// test gnu style option with tab indent
	// default indent is 2
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	    && isBar)\n"
		"		{\n"
		"			bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=gnu, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_TabIndent)
{
	// test gnu style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	      && isBar)\n"
		"		{\n"
		"			bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=gnu, indent=tab=3";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_ForceTab)
{
	// test gnu style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"		{\n"
		"			bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=gnu, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_ForceTabIndent)
{
	// test gnu style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"		{\n"
		"			bar();\n"
		"		}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=gnu, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_MinConditionalIndent1)
{
	// gnu should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"  if (isFoo\n"
		"      && isBar)\n"
		"    {\n"
		"      bar();\n"
		"    }\n"
		"  else\n"
		"    anotherBar();\n"
		"}\n";
	char options[] = "style=gnu";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleGnu_MinConditionalIndent2)
{
	// test gnu style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"  if (isFoo\n"
		"      && isBar)\n"
		"    {\n"
		"      bar();\n"
		"    }\n"
		"  else\n"
		"    anotherBar();\n"
		"}\n";
	char options[] = "style=gnu, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Linux Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleLinux)
{
	// test linux style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleLinux_Short)
{
	// test linux style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A8";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleLinux_Brackets)
{
	// test linux style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=linux, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleLinux_BlockIndent)
{
	// test linux style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=linux, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleLinux_BracketIndent)
{
	// test linux style option with indent brackets
	// brackets should not be broken
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=linux, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_SpaceIndent)
{
	// test linux style option with space indent of 6
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"      if (isFoo\n"
		"          && isBar) {\n"
		"            bar();\n"
		"      } else\n"
		"            anotherBar();\n"
		"}\n";
	char options[] = "style=linux, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_Tab)
{
	// test linux style option with tab indent
	// default indent is 8
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	    && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=linux, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_TabIndent)
{
	// test linux style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	    && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=linux, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_ForceTab)
{
	// test linux style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	    && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=linux, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_ForceTabIndent)
{
	// test linux style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	    && isBar) {\n"
		"		bar();\n"
		"	} else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=linux, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_MinConditionalIndent1)
{
	// Linux should use a default setting of MINCOND_ONEHALF
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"                    && isBar)\n"
		"    {\n"
		"            bar();\n"
		"    }\n"
		"    else\n"
		"            anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo\n"
		"            && isBar) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n";
	char options[] = "style=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleLinux_MinConditionalIndent2)
{
	// test linux style option with min conditional indent
	// Linux should ignore setting and use MINCOND_ONEHALF
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"                    && isBar)\n"
		"    {\n"
		"            bar();\n"
		"    }\n"
		"    else\n"
		"            anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo\n"
		"            && isBar) {\n"
		"                bar();\n"
		"        } else\n"
		"                anotherBar();\n"
		"}\n";
	char options[] = "style=linux, min-conditional-indent=2";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Horstmann Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyleHorstmann)
{
	// test horstmann style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"   bool var1;\n"
		"   void func1();\n"
		"protected:\n"
		"   bool var2;\n"
		"   void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{  if (isFoo)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(cppStyleText, CppStyleHorstmann_Short)
{
	// test horstmann style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"   bool var1;\n"
		"   void func1();\n"
		"protected:\n"
		"   bool var2;\n"
		"   void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{  if (isFoo)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A9";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleHorstmann_Brackets)
{
	// test horstmann style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"   bool var1;\n"
		"   void func1();\n"
		"protected:\n"
		"   bool var2;\n"
		"   void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{  if (isFoo)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=horstmann, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyleHorstmann_BlockIndent)
{
	// test horstmann style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"   bool var1;\n"
		"   void func1();\n"
		"protected:\n"
		"   bool var2;\n"
		"   void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{  if (isFoo)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=horstmann, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(cppStyleText, CppStyleHorstmann_BracketIndent)
{
	// test horstmann style option with indent brackets
	// brackets should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"   bool var1;\n"
		"   void func1();\n"
		"protected:\n"
		"   bool var2;\n"
		"   void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{  if (isFoo)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=horstmann, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_SpaceIndent)
{
	// test horstmann style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{     if (isFoo\n"
		"                  && isBar)\n"
		"      {     bar();\n"
		"      }\n"
		"      else\n"
		"            anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_Tab)
{
	// test horstmann style option with tab indent
	// default indent is 3
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{	if (isFoo\n"
		"	      && isBar)\n"
		"	{	bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_TabIndent)
{
	// test horstmann style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{	if (isFoo\n"
		"	            && isBar)\n"
		"	{	bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_ForceTab)
{
	// test horstmann style option with force tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{	if (isFoo\n"
		"			&& isBar)\n"
		"	{	bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_ForceTabIndent)
{
	// test horstmann style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{	if (isFoo\n"
		"			&& isBar)\n"
		"	{	bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_MinConditionalIndent1)
{
	// horstmann should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{  if (isFoo\n"
		"         && isBar)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_MinConditionalIndent2)
{
	// test horstmann style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{  if (isFoo\n"
		"       && isBar)\n"
		"   {  bar();\n"
		"   }\n"
		"   else\n"
		"      anotherBar();\n"
		"}\n";
	char options[] = "style=horstmann, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyleHorstmann_SwitchBlockIndent)
{
	// test horstmann style with switch blocks
	char text[] =
		"\nvoid Foo(int fooBar)\n"
		"{  switch (fooBar)\n"
		"   {  case 1:\n"
		"         fooBar = 1;\n"
		"         break;\n"
		"      case 2:\n"
		"      {  fooBar = 2;\n"
		"      }\n"
		"      break;\n"
		"      default:\n"
		"         break;\n"
		"   }\n"
		"   int bar = true;\n"
		"}\n";
	char options[] = "style=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ 1TBS Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST_FIXTURE(cppStyleText, CppStyle1TBS)
{
	// test 1tbs style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=1tbs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyle1TBS_Alt)
{
	// test 1tbs style alternate otbs option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=otbs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyle1TBS_Short)
{
	// test 1tbs style short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-A10";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyle1TBS_Brackets)
{
	// test 1tbs style option with brackets option
	// the brackets should NOT change
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=1tbs, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyle1TBS_BlockIndent)
{
	// test 1tbs style option with indent blocks
	// blocks should NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=1tbs, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStyle1TBS_BracketIndent)
{
	// test 1tbs style option with indent brackets
	// brackets shoud NOT be indented
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=1tbs, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_SpaceIndent)
{
	// test 1tbs style option with space indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"      if (isFoo\n"
		"                  && isBar) {\n"
		"            bar();\n"
		"      } else {\n"
		"            anotherBar();\n"
		"      }\n"
		"}\n";
	char options[] = "style=1tbs, indent=spaces=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_Tab)
{
	// test 1tbs style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	        && isBar) {\n"
		"		bar();\n"
		"	} else {\n"
		"		anotherBar();\n"
		"	}\n"
		"}\n";
	char options[] = "style=1tbs, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_TabIndent)
{
	// test 1tbs style option with tab indent
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	            && isBar) {\n"
		"		bar();\n"
		"	} else {\n"
		"		anotherBar();\n"
		"	}\n"
		"}\n";
	char options[] = "style=1tbs, indent=tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_ForceTab)
{
	// test 1tbs style option with force tab
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else {\n"
		"		anotherBar();\n"
		"	}\n"
		"}\n";
	char options[] = "style=1tbs, indent=force-tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_ForceTabIndent)
{
	// test 1tbs style option with force tab
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar) {\n"
		"		bar();\n"
		"	} else {\n"
		"		anotherBar();\n"
		"	}\n"
		"}\n";
	char options[] = "style=1tbs, indent=force-tab=6";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_MinConditionalIndent1)
{
	// 1tbs should use a default setting of MINCOND_TWO
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "style=1tbs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_MinConditionalIndent2)
{
	// test 1tbs style option with min conditional indent 0
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"        && isBar) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "style=1tbs, min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppStyle1TBS_AddOneLineBrackets)
{
	// test 1tbs style option with add one line brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo\n"
		"            && isBar) {\n"
		"        bar();\n"
		"    } else\n"
		"        { anotherBar(); }\n"
		"}\n";
	char options[] = "style=1tbs, add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Other Style tests
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

TEST(CppStylePrecedence_1TBS_AddOneLineBrackets)
{
	// add-one-line-brackets implies keep-one-line-blocks
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"        { bar(); }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"        { bar(); }\n"
		"    else\n"
		"        { anotherBar(); }\n"
		"}\n";
	char options[] = "style=1tbs, add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStylePrecedence_IndentBlocks_IndentBrackets)
{
	// cannot have both block indent and bracket indent
	// default to block indent
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"    void func1();\n"
		"protected:\n"
		"    bool var2;\n"
		"    void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "indent-blocks, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStylePrecedence_Horstmann_IndentBrackets)
{
	// CAN have both horstmann brackets and bracket indent
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"    {   private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"    };\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"    {   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-brackets, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppStyleText, CppStylePrecedence_Horstmann_IndentBlocks)
{
	// CAN have both horstmann brackets and block indent
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{   private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-blocks, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Java Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct javaStyleText
{
	string textStr;
	const char* textIn;

	javaStyleText()
	{
		textStr =
			"\npublic class FooClass\n"
			"{\n"
			"    private bool var1;\n"
			"    private bool var2;\n"
			"\n"
			"    public void foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo)\n"
			"        {\n"
			"            bar();\n"
			"        }\n"
			"        else\n"
			"            anotherBar();\n"
			"    }\n"
			"}\n";

		textIn = textStr.c_str();
	}
};

TEST_FIXTURE(javaStyleText, JavaStyleAllman)
{
	// test allman style option
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"        else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n";

	char options[] = "style=allman, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleJava)
{
	// test java style option
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n";

	char options[] = "style=java, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleKR)
{
	// test k&r style option
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n";

	char options[] = "style=kr, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleStroustrup)
{
	// test stroustrup style option
	char text[] =
		"\npublic class FooClass {\n"
		"     private bool var1;\n"
		"     private bool var2;\n"
		"\n"
		"     public void foo(bool isFoo)\n"
		"     {\n"
		"          if (isFoo) {\n"
		"               bar();\n"
		"          } else\n"
		"               anotherBar();\n"
		"     }\n"
		"}\n";

	char options[] = "style=stroustrup, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleWhitesmith)
{
	// test whitesmith style option
	char text[] =
		"\npublic class FooClass\n"
		"    {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"        {\n"
		"        if (isFoo)\n"
		"            {\n"
		"            bar();\n"
		"            }\n"
		"        else\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n";

	char options[] = "style=whitesmith, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleBanner)
{
	// test banner style option
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"            }\n"
		"        else\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n";

	char options[] = "style=banner, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleGnu)
{
	// test gnu style option
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"  private bool var1;\n"
		"  private bool var2;\n"
		"\n"
		"  public void foo(bool isFoo)\n"
		"  {\n"
		"    if (isFoo)\n"
		"      {\n"
		"        bar();\n"
		"      }\n"
		"    else\n"
		"      anotherBar();\n"
		"  }\n"
		"}\n";

	char options[] = "style=gnu, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(javaStyleText, JavaStyleLinux)
{
	// test linux style option
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {\n"
		"                if (isFoo) {\n"
		"                        bar();\n"
		"                } else\n"
		"                        anotherBar();\n"
		"        }\n"
		"}\n";

	char options[] = "style=linux, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyleHorstmann)
{
	// test horstmann style option
	char text[] =
		"\npublic class FooClass\n"
		"{  private bool var1;\n"
		"   private bool var2;\n"
		"\n"
		"   public void foo(bool isFoo)\n"
		"   {  if (isFoo)\n"
		"      {  bar();\n"
		"      }\n"
		"      else\n"
		"         anotherBar();\n"
		"   }\n"
		"}\n";

	char options[] = "style=horstmann, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaStyleText, JavaStyle1TBS)
{
	// test 1tbs style option
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "style=1tbs, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C# Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct sharpStyleText
{
	string textStr;
	const char* textIn;

	sharpStyleText()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public class FooClass\n"
			"{\n"
			"    private bool var1;\n"
			"    private bool var2;\n"
			"\n"
			"    public void foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo)\n"
			"        {\n"
			"            bar();\n"
			"        }\n"
			"        else\n"
			"            anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";

		textIn = textStr.c_str();
	}
};

TEST_FIXTURE(sharpStyleText, SharpStyleAllman)
{
	// test allman style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"        else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=allman, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleJava)
{
	// test java style option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=java, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleKR)
{
	// test k&r style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=kr, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleStroustrup)
{
	// test stroustrup style option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public class FooClass {\n"
		"     private bool var1;\n"
		"     private bool var2;\n"
		"\n"
		"     public void foo(bool isFoo)\n"
		"     {\n"
		"          if (isFoo) {\n"
		"               bar();\n"
		"          } else\n"
		"               anotherBar();\n"
		"     }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=stroustrup, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleWhitesmith)
{
	// test whitesmith style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"    {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"        {\n"
		"        if (isFoo)\n"
		"            {\n"
		"            bar();\n"
		"            }\n"
		"        else\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=whitesmith, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleBanner)
{
	// test banner style option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"            }\n"
		"        else\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=banner, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleGnu)
{
	// test gnu style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"{\n"
		"  private bool var1;\n"
		"  private bool var2;\n"
		"\n"
		"  public void foo(bool isFoo)\n"
		"  {\n"
		"    if (isFoo)\n"
		"      {\n"
		"        bar();\n"
		"      }\n"
		"    else\n"
		"      anotherBar();\n"
		"  }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=gnu, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpStyleText, SharpStyleLinux)
{
	// test linux style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"{\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {\n"
		"                if (isFoo) {\n"
		"                        bar();\n"
		"                } else\n"
		"                        anotherBar();\n"
		"        }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpStyleText, SharpStyleHorstmann)
{
	// test horstmann style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"{  private bool var1;\n"
		"   private bool var2;\n"
		"\n"
		"   public void foo(bool isFoo)\n"
		"   {  if (isFoo)\n"
		"      {  bar();\n"
		"      }\n"
		"      else\n"
		"         anotherBar();\n"
		"   }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "style=horstmann, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpStyleText, SharpStyle1TBS)
{
	// test 1tbs style option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";

	char options[] = "style=1tbs, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
