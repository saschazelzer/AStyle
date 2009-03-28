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

SUITE(JavaBracketOptions)
{
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

	TEST_FIXTURE(javaText, BracketsNone)
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

	TEST_FIXTURE(javaText, BracketsNoneBlocks)
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


	TEST_FIXTURE(javaText, BracketsNoneBrackets)
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
		char options[] = "mode=java";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	//-------------------------------------------------------------------------
	// AStyle Java Break Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(javaText, BracketsBreak)
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

	TEST_FIXTURE(javaText, BracketsBreakShort)
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

	TEST_FIXTURE(javaText, BracketsBreakBlocks)
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


	TEST_FIXTURE(javaText, BracketsBreakBrackets)
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
		char options[] = "brackets=break, mode=java";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}
	//-------------------------------------------------------------------------
	// AStyle Java Attach Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(javaText, BracketsAttach)
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

	TEST_FIXTURE(javaText, BracketsAttachShort)
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

	TEST_FIXTURE(javaText, BracketsAttachBlocks)
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

	TEST_FIXTURE(javaText, BracketsAttachBrackets)
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

	TEST_FIXTURE(javaText, BracketsAttachBreakClosing)
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
		char options[] = "brackets=attach, mode=java";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	//-------------------------------------------------------------------------
	// AStyle Java Linux Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(javaText, BracketsLinux)
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

	TEST_FIXTURE(javaText, BracketsLinuxShort)
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

	TEST_FIXTURE(javaText, BracketsLinuxBlocks)
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

	TEST_FIXTURE(javaText, BracketsLinuxBrackets)
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

	TEST_FIXTURE(javaText, BracketsLinuxBreakClosing)
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
		char options[] = "brackets=linux, mode=java";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}
	//-------------------------------------------------------------------------
	// AStyle Java Stroustrup Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(javaText, BracketsStroustrup)
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

	TEST_FIXTURE(javaText, BracketsStroustrupShort)
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

	TEST_FIXTURE(javaText, BracketsStroustrupBlocks)
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

	TEST_FIXTURE(javaText, BracketsStroustrupBrackets)
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

	TEST_FIXTURE(javaText, BracketsStroustrupBreakClosing)
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
		char options[] = "brackets=stroustrup, mode=java";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	//-------------------------------------------------------------------------
	// AStyle Java Other Bracket Options
	//-------------------------------------------------------------------------

	TEST_FIXTURE(javaText, BracketsOtherNamespace)
	{
		// indent namespaces should NOT affect java formatting
		char options[] = "indent-namespaces, mode=java";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(textIn, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(javaText, BracketsOtherClass)
	{
		// indent classes should NOT affect java formatting
		char options[] = "indent-classes, mode=java";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(textIn, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(javaText, BracketsOtherNamespaceClass)
	{
		// indent namespaces and classes should NOT affect java formatting
		char options[] = "indent-namespaces, indent-classes, mode=java";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(textIn, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherInterface)
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

	TEST(BracketsOtherInterfaceBlocks)
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

	TEST(BracketsOtherInterfaceBrackets)
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

		char options[] = "mode=java";
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

		char options[] = "indent-blocks, mode=java";
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

		char options[] = "indent-brackets, mode=java";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherStaticConstructor)
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
	TEST(BracketsOtherStaticConstructorBlocks)
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

	TEST(BracketsOtherStaticConstructorBrackets)
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

	TEST(BracketsOtherThrows)
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

	TEST(BracketsOtherThrowsBlocks)
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

	TEST(BracketsOtherThrowsBrackets)
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

	TEST(BracketsOtherNewOperator1)
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

	TEST(BracketsOtherNewOperator2)
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

	TEST(BracketsArray1)
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

	// TODO: add more tests for array brackets

}   // end SUITE(JavaBracketOptions)
