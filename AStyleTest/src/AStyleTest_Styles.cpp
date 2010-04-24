//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//----------------------------------------------------------------------------
// AStyle C++ text for style tests
//----------------------------------------------------------------------------

struct StyleAllmanCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleAllmanCppF()
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

TEST_F(StyleAllmanCppF, AllmanOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleAllmanCppF, AnsiOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleAllmanCppF, BSDOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleAllmanCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleAllmanCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleAllmanCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleAllmanCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleAllmanCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Java Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleJavaCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleJavaCppF()
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

TEST_F(StyleJavaCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleJavaCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleJavaCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleJavaCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleJavaCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleJavaCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ K & R Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleKRCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleKRCppF()
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

TEST_F(StyleKRCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleKRCppF, LongOption1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleKRCppF, LongOption2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleKRCppF, Short)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleKRCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleKRCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleKRCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleKRCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Stroustrup Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleStroustrupCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleStroustrupCppF()
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


TEST_F(StyleStroustrupCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleStroustrupCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleStroustrupCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleStroustrupCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST_F(StyleStroustrupCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleStroustrupCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleStroustrupCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleStroustrupCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleStroustrupCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleStroustrupCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(StyleStroustrupCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleStroustrupCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Whitesmith Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleWhitesmithCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleWhitesmithCppF()
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

TEST_F(StyleWhitesmithCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleWhitesmithCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleWhitesmithCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleWhitesmithCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleWhitesmithCpp, SwitchBlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Banner Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleBannerCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleBannerCppF()
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

TEST_F(StyleBannerCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleBannerCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleBannerCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleBannerCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleBannerCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(StyleBannerCpp, SwitchBlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Gnu Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleGnuCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleGnuCppF()
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

TEST_F(StyleGnuCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleGnuCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleGnuCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleGnuCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleGnuCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Linux Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleLinuxCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleLinuxCppF()
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

TEST_F(StyleLinuxCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleLinuxCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleLinuxCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleLinuxCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleLinuxCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleLinuxCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ Horstmann Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StyleHorstmannCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StyleHorstmannCppF()
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

TEST_F(StyleHorstmannCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(StyleHorstmannCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleHorstmannCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StyleHorstmannCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(StyleHorstmannCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(StyleHorstmannCpp, SwitchBlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C++ 1TBS Style
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct Style1TBSCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	Style1TBSCppF()
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

TEST_F(Style1TBSCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style1TBSCppF, Alt)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style1TBSCppF, Short)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style1TBSCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style1TBSCppF, BlockIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style1TBSCppF, BracketIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, SpaceIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, Tab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, TabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, ForceTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, ForceTabIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, MinConditionalIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, MinConditionalIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Style1TBSCpp, AddOneLineBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Other Style tests
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct StylePrecedenceCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	StylePrecedenceCppF()
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

TEST_F(StylePrecedenceCppF, IndentBlocks_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StylePrecedenceCppF, Horstmann_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StylePrecedenceCppF, Horstmann_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(StylePrecedenceCppF, 1TBS_AddOneLineBrackets)
{
	// add-one-line-brackets implies keep-one-line-blocks
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
		"        { anotherBar(); }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";;
	char options[] = "style=1tbs, add-one-line-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Java Files
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct Style_Java : public ::testing::Test
{
	string textStr;
	const char* textIn;

	Style_Java()
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

TEST_F(Style_Java, Allman)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, Java)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, KR)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, Stroustrup)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, Whitesmith)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, Banner)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, Gnu)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(Style_Java, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Java, 1TBS)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle C# Files
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

struct Style_Sharp : public ::testing::Test
{
	string textStr;
	const char* textIn;

	Style_Sharp()
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

TEST_F(Style_Sharp, Allman)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, Java)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, KR)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, Stroustrup)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, Whitesmith)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, Banner)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, Gnu)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(Style_Sharp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(Style_Sharp, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(Style_Sharp, 1TBS)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
