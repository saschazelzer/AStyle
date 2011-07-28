//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//-------------------------------------------------------------------------
// AStyle Break Closing Brackets
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(BreakClosingBrackets, LongOption)
{
	// test NONE_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, ShortOption)
{
	// test NONE_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "-y";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Break)
{
	// test BREAK_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=break, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Attach)
{
	// test ATTACH_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=attach, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Linux)
{
	// test LINUX_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=linux, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Stroustrup)
{
	// test STROUSTRUP_MODE brackets with break closing headers
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=stroustrup, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, KeepBlocks)
{
	// test break closing headers with keep one line blocks
	// it shouldn't make any difference
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=attach, break-closing-brackets, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, ElseSans)
{
	// test if/else without break closing brackets
	// else statement should be attached to the closing bracket
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"    else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, Catch)
{
	// test try/catch with break closing brackets
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    } catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    }\n"
		"    catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, CatchSans)
{
	// test try/catch without break closing brackets
	// catch statement should be attached to the closing bracket
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    }\n"
		"    catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    try {\n"
		"        bar();\n"
		"    } catch (int i) {\n"
		"        cout << i << endl;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, While)
{
	// test do/while with break closing brackets
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    } while (int x < 9);\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (int x < 9);\n"
		"}\n";
	char options[] = "brackets=attach, break-closing-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBrackets, WhileSans)
{
	// test do/while without break closing brackets
	// while statement should be attached to the closing bracket
	char textIn[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (int x < 9);\n"
		"}\n";
	char text[] =
		"\nvoid FooClass::Foo(bool isFoo) {\n"
		"    do {\n"
		"        bar();\n"
		"    } while (int x < 9);\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Break Else If
//-------------------------------------------------------------------------

TEST(BreakElseIfs, LongOption)
{
	// test break else/if
	// else/if statements should be broken
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        } else\n"
		"            if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char options[] = "break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, ShortOption)
{
	// test break else/if short options
	// else/if statements should be broken
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        } else\n"
		"            if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char options[] = "-e";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, Sans)
{
	// test without break else/if
	// else/if statements should be joined
	// but do NOT join #else
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else if (isBar) {\n"
		"        anotherBar();\n"
		"    } else    if (isBar) {\n"
		"        anotherBar();\n"
		"    } else {\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfs, KeepOneLine)
{
	// test break else/if with keep one line statements
	// else/if statements remain the same with breaking/attaching
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"            } else    if (isBar) {\n"
		"                anotherBar();\n"
		"            } else {\n"
		"                if (isBar) {\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else\n"
		"        if (isBar) {\n"
		"            anotherBar();\n"
		"        } else    if (isBar) {\n"
		"            anotherBar();\n"
		"        } else {\n"
		"            if (isBar) {\n"
		"                anotherBar();\n"
		"            }\n"
		"        }\n"
		"\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else anotherBar();\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"\n"
		"#if 0\n"
		"    foo();\n"
		"#else\n"
		"    if (bar)\n"
		"        fooBar();\n"
		"#endif\n"
		"}\n";
	char options[] = "break-elseifs, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Keep One Line Statements
//-------------------------------------------------------------------------

TEST(KeepOneLineStatements, LongOption)
{
	// test keep one line statements
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        isFoo=false; isBar=true;\n"
		"    }\n"
		"}\n";
	char options[] = "keep-one-line-statements";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatements, ShortOption)
{
	// // test keep one line statements short option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        isFoo=false; isBar=true;\n"
		"    }\n"
		"}\n";
	char options[] = "-o";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Keep One Line Blocks
//-------------------------------------------------------------------------

TEST(KeepOneLineBlocks, LongOption)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; i=i-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, ShortOption)
{
	// test keep one line blocks short option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; i=i-10; }\n"
		"}\n";
	char options[] = "-O";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, StartOfLine)
{
	// line beginning with one-line blocks do NOT get a extra indent
	char text[] =
		"\nclass Foo\n"
		"{\n"
		"public:\n"
		"    int getFoo() const\n"
		"    { return isFoo; }\n"
		"};\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, NoneBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, AttachBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo() {\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(KeepOneLineBlocks, LinuxBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, RunInBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{   if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakElseIf)
{
	// test keep one line blocks and break elseifs
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; if (i) i=i-10; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j)\n"
		"    { j=1; if (i) i=i-10; }\n"
		"    if (!j)\n"
		"    { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j)\n"
		"    { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, KeepOneLineStatementsAndBreakElseIf)
{
	// test keep one line blocks and keep one line statements
	//     with if statement and break elseifs
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; if (i) i=i-10; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j) { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, keep-one-line-statements, break-elseifs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, MultipleBrackets)
{
	// test keep one line blocks with multiple brackets
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public string FooName { get { return Foo; } set { Foo = value; } }\n"
		"\n"
		"    public event EventHandler Cancelled { add { } remove { } }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, Sans1)
{
	// test without keep one line blocks
	// should not break {} when break brackets
	char text[] =
		"\nclass JipeConsole\n"
		"{\n"
		"    public JipeConsole(Jipe parent)\n"
		"    {\n"
		"        jipeConsole.addKeyListener(new KeyListener()\n"
		"        {\n"
		"            public void keyReleased(KeyEvent e) {}\n"
		"            public void keyTyped(KeyEvent e) {}\n"
		"        });\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, Sans2)
{
	// test without keep one line blocks
	// test attach bracket inside comment on single line block
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())     // comment\n"
		"        { return false; }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {   // comment\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, SansMultipleBrackets)
{
	// test without keep one line blocks with multiple brackets
	char textIn[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public string FooName { get { return Foo; } set { Foo = value; } }\n"
		"\n"
		"    public event EventHandler Cancelled { add { } remove { } }\n"
		"}\n";
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public string FooName {\n"
		"        get {\n"
		"            return Foo;\n"
		"        }\n"
		"        set {\n"
		"            Foo = value;\n"
		"        }\n"
		"    }\n"
		"\n"
		"    public event EventHandler Cancelled {\n"
		"        add { } remove { }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, NoneRunIn)
{
	// test none brackets with keep one line blocks and run-in
	// should not indent the run-in
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, RunInRunIn)
{
	// test run-in brackets with keep one line blocks and run-in
	// should not indent the run-in
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, NoneClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, BreakClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, AttachClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, LinuxClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentSwitchBlock)
{
	// test one-line blocks with switch blocks
	char text[] =
		"\nvoid Foo(int fooBar)\n"
		"{\n"
		"    switch (fooBar)\n"
		"    {\n"
		"    case 1:\n"
		"        fooBar = 1;\n"
		"        break;\n"
		"    case 2:\n"
		"    { fooBar = 2; }\n"
		"    break;\n"
		"    default:\n"
		"    { break; }\n"
		"    }\n"
		"    int bar = true;\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentSwitchBlock_IndentSwitches)
{
	// test one-line blocks with indented switch blocks
	char text[] =
		"\nvoid Foo(int fooBar)\n"
		"{\n"
		"    switch (fooBar)\n"
		"    {\n"
		"        case 1:\n"
		"            fooBar = 1;\n"
		"            break;\n"
		"        case 2:\n"
		"        { fooBar = 2; }\n"
		"        break;\n"
		"        default:\n"
		"        { break; }\n"
		"    }\n"
		"    int bar = true;\n"
		"}\n";
	char options[] = "keep-one-line-blocks, indent-switches";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentAfterHeader)
{
	// test one line blocks indentation following a header
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    { bar(); }\n"
		"    else\n"
		"    { anotherBar(); }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentAfterHeaderSansBrackets)
{
	// Test one line blocks indentation following a header
	// when the header does not contain brackets.
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isBar1)\n"
		"        if (isBar2)\n"
		"        { return true; }\n"
		"\n"
		"    if (isBar1)\n"
		"        if (isBar2) { return true; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocks, IndentSansHeader)
{
	// test one line blocks indentation withouta header
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    bar()\n"
		"    { anotherBar(); }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(KeepOneLineBlocks, IndentWithConstMethod)
{
	// Test one line blocks indentation following a header
	// when the header does not contain brackets.
	char text[] =
		"\nclass FooClass\n"
		"{\n"
		"    virtual bool foo() const\n"
		"    { return false; }\n"
		"};\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Add Brackets
//-------------------------------------------------------------------------

TEST(AddBrackets, LongOption)
{
	// test add brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ShortOption)
{
	// test add brackets short option
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "-j";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(AddBrackets, All)
{
	// test add brackets for all headers
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo)\n"
		"        bar();\n"
		"\n"
		"    do\n"
		"        bar();\n"
		"    while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else {\n"
		"        return true;\n"
		"    }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) {\n"
		"        bar &= ::FooBar();\n"
		"    }\n"
		"\n"
		"    while (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ElseIf)
{
	// test add brackets for "else if" statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, SemiFollows)
{
	// test add brackets when a semi-colon follows the statement
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ; func1(); i++;\n"
		"    while (isFoo)  // comment\n"
		"            ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ;\n"
		"    func1();\n"
		"    i++;\n"
		"    while (isFoo)  // comment\n"
		"        ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Sharp)
{
	// test add brackets to C# headers
	// 'delegate' statement contans brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray)\n"
		"        System.Console.WriteLine(i);\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray) {\n"
		"        System.Console.WriteLine(i);\n"
		"    }\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate {\n"
		"        fooBar* = null;\n"
		"    });\n"
		"}\n";
	char options[] = "add-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, KeepOneLiners)
{
	// add brackets with keep one liners
	// should break the added brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo)\n"
		"        bar();\n"
		"\n"
		"    do\n"
		"        bar();\n"
		"        while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else {\n"
		"        return true;\n"
		"    }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) {\n"
		"        bar &= ::FooBar();\n"
		"    }\n"
		"\n"
		"    while (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets, keep-one-line-blocks, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, SingleLine)
{
	// add brackets to one line statements
	// should break the statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    }\n"
		"    else {\n"
		"        return true;\n"
		"    }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) {\n"
		"        bar &= ::FooBar();\n"
		"    }\n"
		"\n"
		"    while (isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"\n"
		"    do {\n"
		"        bar();\n"
		"    }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, SingleLineKeepOneLiners)
{
	// add brackets to one line statements with keep one liners
	// should keep one line blocks with added brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) { return false; }\n"
		"\n"
		"    if (isFoo()) { return false; } else { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo) { bar(); }\n"
		"\n"
		"    do { bar(); } while (isFoo);\n"
		"}\n";
	char options[] = "add-brackets, keep-one-line-blocks, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Break)
{
	// test add brackets for broken brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    {\n"
		"        return false;\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        return true;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Attach)
{
	// test add brackets for attached brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) {\n"
		"        return false;\n"
		"    } else {\n"
		"        return true;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets, brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, RunIn)
{
	// test add brackets for run-in brakets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo())\n"
		"    {   return false;\n"
		"    }\n"
		"    else\n"
		"    {   return true;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ExtraSpaces)
{
	// extra spaces should be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str )   (*str) += \"<?xml \";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str ) {\n"
		"        (*str) += \"<?xml \";\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, ElseParen)
{
	// else statement with following paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) break;\n"
		"    else (numBar)--;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) {\n"
		"        break;\n"
		"    }\n"
		"    else {\n"
		"        (numBar)--;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Quote)
{
	// must bypass quote with semi-colons and escaped quote marks
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = '\\'';\n"
		"    if (isFoo) bar = '\\\\';\n"
		"    if (isBar) bar = \";;version=\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar = '\\'';\n"
		"    }\n"
		"    if (isFoo) {\n"
		"        bar = '\\\\';\n"
		"    }\n"
		"    if (isBar) {\n"
		"        bar = \";;version=\";\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, QuoteSans)
{
	// must bypass multi-line quote
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"        char* bar = \"one \\\n"
		"  two \\\n"
		"      three\";\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Comment)
{
	// must bypass comment before a semi-colon
	// the last statement should be bracketed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment */ foo2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) {\n"
		"        bar = /* comment */ foo2;\n"
		"    }\n"
		"}\n";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddBrackets, Sans)
{
	// brackets should be added to specified headers only
	char text[] =
		"\npublic unsafe int foo()\n"
		"{\n"
		"    int readCount;\n"
		"    fixed(byte* pBuffer = buffer)\n"
		"        readCount = ReadMemory(size);\n"
		"}\n";
	char options[] = "add-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Add One Line Brackets
// Implies keep-one-line-blocks
//-------------------------------------------------------------------------

TEST(AddOneLineBrackets, LongOption)
{
	// test add one line brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ShortOption)
{
	// test add one line brackets short option
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"}\n";
	char options[] = "-J";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(AddOneLineBrackets, All)
{
	// test add one line brackets for all headers
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo)\n"
		"        bar();\n"
		"\n"
		"    do\n"
		"        bar();\n"
		"    while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"    { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo)\n"
		"    { bar(); }\n"
		"\n"
		"    do\n"
		"    { bar(); }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ElseIf)
{
	// test add one line brackets for "else if" statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else if (isFoo())\n"
		"        return false;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else if (isFoo())\n"
		"    { return false; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, SemiFollows)
{
	// test add brackets when a semi-colon follows the statement
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ; func1(); i++;\n"
		"    while (isFoo)  // comment\n"
		"            ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a == 0) ;\n"
		"    func1();\n"
		"    i++;\n"
		"    while (isFoo)  // comment\n"
		"        ;\n"
		"    while (isFoo); // comment\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Sharp)
{
	// test add one line brackets to C# headers
	// 'delegate' statement contans brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray)\n"
		"        System.Console.WriteLine(i);\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    foreach (int i in fibarray)\n"
		"    { System.Console.WriteLine(i); }\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char options[] = "add-one-line-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, SingleLine)
{
	// add one line brackets to one line statements
	// should keep the one line statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) { return false; }\n"
		"\n"
		"    if (isFoo()) { return false; }\n"
		"    else { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo) { bar(); }\n"
		"\n"
		"    do { bar(); }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, SingleLineKeepOneLiners)
{
	// add one line brackets to one line statements with keep one liners
	// should keep the one liners (keep blocks is implied)
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) return false;\n"
		"\n"
		"    if (isFoo()) return false; else return true;\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) bar &= ::FooBar();\n"
		"\n"
		"    while (isFoo) bar();\n"
		"\n"
		"    do bar(); while (isFoo);\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo()) { return false; }\n"
		"\n"
		"    if (isFoo()) { return false; } else { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i) { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo) { bar(); }\n"
		"\n"
		"    do { bar(); } while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Break)
{
	// test add one line brackets for broken brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Attach)
{
	// test add one line brackets for attached brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, RunIn)
{
	// test add one line brackets for run-in brakets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        return false;\n"
		"    else\n"
		"        return true;\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo())\n"
		"    { return false; }\n"
		"    else\n"
		"    { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ExtraSpaces)
{
	// extra spaces should not be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str )   (*str) += \"<?xml \";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( str )   { (*str) += \"<?xml \"; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, ElseParen)
{
	// else statement with following paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) break;\n"
		"    else (numBar)--;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { break; }\n"
		"    else { (numBar)--; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Quote)
{
	// must bypass quote with semi-colons and escaped quote marks
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = '\\'';\n"
		"    if (isFoo) bar = '\\\\';\n"
		"    if (isBar) bar = \";;version=\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { bar = '\\''; }\n"
		"    if (isFoo) { bar = '\\\\'; }\n"
		"    if (isBar) { bar = \";;version=\"; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, QuoteSans)
{
	// must bypass multi-line quote
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"        char* bar = \"one \\\n"
		"  two \\\n"
		"      three\";\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Comment)
{
	// must bypass comment before a semi-colon
	// the last statement should be bracketed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment */ foo2;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) bar = // comment\n"
		"            foo2;\n"
		"    if (isFoo) bar =  /* comment */\n"
		"            foo2;\n"
		"    if (isFoo) bar = /* comment\n"
		"                        comment */\n"
		"            foo2;\n"
		"    if (isFoo) { bar = /* comment */ foo2; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBrackets, Sans)
{
	// brackets should be added to specified headers only
	char text[] =
		"\npublic unsafe int foo()\n"
		"{\n"
		"    int readCount;\n"
		"    fixed(byte* pBuffer = buffer)\n"
		"        readCount = ReadMemory(size);\n"
		"}\n";
	char options[] = "add-one-line-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Convert Tabs
//-------------------------------------------------------------------------

TEST(ConvertTabs, LongOption)
{
	// test convert tabs
	char textIn[] =
		"\nstatic FooBar foo1[] =\n"
		"{\n"
		"    { 10000,	0,		9 },\n"
		"    { 20000, 	0, 		9 },\n"
		"    { 30000,  	0,  	9 },\n"
		"    { 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar foo2[] =\n"
		"{\n"
		"	{ 10000,	0,		9 },\n"
		"	{ 20000, 	0, 		9 },\n"
		"	{ 30000,  	0,  	9 },\n"
		"	{ 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar foo3[] =\n"
		"{\n"
		"	{ 10000,	0,		9 },\n"
		" 	{ 20000, 	0, 		9 },\n"
		"  	{ 30000,  	0,  	9 },\n"
		"   	{ 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar foo4[] =\n"
		"{\n"
		"	{ 100,  	0,		9 },\n"
		" 	{ 200,   	0, 		9 },\n"
		"  	{ 300,    	0,  	9 },\n"
		"   	{ 400,     	0,   	9 },\n"
		"};\n";
	char text[] =
		"\nstatic FooBar foo1[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar foo2[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar foo3[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar foo4[] =\n"
		"{\n"
		"    { 100,      0,      9 },\n"
		"    { 200,      0,      9 },\n"
		"    { 300,      0,      9 },\n"
		"    { 400,      0,      9 },\n"
		"};\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, ShortOption)
{
	// test convert tabs short option
	char textIn[] =
		"\nstatic FooBar foo[] =\n"
		"{\n"
		"    { 10000,	0,		9 },\n"
		"    { 20000, 	0, 		9 },\n"
		"    { 30000,  	0,  	9 },\n"
		"    { 40000,   	0,   	9 },\n"
		"};\n"
		"\n"
		"static FooBar fooTab[] =\n"
		"{\n"
		"	{ 10000,	0,		9 },\n"
		"	{ 20000, 	0, 		9 },\n"
		"	{ 30000,  	0,  	9 },\n"
		"	{ 40000,   	0,   	9 },\n"
		"}\n";
	char text[] =
		"\nstatic FooBar foo[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"};\n"
		"\n"
		"static FooBar fooTab[] =\n"
		"{\n"
		"    { 10000,    0,      9 },\n"
		"    { 20000,    0,      9 },\n"
		"    { 30000,    0,      9 },\n"
		"    { 40000,    0,      9 },\n"
		"}\n";
	char options[] = "-c";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc1)
{
	// convert comments, line comments, preprocessor
	// do NOT convert quotes
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*\n"
		"	 * comment		comment\n"
		"  	 * comment	 	comment\n"
		"   	 * comment	  	comment\n"
		"     * comment	   	comment\n"
		"  	 */\n"
		"\n"
		"/*\n"
		"	commentedCode();\n"
		"*/\n"
		"\n"
		"    //	line    comment\n"
		" 	//  line	comment\n"
		"  	// 	line	comment\n"
		"   	//	line	comment\n"
		"\n"
		"#ifdef	foo\n"
		"	#error is foo\n"
		"  	#endif	// end	 of	if\n"
		"\n"
		"	char* quote =\n"
		" 	    \"this	is	a	quote \\\n"
		"  	quote 		continuation  \\\n"
		"	quote  		continuation\";\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*\n"
		"	 * comment      comment\n"
		"	 * comment      comment\n"
		"	 * comment      comment\n"
		"	 * comment      comment\n"
		"	 */\n"
		"\n"
		"	/*\n"
		"	    commentedCode();\n"
		"	*/\n"
		"\n"
		"	//  line    comment\n"
		"	//  line    comment\n"
		"	//  line    comment\n"
		"	//  line    comment\n"
		"\n"
		"#ifdef  foo\n"
		"#error is foo\n"
		"#endif  // end   of if\n"
		"\n"
		"	char* quote =\n"
		"	    \"this	is	a	quote \\\n"
		"  	quote 		continuation  \\\n"
		"	quote  		continuation\";\n"
		"}\n";
	char options[] = "convert-tabs, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc2)
{
	// test convert-tabs with comments
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*	comment1\n"
		"		comment2\n"
		"	*/\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    /*  comment1\n"
		"        comment2\n"
		"    */\n"
		"}\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc3)
{
	// test convert-tabs with line comments and tabbed output
	// should NOT convert the leading tabs in a non-indent comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"//	comment1	comment1a\n"
		" //	comment2	comment2a\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"//	comment1 comment1a\n"
		"//	comment2    comment2a\n"
		"}\n";
	char options[] = "convert-tabs, --indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc4)
{
	// test convert-tabs with unpad-paren and pad-paren-in
	// should replace the tab after the opening paren
	char textIn[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if(	isFoo )\n"
		"        bar;\n"
		"}\n";
	char text[] =
		"\nvoid foo( bool isFoo )\n"
		"{\n"
		"    if( isFoo )\n"
		"        bar;\n"
		"}\n";
	char options[] = "convert-tabs, unpad-paren, pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc5)
{
	// test convert-tabs with comment continuation
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	int bar1; /* comment1 */\n"
		"	int bar2; /* comment2\n"
		"				 comment3 */\n"
		"	int bar3; /* comment3 */\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int bar1; /* comment1 */\n"
		"    int bar2; /* comment2\n"
		"                 comment3 */\n"
		"    int bar3; /* comment3 */\n"
		"}\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabs, Misc6)
{
	// verify that tabs are still present within quotes
	// should NOT have been replaced when AStyle was run
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* quote = \"this	is	a	quote \";\n"
		"}\n";
	// just check for the tab characters
	EXPECT_EQ('\t', text[37]);
	EXPECT_EQ('\t', text[40]);
	EXPECT_EQ('\t', text[42]);
}

//-------------------------------------------------------------------------
// AStyle Max Code Length and Break After Conditional
//-------------------------------------------------------------------------

TEST(MaxCodeLength, LongOption)
{
	// Test max code length long option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            || thisVariable2 == thatVariable2\n"
		"            || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ShortOption)
{
	// Test max code length short option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            || thisVariable2 == thatVariable2\n"
		"            || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "-xC50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ErrorMin)
{
	// Test max code length minimum value error.
	// Should call the error handler.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	// use errorHandler2 to verify the error
	char options[] = "max-code-length=49";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ErrorMax)
{
	// Test max code length maximum value error.
	// Should call the error handler.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	// use errorHandler2 to verify the error
	char options[] = "max-code-length=201";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterSemiColon1)
{
	// Test max code length breaking on a semicolon.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charDistance = 1; charDistance < remainingCharNum; charDistance++)\n"
		"    {}\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    for (charDistance = 1;\n"
		"            charDistance < remainingCharNum; charDistance++)\n"
		"    {}\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterSemiColon2)
{
	// Test max code length breaking on a semicolon.
	// Should not break before an end of line comment.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    toolBar->AddTool(idBtnSearch, wxBITMAP_TYPE_PNG); //Control(pBtnSearch);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    toolBar->AddTool(idBtnSearch,\n"
		"                     wxBITMAP_TYPE_PNG); //Control(pBtnSearch);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBeforeLogical)
{
	// Test max code length break before conditional (the default).
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or thisVariable2 == thatVariable2 or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and thisVariable2 == thatVariable2 and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            || thisVariable2 == thatVariable2\n"
		"            || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            && thisVariable2 == thatVariable2\n"
		"            && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            or thisVariable2 == thatVariable2\n"
		"            or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1\n"
		"            and thisVariable2 == thatVariable2\n"
		"            and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterLogical)
{
	// Test max code length break after logical.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or thisVariable2 == thatVariable2 or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and thisVariable2 == thatVariable2 and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 ||\n"
		"            thisVariable2 == thatVariable2 ||\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 &&\n"
		"            thisVariable2 == thatVariable2 &&\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or\n"
		"            thisVariable2 == thatVariable2 or\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and\n"
		"            thisVariable2 == thatVariable2 and\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50, break-after-logical";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterLogicalMisc)
{
	// Test max code length break after logical with the break coming just before
	// the "thisVariable3" (max-code-length2=70).
	// Without a correction the line will break with the logical beginning the line
	// (i.e. "|| thisVariable3 == thatVariable3)"
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or thisVariable2 == thatVariable2 or thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and thisVariable2 == thatVariable2 and thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 ||\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 &&\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 or thisVariable2 == thatVariable2 or\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"    if (thisVariable1 == thatVariable1 and thisVariable2 == thatVariable2 and\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=70, break-after-logical";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterShortConcatenated)
{
	// test break after conditional short option concatenated
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == thatVariable1 ||\n"
		"            thisVariable2 == thatVariable2 ||\n"
		"            thisVariable3 == thatVariable3)\n"
		"        bar();\n"
		"}";
	char options[] = "-xC50xL";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterComma1)
{
	// Test max code length breaking on a comma.
	char textIn[] =
		"\nclass FooClass\n"
		"{\n"
		"private:\n"
		"    size_t Utf16ToUtf8(char* utf16In, size_t inLen, FileEncoding encoding, bool firstBlock, char* utf8Out) const;\n"
		"};\n"
		"\n"
		"void foo()\n"
		"{\n"
		"    size_t utf1 = Utf16ToUtf8(utf16In, inLen, encoding, firstBlock, utf8Out);\n"
		"}";
	char text[] =
		"\nclass FooClass\n"
		"{\n"
		"private:\n"
		"    size_t Utf16ToUtf8(char* utf16In, size_t inLen,\n"
		"                       FileEncoding encoding, bool firstBlock,\n"
		"                       char* utf8Out) const;\n"
		"};\n"
		"\n"
		"void foo()\n"
		"{\n"
		"    size_t utf1 = Utf16ToUtf8(utf16In, inLen, encoding,\n"
		"                              firstBlock, utf8Out);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakAfterComma2)
{
	// Test max code length breaking on a comma.
	char textIn[] =
		"\nint ASBeautifier::getInStatementIndentAssign(const string& line) const\n"
		"{}\n"
		"\n"
		"void ASBeautifier::registerInStatementIndent(const string& line, int i, int tabIncrementIn, int minIndent)\n"
		"{}";
	char text[] =
		"\nint ASBeautifier::getInStatementIndentAssign(\n"
		"    const string& line) const\n"
		"{}\n"
		"\n"
		"void ASBeautifier::registerInStatementIndent(\n"
		"    const string& line, int i, int tabIncrementIn,\n"
		"    int minIndent)\n"
		"{}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote1)
{
	// Max code length should not break a quote line.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 == \"a very long, long, long, long, long, quote\")\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (thisVariable1 ==\n"
		"            \"a very long, long, long, long, long, quote\")\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote2)
{
	// Max code length should not break a quote line.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    sendMsg(\"  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3\"\n"
		"            \"thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6\");\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Quote3)
{
	// Max code length should not break a quote line following a paren e.g. after wxT(.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (variable1 == wxT(\"xxxx xxx xxxxx xxxxxxx xxxxxxx\"))\n"
		"        ++mit;\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (variable1 ==\n"
		"            wxT(\"xxxx xxx xxxxx xxxxxxx xxxxxxx\"))\n"
		"        ++mit;\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment1)
{
	// Max code length should not break a line comment only line.
	char text[] =
		"\n//  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)\n"
		"void foo()\n"
		"{\n"
		"    // if (thisVariable1 == thatVariable1 && thisVariable2 == thatVariable2 && thisVariable3 == thatVariable3)\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, LineComment2)
{
	// Max code length should not break inside a line comment.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (x == 1) // this is a long, long, long, long, long, long, long, comment\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(MaxCodeLength, Comment1)
{
	// Max code length should not break a comment line.
	char text[] =
		"\n/*  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3\n"
		" *  thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6)\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"    /*  if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3\n"
		"     *  thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6)\n"
		"     */\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Comment2)
{
	// Max code length should not break inside a line comment.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (x == 1) /* this is a long, long, long, long, long, long, long, comment */\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ExtraSpaces1)
{
	// Max code length should not add an extra line when breaking on multiple spaces.
	// This gives a blank formattedLine after the break.
	char textIn[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",                         SetValue(ReadInt(GetMetric)));\n"
		"}";
	char text[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",\n"
		"            SetValue(ReadInt(GetMetric)));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ExtraSpaces2)
{
	// Max code length should not add an extra line when breaking on multiple spaces.
	// This gives a non-blank formattedLine with leading spaces after the break.
	char textIn[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",          SetValue(ReadInt(GetMetric)));\n"
		"}";
	char text[] =
		"\nbool foo ()\n"
		"{\n"
		"    XRCCTRL(*this, \"spnAuiBorder\",\n"
		"            SetValue(ReadInt(GetMetric)));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Template)
{
	// Max code length should not break within a template definition.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    RegisterEventSink ( new cbEventFunctor < AutoVersioning, CodeBlocksEvent > ( OnProjectActivated ) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    RegisterEventSink ( new cbEventFunctor\n"
		"                        < AutoVersioning, CodeBlocksEvent >\n"
		"                        ( OnProjectActivated ) );\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PreprocessorDefine)
{
	// Max code length should not break a preprocessor define.
	char text[] =
		"\n#define MACRO1   if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3 \\\n"
		"                       thisVariable4 == thatVariable4 || thisVariable5 == thatVariable5 || thisVariable6 == thatVariable6\n"
		"";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, SQL)
{
	// Max code length should not break a SQL statement.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"             INTO   branch (branch_id, branch_name, branch_addr, branch_city)\n"
		"             VALUES (:bid, :bname, :baddr:baddr_ind1, :baddr:baddr_ind2);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Assembler)
{
	// Max code length should not break an assembler statement.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    asm (\"sar1 %1\n"
		"         movl %1, %0\": \"=r\"(res[i]) :\"r\" (res[i]), \"memory\");\n"
		"\n"
		"    __asm__ (\"sarl %0\"\n"
		"             : \"=r\" (res[i]) :\"r\" (num[i]), \"r\" (num[i]): \"memory\");\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, MicrosoftAssembler)
{
	// Max code length should not break an assembler statement.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm mov eax, fs:[0x8] __asm push edp  __asm push edq  __asm push edx\n"
		"\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8 mov dx, 0xD007 out dx, al out dx, al out dx, al\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, Array)
{
	// Max code length should not break an array.
	char text[] =
		"\nstatic BarButton bbs[] =\n"
		"{\n"
		"    { STD_FILEOPEN,  IDM_FILE_OPEN,  IDM_FILE_OPEN,  IDM_FILE_OPEN,  \"Open File\" },\n"
		"    { STD_FILESAVE,  IDM_FILE_SAVE,  IDM_FILE_SAVE,  IDM_FILE_SAVE,  \"Save File\" },\n"
		"    { STD_UNDO,      IDM_EDIT_UNDO,  IDM_EDIT_UNDO,  IDM_EDIT_UNDO,  \"Undo\"      },\n"
		"    { STD_REDOW,     IDM_EDIT_REDO,  IDM_EDIT_REDO,  IDM_EDIT_REDO,  \"Redo\"      },\n"
		"};";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ArrayInStatement)
{
	// Max code length should not break an in-statement array.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* a[] = { one, two, three, four, five, six, seven, eight,\n"
		"                };\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak1)
{
	// Test max code length with only a paren break.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    inStatementIndentStackSizeStack->push_back(inStatementIndentStack->size());\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    inStatementIndentStackSizeStack->push_back(\n"
		"        inStatementIndentStack->size());\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, ParenBreak2)
{
	// Test max code length with a paren break after an operator.
	// Should break before the paren.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    int variable1 = variable2 + variable3 + (var4 * var5);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int variable1 = variable2 + variable3 +\n"
		"                    (var4 * var5);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocks1)
{
	// Test max code length with break-blocks.
	// Should have empty lines before and after the 'if' statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2, longVariable3);\n"
		"    if (longVariable1 || longVariable2 || longVariable3)\n"
		"        bar();\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2, longVariable3);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"\n"
		"    if (longVariable1 || longVariable2\n"
		"            || longVariable3)\n"
		"        bar();\n"
		"\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"}";
	char options[] = "max-code-length=50, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocks2)
{
	// Test max code length with break-blocks with 'else' statement.
	// Should have empty lines before and after the 'if-else' statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2, longVariable3);\n"
		"    if (longVariable1 || longVariable2 || longVariable3)\n"
		"        bar();\n"
		"    else\n"
		"        bar2();\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2, longVariable3);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"\n"
		"    if (longVariable1 || longVariable2\n"
		"            || longVariable3)\n"
		"        bar();\n"
		"    else\n"
		"        bar2();\n"
		"\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"}";
	char options[] = "max-code-length=50, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocks3)
{
	// Test max code length with break-blocks at the end of a line.
	// The empty line should be after the statement.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"    // empty line should preceed this\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"\n"
		"    // empty line should preceed this\n"
		"}";
	char options[] = "max-code-length=100, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocksAll1)
{
	// Test max code length with break-blocks=all.
	// Should have empty lines before and after the 'if' and 'else' statements.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2, longVariable3);\n"
		"    if (longVariable1 || longVariable2 || longVariable3)\n"
		"        bar1();\n"
		"    else\n"
		"        bar2();\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2, longVariable3);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1 = fooFunction1(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"\n"
		"    if (longVariable1 || longVariable2\n"
		"            || longVariable3)\n"
		"        bar1();\n"
		"\n"
		"    else\n"
		"        bar2();\n"
		"\n"
		"    bar2 = fooFunction2(longVariable1, longVariable2,\n"
		"                        longVariable3);\n"
		"}";
	char options[] = "max-code-length=50, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakBlocksAll2)
{
	// Test max code length with break-blocks=all at the end of a line.
	// The empty lines should be after the statements.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"        else\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"    // empty line should preceed this\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"        if (isBar())\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"\n"
		"        else\n"
		"            GetSnippetsWindow()->GetSnippetsTreeCtrlTwo()->SaveItemsToFile(GetConfig()->SettingsSnippetsXmlPath);\n"
		"\n"
		"    // empty line should preceed this\n"
		"}";
	char options[] = "max-code-length=100, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMinimum)
{
	// Test max code length with a break below the minimum (should not break).
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (x == \"xxxxxxxxxx xxxxxxxxx x xxx  xxxxxxxxxxxxxxxx xxxxxxxxxxx\")\n"
		"        bar();\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMaximum)
{
	// Test max code length with a break above the maximum (should not break).
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar (variable1, variable2, variable3, variable4, varX)\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, BreakMaximumWithPad)
{
	// Test max code length with a break below the max but above the max with padding.
	// The statement should break when the padding is accounted for.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_DrawArea->Connect.threexxxxxxx(wxEVT_LEFT_DOWN,0,this);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_DrawArea->Connect.threexxxxxxx ( wxEVT_LEFT_DOWN,\n"
		"                                       0, this );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, IsLineReady)
{
	// Test max code length with isLineReady.
	// If isLineReady is set when the break is detected, the statement "cltError,"
	// will be deleted from the output.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_RegExes.Add(RegExStruct(_(\"Undefined reference\"), cltError, _T(\"(\") + FilePathWithSpaces + _T(\"(undefined reference.*)\")));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_RegExes.Add(RegExStruct(_(\"Undefined reference\"),\n"
		"                              cltError,\n"
		"                              _T(\"(\") + FilePathWithSpaces +\n"
		"                              _T(\"(undefined reference.*)\")));\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineStatements)
{
	// Test max code length with keep one-line statements.
	// Should break at the semicolons.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    Push(value1, value a1);Push(value2, value a2);Push(value3, value a3);Push(value4, value a4);\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    Push(value1, value a1); Push(value2, value a2);\n"
		"    Push(value3, value a3); Push(value4, value a4);\n"
		"}";
	char options[] = "max-code-length=50, keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocks)
{
	// Test max code length with keep one-line blocks.
	// Should NOT break the block.
	char text[] =
		"\nvoid Push(HSQUIRRELVM v, SQAnythingPtr value) { sq_pushuserpointer (v, value); }";
	char options[] = "max-code-length=50, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocksLogical)
{
	// Test max code length with keep one-line blocks and logical operators.
	// Should NOT break the block.
	char text[] =
		"\nvoid foo() { if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2) ++mit; }";
	char options[] = "max-code-length=50, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, KeepOneLineBlocksSans)
{
	// Test max code length without keep one-line blocks.
	// Should break the block.
	char textIn[] =
		"\nvoid Push(HSQUIRRELVM v, SQAnythingPtr value) { sq_pushuserpointer (v, value); }";
	char text[] =
		"\nvoid Push(HSQUIRRELVM v, SQAnythingPtr value) {\n"
		"    sq_pushuserpointer (v, value);\n"
		"}";
	char options[] = "max-code-length=50";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachPointerToType)
{
	// Test max code length with align-pointer=type.
	// Aborted when formatPointerOrReference() method contained a call to appendCurrentChar().
	char textIn[] =
		"\nvoid searchrangexxxxxxxxxxx(SQRex* exp, const SQChar** text_begin)\n"
		"{}";
	char text[] =
		"\nvoid searchrangexxxxxxxxxxx(SQRex* exp,\n"
		"                            const SQChar** text_begin)\n"
		"{}";
	char options[] = "max-code-length=50, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AddBrackets)
{
	// Test max code length with add-brackets.
	// Should not add an extra line or break the bracket when add-brackets is used.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (multi_line_comment_beginxxx < line.Length())\n"
		"        AnalyseLine();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (multi_line_comment_beginxxx <\n"
		"            line.Length()) {\n"
		"        AnalyseLine();\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=50, add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen1)
{
	// Test max code length with pad-paren.
	// Should not break a "wxT(" when a space is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!ret)\n"
		"        MessageBox(wxT(\"Couldn't save\") + wxT(\"Write-protected?\"));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( wxT ( \"Couldn't save\" ) +\n"
		"                     wxT ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen2)
{
	// Test max code length with pad-paren.
	// Should not break a paren followed by a quote when the paren is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox( ( \"save-file\" ) + ( \"Write-protected?\" ) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"save-file\" ) +\n"
		"                     ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen3)
{
	// Test max code length with pad-paren.
	// Should not break on a closing paren when a space is added.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!ret)\n"
		"        MessageBox((\"Couldn't save write protectedxxxx\") + (\"Write-protected?\"));\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"Couldn't save write protectedxxxx\" )\n"
		"                     + ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, PadParen4)
{
	// Test max code length with pad-paren.
	// Should not break on a closing paren when paren is padded.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"Couldn't save write protectedxxxx\" ) + ( \"Write-protected?\" ) );\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( !ret )\n"
		"        MessageBox ( ( \"Couldn't save write protectedxxxx\" )\n"
		"                     + ( \"Write-protected?\" ) );\n"
		"}";
	char options[] = "max-code-length=50, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket1)
{
	// Test max code length when a bracket is attached.
	// Should break when the bracket is attached.
	char textIn[] =
		"\nbool QueryColour ( char* propgrid, char* primary )\n"
		"{\n"
		"}";
	char text[] =
		"\nbool QueryColour ( char* propgrid,\n"
		"                   char* primary ) {\n"
		"}";
	char options[] = "max-code-length=50, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket2)
{
	// Test max code length when a bracket is attached inside a comment.
	// Should break when the bracket is attached.
	char textIn[] =
		"\nbool QueryColour ( char* propgrid, char* primary ) // comment\n"
		"{\n"
		"}";
	char text[] =
		"\nbool QueryColour ( char* propgrid,\n"
		"                   char* primary ) { // comment\n"
		"}";
	char options[] = "max-code-length=50, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxCodeLength, AttachBracket3)
{
	// Test max code length when a bracket is changed from run-in to attached.
	char textIn[] =
		"\nvoid ClassBrowser::SetParser ( Parser* parser )\n"
		"{   if ( parser != m_pParser\n"
		"            || ( parser && m_pParser\n"
		"                 && parser->ClassBrowserOptions().displayFilter != m_pParser->ClassBrowserOptions().displayFilter ) )\n"
		"    {   UnlinkParser();\n"
		"\n"
		"        if ( parser )\n"
		"        {   parser->m_pClassBrowser = this;\n"
		"            m_pParser = parser;\n"
		"            UpdateView();\n"
		"        }\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid ClassBrowser::SetParser ( Parser* parser ) {\n"
		"    if ( parser != m_pParser\n"
		"            || ( parser && m_pParser\n"
		"                 && parser->ClassBrowserOptions().displayFilter !=\n"
		"                 m_pParser->ClassBrowserOptions().displayFilter ) ) {\n"
		"        UnlinkParser();\n"
		"\n"
		"        if ( parser ) {\n"
		"            parser->m_pClassBrowser = this;\n"
		"            m_pParser = parser;\n"
		"            UpdateView();\n"
		"        }\n"
		"    }\n"
		"}";
	char options[] = "max-code-length=100, style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
