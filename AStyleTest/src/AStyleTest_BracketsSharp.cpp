//-----------------------------------------------------------------------------
// AStyle C# Bracket Options
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
// AStyle C# Bracket Options
//-----------------------------------------------------------------------------

//-------------------------------------------------------------------------
// AStyle C# Default Bracket Options
//-------------------------------------------------------------------------

struct BracketsNoneSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsNoneSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsNoneSharpF, Default)
{
	// test default brackets option (do not change)
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
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
		"        } else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneSharpF, Namespace)
{
	// test default brackets option, with indented namespace
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    public interface FooInterface\n"
		"    {\n"
		"        int FooGet {\n"
		"            get;\n"
		"            set;\n"
		"        }\n"
		"        void Write(string text);\n"
		"    }\n"
		"\n"
		"    public class FooClass\n"
		"    {\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {\n"
		"            if (isFoo)\n"
		"            {\n"
		"                bar();\n"
		"            } else {\n"
		"                anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneSharp, EmptyBrackets)
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
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneSharp, Break)
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
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneSharp, Attach)
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
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneSharp, Linux)
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
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneSharp, RunIn)
{
	// test default brackets option with run-in brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   // comment\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Break Bracket Options
//-------------------------------------------------------------------------

struct BracketsBreakSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsBreakSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsBreakSharpF, LongOption)
{
	// test break brackets option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{\n"
		"    int FooGet\n"
		"    {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
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
		"        {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakSharpF, ShortOption)
{
	// test break brackets short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{\n"
		"    int FooGet\n"
		"    {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
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
		"        {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "-b, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakSharpF, Namespace)
{
	// test break brackets option, with indented namespace
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    public interface FooInterface\n"
		"    {\n"
		"        int FooGet\n"
		"        {\n"
		"            get;\n"
		"            set;\n"
		"        }\n"
		"        void Write(string text);\n"
		"    }\n"
		"\n"
		"    public class FooClass\n"
		"    {\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {\n"
		"            if (isFoo)\n"
		"            {\n"
		"                bar();\n"
		"            }\n"
		"            else\n"
		"            {\n"
		"                anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakSharp, EmptyBrackets)
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
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakSharp, Break)
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
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakSharp, Attach)
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
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakSharp, Linux)
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
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakSharp, RunIn)
{
	// test break brackets option with run-in brackets
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
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Attach Bracket Options
//-------------------------------------------------------------------------

struct BracketsAttachSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsAttachSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsAttachSharpF, LongOption)
{
	// test attach brackets option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass {\n"
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
		"}\n"
		"}\n";
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachSharpF, ShortOption)
{
	// test attach brackets short option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass {\n"
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
		"}\n"
		"}\n";
	char options[] = "-a, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachSharpF, Namespace)
{
	// test attach brackets option, with indented namespace
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"    public interface FooInterface {\n"
		"        int FooGet {\n"
		"            get;\n"
		"            set;\n"
		"        }\n"
		"        void Write(string text);\n"
		"    }\n"
		"\n"
		"    public class FooClass {\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo) {\n"
		"            if (isFoo) {\n"
		"                bar();\n"
		"            } else {\n"
		"                anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachSharpF, BreakClosing)
{
	// test attach brackets option, with break closing brackets
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass {\n"
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
		"}\n"
		"}\n";
	char options[] = "brackets=attach, break-closing-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachSharp, EmptyBrackets)
{
	// test attach brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachSharp, Break)
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
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachSharp, Attach)
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
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachSharp, Linux)
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
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachSharp, RunIn)
{
	// test attach brackets option with run-in brackets
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
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Linux Bracket Options
//-------------------------------------------------------------------------

struct BracketsLinuxSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsLinuxSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsLinuxSharpF, LongOption)
{
	// test linux brackets option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
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
		"}\n";
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxSharpF, ShortOption)
{
	// test linux brackets short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
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
		"}\n";
	char options[] = "-l, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxSharpF, Namespace)
{
	// test linux brackets option, with indented namespace
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    public interface FooInterface\n"
		"    {\n"
		"        int FooGet {\n"
		"            get;\n"
		"            set;\n"
		"        }\n"
		"        void Write(string text);\n"
		"    }\n"
		"\n"
		"    public class FooClass\n"
		"    {\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {\n"
		"            if (isFoo) {\n"
		"                bar();\n"
		"            } else {\n"
		"                anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxSharpF, BreakClosing)
{
	// test linux brackets option, with break closing brackets
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
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
		"        }\n"
		"        else {\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=linux, break-closing-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxSharp, EmptyBrackets)
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
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsLinuxSharp, Break)
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
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxSharp, Attach)
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
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxSharp, Linux)
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
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxSharp, RunIn)
{
	// test linux brackets option with run-in brackets
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
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxSharp, Formatting)
{
	// test linux brackets option, for non-function top level objects
	// brackets are attached for arrays, structs, and other top level objects
	//     that are not classes or functions.
	char textIn[] =
		"\nnamespace fooName\n"
		"{\n"
		"public class fooClass\n"
		"{\n"
		"    public struct Examination\n"
		"    {\n"
		"        public void setDetails(string str1, string str2)\n"
		"        {\n"
		"            ExamCode=str1;\n"
		"        }\n"
		"\n"
		"        public string[] getdetails()\n"
		"        {\n"
		"            temp=new string[2];\n"
		"            return temp;\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char text[] =
		"\nnamespace fooName\n"
		"{\n"
		"public class fooClass\n"
		"{\n"
		"    public struct Examination {\n"
		"        public void setDetails(string str1, string str2)\n"
		"        {\n"
		"            ExamCode=str1;\n"
		"        }\n"
		"\n"
		"        public string[] getdetails()\n"
		"        {\n"
		"            temp=new string[2];\n"
		"            return temp;\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxSharp, NestedNamespace)
{
	// test nested namespaces with linux brackets
	char text[] =
		"\nnamespace A\n"
		"{\n"
		"class A\n"
		"{\n"
		"    namespace B\n"
		"    {\n"
		"    class B\n"
		"    {\n"
		"        namespace C\n"
		"        {\n"
		"        class C\n"
		"        {\n"
		"        }\n"
		"        }\n"
		"    }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Stroustrup Bracket Options
//-------------------------------------------------------------------------

struct BracketsStroustrupSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsStroustrupSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsStroustrupSharpF, LongOption)
{
	// test stroustrup brackets option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass {\n"
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
		"}\n";
	char options[] = "brackets=stroustrup, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupSharpF, ShortOption)
{
	// test stroustrup brackets short option
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass {\n"
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
		"}\n";
	char options[] = "-u, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupSharpF, Namespace)
{
	// test stroustrup brackets option, with indented namespace
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"    public interface FooInterface {\n"
		"        int FooGet {\n"
		"            get;\n"
		"            set;\n"
		"        }\n"
		"        void Write(string text);\n"
		"    }\n"
		"\n"
		"    public class FooClass {\n"
		"        private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {\n"
		"            if (isFoo) {\n"
		"                bar();\n"
		"            } else {\n"
		"                anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup, indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupSharpF, BreakClosing)
{
	// test stroustrup brackets option with break closing brackets
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass {\n"
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
		"}\n"
		"}\n";
	char options[] = "brackets=stroustrup, break-closing-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupSharp, EmptyBrackets)
{
	// test stroustrup brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass {\n"
		"    public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=stroustrup, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupSharp, Formatting)
{
	// test stroustrup brackets option, for non-function top level objects
	// brackets are attached for arrays, structs, and other top level objects
	//     that are not classes or functions.
	char textIn[] =
		"\nnamespace fooName\n"
		"{\n"
		"public class fooClass\n"
		"{\n"
		"    public struct Examination\n"
		"    {\n"
		"        public void setDetails(string str1, string str2)\n"
		"        {\n"
		"            ExamCode=str1;\n"
		"        }\n"
		"\n"
		"        public string[] getdetails()\n"
		"        {\n"
		"            temp=new string[2];\n"
		"            return temp;\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char text[] =
		"\nnamespace fooName {\n"
		"public class fooClass {\n"
		"    public struct Examination {\n"
		"        public void setDetails(string str1, string str2)\n"
		"        {\n"
		"            ExamCode=str1;\n"
		"        }\n"
		"\n"
		"        public string[] getdetails()\n"
		"        {\n"
		"            temp=new string[2];\n"
		"            return temp;\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=stroustrup, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupSharp, NestedNamespace)
{
	// test nested namespaces with stroustrup brackets
	char text[] =
		"\nnamespace A {\n"
		"class A {\n"
		"    namespace B {\n"
		"    class B {\n"
		"        namespace C {\n"
		"        class C {\n"
		"        }\n"
		"        }\n"
		"    }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=stroustrup, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Break Bracket Options
//-------------------------------------------------------------------------

struct BracketsRunInSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsRunInSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsRunInSharpF, LongOption)
{
	// test run-in brackets option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{   int FooGet\n"
		"    {   get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass\n"
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
		"}\n"
		"}\n";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsRunInSharpF, ShortOption)
{
	// test run-in brackets short option
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"{   int FooGet\n"
		"    {   get;\n"
		"        set;\n"
		"    }\n"
		"    void Write(string text);\n"
		"}\n"
		"\n"
		"public class FooClass\n"
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
		"}\n"
		"}\n";
	char options[] = "-g, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsRunInSharpF, Namespace)
{
	// test run-in brackets option, with indented namespace
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    public interface FooInterface\n"
		"    {   int FooGet\n"
		"        {   get;\n"
		"            set;\n"
		"        }\n"
		"        void Write(string text);\n"
		"    }\n"
		"\n"
		"    public class FooClass\n"
		"    {   private bool var1;\n"
		"        private bool var2;\n"
		"\n"
		"        public void foo(bool isFoo)\n"
		"        {   if (isFoo)\n"
		"            {   bar();\n"
		"            }\n"
		"            else\n"
		"            {   anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=run-in, indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsRunInSharp, EmptyBrackets)
{
	// test run-in brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass\n"
		"{   public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsRunInSharp, Break)
{
	// test run-in brackets option with broken brackets
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
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsRunInSharp, Attach)
{
	// test run-in brackets option with attached brackets
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
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsRunInSharp, Linux)
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
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsRunInSharp, RunIn)
{
	// test break brackets option with run-in brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Other Bracket Options
//-------------------------------------------------------------------------

struct BracketsOtherSharpF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsOtherSharpF()
	{
		textStr =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public interface FooInterface\n"
			"{\n"
			"    int FooGet {get; set;}\n"
			"    void Write(string text);\n"
			"}\n"
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
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"}\n";
		textIn = textStr.c_str();
	}
};

TEST_F(BracketsOtherSharpF, IndentClasses)
{
	// indent classes should NOT affect C# formatting
	char options[] = "indent-classes, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(textIn, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, ClassContinuation_Attached)
{
	// test with class continuation and attached brackets
	char text[] =
		"\npublic interface Foo\n"
		"    : Bar {\n"
		"}\n"
		"\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, ClassContinuation_Broken)
{
	// test with class continuation and broken brackets
	char text[] =
		"\npublic interface Foo\n"
		"    : Bar\n"
		"{\n"
		"}\n"
		"\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, Where)
{
	// test a method that contains a where statement
	// should be recognized as a block opener
	char text[] =
		"\nvoid SetParent<T> (List<T> list) where T : INode\n"
		"{\n"
		"    if (list != null)\n"
		"    {\n"
		"        foreach (T x in list)\n"
		"        {\n"
		"            x.Parent = parent;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, WhereClass)
{
	// test a class that contains a where statement
	char text[] =
		"\npublic sealed class Foo<A, B> : FooBar\n"
		"    where A : Bar1\n"
		"    where B : Bar2\n"
		"{\n"
		"    int a;\n"
		"    int b;\n"
		"\n"
		"    protected override void Foo1()\n"
		"    {\n"
		"        if foo()\n"
		"        {\n"
		"            FooBar1();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, WhereClassClass)
{
	// test a class that contains a where statement, with two 'class' statements
	char text[] =
		"\npublic class Foo<T> : FooBar1<T>, FooBar2\n"
		"    where T : class\n"
		"{\n"
		"    Bar();\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, Accessors1)
{
	// test indent of getters and setters
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool foo;\n"
		"\n"
		"    public bool Foo\n"
		"    {\n"
		"        get\n"
		"        {\n"
		"            return foo;\n"
		"        }\n"
		"        set\n"
		"        {\n"
		"            foo = value;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, Accessors2)
{
	// test indent of getters and setters, with comments and empty lines
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    private bool foo;\n"
		"\n"
		"    public bool Foo\n"
		"    {\n"
		"        // comment\n"
		"\n"
		"        get\n"
		"        {\n"
		"            return foo;\n"
		"        }\n"
		"        set\n"
		"        {\n"
		"            foo = value;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, NestedClass)
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
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, NestedNamespace)
{
	// test nested namespaces
	char text[] =
		"\nnamespace A\n"
		"{\n"
		"namespace B\n"
		"{\n"
		"namespace C\n"
		"{\n"
		"public class fooClass\n"
		"{\n"
		"    void foo(bool isFoo)\n"
		"    {\n"
		"        if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"        else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n"
		"}\n"
		"}\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherSharp, NestedNamespace_IndentNamespaces)
{
	// test nested indented namespaces
	char text[] =
		"\nnamespace A\n"
		"{\n"
		"    namespace B\n"
		"    {\n"
		"        namespace C\n"
		"        {\n"
		"            public class fooClass\n"
		"            {\n"
		"                void foo(bool isFoo)\n"
		"                {\n"
		"                    if (isFoo)\n"
		"                    {\n"
		"                        bar();\n"
		"                    }\n"
		"                    else\n"
		"                        anotherBar();\n"
		"                }\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-namespaces, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Other Bracket Options
//-------------------------------------------------------------------------

TEST(BracketsOtherSharp, NewOperator1)
{
	// test new operator ending with })
	char text[] =
		"\npublic IEnumerable<DesignItem> SelectedItems {\n"
		"    set {\n"
		"        Current.Begin(new Action(delegate {\n"
		"            selectedItems = value;\n"
		"        }), DispatcherPriority.Background);\n"
		"    }\n"
		"}\n"
		"\n"
		"static CodeType CreateNode(List<Type> nodeTypes) {\n"
		"    m.Add(new xx(new yy(new zz(), \"Begin\"), new aaa[] { var }));\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

// TODO: fix the following
TEST(BracketsOtherSharp, NewOperator2)
{
	// test new operator ending with })
	// C# does a full indent of brackets within a paren
	/*
	char text[] =
		"\nstatic void Parse(string fileName, string fileContent)\n"
		"{\n"
		"    Module module = BooParser(4, new CompileUnit(), fileName,\n"
		"                              new StringReader(fileContent),\n"
		"                              delegate(RecognitionException e) {\n"
		"                                  AppendLine(e.ToString());\n"
		"                              });\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
	*/
}

// TODO: fix the following
TEST(BracketsOtherSharp, NewOperator3)
{
	// test new operator ending with })
	// C# does a full indent of brackets within a paren
	/*
	char text[] =
		"\npublic ResolveResult ResolveIdentifier(string identifier)\n"
		"{\n"
		"    return Identifier(new IdentifierExpression(identifier) {\n"
		"                          StartLocation = position\n"
		"                      }, context);\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
	*/
}

TEST(BracketsOtherSharp, ReturnStatement)
{
	// test return statement ending with };
	// }; should not have an in-statement indent.
	char text[] =
		"\npublic IViewContent CreateContentForFile(OpenedFile file)\n"
		"{\n"
		"    return new SimpleViewContent(errorMessage) {\n"
		"        TitleName = Path.GetFileName(file.FileName)\n"
		"    };\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Array Bracket Options
//-------------------------------------------------------------------------

TEST(BracketsArraySharp, None_Comments)
{
	// comments preceding array entries should NOT break the line
	char text[] =
		"\nstatic readonly\n"
		"int[][] _stateTable =             { // 0    1    2    3    4\n"
		"    /* 0: in Code       */ new int[] { 1  , 7  , 0  , 0  , 0  },\n"
		"    /* 1: after quote   */ new int[] { 2  , 6  , 10 , 0  , 8  },\n"
		"    /* 2: after d-quote */ new int[] { 3  , 7  , 0  , 0  , 0  }\n"
		"};\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, None_Misc1)
{
	// The following unusual C# array was badly formatted.
	// It could be better but this is an improvement over what it was.
	char textIn[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings = {\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"        new string[]{ PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"            PwDefs.UserNameField, \"Branch\", \"Phone #\" }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"        new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"        new string[]{ PwDefs.TitleField, PwDefs.UserNameField,\n"
		"            PwDefs.PasswordField }),\n"
		"};";
	char text[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings = {\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"    new string[]{\n"
		"        PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"        PwDefs.UserNameField, \"Branch\", \"Phone #\"\n"
		"    }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"    new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"    new string[]{\n"
		"        PwDefs.TitleField, PwDefs.UserNameField,\n"
		"        PwDefs.PasswordField\n"
		"    }),\n"
		"};";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, Break_Comments)
{
	// comments preceding array entries should NOT break the line
	char text[] =
		"\nstatic readonly\n"
		"int[][] _stateTable =               // 0    1    2    3    4\n"
		"{\n"
		"    /* 0: in Code       */ new int[] { 1  , 7  , 0  , 0  , 0  },\n"
		"    /* 1: after quote   */ new int[] { 2  , 6  , 10 , 0  , 8  },\n"
		"    /* 2: after d-quote */ new int[] { 3  , 7  , 0  , 0  , 0  }\n"
		"};\n";
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, Break_Misc1)
{
	// The following unusual C# array was badly formatted.
	// It could be better but this is an improvement over what it was.
	char textIn[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings = {\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"        new string[]{ PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"            PwDefs.UserNameField, \"Branch\", \"Phone #\" }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"        new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"        new string[]{ PwDefs.TitleField, PwDefs.UserNameField,\n"
		"            PwDefs.PasswordField }),\n"
		"};";
	char text[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings =\n"
		"{\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"    new string[]{\n"
		"        PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"        PwDefs.UserNameField, \"Branch\", \"Phone #\"\n"
		"    }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"    new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"    new string[]{\n"
		"        PwDefs.TitleField, PwDefs.UserNameField,\n"
		"        PwDefs.PasswordField\n"
		"    }),\n"
		"};";
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, Attach_Comments)
{
	// comments preceding array entries should NOT break the line
	char text[] =
		"\nstatic readonly\n"
		"int[][] _stateTable =             { // 0    1    2    3    4\n"
		"    /* 0: in Code       */ new int[] { 1  , 7  , 0  , 0  , 0  },\n"
		"    /* 1: after quote   */ new int[] { 2  , 6  , 10 , 0  , 8  },\n"
		"    /* 2: after d-quote */ new int[] { 3  , 7  , 0  , 0  , 0  }\n"
		"};\n";
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, Attach_Misc1)
{
	// The following unusual C# array was badly formatted.
	// It could be better but this is an improvement over what it was.
	char textIn[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings =\n"
		"{\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"        new string[]{ PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"            PwDefs.UserNameField, \"Branch\", \"Phone #\" }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"        new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"        new string[]{ PwDefs.TitleField, PwDefs.UserNameField,\n"
		"            PwDefs.PasswordField }),\n"
		"};";
	char text[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings = {\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"    new string[]{\n"
		"        PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"        PwDefs.UserNameField, \"Branch\", \"Phone #\"\n"
		"    }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"    new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"    new string[]{\n"
		"        PwDefs.TitleField, PwDefs.UserNameField,\n"
		"        PwDefs.PasswordField\n"
		"    }),\n"
		"};";
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, RunIn_Comments)
{
	// comments preceding array entries should NOT break the line
	char text[] =
		"\nstatic readonly\n"
		"int[][] _stateTable =               // 0    1    2    3    4\n"
		"{   /* 0: in Code       */ new int[] { 1  , 7  , 0  , 0  , 0  },\n"
		"    /* 1: after quote   */ new int[] { 2  , 6  , 10 , 0  , 8  },\n"
		"    /* 2: after d-quote */ new int[] { 3  , 7  , 0  , 0  , 0  }\n"
		"};\n";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, RunIn_Misc1)
{
	// The following unusual C# array was badly formatted.
	// It could be better but this is an improvement over what it was.
	char textIn[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings = {\n"
		"    new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"        new string[]{ PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"            PwDefs.UserNameField, \"Branch\", \"Phone #\" }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"        new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"        new string[]{ PwDefs.TitleField, PwDefs.UserNameField,\n"
		"            PwDefs.PasswordField }),\n"
		"};";
	char text[] =
		"\nprivate static readonly SplashIdMapping[] SplashIdMappings =\n"
		"{   new SplashIdMapping(\"Bank Accts\", PwIcon.Homebanking,\n"
		"    new string[]{ PwDefs.TitleField, \"Account #\", PwDefs.PasswordField,\n"
		"        PwDefs.UserNameField, \"Branch\", \"Phone #\"\n"
		"    }),\n"
		"    new SplashIdMapping(\"Birthdays\", PwIcon.UserCommunication,\n"
		"    new string[]{ PwDefs.TitleField, \"Date\" }),\n"
		"    new SplashIdMapping(\"Calling Cards\", PwIcon.EMail,\n"
		"    new string[]{ PwDefs.TitleField, PwDefs.UserNameField,\n"
		"        PwDefs.PasswordField\n"
		"    }),\n"
		"};";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Array Bracket Non-In-Statement Options
// Currently with C# some commands are handled as non-in-statement arrays
//-------------------------------------------------------------------------

TEST(BracketsArraySharp, InStatementIndentWithParenLineBegin)
{
	// a paren begins a line with an in-statement indent
	char text[] =
		"\nprivate void foo()\n"
		"{\n"
		"    search(\n"
		"        () => DoSearch(Select(i => i.Node).ToList()),\n"
		"        result => SearchCompleted(result),\n"
		"    );\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, Clear_NonInStatementArray2)
{
	// The isNonInStatementArray should be cleared before brackets are added.
	// If not cleared the CreateDirectory line is wrong.
	char textIn[] =
		"\npublic void CreateEntry()\n"
		"{\n"
		"    workspaceItem.Name = StringParser(new string[,] {{SolutionName}});\n"
		"    if (!Directory.Exists(SolutionPath))\n"
		"        CreateDirectory(SolutionPath);\n"
		"}";
	char text[] =
		"\npublic void CreateEntry()\n"
		"{\n"
		"    workspaceItem.Name = StringParser(new string[,] {{SolutionName}});\n"
		"    if (!Directory.Exists(SolutionPath)) {\n"
		"        CreateDirectory(SolutionPath);\n"
		"    }\n"
		"}";
	char options[] = "add-brackets, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsArraySharp, Clear_NonInStatementArray3)
{
	// The isNonInStatementArray should be cleared before brackets are added.
	// If not cleared the final in-statement indent will be wrong.
	char text[] =
		"\nstatic void LoadProjectInternal()\n"
		"{\n"
		"    string[,] parseArgs = {{solutionFile}, {fileName}};\n"
		"    int res = ShowCustomDialog(MessageService.ProductName,\n"
		"                               StringParser.Parse(parseArgs1),\n"
		"                               0, 2);\n"
		"}";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArraySharp, Clear_NonInStatementArray4)
{
	// The isNonInStatementArray should be cleared before brackets are added.
	// If not cleared the last two lines will be wrong.
	char text[] =
		"\nstatic void NeedsToClear()\n"
		"{\n"
		"    Message.Show(Parse(new string[,] {{ count.ToString() }}));\n"
		"    MessageBox.Show(WorkbenchSingleton.MainWin32Window,\n"
		"                    MessageBoxButtons.OK,\n"
		"                    MessageBoxIcon.Information);\n"
		"}";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


//----------------------------------------------------------------------------

}  // namespace
