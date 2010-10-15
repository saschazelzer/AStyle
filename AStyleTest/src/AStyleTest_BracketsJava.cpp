//-----------------------------------------------------------------------------
// AStyle Java Bracket Options
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//-----------------------------------------------------------------------------
// AStyle Java Bracket Options
//-----------------------------------------------------------------------------

//-------------------------------------------------------------------------
// AStyle Java Default Bracket Options
//-------------------------------------------------------------------------

struct BracketsNoneJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsNoneJavaF()
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

TEST_F(BracketsNoneJavaF, Default)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneJavaF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(BracketsNoneJavaF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, EnumConstructorBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneJava, EnumConstructorAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsNoneJava, EnumConstructorHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Break Bracket Options
//-------------------------------------------------------------------------

struct BracketsBreakJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsBreakJavaF()
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

TEST_F(BracketsBreakJavaF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakJavaF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakJavaF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(BracketsBreakJavaF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakJava, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsBreakJava, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakJava, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakJava, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakJava, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakJava, EnumConstructor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Attach Bracket Options
//-------------------------------------------------------------------------

struct BracketsAttachJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsAttachJavaF()
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

TEST_F(BracketsAttachJavaF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachJavaF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachJavaF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachJavaF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachJavaF, BreakClosing)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachJava, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachJava, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachJava, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachJava, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachJava, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachJava, EnumConstructor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Linux Bracket Options
//-------------------------------------------------------------------------

struct BracketsLinuxJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsLinuxJavaF()
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

TEST_F(BracketsLinuxJavaF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxJavaF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxJavaF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxJavaF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxJavaF, BreakClosing)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxJava, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsLinuxJava, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxJava, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxJava, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxJava, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxJava, EnumConstructor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Stroustrup Bracket Options
//-------------------------------------------------------------------------

struct BracketsStroustrupJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsStroustrupJavaF()
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

TEST_F(BracketsStroustrupJavaF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupJavaF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupJavaF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupJavaF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupJavaF, BreakClosing)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupJava, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupJava, EnumConstructor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Horstmann Bracket Options
//-------------------------------------------------------------------------

struct BracketsHorstmannJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsHorstmannJavaF()
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

TEST_F(BracketsHorstmannJavaF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannJavaF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannJavaF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannJava, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannJava, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannJava, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannJava, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannJava, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannJava, EnumConstructor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Other Bracket Options
//-------------------------------------------------------------------------

struct BracketsOtherJavaF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsOtherJavaF()
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
TEST_F(BracketsOtherJavaF, IndentNamespaces)
{
	// indent namespaces should NOT affect java formatting
	char options[] = "indent-namespaces, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(textIn, textOut);
	delete [] textOut;
}

TEST_F(BracketsOtherJavaF, IndentClasses)
{
	// indent classes should NOT affect java formatting
	char options[] = "indent-classes, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(textIn, textOut);
	delete [] textOut;
}

TEST_F(BracketsOtherJavaF, IndentNamespaces_IndentClass)
{
	// indent namespaces and classes should NOT affect java formatting
	char options[] = "indent-namespaces, indent-classes, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(textIn, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, ClassContinuation_Attached)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, ClassContinuation_Broken)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, Interface)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, Interface_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, Interface_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, NestedClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, NestedClass_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, NestedClass_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, StaticConstructor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsOtherJava, StaticConstructor_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, StaticConstructor_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, Throws)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, Throws_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, Throws_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, NewOperator1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherJava, NewOperator2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Java Array Bracket Options
//-------------------------------------------------------------------------

TEST(BracketsArrayJava, None_InStatement)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, None_OneLineBlock1)
{
	// single line blocks should not be broken
	char text[] =
		"\npublic OSTask[] getOSTasks()\n"
		"{\n"
		"    return new OSTask[] { /* comment */ };\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, None_OneLineBlock2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, Break_OneLineBlock2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, Attach_OneLineBlock2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, Horstmann_OneLineBlock2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


//-------------------------------------------------------------------------
// AStyle Java Array Bracket Non-In-Statement Options
//-------------------------------------------------------------------------

TEST(BracketsArrayJava, InStatementArray1)
{
	// TODO: This should be indented as an in-statement array.
	//       Why is it indented 9 spaces?
	char text[] =
		"\nvoid LoadToc()\n"
		"{\n"
		"    File[] files = new File[] { new File(dir1, \"test.java\"),\n"
		"             new File(dir2, \"test.class\"),\n"
		"             new File(dir3, \"that.java\")\n"
		"    };\n"
		"}";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, InStatementArray2)
{
	// TODO: This should be indented as an in-statement array.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    String footerText = jEdit.getProperty ( \"print.footerText\",\n"
		"    new Object[] { new Date(), valueOf(pageIndex + 1)});\n"
		"}";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, InStatement_LineCommentClear)
{
	// isNonInStatementArray should be cleared when a // follows a }
	// if not cleared the "? ERROR" line will not be correctly indented
	char text[] =
		"\npublic enum KeyboardCommand\n"
		"{\n"
		"    TAB_OUT_FORWARD,\n"
		"    TAB_OUT_BACK\n"
		"} // this comment\n"
		"\n"
		"static class Entry\n"
		"{\n"
		"    Entry(PluginJAR jar)\n"
		"    {\n"
		"        if (plugin != null)\n"
		"        {\n"
		"            status = plugin instanceof EditPlugin.Broken\n"
		"                     ? ERROR : LOADED;\n"
		"            clazz = plugin.getClassName();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayJava, InStatement_CommentClear)
{
	// isNonInStatementArray should be cleared when a /* follows a }
	// if not cleared the "? ERROR" line will not be correctly indented
	char text[] =
		"\npublic enum KeyboardCommand\n"
		"{\n"
		"    TAB_OUT_FORWARD,\n"
		"    TAB_OUT_BACK\n"
		"} /* this comment */\n"
		"\n"
		"static class Entry\n"
		"{\n"
		"    Entry(PluginJAR jar)\n"
		"    {\n"
		"        if (plugin != null)\n"
		"        {\n"
		"            status = plugin instanceof EditPlugin.Broken\n"
		"                     ? ERROR : LOADED;\n"
		"            clazz = plugin.getClassName();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


//----------------------------------------------------------------------------

}  // namespace
