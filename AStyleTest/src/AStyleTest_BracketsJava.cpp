//-----------------------------------------------------------------------------
// AStyle Java Bracket Options
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-----------------------------------------------------------------------------
// AStyle Java Bracket Options
//-----------------------------------------------------------------------------

//-------------------------------------------------------------------------
// AStyle Java Common Text for Testing
//-------------------------------------------------------------------------

struct javaText
{
	string textStr;
	const char* textIn;

	javaText()
	{
		textStr =
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

		textIn = textStr.c_str();
	}
};

//-------------------------------------------------------------------------
// AStyle Java Default Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsNone)
{
	// test default brackets option (do not change)
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

	char options[] = "mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsNoneBlocks)
{
	// test default blocks option, with indent blocks
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n";

	char options[] = "indent-blocks, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(javaText, JavaBracketsNoneBrackets)
{
	// test default brackets option, with indent brackets
	char text[] =
		"\npublic class FooClass\n"
		"    {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"        {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"            }\n"
		"        else {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n";

	char options[] = "indent-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsNoneEmptyBrackets)
{
	// test default brackets option (do not change)
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsNoneBreak)
{
	// test default brackets option with broken brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsNoneAttach)
{
	// test default brackets option with attached brackets
	char text[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsNoneLinux)
{
	// test default brackets option with linux brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsNoneHorstmann)
{
	// test default brackets option with horstmann brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Break Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsBreak)
{
	// test break brackets option
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
		"        {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsBreakShort)
{
	// test break brackets short option
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
		"        {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "-b, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsBreakBlocks)
{
	// test break brackets option, with indent blocks
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo)\n"
		"            {\n"
		"                bar();\n"
		"            }\n"
		"        else\n"
		"            {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=break, indent-blocks, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(javaText, JavaBracketsBreakBrackets)
{
	// test break brackets option, with indent brackets
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
		"            {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n";

	char options[] = "brackets=break, indent-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsBreakEmptyBrackets)
{
	// test break brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(JavaBracketsBreakBreak)
{
	// test break brackets option with broken brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsBreakAttach)
{
	// test break brackets option with attached brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsBreakLinux)
{
	// test break brackets option with linux brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsBreakHorstmann)
{
	// test break brackets option with horstmann brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Attach Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsAttach)
{
	// test attach brackets option
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsAttachShort)
{
	// test attach brackets short option
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        } else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "-a, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsAttachBlocks)
{
	// test attach brackets option, with indent blocks
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=attach, indent-blocks, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsAttachBrackets)
{
	// test attach brackets option, with indent brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"            }\n"
		"        else {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n";

	char options[] = "brackets=attach, indent-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsAttachBreakClosing)
{
	// test attach brackets option, with break closing brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo) {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        }\n"
		"        else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=attach, break-closing-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsAttachEmptyBrackets)
{
	// test attach brackets option
	// attach both brackets
	char textIn[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char text[] =
		"\npublic class FooClass {\n"
		"    public FooClass() {}\n"
		"    public FooClass() {}\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsAttachBreak)
{
	// test attach brackets option with broken brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsAttachAttach)
{
	// test attach brackets option with attached brackets
	char text[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsAttachLinux)
{
	// test attach brackets option with linux brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsAttachHorstmann)
{
	// test attach brackets option with horstmann brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Linux Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsLinux)
{
	// test linux brackets option
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

	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsLinuxShort)
{
	// test linux brackets short option
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
	char options[] = "-l, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsLinuxBlocks)
{
	// test linux blocks option, with indent blocks
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=linux, indent-blocks, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsLinuxBrackets)
{
	// test linux brackets option, with indent brackets
	char text[] =
		"\npublic class FooClass\n"
		"    {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"        {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"            }\n"
		"        else {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n";

	char options[] = "brackets=linux, indent-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsLinuxBreakClosing)
{
	// test linux brackets option, with break closing brackets
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
		"        }\n"
		"        else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=linux, break-closing-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsLinuxEmptyBrackets)
{
	// test linux brackets option
	// do not change empty broken brackets
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(JavaBracketsLinuxBreak)
{
	// test linux brackets option with broken brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsLinuxAttach)
{
	// test linux brackets option with attached brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsLinuxLinux)
{
	// test linux brackets option with linux brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsLinuxHorstmann)
{
	// test linux brackets option with horstmann brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Stroustrup Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsStroustrup)
{
	// test stroustrup brackets option
	char text[] =
		"\npublic class FooClass {\n"
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

	char options[] = "brackets=stroustrup, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsStroustrupShort)
{
	// test stroustrup brackets short option
	char text[] =
		"\npublic class FooClass {\n"
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
	char options[] = "-u, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsStroustrupBlocks)
{
	// test stroustrup brackets option, with indent blocks
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=stroustrup, indent-blocks, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsStroustrupBrackets)
{
	// test stroustrup brackets option, with indent brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"        {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"            }\n"
		"        else {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n";

	char options[] = "brackets=stroustrup, indent-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsStroustrupBreakClosing)
{
	// test stroustrup brackets option, with brea closing brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        }\n"
		"        else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=stroustrup, break-closing-brackets, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsStroustrupEmptyBrackets)
{
	// test stroustrup brackets option
	// do not change empty broken brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=stroustrup, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Horstmann Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsHorstmann)
{
	// test horstmann brackets option
	char text[] =
		"\npublic class FooClass\n"
		"{   private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"        else\n"
		"        {   anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsHorstmannShort)
{
	// test horstmann brackets short option
	char text[] =
		"\npublic class FooClass\n"
		"{   private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"        else\n"
		"        {   anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "-g, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsHorstmannBlocks)
{
	// test horstmann brackets option, with indent blocks
	char text[] =
		"\npublic class FooClass\n"
		"{   private bool var1;\n"
		"    private bool var2;\n"
		"\n"
		"    public void foo(bool isFoo)\n"
		"    {   if (isFoo)\n"
		"            {   bar();\n"
		"            }\n"
		"        else\n"
		"            {   anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n";

	char options[] = "brackets=horstmann, indent-blocks, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsHorstmannEmptyBrackets)
{
	// test horstmann brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass\n"
		"{   public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsHorstmannBreak)
{
	// test horstmann brackets option with broken brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsHorstmannAttach)
{
	// test horstmann brackets option with attached brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsHorstmannLinux)
{
	// test horstmann brackets option with linux brackets
	char textIn[] =
		"\npublic void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsHorstmannHorstmann)
{
	// test horstmann brackets option with horstmann brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Other Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsOtherNamespace)
{
	// indent namespaces should NOT affect java formatting
	char options[] = "indent-namespaces, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsOtherClass)
{
	// indent classes should NOT affect java formatting
	char options[] = "indent-classes, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsOtherNamespaceClass)
{
	// indent namespaces and classes should NOT affect java formatting
	char options[] = "indent-namespaces, indent-classes, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherInterface)
{
	// test default brackets option (do not change)
	char text[] =
		"\npublic interface FooIF\n"
		"{\n"
		"    public void foo1();\n"
		"    public void foo2();\n"
		"}\n";

	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherInterfaceBlocks)
{
	// test interface with indent blocks option
	// should not indent the interface
	char text[] =
		"\npublic interface FooIF\n"
		"{\n"
		"    public void foo1();\n"
		"    public void foo2();\n"
		"}\n";

	char options[] = "indent-blocks, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherInterfaceBrackets)
{
	// test interface with indent brackets option
	char text[] =
		"\npublic interface FooIF\n"
		"    {\n"
		"    public void foo1();\n"
		"    public void foo2();\n"
		"    }\n";

	char options[] = "indent-brackets, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherNestedClass)
{
	// test interface with nested classes
	char text[] =
		"\npublic class A\n"
		"{\n"
		"    public int foo1;\n"
		"    public class B\n"
		"    {\n"
		"        public int foo2;\n"
		"        public class C\n"
		"        {\n"
		"            public void foo(bool isFoo)\n"
		"            {\n"
		"                if (isFoo)\n"
		"                {\n"
		"                    bar();\n"
		"                }\n"
		"                else\n"
		"                    anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherNestedClassBlocks)
{
	// test interface with nested classes and indented blocks
	char text[] =
		"\npublic class A\n"
		"{\n"
		"    public int foo1;\n"
		"    public class B\n"
		"    {\n"
		"        public int foo2;\n"
		"        public class C\n"
		"        {\n"
		"            public void foo(bool isFoo)\n"
		"            {\n"
		"                if (isFoo)\n"
		"                    {\n"
		"                        bar();\n"
		"                    }\n"
		"                else\n"
		"                    anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";

	char options[] = "indent-blocks, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherNestedClassBrackets)
{
	// test interface with nested classes and indented brackets
	char text[] =
		"\npublic class A\n"
		"    {\n"
		"    public int foo1;\n"
		"    public class B\n"
		"        {\n"
		"        public int foo2;\n"
		"        public class C\n"
		"            {\n"
		"            public void foo(bool isFoo)\n"
		"                {\n"
		"                if (isFoo)\n"
		"                    {\n"
		"                    bar();\n"
		"                    }\n"
		"                else\n"
		"                    anotherBar();\n"
		"                }\n"
		"            }\n"
		"        }\n"
		"    }\n";

	char options[] = "indent-brackets, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherStaticConstructor)
{
	// test gnu style option, with static constructor
	// sould NOT indent the method opening bracket
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool foo;\n"
		"    private int  bar;\n"
		"\n"
		"    static\n"
		"    {\n"
		"        if (foo)\n"
		"        {\n"
		"            bar = 0;\n"
		"        }\n"
		"        else\n"
		"            bar = 1;\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(JavaBracketsOtherStaticConstructorBlocks)
{
	// test gnu style option, with static constructor
	// sould NOT indent the method opening bracket
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool foo;\n"
		"    private int  bar;\n"
		"\n"
		"    static\n"
		"    {\n"
		"        if (foo)\n"
		"            {\n"
		"                bar = 0;\n"
		"            }\n"
		"        else\n"
		"            bar = 1;\n"
		"    }\n"
		"}\n"
		"\n";
	char options[] = "indent-blocks, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherStaticConstructorBrackets)
{
	// test gnu style option, with static constructor
	// should NOT indent the method opening bracket
	char text[] =
		"\npublic class FooClass\n"
		"    {\n"
		"    private bool foo;\n"
		"    private int  bar;\n"
		"\n"
		"    static\n"
		"        {\n"
		"        if (foo)\n"
		"            {\n"
		"            bar = 0;\n"
		"            }\n"
		"        else\n"
		"            bar = 1;\n"
		"        }\n"
		"    }\n"
		"\n";
	char options[] = "indent-brackets, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherThrows)
{
	// test a method that contains a throws statement
	// should be recognized as a block opener
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool foo;\n"
		"    private int  bar;\n"
		"\n"
		"    public void fooBar() throws IOException\n"
		"    {\n"
		"        if (foo)\n"
		"        {\n"
		"            throw new IOException(bar);\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherThrowsBlocks)
{
	// test a method that contains a throws statement, with indent blocks
	// should be recognized as a block opener
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool foo;\n"
		"    private int  bar;\n"
		"\n"
		"    public void fooBar() throws IOException\n"
		"    {\n"
		"        if (foo)\n"
		"            {\n"
		"                throw new IOException(bar);\n"
		"            }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-blocks, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherThrowsBrackets)
{
	// test a method that contains a throws statement, with indent brackets
	// should be recognized as a block opener
	char text[] =
		"\npublic class FooClass\n"
		"    {\n"
		"    static private bool foo;\n"
		"    static private int  bar;\n"
		"\n"
		"    public void fooBar() throws IOException\n"
		"        {\n"
		"        if (foo)\n"
		"            {\n"
		"            throw new IOException(bar);\n"
		"            }\n"
		"        }\n"
		"    }\n";
	char options[] = "indent-brackets, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherNewOperator1)
{
	// test new operator ending with })
	char text[] =
		"\npublic class fooClass\n"
		"{\n"
		"    public Foo()\n"
		"    {\n"
		"        foo(new bar()\n"
		"        {\n"
		"            public void fooBar(ChangeEvent e)\n"
		"            {\n"
		"                int x = 2;\n"
		"            }\n"
		"        });\n"
		"\n"
		"        mlist.setListData(new Object [] { });\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOtherNewOperator2)
{
	// test new operator ending with }.start();
	char text[] =
		"\npublic class fooClass\n"
		"{\n"
		"    public Foo()\n"
		"    {\n"
		"        new Thread(\"Sizesavingdelay\")\n"
		"        {\n"
		"        } .start();\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Array Bracket Options
//-------------------------------------------------------------------------

TEST(JavaBracketsArray1)
{
	// the following "new Type" array should have an in statement indent
	// must view the whitespace to see the in statement indent
	char text[] =
		"\npublic class ClassUtil implements Constants\n"
		"{\n"
		"	static void generateMethod()\n"
		"	{\n"
		"		cv.visitMethodInsn(\n"
		"		    Type.getMethodDescriptor(\n"
		"		        Type.getType(Object.class),\n"
		"		        new Type [] {\n"
		"		            Type.getType(String.class),\n"
		"		            Type.getType(Object [].class),\n"
		"		            Type.getType(Boolean.TYPE)\n"
		"		        }\n"
		"		    )\n"
		"		);\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

// TODO: add more tests for java array brackets
