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

TEST_FIXTURE(javaText, JavaBracketsNone_Blocks)
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


TEST_FIXTURE(javaText, JavaBracketsNone_Brackets)
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

TEST(JavaBracketsNone_EmptyBrackets)
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

TEST(JavaBracketsNone_Break)
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

TEST(JavaBracketsNone_Attach)
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

TEST(JavaBracketsNone_Linux)
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

TEST(JavaBracketsNone_Horstmann)
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

TEST(JavaBracketsNone_EnumConstructorBreak)
{
	// test defzult brackets option with an enum constructor
	char text[] =
		"\npublic enum Scope\n"
		"{\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsNone_EnumConstructorAttach)
{
	// test default brackets option with an enum constructor
	char text[] =
		"\npublic enum Scope {\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s) {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes) {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(JavaBracketsNone_EnumConstructorHorstmann)
{
	// test default brackets option with an enum constructor
	char text[] =
		"\npublic enum Scope\n"
		"{   global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {   Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {   if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
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

TEST_FIXTURE(javaText, JavaBracketsBreak_Short)
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

TEST_FIXTURE(javaText, JavaBracketsBreak_Blocks)
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


TEST_FIXTURE(javaText, JavaBracketsBreak_Brackets)
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

TEST(JavaBracketsBreak_EmptyBrackets)
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
TEST(JavaBracketsBreak_Break)
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

TEST(JavaBracketsBreak_Attach)
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

TEST(JavaBracketsBreak_Linux)
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

TEST(JavaBracketsBreak_Horstmann)
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

TEST(JavaBracketsBreak_EnumConstructor)
{
	// test break brackets option with an enum constructor
	char textIn[] =
		"\npublic enum Scope {\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s) {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes) {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic enum Scope\n"
		"{\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
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

TEST_FIXTURE(javaText, JavaBracketsAttach_Short)
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

TEST_FIXTURE(javaText, JavaBracketsAttach_Blocks)
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

TEST_FIXTURE(javaText, JavaBracketsAttach_Brackets)
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

TEST_FIXTURE(javaText, JavaBracketsAttach_BreakClosing)
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

TEST(JavaBracketsAttach_EmptyBrackets)
{
	// test attach brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsAttach_Break)
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

TEST(JavaBracketsAttach_Attach)
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

TEST(JavaBracketsAttach_Linux)
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

TEST(JavaBracketsAttach_Horstmann)
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

TEST(JavaBracketsAttach_EnumConstructor)
{
	// test attach brackets option with an enum constructor
	char textIn[] =
		"\npublic enum Scope\n"
		"{\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic enum Scope {\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s) {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes) {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
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

TEST_FIXTURE(javaText, JavaBracketsLinux_Short)
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

TEST_FIXTURE(javaText, JavaBracketsLinux_Blocks)
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

TEST_FIXTURE(javaText, JavaBracketsLinux_Brackets)
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

TEST_FIXTURE(javaText, JavaBracketsLinux_BreakClosing)
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

TEST(JavaBracketsLinux_EmptyBrackets)
{
	// test linux brackets option
	// do not change empty brackets
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
TEST(JavaBracketsLinux_Break)
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

TEST(JavaBracketsLinux_Attach)
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

TEST(JavaBracketsLinux_Linux)
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

TEST(JavaBracketsLinux_Horstmann)
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

TEST(JavaBracketsLinux_EnumConstructor)
{
	// test linux brackets option with an enum constructor
	char textIn[] =
		"\npublic enum Scope\n"
		"{\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic enum Scope {\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes) {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
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

TEST_FIXTURE(javaText, JavaBracketsStroustrup_Short)
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

TEST_FIXTURE(javaText, JavaBracketsStroustrup_Blocks)
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

TEST_FIXTURE(javaText, JavaBracketsStroustrup_Brackets)
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

TEST_FIXTURE(javaText, JavaBracketsStroustrup_BreakClosing)
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

TEST(JavaBracketsStroustrup_EmptyBrackets)
{
	// test stroustrup brackets option
	// do not change empty brackets
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

TEST(JavaBracketsStroustrup_EnumConstructor)
{
	// test stroustrup brackets option with an enum constructor
	char textIn[] =
		"\npublic enum Scope\n"
		"{\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic enum Scope {\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes) {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
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

TEST_FIXTURE(javaText, JavaBracketsHorstmann_Short)
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

TEST_FIXTURE(javaText, JavaBracketsHorstmann_Blocks)
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

TEST(JavaBracketsHorstmann_EmptyBrackets)
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

TEST(JavaBracketsHorstmann_Break)
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

TEST(JavaBracketsHorstmann_Attach)
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

TEST(JavaBracketsHorstmann_Linux)
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

TEST(JavaBracketsHorstmann_Horstmann)
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

TEST(JavaBracketsHorstmann_EnumConstructor)
{
	// test horstmann brackets option with an enum constructor
	char textIn[] =
		"\npublic enum Scope\n"
		"{\n"
		"    global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {\n"
		"        Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {\n"
		"            if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\npublic enum Scope\n"
		"{   global, view, editpane;\n"
		"\n"
		"    public static Scope fromString(String s)\n"
		"    {   Scope[] scopes = values();\n"
		"        for (Scope scope: scopes)\n"
		"        {   if (scope.toString().equals(s))\n"
		"                return scope;\n"
		"        }\n"
		"\n"
		"        return global;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Other Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(javaText, JavaBracketsOther_Namespace)
{
	// indent namespaces should NOT affect java formatting
	char options[] = "indent-namespaces, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsOther_Class)
{
	// indent classes should NOT affect java formatting
	char options[] = "indent-classes, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST_FIXTURE(javaText, JavaBracketsOther_NamespaceClass)
{
	// indent namespaces and classes should NOT affect java formatting
	char options[] = "indent-namespaces, indent-classes, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOther_ClassContinuationAttached)
{
	// test with class continuaton and attached brackets
	char text[] =
		"\npublic class Foo\n"
		"    extends Bar1\n"
		"    implements Bar2 {\n"
		"    private int FOO = 1;\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOther_ClassContinuationBroken)
{
	// test with class continuaton and broken brackets
	char text[] =
		"\npublic class Foo\n"
		"    extends Bar1\n"
		"    implements Bar2\n"
		"{\n"
		"    private int FOO = 1;\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsOther_Interface)
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

TEST(JavaBracketsOther_InterfaceBlocks)
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

TEST(JavaBracketsOther_InterfaceBrackets)
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

TEST(JavaBracketsOther_NestedClass)
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

TEST(JavaBracketsOther_NestedClassBlocks)
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

TEST(JavaBracketsOther_NestedClassBrackets)
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

TEST(JavaBracketsOther_StaticConstructor)
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
TEST(JavaBracketsOther_StaticConstructorBlocks)
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

TEST(JavaBracketsOther_StaticConstructorBrackets)
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

TEST(JavaBracketsOther_Throws)
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

TEST(JavaBracketsOther_ThrowsBlocks)
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

TEST(JavaBracketsOther_ThrowsBrackets)
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

TEST(JavaBracketsOther_NewOperator1)
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

TEST(JavaBracketsOther_NewOperator2)
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

TEST(JavaBracketsArrayNone_InStatement)
{
	// the following "new Type" array should have an in statement indent
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

TEST(JavaBracketsArrayNone_OneLineBlock1)
{
	// single line blocks should not be broken
	char text[] =
		"\npublic OSTask[] getOSTasks()\n"
		"{\n"
		"    return new OSTask[] { /* comment */ };\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsArrayNone_OneLineBlock2)
{
	// the single line block "{io.toString()}" should not be broken
	char text[] =
		"\npublic void foo()\n"
		"{\n"
		"    catch (IOException io)\n"
		"    {\n"
		"        VFSManager.error(comp,directory,new String[]\n"
		"                         {io.toString()});\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsArrayBreak_OneLineBlock2)
{
	// the single line block "{io.toString()}" should not be broken
	char text[] =
		"\npublic void foo()\n"
		"{\n"
		"    catch (IOException io)\n"
		"    {\n"
		"        VFSManager.error(comp,directory,new String[]\n"
		"                         {io.toString()});\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsArrayAttach_OneLineBlock2)
{
	// the single line block "{io.toString()}" should not be broken
	char text[] =
		"\npublic void foo() {\n"
		"    catch (IOException io) {\n"
		"        VFSManager.error(comp,directory,new String[]\n"
		"                         {io.toString()});\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(JavaBracketsArrayHorstmann_OneLineBlock2)
{
	// the single line block "{io.toString()}" should not be broken
	char text[] =
		"\npublic void foo()\n"
		"{   catch (IOException io)\n"
		"    {   VFSManager.error(comp,directory,new String[]\n"
		"                         {io.toString()});\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
