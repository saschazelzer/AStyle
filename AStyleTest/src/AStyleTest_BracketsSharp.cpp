//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <UnitTest++.h>
#include <iostream>  // for cout

#include "astyle.h"

//-----------------------------------------------------------------------------
// declarations
//-----------------------------------------------------------------------------

// AStyleMain callback function declarations
void  STDCALL errorHandler(int errorNumber, char* errorMessage);
char* STDCALL memoryAlloc(unsigned long memoryNeeded);


//-----------------------------------------------------------------------------
// AStyle C# Bracket Options
//-----------------------------------------------------------------------------

SUITE(SharpBracketOptions)
{
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

	TEST_FIXTURE(sharpText, BracketsNone)
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

	TEST_FIXTURE(sharpText, BracketsNoneNamespace)
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

	TEST_FIXTURE(sharpText, BracketsNoneBlocks)
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


	TEST_FIXTURE(sharpText, BracketsNoneBrackets)
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

	TEST(BracketsNoneEmptyBrackets)
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
	//-------------------------------------------------------------------------
	// AStyle C# Break Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(sharpText, BracketsBreak)
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

	TEST_FIXTURE(sharpText, BracketsBreakShort)
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

	TEST_FIXTURE(sharpText, BracketsBreakNamespace)
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

	TEST_FIXTURE(sharpText, BracketsBreakBlocks)
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


	TEST_FIXTURE(sharpText, BracketsBreakBrackets)
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

	TEST(BracketsBreakEmptyBrackets)
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

	//-------------------------------------------------------------------------
	// AStyle C# Attach Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(sharpText, BracketsAttach)
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

	TEST_FIXTURE(sharpText, BracketsAttachShort)
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

	TEST_FIXTURE(sharpText, BracketsAttachNamespace)
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

	TEST_FIXTURE(sharpText, BracketsAttachBlocks)
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


	TEST_FIXTURE(sharpText, BracketsAttachBrackets)
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

	TEST_FIXTURE(sharpText, BracketsAttachBreakClosing)
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

	TEST(BracketsAttachEmptyBrackets)
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
		char options[] = "brackets=attach, mode=cs";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	//-------------------------------------------------------------------------
	// AStyle C# Linux Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(sharpText, BracketsLinux)
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

	TEST_FIXTURE(sharpText, BracketsLinuxShort)
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

	TEST_FIXTURE(sharpText, BracketsLinuxNamespace)
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

	TEST_FIXTURE(sharpText, BracketsLinuxBlocks)
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


	TEST_FIXTURE(sharpText, BracketsLinuxBrackets)
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

	TEST_FIXTURE(sharpText, BracketsLinuxBreakClosing)
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

	TEST(BracketsLinuxEmptyBrackets)
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
		char options[] = "brackets=linux, mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}
	TEST_FIXTURE(sharpText, BracketsLinuxFormatting)
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
			"        public void setDetails(string str1, string str2) {\n"
			"            ExamCode=str1;\n"
			"        }\n"
			"\n"
			"        public string[] getdetails() {\n"
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

	TEST(BracketsLinuxNestedNamespace)
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

	TEST_FIXTURE(sharpText, BracketsStroustrup)
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

	TEST_FIXTURE(sharpText, BracketsStroustrupShort)
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

	TEST_FIXTURE(sharpText, BracketsStroustrupNamespace)
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

	TEST_FIXTURE(sharpText, BracketsStroustrupBlocks)
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


	TEST_FIXTURE(sharpText, BracketsStroustrupBrackets)
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


	TEST_FIXTURE(sharpText, BracketsStroustrupBreakClosing)
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

	TEST(BracketsStroustrupEmptyBrackets)
	{
		// test stroustrup brackets option
		// do not change empty broken brackets
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

	TEST_FIXTURE(sharpText, BracketsStroustrupFormatting)
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
			"        public void setDetails(string str1, string str2) {\n"
			"            ExamCode=str1;\n"
			"        }\n"
			"\n"
			"        public string[] getdetails() {\n"
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

	TEST(BracketsStroustrupNestedNamespace)
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
	// AStyle C# Other Bracket Options
	//-------------------------------------------------------------------------

	TEST(BracketsOtherWhere)
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

	TEST(BracketsOtherWhereBlocks)
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

	TEST(BracketsOtherWhereBrackets)
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

	TEST(BracketsOtherWhereClass)
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

	TEST(BracketsOtherWhereClassBlocks)
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

	TEST(BracketsOtherWhereClassBrackets)
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

	TEST(BracketsOtherWhereClassClass)
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

	TEST_FIXTURE(sharpText, BracketsOtherClass)
	{
		// indent classes should NOT affect C# formatting
		char options[] = "indent-classes, keep-one-line-blocks, mode=cs";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(textIn, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherAccessors1)
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

	TEST(BracketsOtherAccessors2)
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

	TEST(BracketsOtherNestedClass)
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

	TEST(BracketsOtherNestedClassBlocks)
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

	TEST(BracketsOtherNestedClassBrackets)
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

	TEST(BracketsOtherNestedNamespace)
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

	TEST(BracketsOtherNestedNamespaceBlocks)
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

	TEST(BracketsOtherNestedNamespaceBrackets)
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

	TEST(BracketsOtherNestedNamespaceIndent)
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

	TEST(BracketsOtherNestedNamespaceIndentBlocks)
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

	TEST(BracketsOtherNestedNamespaceIndentBrackets)
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

	TEST(BracketsOtherNewOperator1)
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

	TEST(BracketsOtherNewOperator2)
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

	TEST(BracketsOtherNewOperator3)
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

	// TODO: add tests for array brackets

}   // end SUITE(SharpBracketOptions)

