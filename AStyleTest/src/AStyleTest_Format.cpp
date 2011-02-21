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
		"    if (a == 0) {\n"
		"        ;\n"
		"    }\n"
		"    func1();\n"
		"    i++;\n"
		"    while (isFoo) { // comment\n"
		"        ;\n"
		"    }\n"
		"    while (isFoo) {\n"
		"        ;    // comment\n"
		"    }\n"
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
		"    if (a == 0) { ; }\n"
		"    func1();\n"
		"    i++;\n"
		"    while (isFoo)  // comment\n"
		"    { ; }\n"
		"    while (isFoo) { ; } // comment\n"
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
// AStyle Align Pointer
//-------------------------------------------------------------------------
TEST(AlignPointerNone, LongOption)
{
	// pointers and references should not be changed
	char text[] =
		"\nstring foo(const string *bar)   // comment\n"
		"{\n"
		"    const string* bar;     // comment\n"
		"    const string *bar;     // comment\n"
		"    const string   *bar;   // comment\n"
		"    const string  * bar;   // comment\n"
		"    const string*bar;      // comment\n"
		"    const string& bar;     // comment\n"
		"    const string &bar;     // comment\n"
		"    const string    &bar;  // comment\n"
		"    const string  &  bar;  // comment\n"
		"    const string&bar;      // comment\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, Tabs)
{
	// test with tab separators
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char	*bar;\n"
		"    const char		*bar;\n"
		"    const char*		bar;\n"
		"    const char		*		bar;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, AddressOf)
{
	// "address of" operator should NOT be changed
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1 == &AS_BAR1\n"
		"            || bar2 == &AS_BAR2)   // comment\n"
		"        return;\n"
		"    return &x;\n"
		"    return (&x);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, Dereference)
{
	// dereference should NOT be changed
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    TRxtra (*prevWordH);   // comment\n"
		"    if (fileName.empty())\n"
		"        *traceOutF << lineNum << endl;\n"
		"    else\n"
		"        *traceOutF << fileName << endl;\n"
		"    RegisterImage((char**)xpm_data_ptrs[i]);\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"    *newVec = **iter;\n"
		"    (info.*entryFunc[j])(value);\n"
		"    bool gtr = (*a)->IsLarger(**b);\n"
		"    return *this;\n"
		"    return (*this);\n"
		"    if (*doc) delete *doc;\n"
		"\n"
		"    if(prev) next = next;\n"
		"    else *chain = next;\n"
		"\n"
		"    for (tp::iterator it = p.begin(); it != p.end(); ++it) {\n"
		"        fill( m, **it );\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, GlobalVariables)
{
	// test with global variables
	char textIn[] =
		"\n// global variables\n"
		"ostream* _err = &cerr;\n"
		"ASConsole * g_console;\n"
		"stringstream *_err = NULL;\n";
	char text[] =
		"\n// global variables\n"
		"ostream* _err = &cerr;\n"
		"ASConsole * g_console;\n"
		"stringstream *_err = NULL;\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, GlobalDeclarations)
{
	// test with global declarations
	char text[] =
		"\n// function declarations\n"
		"void *foo(char* fooBar);\n"
		"char&bar(char&);\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, Cast1)
{
	// cast should not be changed
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string *bar;          // comment0\n"
		"    foo = (RefNode **) bar();   // comment1\n"
		"    foo = (RefNode *) bar();    // comment2\n"
		"    foo = ( RefNode ** ) bar(); // comment1\n"
		"    foo = ( RefNode * ) bar();  // comment2\n"
		"    foo = const_cast<RefNode **>(bar()); // comment3\n"
		"    foo = const_cast<RefNode *>(bar());  // comment4\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, Cast2)
{
	// cast should not be changed
	char text[] =
		"\nvoid foo(void *, void *);\n"
		"void foo(void *fooBar, void * fooBar);\n"
		"void foo(void **, void**);\n"
		"void foo(wxCommandEvent &);\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, ConvertTabs)
{
	// test tab conversion
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox	*channel;\n"
		"    wxTextCtrl	*filename;\n"
		"    char		*	stamp;\n"
		"    void			*userData;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox   *channel;\n"
		"    wxTextCtrl  *filename;\n"
		"    char        *   stamp;\n"
		"    void            *userData;\n"
		"}\n";
	char options[] = "convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, Paren)
{
	// test pointer recognition in a paren
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject* p  = pm->GetProject())\n"
		"        getBar();\n"
		"    if(cbProject * p = pm->GetProject())\n"
		"        getBar();\n"
		"    if(cbProject  *p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, PointerToPointer)
{
	// test double pointer
	char text[] =
		"\nint main(int argc, char **argv)\n"
		"{\n"
		"    char    **bar1;\n"
		"    char  **  bar1;\n"
		"    char**    bar1;\n"
		"    char	**	bar1;\n"
		"    char		**		bar1;\n"
		"    char**bar1;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, EndOfLine1)
{
	// test pointer at end of line
	char text[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, EndOfLine2)
{
	// test pointer at end of line with spaces or comment after
	char textIn[] =
		"\nvoid*   \n"
		"foo() {}\n"
		"\n"
		"char &   \n"
		"bar() {}\n"
		"\n"
		"void*      // comment  \n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */  \n"
		"foo() {}\n"
		"\n"
		"char**   \n"
		"bar() {}\n";
	char text[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n"
		"\n"
		"void*      // comment\n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */\n"
		"foo() {}\n"
		"\n"
		"char**\n"
		"bar() {}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, Comment)
{
	// test pointer with comment after
	char text[] =
		"\nvoid Foo(WordList*/*keyword*/,\n"
		"         WordList**/*keyword*/) {\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, OperatorOverload)
{
	// test pointer with overloaded operator
	char text[] =
		"\nclass Foo\n"
		"{\n"
		"    T& operator* () const {};\n"
		"    T * operator-> () {};\n"
		"};\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, ConversionOperator)
{
	// test pointer with conversion operator
	char text[] =
		"\n// conversion operator declarations\n"
		"operator EventRef &() { return fEvent; }\n"
		"operator HIRect * () { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef&();\n"
		"operator HIRect *();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef& rf = (EventRef&) tf;\n"
		"HIRect *pr   = (HIRect *) tr;\n"
		"bool bb      = (bool) tb;\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, ScopeResolution)
{
	// should not change scope resolution operator
	char text[] =
		"\nstruct CV {\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType:: *var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType:: * var;\n"
		"} cv;\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNone, PadParenOutside)
{
	// should not change scope resolution operator
	char text[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR)& showIcon},\n"
		"        { Dynamic,  (LPTSTR) & isDynamic},\n"
		"        { Maxtext,  (LPTSTR) &maxText},\n"
		"        { IconID,   (LPTSTR)&iconID},\n"
		"    };\n"
		"}";
	char options[] = "pad-paren-out";
	char* textOut1 = AStyleMain(text, options, errorHandler, memoryAlloc);
	// format twice to be sure an extra space is not added
	char* textOut = AStyleMain(textOut1, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut1;
	delete [] textOut;
}

TEST(AlignPointerNone, UnpadParen)
{
	// unpad-paren should NOT delete space padding
	char text[] =
		"\nLUA_API lua_State     *(lua_tothread)(lua_State *L, int idx);\n"
		"LUA_API const void     *(lua_topointer)(lua_State *L, int idx);\n";
	char options[] = "unpad-paren";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, LongOption)
{
	// test align pointer=type
	char textIn[] =
		"\nstring foo(const string *bar)   // comment\n"
		"{\n"
		"    const string* bar;     // comment\n"
		"    const string *bar;     // comment\n"
		"    const string   *bar;   // comment\n"
		"    const string  * bar;   // comment\n"
		"    const string*bar;      // comment\n"
		"    const string& bar;     // comment\n"
		"    const string &bar;     // comment\n"
		"    const string    &bar;  // comment\n"
		"    const string  &  bar;  // comment\n"
		"    const string&bar;      // comment\n"
		"}\n";
	char text[] =
		"\nstring foo(const string* bar)   // comment\n"
		"{\n"
		"    const string* bar;     // comment\n"
		"    const string* bar;     // comment\n"
		"    const string*   bar;   // comment\n"
		"    const string*   bar;   // comment\n"
		"    const string* bar;     // comment\n"
		"    const string& bar;     // comment\n"
		"    const string& bar;     // comment\n"
		"    const string&    bar;  // comment\n"
		"    const string&    bar;  // comment\n"
		"    const string& bar;     // comment\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, ShortOption)
{
	// test align pointer=type short option
	char textIn[] =
		"\nstring foo(const string *bar)\n"
		"{\n"
		"    const string* bar;\n"
		"    const string *bar;\n"
		"}\n";
	char text[] =
		"\nstring foo(const string* bar)\n"
		"{\n"
		"    const string* bar;\n"
		"    const string* bar;\n"
		"}\n";
	char options[] = "-k1";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, FromCentered)
{
	// test align pointer=type when input is centered
	// a space is deleted in certain circumstances
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string * bar;     // remove space\n"
		"    const string  * bar;    // don't remove\n"
		"    const string *  bar;    // don't remove\n"
		"    const string* bar;      // don't remove\n"
		"    const string *bar;      // don't remove\n"
		"\n"
		"    const string ** bar;    // remove space\n"
		"    const string  ** bar;   // don't remove\n"
		"    const string **  bar;   // don't remove\n"
		"    const string** bar;     // don't remove\n"
		"    const string **bar;     // don't remove\n"
		"\n"
		"    const string & bar;     // remove space\n"
		"    const string  & bar;    // don't remove\n"
		"    const string &  bar;    // don't remove\n"
		"    const string& bar;      // don't remove\n"
		"    const string &bar;      // don't remove\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string* bar;      // remove space\n"
		"    const string*   bar;    // don't remove\n"
		"    const string*   bar;    // don't remove\n"
		"    const string* bar;      // don't remove\n"
		"    const string* bar;      // don't remove\n"
		"\n"
		"    const string** bar;     // remove space\n"
		"    const string**   bar;   // don't remove\n"
		"    const string**   bar;   // don't remove\n"
		"    const string** bar;     // don't remove\n"
		"    const string** bar;     // don't remove\n"
		"\n"
		"    const string& bar;      // remove space\n"
		"    const string&   bar;    // don't remove\n"
		"    const string&   bar;    // don't remove\n"
		"    const string& bar;      // don't remove\n"
		"    const string& bar;      // don't remove\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Tabs)
{
	// test with tab separators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char	*bar;\n"
		"    const char		*bar;\n"
		"    const char*		bar;\n"
		"    const char		*		bar;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char*	bar;\n"
		"    const char*		bar;\n"
		"    const char*		bar;\n"
		"    const char*				bar;\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, AddressOf)
{
	// "address of" operator should NOT be separated from the name
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1 == &AS_BAR1\n"
		"            || bar2 == &AS_BAR2)   // comment\n"
		"        return;\n"
		"    return &x;\n"
		"    return (&x);\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Dereference)
{
	// dereference should NOT be separated from the name
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    TRxtra (*prevWordH);   // comment\n"
		"    if (fileName.empty())\n"
		"        *traceOutF << lineNum << endl;\n"
		"    else\n"
		"        *traceOutF << fileName << endl;\n"
		"    RegisterImage((char**)xpm_data_ptrs[i]);\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"    *newVec = **iter;\n"
		"    (info.*entryFunc[j])(value);\n"
		"    bool gtr = (*a)->IsLarger(**b);\n"
		"    return *this;\n"
		"    return (*this);\n"
		"    if (*doc) delete *doc;\n"
		"\n"
		"    if(prev) next = next;\n"
		"    else *chain = next;\n"
		"\n"
		"    for (tp::iterator it = p.begin(); it != p.end(); ++it) {\n"
		"        fill( m, **it );\n"
		"    }\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, GlobalVariables)
{
	// test with global variables
	char textIn[] =
		"\n// global variables\n"
		"ostream *_err = &cerr;\n"
		"ASConsole *g_console;\n"
		"stringstream *_err = NULL;\n";
	char text[] =
		"\n// global variables\n"
		"ostream* _err = &cerr;\n"
		"ASConsole* g_console;\n"
		"stringstream* _err = NULL;\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, GlobalDeclarations)
{
	// test with global declarations
	char textIn[] =
		"\n// function declarations\n"
		"void *foo(char*fooBar);\n"
		"char&bar(char&);\n";
	char text[] =
		"\n// function declarations\n"
		"void* foo(char* fooBar);\n"
		"char& bar(char&);\n";;
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Cast1)
{
	// cast should not be space padded
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string *bar;          // comment0\n"
		"    foo = (RefNode **) bar();   // comment1\n"
		"    foo = (RefNode *) bar();    // comment2\n"
		"    foo = ( RefNode ** ) bar(); // comment1\n"
		"    foo = ( RefNode * ) bar();  // comment2\n"
		"    foo = const_cast<RefNode **>(bar()); // comment3\n"
		"    foo = const_cast<RefNode *>(bar());  // comment4\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string* bar;          // comment0\n"
		"    foo = (RefNode**) bar();    // comment1\n"
		"    foo = (RefNode*) bar();     // comment2\n"
		"    foo = ( RefNode** ) bar();  // comment1\n"
		"    foo = ( RefNode* ) bar();   // comment2\n"
		"    foo = const_cast<RefNode**>(bar());  // comment3\n"
		"    foo = const_cast<RefNode*>(bar());   // comment4\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Cast2)
{
	// cast should not be space padded
	char textIn[] =
		"\nvoid foo(void *, void *);\n"
		"void foo(void *fooBar, void * fooBar);\n";
	char text[] =
		"\nvoid foo(void*, void*);\n"
		"void foo(void* fooBar, void* fooBar);\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, ConvertTabs)
{
	// test tab conversion on type
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox	*channel;\n"
		"    wxTextCtrl	*filename;\n"
		"    char		*	stamp;\n"
		"    void			*userData;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox*   channel;\n"
		"    wxTextCtrl*  filename;\n"
		"    char*           stamp;\n"
		"    void*            userData;\n"
		"}\n";
	char options[] = "align-pointer=type, convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Paren)
{
	// test pointer recognition in a paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject *p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject* p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, PointerToPointer)
{
	// test double pointer
	char textIn[] =
		"\nint main(int argc, char **argv)\n"
		"{\n"
		"    char    **bar1;\n"
		"    char  **  bar1;\n"
		"    char**    bar1;\n"
		"    char	**	bar1;\n"
		"    char		**		bar1;\n"
		"    char**bar1;\n"
		"}\n";
	char text[] =
		"\nint main(int argc, char** argv)\n"
		"{\n"
		"    char**    bar1;\n"
		"    char**    bar1;\n"
		"    char**    bar1;\n"
		"    char**		bar1;\n"
		"    char**				bar1;\n"
		"    char** bar1;\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, EndOfLine1)
{
	// test pointer at end of line
	char textIn[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n";
	char text[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char&\n"
		"bar() {}\n";
	char options[] = "align-pointer=type, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, EndOfLine2)
{
	// test pointer at end of line with spaces or comment after
	char textIn[] =
		"\nvoid*   \n"
		"foo() {}\n"
		"\n"
		"char &   \n"
		"bar() {}\n"
		"\n"
		"void*      // comment  \n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */  \n"
		"foo() {}\n"
		"\n"
		"char**   \n"
		"bar() {}\n";
	char text[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char&\n"
		"bar() {}\n"
		"\n"
		"void*      // comment\n"
		"foo() {}\n"
		"\n"
		"void**     /* comment */\n"
		"foo() {}\n"
		"\n"
		"char**\n"
		"bar() {}\n";
	char options[] = "align-pointer=type, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Comment)
{
	// test pointer with comment after
	char textIn[] =
		"\nvoid Foo(WordList*/*keyword*/,\n"
		"         WordList**/*keyword*/) {\n"
		"}\n";
	char text[] =
		"\nvoid Foo(WordList* /*keyword*/,\n"
		"         WordList** /*keyword*/) {\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, OperatorOverload)
{
	// test pointer with overloaded operator
	char textIn[] =
		"\nclass Foo\n"
		"{\n"
		"    T& operator* () const {};\n"
		"    T * operator-> () {};\n"
		"};\n";
	char text[] =
		"\nclass Foo\n"
		"{\n"
		"    T& operator* () const {};\n"
		"    T* operator-> () {};\n"
		"};\n";
	char options[] = "align-pointer=type, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, ConversionOperator)
{
	// test pointer with conversion operator
	char textIn[] =
		"\n// conversion operator declarations\n"
		"operator EventRef &() { return fEvent; }\n"
		"operator HIRect * () { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef&();\n"
		"operator HIRect *();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef& rf = (EventRef&) tf;\n"
		"HIRect *pr   = (HIRect *) tr;\n"
		"bool bb      = (bool) tb;\n";
	char text[] =
		"\n// conversion operator declarations\n"
		"operator EventRef& () { return fEvent; }\n"
		"operator HIRect* () { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef& ();\n"
		"operator HIRect* ();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef& rf = (EventRef&) tf;\n"
		"HIRect* pr   = (HIRect*) tr;\n"
		"bool bb      = (bool) tb;\n";
	char options[] = "align-pointer=type, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, ScopeResolution)
{
	// should pad scope resolution operator
	char textIn[] =
		"\nstruct CV {\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType:: *var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType:: * var;\n"
		"} cv;\n";
	char text[] =
		"\nstruct CV {\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType::* var;\n"
		"} cv;\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, PadParenOutside)
{
	// should not change scope resolution operator
	char textIn[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR)& showIcon},\n"
		"        { Dynamic,  (LPTSTR) & isDynamic},\n"
		"        { Maxtext,  (LPTSTR) &maxText},\n"
		"        { IconID,   (LPTSTR)&iconID},\n"
		"    };\n"
		"}";
	char text[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR)& showIcon},\n"
		"        { Dynamic,  (LPTSTR)& isDynamic},\n"
		"        { Maxtext,  (LPTSTR)& maxText},\n"
		"        { IconID,   (LPTSTR)& iconID},\n"
		"    };\n"
		"}";
	char options[] = "align-pointer=type, pad-paren-out";
	char* textOut1 = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	// format twice to be sure an extra space is not added
	char* textOut = AStyleMain(textOut1, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut1;
	delete [] textOut;
}

TEST(AlignPointerType, UnpadParen)
{
	// unpad-paren should NOT delete space padding
	char textIn[] =
		"\nLUA_API lua_State     *(lua_tothread)(lua_State *L, int idx);\n"
		"LUA_API const void     *(lua_topointer)(lua_State *L, int idx);\n";
	char text[] =
		"\nLUA_API lua_State*     (lua_tothread)(lua_State* L, int idx);\n"
		"LUA_API const void*     (lua_topointer)(lua_State* L, int idx);\n";
	char options[] = "align-pointer=type, unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Catch)
{
	// 'catch' statement is a reference, not an operator
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    try {\n"
		"        wxBufferedInputStream fb(fs);\n"
		"    }\n"
		"    catch (cbException&ex) {\n"
		"        ex.ShowErrorMessage(true);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    try {\n"
		"        wxBufferedInputStream fb(fs);\n"
		"    }\n"
		"    catch (cbException& ex) {\n"
		"        ex.ShowErrorMessage(true);\n"
		"    }\n"
		"}\n";
	char options[] = "align-pointer=type, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, AndOperator)
{
	// should not unpad && operator
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo() && isBar())   // comment\n"
		"        return;\n"
		"    if (isFoo && isBar)   // comment\n"
		"        return;\n"
		"    if (isFoo\n"
		"            && isBar1)   // comment\n"
		"        return;\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Sans1)
{
	// these are not pointers
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a *= b;\n"
		"    a &= b;\n"
		"    a && b;\n"
		"    x = a * b;\n"
		"    x = a & b;\n"
		"    bar[boo*foo-1] = 2;\n"
		"}\n";
	char options[] = "align-pointer=type";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType, Sans2)
{
	// these should be padded as operators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    a*=b;\n"
		"    a&=b;\n"
		"    a&&b;\n"
		"    x=a*b;\n"
		"    x=a&b;\n"
		"    if (len*tab>longest) bar();\n"
		"    SetWidth(width()+(pixels*indentAmt));\n"
		"    if (m_Flags&flLocal) return;\n"
		"    Link(m_y+.5*h-.5*m_fontSize);\n"
		"    if ((Flags&flVariable)&&(Flags&flId))\n"
		"        bar();\n"
		"    out_html(change_to_size(i*j));\n"
		"    if (i>*maxcol) *maxcol=i;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a *= b;\n"
		"    a &= b;\n"
		"    a && b;\n"
		"    x = a * b;\n"
		"    x = a & b;\n"
		"    if (len * tab > longest) bar();\n"
		"    SetWidth(width() + (pixels * indentAmt));\n"
		"    if (m_Flags & flLocal) return;\n"
		"    Link(m_y + .5 * h - .5 * m_fontSize);\n"
		"    if ((Flags & flVariable) && (Flags & flId))\n"
		"        bar();\n"
		"    out_html(change_to_size(i * j));\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"}\n";
	char options[] = "align-pointer=type, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, LongOption)
{
	// test align pointer=middle
	char textIn[] =
		"\nstring foo(const string *bar)   // comment\n"
		"{\n"
		"    const string* bar;     // comment\n"
		"    const string *bar;     // comment\n"
		"    const string   *bar;   // comment\n"
		"    const string  * bar;   // comment\n"
		"    const string*bar;      // comment\n"
		"    const string& bar;     // comment\n"
		"    const string &bar;     // comment\n"
		"    const string    &bar;  // comment\n"
		"    const string  &  bar;  // comment\n"
		"    const string&bar;      // comment\n"
		"}\n";
	char text[] =
		"\nstring foo(const string * bar)  // comment\n"
		"{\n"
		"    const string * bar;    // comment\n"
		"    const string * bar;    // comment\n"
		"    const string  * bar;   // comment\n"
		"    const string  * bar;   // comment\n"
		"    const string * bar;    // comment\n"
		"    const string & bar;    // comment\n"
		"    const string & bar;    // comment\n"
		"    const string  &  bar;  // comment\n"
		"    const string  &  bar;  // comment\n"
		"    const string & bar;    // comment\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, ShortOption)
{
	// test align pointer=middle short option
	char textIn[] =
		"\nstring foo(const string *bar)\n"
		"{\n"
		"    const string* bar;\n"
		"    const string *bar;\n"
		"}\n";
	char text[] =
		"\nstring foo(const string * bar)\n"
		"{\n"
		"    const string * bar;\n"
		"    const string * bar;\n"
		"}\n";
	char options[] = "-k2";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Tabs)
{
	// test with tab separators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char	*bar;\n"
		"    const char		*bar;\n"
		"    const char*		bar;\n"
		"    const char		*		bar;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char	* bar;\n"
		"    const char	*	bar;\n"
		"    const char	*	bar;\n"
		"    const char		*		bar;\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, AddressOf)
{
	// "address of" operator should NOT be separated from the name
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1 == &AS_BAR1\n"
		"            || bar2 == &AS_BAR2)   // comment\n"
		"        return;\n"
		"    return &x;\n"
		"    return (&x);\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Dereference)
{
	// dereference should NOT be separated from the name
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    TRxtra (*prevWordH);   // comment\n"
		"    if (fileName.empty())\n"
		"        *traceOutF << lineNum << endl;\n"
		"    else\n"
		"        *traceOutF << fileName << endl;\n"
		"    RegisterImage((char **)xpm_data_ptrs[i]);\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"    *newVec = **iter;\n"
		"    (info.*entryFunc[j])(value);\n"
		"    bool gtr = (*a)->IsLarger(**b);\n"
		"    return *this;\n"
		"    return (*this);\n"
		"    if (*doc) delete *doc;\n"
		"\n"
		"    if(prev) next = next;\n"
		"    else *chain = next;\n"
		"\n"
		"    for (tp::iterator it = p.begin(); it != p.end(); ++it) {\n"
		"        fill( m, **it );\n"
		"    }\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, GlobalVariables)
{
	// test with global variables
	char textIn[] =
		"\n// global variables\n"
		"ostream* _err = &cerr;\n"
		"ASConsole* g_console;\n"
		"stringstream* _err = NULL;\n";
	char text[] =
		"\n// global variables\n"
		"ostream * _err = &cerr;\n"
		"ASConsole * g_console;\n"
		"stringstream * _err = NULL;\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, GlobalDeclarations)
{
	// test with global declarations
	char textIn[] =
		"\n// function declarations\n"
		"void *foo(char*fooBar);\n"
		"char&bar(char&);\n";
	char text[] =
		"\n// function declarations\n"
		"void * foo(char * fooBar);\n"
		"char & bar(char &);\n";;
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Cast1)
{
	// cast should be space padded
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string* bar;          // comment0\n"
		"    foo = (RefNode**) bar();    // comment1\n"
		"    foo = (RefNode*) bar();     // comment2\n"
		"    foo = ( RefNode** ) bar();  // comment1\n"
		"    foo = ( RefNode* ) bar();   // comment2\n"
		"    foo = const_cast<RefNode**>(bar());  // comment3\n"
		"    foo = const_cast<RefNode*>(bar());   // comment4\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string * bar;         // comment0\n"
		"    foo = (RefNode **) bar();   // comment1\n"
		"    foo = (RefNode *) bar();    // comment2\n"
		"    foo = ( RefNode ** ) bar(); // comment1\n"
		"    foo = ( RefNode * ) bar();  // comment2\n"
		"    foo = const_cast<RefNode **>(bar()); // comment3\n"
		"    foo = const_cast<RefNode *>(bar());  // comment4\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Cast2)
{
	// cast should be space padded
	char textIn[] =
		"\nvoid foo(void*, void*);\n"
		"void foo(void*fooBar, void* fooBar);\n";
	char text[] =
		"\nvoid foo(void *, void *);\n"
		"void foo(void * fooBar, void * fooBar);\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, ConvertTabs)
{
	// test tab conversion on type
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox*	channel;\n"
		"    wxTextCtrl	*filename;\n"
		"    char		*	stamp;\n"
		"    void*			userData;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox * channel;\n"
		"    wxTextCtrl * filename;\n"
		"    char      *     stamp;\n"
		"    void      *     userData;\n"
		"}\n";
	char options[] = "align-pointer=middle, convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Paren)
{
	// test pointer recognition in a paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject *p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject * p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, PointerToPointer)
{
	// test double pointer
	char textIn[] =
		"\nint main(int argc, char **argv)\n"
		"{\n"
		"    char    **bar1;\n"
		"    char  **  bar1;\n"
		"    char**    bar1;\n"
		"    char	**	bar1;\n"
		"    char		**		bar1;\n"
		"    char**bar1;\n"
		"}\n";
	char text[] =
		"\nint main(int argc, char ** argv)\n"
		"{\n"
		"    char  **  bar1;\n"
		"    char  **  bar1;\n"
		"    char  **  bar1;\n"
		"    char	**	bar1;\n"
		"    char		**		bar1;\n"
		"    char ** bar1;\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, EndOfLine1)
{
	// test pointer at end of line
	char textIn[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n";
	char text[] =
		"\nvoid *\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n";
	char options[] = "align-pointer=middle, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, EndOfLine2)
{
	// test pointer at end of line with spaces or comment after
	char textIn[] =
		"\nvoid*   \n"
		"foo() {}\n"
		"\n"
		"char &   \n"
		"bar() {}\n"
		"\n"
		"void*      // comment  \n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */  \n"
		"foo() {}\n"
		"\n"
		"char**   \n"
		"bar() {}\n";
	char text[] =
		"\nvoid *\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n"
		"\n"
		"void *     // comment\n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */\n"
		"foo() {}\n"
		"\n"
		"char **\n"
		"bar() {}\n";
	char options[] = "align-pointer=middle, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Comment)
{
	// test pointer with comment after
	char textIn[] =
		"\nvoid Foo(WordList*/*keyword*/,\n"
		"         WordList**/*keyword*/) {\n"
		"}\n";
	char text[] =
		"\nvoid Foo(WordList * /*keyword*/,\n"
		"         WordList ** /*keyword*/) {\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, OperatorOverload)
{
	// test pointer with overloaded operator
	char textIn[] =
		"\nclass Foo\n"
		"{\n"
		"    T& operator* () const {};\n"
		"    T * operator-> () {};\n"
		"};\n";
	char text[] =
		"\nclass Foo\n"
		"{\n"
		"    T & operator* () const {};\n"
		"    T * operator-> () {};\n"
		"};\n";
	char options[] = "align-pointer=middle, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, ConversionOperator)
{
	// test pointer with conversion operator
	char textIn[] =
		"\n// conversion operator declarations\n"
		"operator EventRef &() { return fEvent; }\n"
		"operator HIRect * () { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef&();\n"
		"operator HIRect *();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef& rf = (EventRef&) tf;\n"
		"HIRect *pr   = (HIRect *) tr;\n"
		"bool bb      = (bool) tb;\n";
	char text[] =
		"\n// conversion operator declarations\n"
		"operator EventRef & () { return fEvent; }\n"
		"operator HIRect * () { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef & ();\n"
		"operator HIRect * ();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef & rf = (EventRef &) tf;\n"
		"HIRect * pr   = (HIRect *) tr;\n"
		"bool bb      = (bool) tb;\n";
	char options[] = "align-pointer=middle, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, ScopeResolution)
{
	// should pad scope resolution operator
	char textIn[] =
		"\nstruct CV {\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType:: *var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType:: * var;\n"
		"} cv;\n";
	char text[] =
		"\nstruct CV {\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType::*  var;\n"
		"} cv;\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, PadParenOutside)
{
	// should not change scope resolution operator
	char textIn[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR)& showIcon},\n"
		"        { Dynamic,  (LPTSTR) & isDynamic},\n"
		"        { Maxtext,  (LPTSTR) &maxText},\n"
		"        { IconID,   (LPTSTR)&iconID},\n"
		"    };\n"
		"}";
	char text[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR) & showIcon},\n"
		"        { Dynamic,  (LPTSTR) & isDynamic},\n"
		"        { Maxtext,  (LPTSTR) & maxText},\n"
		"        { IconID,   (LPTSTR) & iconID},\n"
		"    };\n"
		"}";
	char options[] = "align-pointer=middle, pad-paren-out";
	char* textOut1 = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	// format twice to be sure an extra space is not added
	char* textOut = AStyleMain(textOut1, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut1;
	delete [] textOut;
}

TEST(AlignPointerMiddle, UnpadParen)
{
	// unpad-paren should NOT delete space padding
	char textIn[] =
		"\nLUA_API lua_State*     (lua_tothread)(lua_State *L, int idx);\n"
		"LUA_API const void     *(lua_topointer)(lua_State *L, int idx);\n";
	char text[] =
		"\nLUA_API lua_State   *  (lua_tothread)(lua_State * L, int idx);\n"
		"LUA_API const void   *  (lua_topointer)(lua_State * L, int idx);\n";
	char options[] = "align-pointer=middle, unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Catch)
{
	// 'catch' statement is a reference, not an operator
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    try {\n"
		"        wxBufferedInputStream fb(fs);\n"
		"    }\n"
		"    catch (cbException&ex) {\n"
		"        ex.ShowErrorMessage(true);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    try {\n"
		"        wxBufferedInputStream fb(fs);\n"
		"    }\n"
		"    catch (cbException & ex) {\n"
		"        ex.ShowErrorMessage(true);\n"
		"    }\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, AndOperator)
{
	// should not unpad && operator
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo() && isBar())   // comment\n"
		"        return;\n"
		"    if (isFoo && isBar)   // comment\n"
		"        return;\n"
		"    if (isFoo\n"
		"            && isBar1)   // comment\n"
		"        return;\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Sans1)
{
	// these are not pointers
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a *= b;\n"
		"    a &= b;\n"
		"    a && b;\n"
		"    x = a * b;\n"
		"    x = a & b;\n"
		"    bar[boo*foo-1] = 2;\n"
		"}\n";
	char options[] = "align-pointer=middle";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle, Sans2)
{
	// these should be padded as operators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    a*=b;\n"
		"    a&=b;\n"
		"    a&&b;\n"
		"    x=a*b;\n"
		"    x=a&b;\n"
		"    if (len*tab>longest) bar();\n"
		"    SetWidth(width()+(pixels*indentAmt));\n"
		"    if (m_Flags&flLocal) return;\n"
		"    Link(m_y+.5*h-.5*m_fontSize);\n"
		"    if ((Flags&flVariable)&&(Flags&flId))\n"
		"        bar();\n"
		"    out_html(change_to_size(i*j));\n"
		"    if (i>*maxcol) *maxcol=i;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a *= b;\n"
		"    a &= b;\n"
		"    a && b;\n"
		"    x = a * b;\n"
		"    x = a & b;\n"
		"    if (len * tab > longest) bar();\n"
		"    SetWidth(width() + (pixels * indentAmt));\n"
		"    if (m_Flags & flLocal) return;\n"
		"    Link(m_y + .5 * h - .5 * m_fontSize);\n"
		"    if ((Flags & flVariable) && (Flags & flId))\n"
		"        bar();\n"
		"    out_html(change_to_size(i * j));\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"}\n";
	char options[] = "align-pointer=middle, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, LongOption)
{
	// test align pointer=name
	char textIn[] =
		"\nstring foo(const string* bar)   // comment\n"
		"{\n"
		"    const string* bar;     // comment\n"
		"    const string *bar;     // comment\n"
		"    const string   *bar;   // comment\n"
		"    const string  * bar;   // comment\n"
		"    const string*bar;      // comment\n"
		"    const string& bar;     // comment\n"
		"    const string &bar;     // comment\n"
		"    const string    &bar;  // comment\n"
		"    const string  &  bar;  // comment\n"
		"    const string&bar;      // comment\n"
		"}\n";
	char text[] =
		"\nstring foo(const string *bar)   // comment\n"
		"{\n"
		"    const string *bar;     // comment\n"
		"    const string *bar;     // comment\n"
		"    const string   *bar;   // comment\n"
		"    const string   *bar;   // comment\n"
		"    const string *bar;     // comment\n"
		"    const string &bar;     // comment\n"
		"    const string &bar;     // comment\n"
		"    const string    &bar;  // comment\n"
		"    const string    &bar;  // comment\n"
		"    const string &bar;     // comment\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, ShortOption)
{
	// test align pointer=name short option
	char textIn[] =
		"\nstring foo(const string* bar)\n"
		"{\n"
		"    const string *bar;\n"
		"    const string* bar;\n"
		"}\n";
	char text[] =
		"\nstring foo(const string *bar)\n"
		"{\n"
		"    const string *bar;\n"
		"    const string *bar;\n"
		"}\n";
	char options[] = "-k3";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, FromCentered)
{
	// test align pointer=name when input is centered
	// a space is deleted in certain circumstances
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string * bar;     // remove space\n"
		"    const string  * bar;    // don't remove\n"
		"    const string *  bar;    // don't remove\n"
		"    const string* bar;      // don't remove\n"
		"    const string *bar;      // don't remove\n"
		"\n"
		"    const string ** bar;    // remove space\n"
		"    const string  ** bar;   // don't remove\n"
		"    const string **  bar;   // don't remove\n"
		"    const string** bar;     // don't remove\n"
		"    const string **bar;     // don't remove\n"
		"\n"
		"    const string & bar;     // remove space\n"
		"    const string  & bar;    // don't remove\n"
		"    const string &  bar;    // don't remove\n"
		"    const string& bar;      // don't remove\n"
		"    const string &bar;      // don't remove\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string *bar;      // remove space\n"
		"    const string   *bar;    // don't remove\n"
		"    const string   *bar;    // don't remove\n"
		"    const string *bar;      // don't remove\n"
		"    const string *bar;      // don't remove\n"
		"\n"
		"    const string **bar;     // remove space\n"
		"    const string   **bar;   // don't remove\n"
		"    const string   **bar;   // don't remove\n"
		"    const string **bar;     // don't remove\n"
		"    const string **bar;     // don't remove\n"
		"\n"
		"    const string &bar;      // remove space\n"
		"    const string   &bar;    // don't remove\n"
		"    const string   &bar;    // don't remove\n"
		"    const string &bar;      // don't remove\n"
		"    const string &bar;      // don't remove\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Tabs)
{
	// test with tab separators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char*	bar;\n"
		"    const char	*	bar;\n"
		"    const char		*bar;\n"
		"    const char		*		bar;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const char	*bar;\n"
		"    const char		*bar;\n"
		"    const char		*bar;\n"
		"    const char				*bar;\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, AddressOf)
{
	// "address of" operator should NOT be separated from the name
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1 == &AS_BAR1\n"
		"            || bar2 == &AS_BAR2)   // comment\n"
		"        return;\n"
		"    return &x;\n"
		"    return (&x);\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Dereference)
{
	// dereference should NOT be separated from the name
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    TRxtra (*prevWordH);   // comment\n"
		"    if (fileName.empty())\n"
		"        *traceOutF << lineNum << endl;\n"
		"    else\n"
		"        *traceOutF << fileName << endl;\n"
		"    RegisterImage((char **)xpm_data_ptrs[i]);\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"    *newVec = **iter;\n"
		"    (info.*entryFunc[j])(value);\n"
		"    bool gtr = (*a)->IsLarger(**b);\n"
		"    return *this;\n"
		"    return (*this);\n"
		"    if (*doc) delete *doc;\n"
		"\n"
		"    if(prev) next = next;\n"
		"    else *chain = next;\n"
		"\n"
		"    for (tp::iterator it = p.begin(); it != p.end(); ++it) {\n"
		"        fill( m, **it );\n"
		"    }\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, GlobalVariables)
{
	// test with global variables
	char textIn[] =
		"\n// global variables\n"
		"ostream* _err = &cerr;\n"
		"ASConsole* g_console;\n"
		"stringstream* _err = NULL;\n";
	char text[] =
		"\n// global variables\n"
		"ostream *_err = &cerr;\n"
		"ASConsole *g_console;\n"
		"stringstream *_err = NULL;\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, GlobalDeclarations)
{
	// test with global declarations
	char textIn[] =
		"\n// function declarations\n"
		"void* foo(char*fooBar);\n"
		"char&bar(char&);\n";
	char text[] =
		"\n// function declarations\n"
		"void *foo(char *fooBar);\n"
		"char &bar(char &);\n";;
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Cast1)
{
	// cast should be space padded
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string* bar;          // comment0\n"
		"    foo = (RefNode**) bar();    // comment1\n"
		"    foo = (RefNode*) bar();     // comment2\n"
		"    foo = ( RefNode** ) bar();  // comment1\n"
		"    foo = ( RefNode* ) bar();   // comment2\n"
		"    foo = const_cast<RefNode**>(bar());  // comment3\n"
		"    foo = const_cast<RefNode*>(bar());   // comment4\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    const string *bar;          // comment0\n"
		"    foo = (RefNode **) bar();   // comment1\n"
		"    foo = (RefNode *) bar();    // comment2\n"
		"    foo = ( RefNode ** ) bar(); // comment1\n"
		"    foo = ( RefNode * ) bar();  // comment2\n"
		"    foo = const_cast<RefNode **>(bar()); // comment3\n"
		"    foo = const_cast<RefNode *>(bar());  // comment4\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Cast2)
{
	// cast should be space padded
	char textIn[] =
		"\nvoid foo(void*, void*);\n"
		"void foo(void*fooBar, void* fooBar);\n";
	char text[] =
		"\nvoid foo(void *, void *);\n"
		"void foo(void *fooBar, void *fooBar);\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, ConvertTabs)
{
	// test tab conversion on type
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox*	channel;\n"
		"    wxTextCtrl*	filename;\n"
		"    char		*	stamp;\n"
		"    void*			userData;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxListBox  *channel;\n"
		"    wxTextCtrl *filename;\n"
		"    char           *stamp;\n"
		"    void           *userData;\n"
		"}\n";
	char options[] = "align-pointer=name, convert-tabs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Paren)
{
	// test pointer recognition in a paren
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject * p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(cbProject *p = pm->GetProject())\n"
		"        getBar();\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, PointerToPointer)
{
	// test double pointer
	char textIn[] =
		"\nint main(int argc, char** argv)\n"
		"{\n"
		"    char**    bar1;\n"
		"    char  **  bar1;\n"
		"    char    **bar1;\n"
		"    char	**	bar1;\n"
		"    char		**		bar1;\n"
		"}\n";
	char text[] =
		"\nint main(int argc, char **argv)\n"
		"{\n"
		"    char    **bar1;\n"
		"    char    **bar1;\n"
		"    char    **bar1;\n"
		"    char		**bar1;\n"
		"    char				**bar1;\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, EndOfLine1)
{
	// test pointer at end of line
	char textIn[] =
		"\nvoid*\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n";
	char text[] =
		"\nvoid *\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n";
	char options[] = "align-pointer=name, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, EndOfLine2)
{
	// test pointer at end of line with spaces or comment after
	char textIn[] =
		"\nvoid*   \n"
		"foo() {}\n"
		"\n"
		"char &   \n"
		"bar() {}\n"
		"\n"
		"void*      // comment  \n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */  \n"
		"foo() {}\n"
		"\n"
		"char**   \n"
		"bar() {}\n";
	char text[] =
		"\nvoid *\n"
		"foo() {}\n"
		"\n"
		"char &\n"
		"bar() {}\n"
		"\n"
		"void *     // comment\n"
		"foo() {}\n"
		"\n"
		"void **    /* comment */\n"
		"foo() {}\n"
		"\n"
		"char **\n"
		"bar() {}\n";
	char options[] = "align-pointer=name, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Comment)
{
	// test pointer with comment after
	char textIn[] =
		"\nvoid Foo(WordList*/*keyword*/,\n"
		"         WordList**/*keyword*/) {\n"
		"}\n";
	char text[] =
		"\nvoid Foo(WordList */*keyword*/,\n"
		"         WordList **/*keyword*/) {\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, OperatorOverload)
{
	// test pointer with overloaded operator
	char textIn[] =
		"\nclass Foo\n"
		"{\n"
		"    T& operator* () const {};\n"
		"    T * operator-> () {};\n"
		"};\n";
	char text[] =
		"\nclass Foo\n"
		"{\n"
		"    T &operator* () const {};\n"
		"    T *operator-> () {};\n"
		"};\n";
	char options[] = "align-pointer=name, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, ConversionOperator)
{
	// test pointer with conversion operator
	char textIn[] =
		"\n// conversion operator declarations\n"
		"operator EventRef &() { return fEvent; }\n"
		"operator HIRect * () { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef&();\n"
		"operator HIRect *();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef& rf = (EventRef&) tf;\n"
		"HIRect *pr   = (HIRect *) tr;\n"
		"bool bb      = (bool) tb;\n";
	char text[] =
		"\n// conversion operator declarations\n"
		"operator EventRef &() { return fEvent; }\n"
		"operator HIRect *() { return this; }\n"
		"operator bool() { return len ? true : false; }\n"
		"\n"
		"// conversion operator definitions\n"
		"operator EventRef &();\n"
		"operator HIRect *();\n"
		"operator bool() const;\n"
		"\n"
		"// conversion operator casts\n"
		"EventRef &rf = (EventRef &) tf;\n"
		"HIRect *pr   = (HIRect *) tr;\n"
		"bool bb      = (bool) tb;\n";
	char options[] = "align-pointer=name, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, ScopeResolution)
{
	// should not pad scope resolution operator
	char textIn[] =
		"\nstruct CV {\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType:: *var;\n"
		"    VarType TClassType::* var;\n"
		"    VarType TClassType:: * var;\n"
		"} cv;\n";
	char text[] =
		"\nstruct CV {\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType::*var;\n"
		"    VarType TClassType::*var;\n"
		"} cv;\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, PadParenOutside)
{
	// test align-pointer with pad-paren-out
	char textIn[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR)& showIcon},\n"
		"        { Dynamic,  (LPTSTR) & isDynamic},\n"
		"        { Maxtext,  (LPTSTR) &maxText},\n"
		"        { IconID,   (LPTSTR)&iconID},\n"
		"    };\n"
		"}";
	char text[] =
		"\nBOOL RegisterServer() {\n"
		"    static DOREGSTRUCT ClsidEntries[] = {\n"
		"        { ShowIcon, (LPTSTR) &showIcon},\n"
		"        { Dynamic,  (LPTSTR) &isDynamic},\n"
		"        { Maxtext,  (LPTSTR) &maxText},\n"
		"        { IconID,   (LPTSTR) &iconID},\n"
		"    };\n"
		"}";
	char options[] = "align-pointer=name, pad-paren-out";
	char* textOut1 = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	// format twice to be sure an extra space is not added
	char* textOut = AStyleMain(textOut1, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut1;
	delete [] textOut;
}

TEST(AlignPointerName, UnpadParen)
{
	// unpad-paren should NOT delete space padding
	char textIn[] =
		"\nLUA_API lua_State*     (lua_tothread)(lua_State *L, int idx);\n"
		"LUA_API const void*     (lua_topointer)(lua_State *L, int idx);\n";
	char text[] =
		"\nLUA_API lua_State     *(lua_tothread)(lua_State *L, int idx);\n"
		"LUA_API const void     *(lua_topointer)(lua_State *L, int idx);\n";
	char options[] = "align-pointer=name, unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Catch)
{
	// 'catch' statement is a reference, not an operator
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    try {\n"
		"        wxBufferedInputStream fb(fs);\n"
		"    }\n"
		"    catch (cbException&ex) {\n"
		"        ex.ShowErrorMessage(true);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    try {\n"
		"        wxBufferedInputStream fb(fs);\n"
		"    }\n"
		"    catch (cbException &ex) {\n"
		"        ex.ShowErrorMessage(true);\n"
		"    }\n"
		"}\n";
	char options[] = "align-pointer=name, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, AndOperator)
{
	// should not unpad && operator
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo() && isBar())   // comment\n"
		"        return;\n"
		"    if (isFoo && isBar)   // comment\n"
		"        return;\n"
		"    if (isFoo\n"
		"            && isBar1)   // comment\n"
		"        return;\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Sans1)
{
	// these are not pointers
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a *= b;\n"
		"    a &= b;\n"
		"    a && b;\n"
		"    x = a * b;\n"
		"    x = a & b;\n"
		"    bar[boo*foo-1] = 2;\n"
		"}\n";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName, Sans2)
{
	// these should be padded as operators
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    a*=b;\n"
		"    a&=b;\n"
		"    a&&b;\n"
		"    x=a*b;\n"
		"    x=a&b;\n"
		"    if (len*tab>longest) bar();\n"
		"    SetWidth(width()+(pixels*indentAmt));\n"
		"    if (m_Flags&flLocal) return;\n"
		"    Link(m_y+.5*h-.5*m_fontSize);\n"
		"    if ((Flags&flVariable)&&(Flags&flId))\n"
		"        bar();\n"
		"    out_html(change_to_size(i*j));\n"
		"    if (i>*maxcol) *maxcol=i;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    a *= b;\n"
		"    a &= b;\n"
		"    a && b;\n"
		"    x = a * b;\n"
		"    x = a & b;\n"
		"    if (len * tab > longest) bar();\n"
		"    SetWidth(width() + (pixels * indentAmt));\n"
		"    if (m_Flags & flLocal) return;\n"
		"    Link(m_y + .5 * h - .5 * m_fontSize);\n"
		"    if ((Flags & flVariable) && (Flags & flId))\n"
		"        bar();\n"
		"    out_html(change_to_size(i * j));\n"
		"    if (i > *maxcol) *maxcol = i;\n"
		"}\n";
	char options[] = "align-pointer=name, pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointer, ShortLowerLimit)
{
	// test error handling for the short option lower limit
	// should call the error handler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	// use errorHandler2 to verify the error
	char options[] = "-k0";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(AlignPointer, ShortUpperLimit)
{
	// test error handling for the short option upper limit
	// should call the error handler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	// use errorHandler2 to verify the error
	char options[] = "-k4";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(AlignPointer, Java)
{
	// align-pointer should have no effect on Java
	// should pad-oper not align-pointer=type
	char textIn[] =
		"\nbool foo()\n"
		"{\n"
		"    StringBuilder s = new StringBuilder(length*count);\n"
		"    return (modifier&query) == query;\n"
		"}\n";
	char text[] =
		"\nbool foo()\n"
		"{\n"
		"    StringBuilder s = new StringBuilder(length * count);\n"
		"    return (modifier & query) == query;\n"
		"}\n";
	char options[] = "mode=java, pad-oper, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignPointer, Sharp)
{
	// align-pointer should have no effect on C#
	// should pad-oper not align-pointer=type
	char textIn[] =
		"\nbool foo()\n"
		"{\n"
		"    StringBuilder s = new StringBuilder(length*count);\n"
		"    return (modifier&query) == query;\n"
		"}\n";
	char text[] =
		"\nbool foo()\n"
		"{\n"
		"    StringBuilder s = new StringBuilder(length * count);\n"
		"    return (modifier & query) == query;\n"
		"}\n";
	char options[] = "mode=cs, pad-oper, align-pointer=type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
