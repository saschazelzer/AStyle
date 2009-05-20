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

TEST_FIXTURE(sharpText, SharpBracketsNoneNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsNoneBlocks)
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


TEST_FIXTURE(sharpText, SharpBracketsNoneBrackets)
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

TEST(SharpBracketsNoneEmptyBrackets)
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

TEST(SharpBracketsNoneBreak)
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

TEST(SharpBracketsNoneAttach)
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

TEST(SharpBracketsNoneLinux)
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

TEST(SharpBracketsNoneHorstmann)
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

TEST_FIXTURE(sharpText, SharpBracketsBreakShort)
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

TEST_FIXTURE(sharpText, SharpBracketsBreakNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsBreakBlocks)
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


TEST_FIXTURE(sharpText, SharpBracketsBreakBrackets)
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

TEST(SharpBracketsBreakEmptyBrackets)
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

TEST(SharpBracketsBreakBreak)
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

TEST(SharpBracketsBreakAttach)
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

TEST(SharpBracketsBreakLinux)
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

TEST(SharpBracketsBreakHorstmann)
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

TEST_FIXTURE(sharpText, SharpBracketsAttachShort)
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

TEST_FIXTURE(sharpText, SharpBracketsAttachNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsAttachBlocks)
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


TEST_FIXTURE(sharpText, SharpBracketsAttachBrackets)
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

TEST_FIXTURE(sharpText, SharpBracketsAttachBreakClosing)
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

TEST(SharpBracketsAttachEmptyBrackets)
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

TEST(SharpBracketsAttachBreak)
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

TEST(SharpBracketsAttachAttach)
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

TEST(SharpBracketsAttachLinux)
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

TEST(SharpBracketsAttachHorstmann)
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

TEST_FIXTURE(sharpText, SharpBracketsLinuxShort)
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

TEST_FIXTURE(sharpText, SharpBracketsLinuxNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsLinuxBlocks)
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


TEST_FIXTURE(sharpText, SharpBracketsLinuxBrackets)
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

TEST_FIXTURE(sharpText, SharpBracketsLinuxBreakClosing)
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

TEST(SharpBracketsLinuxEmptyBrackets)
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
TEST(SharpBracketsLinuxBreak)
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

TEST(SharpBracketsLinuxAttach)
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

TEST(SharpBracketsLinuxLinux)
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

TEST(SharpBracketsLinuxHorstmann)
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

TEST(SharpBracketsLinuxFormatting)
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

TEST(SharpBracketsLinuxNestedNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsStroustrupShort)
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

TEST_FIXTURE(sharpText, SharpBracketsStroustrupNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsStroustrupBlocks)
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


TEST_FIXTURE(sharpText, SharpBracketsStroustrupBrackets)
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


TEST_FIXTURE(sharpText, SharpBracketsStroustrupBreakClosing)
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

TEST(SharpBracketsStroustrupEmptyBrackets)
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

TEST(SharpBracketsStroustrupFormatting)
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

TEST(SharpBracketsStroustrupNestedNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsHorstmannShort)
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

TEST_FIXTURE(sharpText, SharpBracketsHorstmannNamespace)
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

TEST_FIXTURE(sharpText, SharpBracketsHorstmannBlocks)
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


TEST(SharpBracketsHorstmannEmptyBrackets)
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

TEST(SharpBracketsHorstmannBreak)
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

TEST(SharpBracketsHorstmannAttach)
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

TEST(SharpBracketsHorstmannLinux)
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

TEST(SharpBracketsHorstmannHorstmann)
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

TEST_FIXTURE(sharpText, SharpBracketsOtherClass)
{
	// indent classes should NOT affect C# formatting
	char options[] = "indent-classes, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(textIn, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOtherWhere)
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

TEST(SharpBracketsOtherWhereBlocks)
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

TEST(SharpBracketsOtherWhereBrackets)
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

TEST(SharpBracketsOtherWhereClass)
{
	// test a class that contains a where statement
	char text[] =
		"\npublic sealed class Foo<A, B> : FooBar\n"
		"        where A : Bar1\n"
		"        where B : Bar2\n"
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

TEST(SharpBracketsOtherWhereClassBlocks)
{
	// test a class that contains a where statement, with indent blocks
	char text[] =
		"\npublic sealed class Foo<A, B> : FooBar\n"
		"        where A : Bar1\n"
		"        where B : Bar2\n"
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

TEST(SharpBracketsOtherWhereClassBrackets)
{
	// test a class that contains a where statement, with indent brackets
	char text[] =
		"\npublic sealed class Foo<A, B> : FooBar\n"
		"        where A : Bar1\n"
		"        where B : Bar2\n"
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

TEST(SharpBracketsOtherWhereClassClass)
{
	// test a class that contains a where statement, with two 'class' statements
	char text[] =
		"\npublic class Foo<T> : FooBar1<T>, FooBar2\n"
		"        where T : class\n"
		"{\n"
		"    Bar();\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SharpBracketsOtherAccessors1)
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

TEST(SharpBracketsOtherAccessors2)
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

TEST(SharpBracketsOtherNestedClass)
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

TEST(SharpBracketsOtherNestedClassBlocks)
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

TEST(SharpBracketsOtherNestedClassBrackets)
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

TEST(SharpBracketsOtherNestedNamespace)
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

TEST(SharpBracketsOtherNestedNamespaceBlocks)
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

TEST(SharpBracketsOtherNestedNamespaceBrackets)
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

TEST(SharpBracketsOtherNestedNamespaceIndent)
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

TEST(SharpBracketsOtherNestedNamespaceIndentBlocks)
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

TEST(SharpBracketsOtherNestedNamespaceIndentBrackets)
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

TEST(SharpBracketsOtherNewOperator1)
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

TEST(SharpBracketsOtherNewOperator2)
{
	// test new operator ending with })
	// C# does a full indent of brackets within a paren
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
}

TEST(SharpBracketsOtherNewOperator3)
{
	// test new operator ending with })
	// C# does a full indent of brackets within a paren
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
}

// TODO: add tests for sharp array brackets
