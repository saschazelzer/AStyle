//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-------------------------------------------------------------------------
// AStyle Break Closing Brackets
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(BreakClosingBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsBreak)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsAttach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsLinux)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsStroustrup)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsKeepBlocks)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsElseSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsCatch)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsCatchSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsWhile)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakClosingBracketsWhileSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Break Else If
//-------------------------------------------------------------------------

TEST(BreakElseIfs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfsShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfsSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(BreakElseIfsKeepOneLine)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Keep One Line Statements
//-------------------------------------------------------------------------

TEST(KeepOneLineStatements)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineStatementsShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Keep One Line Blocks
//-------------------------------------------------------------------------

TEST(KeepOneLineBlocks)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; i=i-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksShort)
{
	// test keep one line blocks short option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!j) { j=1; i=i-10; }\n"
		"}\n";
	char options[] = "-O";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksNoneBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksBreakBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksAttachBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(KeepOneLineBlocksLinuxBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksHorstmannBrackets)
{
	// test keep one line blocks
	char text[] =
		"\nvoid foo()\n"
		"{   if (comment&&code) { ++codecomments_lines; }\n"
		"    else if (comment) { ++comment_lines; }\n"
		"    else if (code) { ++code_lines; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksBreakElseIf)
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
		"        { j=1; if (i) i=i-10; }\n"
		"    if (!j)\n"
		"        { j=1; if (i) i=i-10; else i=i-20; }\n"
		"    if (!j)\n"
		"        { j=1; if (i) i=i-10; else if (j) j=j-10; }\n"
		"}\n";
	char options[] = "keep-one-line-blocks, break-elseifs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksKeepOneLineStatementsAndBreakElseIf)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksMultipleBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksSans1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksSans2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksSansMultipleBrackets)
{
	// test without keep one line blocks with multiple brackets
	// TODO: this is wrong on the next-to-last line
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
		"        add { } remove { } }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksNoneRunIn)
{
	// test none brackets with keep one line blocks and run-in
	// should not indent the run-in
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo)\n"
		"        {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksHorstmannRunIn)
{
	// test horstmann brackets with keep one line blocks and run-in
	// should not indent the run-in
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo)\n"
		"        {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksNoneClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo)\n"
		"        {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksBreakClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"        {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksAttachClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo)\n"
		"        {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(KeepOneLineBlocksLinuxClosingHeader)
{
	// test keep one line blocks followed by a closing header
	// should not attach header to the one line statement
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"        {/*ok*/;}\n"
		"    else {bar();}\n"
		"}\n";
	char options[] = "keep-one-line-blocks, brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Add Brackets
//-------------------------------------------------------------------------

TEST(AddBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(AddBracketsAll)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsElseIf)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsSharp)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsKeepOneLiners)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsSingleLine)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsSingleLineKeepOneLiners)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsBreak)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsAttach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsHorstmann)
{
	// test add brackets for horstmann brakets
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
	char options[] = "add-brackets, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsExtraSpaces)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsElseParen)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsQuote)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsQuoteSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsComment)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddBracketsSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Add One Line Brackets
// Implies keep-one-line-blocks
//-------------------------------------------------------------------------

TEST(AddOneLineBrackets)
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
		"        { return false; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsShort)
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
		"        { return false; }\n"
		"}\n";
	char options[] = "-J";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(AddOneLineBracketsAll)
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
		"        { return false; }\n"
		"\n"
		"    if (isFoo())\n"
		"        { return false; }\n"
		"    else\n"
		"        { return true; }\n"
		"\n"
		"    for (int i = 0; i <= 12; ++i)\n"
		"        { bar &= ::FooBar(); }\n"
		"\n"
		"    while (isFoo)\n"
		"        { bar(); }\n"
		"\n"
		"    do\n"
		"        { bar(); }\n"
		"    while (isFoo);\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsElseIf)
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
		"        { return false; }\n"
		"    else if (isFoo())\n"
		"        { return false; }\n"
		"}\n";
	char options[] = "add-one-line-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsSharp)
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
		"        { System.Console.WriteLine(i); }\n"
		"\n"
		"    if (isFoo)\n"
		"        bar(delegate { fooBar* = null; });\n"
		"}\n";
	char options[] = "add-one-line-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsSingleLine)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsSingleLineKeepOneLiners)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsBreak)
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
		"        { return false; }\n"
		"    else\n"
		"        { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsAttach)
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
		"        { return false; }\n"
		"    else\n"
		"        { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsHorstmann)
{
	// test add one line brackets for horstmann brakets
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
		"        { return false; }\n"
		"    else\n"
		"        { return true; }\n"
		"}\n";
	char options[] = "add-one-line-brackets, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsExtraSpaces)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsElseParen)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsQuote)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsQuoteSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsComment)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AddOneLineBracketsSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Convert Tabs
//-------------------------------------------------------------------------

TEST(ConvertTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsMisc1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsMisc2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsMisc3)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsMisc4)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsMisc5)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ConvertTabsMisc6)
{
	// verify that tabs are still present within quotes
	// should NOT have been replaced when AStyle was run
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* quote = \"this	is	a	quote \";\n"
		"}\n";
	// just check for the tab characters
	CHECK_EQUAL('\t', text[37]);
	CHECK_EQUAL('\t', text[40]);
	CHECK_EQUAL('\t', text[42]);
}

//-------------------------------------------------------------------------
// AStyle Align Pointer
//-------------------------------------------------------------------------
TEST(AlignPointerNone)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneAddressOf)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneDereference)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneCast1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneCast2)
{
	// cast should not be changed
	char text[] =
		"\nvoid foo(void *, void *);\n"
		"void foo(void *fooBar, void * fooBar);\n"
		"void foo(void **, void**);\n"
		"void foo(wxCommandEvent &);\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneConvertTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNoneParen)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNonePointerToPointer)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerType)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeFromCentered)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeAddressOf)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeDereference)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeCast1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeCast2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeConvertTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeParen)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypePointerToPointer)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeCatch)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeAndOperator)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeSans1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerTypeSans2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddle)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleAddressOf)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleDereference)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleCast1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleCast2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleConvertTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleParen)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddlePointerToPointer)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleCatch)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleAndOperator)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleSans1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerMiddleSans2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerName)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameFromCentered)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameAddressOf)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameDereference)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameCast1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameCast2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameConvertTabs)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameParen)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNamePointerToPointer)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameCatch)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameAndOperator)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameSans1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerNameSans2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerShortLowerLimit)
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
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(AlignPointerShortUpperLimit)
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
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	delete [] textOut;
}

TEST(AlignPointerJava)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignPointerSharp)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle line ends
// there are other tests in AStyleTestCon
//----------------------------------------------------------------------------

struct testLineEnds
{
	string textLinuxStr;
	string textWindowsStr;
	string textMacOldStr;
	const char* textLinux;
	const char* textWindows;
	const char* textMacOld;

	testLineEnds()
	{
		textLinuxStr =
			"\nvoid foo()\n"
			"{\n"
			"    bar()\n"
			"}\n";
		textWindowsStr =
			"\r\nvoid foo()\r\n"
			"{\r\n"
			"    bar()\r\n"
			"}\r\n";
		textMacOldStr =
			"\rvoid foo()\r"
			"{\r"
			"    bar()\r"
			"}\r";
		textLinux = textLinuxStr.c_str();
		textWindows = textWindowsStr.c_str();
		textMacOld = textMacOldStr.c_str();
	}
};

TEST_FIXTURE(testLineEnds, defaultLinux)
{
	// test default Linux line ends
	char options[] = "";
	char* textOut = AStyleMain(textLinux, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textLinux, textOut);
	delete [] textOut;
}

TEST_FIXTURE(testLineEnds, defaultWindows)
{
	// test default Windows line ends
	char options[] = "";
	char* textOut = AStyleMain(textWindows, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textWindows, textOut);
	delete [] textOut;
}

TEST_FIXTURE(testLineEnds, defaultMacOld)
{
	// test default MacOld line ends
	char options[] = "";
	char* textOut = AStyleMain(textMacOld, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textMacOld, textOut);
	delete [] textOut;
}

TEST_FIXTURE(testLineEnds, defaultBadWindows)
{
	// test default Windows with line end characters reversed
	// should be converted to Windows
	char textBadWindows[] =
		"\n\rvoid foo()\n\r"
		"{\n\r"
		"    bar()\n\r"
		"}\n\r";
	char options[] = "";
	char* textOut = AStyleMain(textBadWindows, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textWindows, textOut);
	delete [] textOut;
}
