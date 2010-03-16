//-----------------------------------------------------------------------------
// AStyle C# Bracket Options
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-----------------------------------------------------------------------------
// AStyle C# Bracket Options
//-----------------------------------------------------------------------------

//-------------------------------------------------------------------------
// AStyle C# Common Text for Testing
//-------------------------------------------------------------------------

struct sharpText
{
	string textStr;
	const char* textIn;

	sharpText()
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

//-------------------------------------------------------------------------
// AStyle C# Default Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsNone)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsNone_Namespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsNone_Blocks)
{
	// test default blocks option, with indented blocks
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
		"            {\n"
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "indent-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpText, SharpBracketsNone_Brackets)
{
	// test default brackets option, with indent brackets
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"    {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"        }\n"
		"    void Write(string text);\n"
		"    }\n"
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
		"        else {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsNone_EmptyBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsNone_Break)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsNone_Attach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsNone_Linux)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsNone_Horstmann)
{
	// test default brackets option with horstmann brackets
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Break Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsBreak)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsBreak_Short)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsBreak_Namespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsBreak_Blocks)
{
	// test break brackets option, with indent blocks
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
		"            {\n"
		"                bar();\n"
		"            }\n"
		"        else\n"
		"            {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=break, indent-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpText, SharpBracketsBreak_Brackets)
{
	// test break brackets option, with indent brackets
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"    {\n"
		"    int FooGet\n"
		"        {\n"
		"        get;\n"
		"        set;\n"
		"        }\n"
		"    void Write(string text);\n"
		"    }\n"
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
		"            {\n"
		"            anotherBar();\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, indent-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsBreak_EmptyBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsBreak_Break)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsBreak_Attach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsBreak_Linux)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsBreak_Horstmann)
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
	char options[] = "brackets=break, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Attach Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsAttach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsAttach_Short)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsAttach_Namespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsAttach_Blocks)
{
	// test attach brackets option, with indent blocks
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
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n"
		"}\n";

	char options[] = "brackets=attach, indent-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpText, SharpBracketsAttach_Brackets)
{
	// test attach brackets option, with indent brackets
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"        }\n"
		"    void Write(string text);\n"
		"    }\n"
		"\n"
		"public class FooClass {\n"
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
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, indent-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsAttach_BreakClosing)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsAttach_EmptyBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsAttach_Break)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsAttach_Attach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsAttach_Linux)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsAttach_Horstmann)
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
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Linux Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsLinux)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsLinux_Short)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsLinux_Namespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsLinux_Blocks)
{
	// test linux brackets option, with indent blocks
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
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n"
		"}\n";

	char options[] = "brackets=linux, indent-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpText, SharpBracketsLinux_Brackets)
{
	// test linux brackets option, with indent brackets
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"public interface FooInterface\n"
		"    {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"        }\n"
		"    void Write(string text);\n"
		"    }\n"
		"\n"
		"public class FooClass\n"
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
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, indent-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsLinux_BreakClosing)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsLinux_EmptyBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(SharpBracketsLinux_Break)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsLinux_Attach)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsLinux_Linux)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsLinux_Horstmann)
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
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsLinux_Formatting)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsLinux_NestedNamespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Stroustrup Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsStroustrup)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsStroustrup_Short)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsStroustrup_Namespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsStroustrup_Blocks)
{
	// test stroustrup brackets option, with indent blocks
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
		"                bar();\n"
		"            }\n"
		"        else {\n"
		"                anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n"
		"}\n";

	char options[] = "brackets=stroustrup, indent-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpText, SharpBracketsStroustrup_Brackets)
{
	// test stroustrup brackets option, with indent brackets
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"public interface FooInterface {\n"
		"    int FooGet {\n"
		"        get;\n"
		"        set;\n"
		"        }\n"
		"    void Write(string text);\n"
		"    }\n"
		"\n"
		"public class FooClass {\n"
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
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup, indent-brackets, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST_FIXTURE(sharpText, SharpBracketsStroustrup_BreakClosing)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsStroustrup_EmptyBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsStroustrup_Formatting)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsStroustrup_NestedNamespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Break Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsHorstmann)
{
	// test horstmann brackets option
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

	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsHorstmann_Short)
{
	// test horstmann brackets short option
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsHorstmann_Namespace)
{
	// test horstmann brackets option, with indented namespace
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
	char options[] = "brackets=horstmann, indent-namespaces, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(sharpText, SharpBracketsHorstmann_Blocks)
{
	// test horstmann brackets option, with indent blocks
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
		"            {   bar();\n"
		"            }\n"
		"        else\n"
		"            {   anotherBar();\n"
		"            }\n"
		"    }\n"
		"}\n"
		"}\n";
	char options[] = "brackets=horstmann, indent-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(SharpBracketsHorstmann_EmptyBrackets)
{
	// test horstmann brackets option
	// do not change empty brackets
	char text[] =
		"\npublic class FooClass\n"
		"{   public FooClass() {}\n"
		"    public FooClass()\n"
		"    {}\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsHorstmann_Break)
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
	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsHorstmann_Attach)
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
	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsHorstmann_Linux)
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
	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsHorstmann_Horstmann)
{
	// test break brackets option with horstmann brackets
	char text[] =
		"\npublic void Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C# Other Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(sharpText, SharpBracketsOther_Class)
{
	// indent classes should NOT affect C# formatting
	char options[] = "indent-classes, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_ClassContinuationAttached)
{
	// test with class continuation and attached brackets
	char text[] =
		"\npublic interface Foo\n"
		"    : Bar {\n"
		"}\n"
		"\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_ClassContinuationBroken)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_Where)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_WhereBlocks)
{
	// test a method that contains a where statement, with indent blocks
	// should be recognized as a block opener
	char text[] =
		"\nvoid SetParent<T> (List<T> list) where T : INode\n"
		"{\n"
		"    if (list != null)\n"
		"        {\n"
		"            foreach (T x in list)\n"
		"                {\n"
		"                    x.Parent = parent;\n"
		"                }\n"
		"        }\n"
		"}\n";
	char options[] = "indent-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_WhereBrackets)
{
	// test a method that contains a where statement, with indent brackets
	// should be recognized as a block opener
	char text[] =
		"\nvoid SetParent<T> (List<T> list) where T : INode\n"
		"    {\n"
		"    if (list != null)\n"
		"        {\n"
		"        foreach (T x in list)\n"
		"            {\n"
		"            x.Parent = parent;\n"
		"            }\n"
		"        }\n"
		"    }\n";
	char options[] = "indent-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_WhereClass)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_WhereClassBlocks)
{
	// test a class that contains a where statement, with indent blocks
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
		"            {\n"
		"                FooBar1();\n"
		"            }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_WhereClassBrackets)
{
	// test a class that contains a where statement, with indent brackets
	char text[] =
		"\npublic sealed class Foo<A, B> : FooBar\n"
		"    where A : Bar1\n"
		"    where B : Bar2\n"
		"    {\n"
		"    int a;\n"
		"    int b;\n"
		"\n"
		"    protected override void Foo1()\n"
		"        {\n"
		"        if foo()\n"
		"            {\n"
		"            FooBar1();\n"
		"            }\n"
		"        }\n"
		"    }\n";
	char options[] = "indent-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_WhereClassClass)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_Accessors1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_Accessors2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedClass)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedClassBlocks)
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

	char options[] = "indent-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedClassBrackets)
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

	char options[] = "indent-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedNamespace)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedNamespaceBlocks)
{
	// test nested namespaces and indented blocks
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
		"            {\n"
		"                bar();\n"
		"            }\n"
		"        else\n"
		"            anotherBar();\n"
		"    }\n"
		"}\n"
		"}\n"
		"}\n"
		"}\n";
	char options[] = "indent-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedNamespaceBrackets)
{
	// test nested namespaces and indented brackets
	char text[] =
		"\nnamespace A\n"
		"{\n"
		"namespace B\n"
		"{\n"
		"namespace C\n"
		"{\n"
		"public class fooClass\n"
		"    {\n"
		"    void foo(bool isFoo)\n"
		"        {\n"
		"        if (isFoo)\n"
		"            {\n"
		"            bar();\n"
		"            }\n"
		"        else\n"
		"            anotherBar();\n"
		"        }\n"
		"    }\n"
		"}\n"
		"}\n"
		"}\n";
	char options[] = "indent-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedNamespaceIndent)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedNamespaceIndentBlocks)
{
	// test nested indented namespaces and indented blocks
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
		"                        {\n"
		"                            bar();\n"
		"                        }\n"
		"                    else\n"
		"                        anotherBar();\n"
		"                }\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-namespaces, indent-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NestedNamespaceIndentBrackets)
{
	// test nested indented namespaces and indented brackets
	char text[] =
		"\nnamespace A\n"
		"    {\n"
		"    namespace B\n"
		"        {\n"
		"        namespace C\n"
		"            {\n"
		"            public class fooClass\n"
		"                {\n"
		"                void foo(bool isFoo)\n"
		"                    {\n"
		"                    if (isFoo)\n"
		"                        {\n"
		"                        bar();\n"
		"                        }\n"
		"                    else\n"
		"                        anotherBar();\n"
		"                    }\n"
		"                }\n"
		"            }\n"
		"        }\n"
		"    }\n";
	char options[] = "indent-namespaces, indent-brackets, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOther_NewOperator1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

// TODO: fix the following
TEST(SharpBracketsOther_NewOperator2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
	*/
}

// TODO: fix the following
TEST(SharpBracketsOther_NewOperator3)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
	*/
}

//-------------------------------------------------------------------------
// AStyle C# Array Bracket Options
//-------------------------------------------------------------------------

TEST(SharpBracketsArrayNone_Comments)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsArrayBreak_Comments)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(SharpBracketsArrayAttach_Comments)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(SharpBracketsArrayHorstmann_Comments)
{
	// comments preceding array entries should NOT break the line
	char text[] =
		"\nstatic readonly\n"
		"int[][] _stateTable =               // 0    1    2    3    4\n"
		"{   /* 0: in Code       */ new int[] { 1  , 7  , 0  , 0  , 0  },\n"
		"    /* 1: after quote   */ new int[] { 2  , 6  , 10 , 0  , 8  },\n"
		"    /* 2: after d-quote */ new int[] { 3  , 7  , 0  , 0  , 0  }\n"
		"};\n";
	char options[] = "brackets=horstmann, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
