//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-----------------------------------------------------------------------------
// AStyle C++ Bracket Options
//-----------------------------------------------------------------------------

SUITE(CppBracketOptions)
{

//-------------------------------------------------------------------------
// AStyle C++ Common Text for Testing
//-------------------------------------------------------------------------
	struct cppText
	{
		string textStr;
		const char* textIn;

		cppText()
		{
			textStr =
				"\nnamespace FooName\n"
				"{\n"
				"\n"
				"class FooClass\n"
				"{\n"
				"private:\n"
				"    bool var1;\n"
				"    void func1();\n"
				"protected:\n"
				"    bool var2;\n"
				"    void func2();\n"
				"};\n"
				"\n"
				"void FooClass::Foo(bool isFoo)\n"
				"{\n"
				"    if (isFoo) {\n"
				"        bar();\n"
				"    } else {\n"
				"        anotherBar();\n"
				"    }\n"
				"}\n"
				"\n"
				"}   // end FooName\n";

			textIn = textStr.c_str();
		}
	};

//-------------------------------------------------------------------------
// AStyle C++ Default Bracket Options
//-------------------------------------------------------------------------

	TEST_FIXTURE(cppText, BracketsNone)
	{
		// test default brackets option (do not change)
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsNoneNamespace)
	{
		// test default brackets option (do not change)
		// indented namespace
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"    class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsNoneClass)
	{
		// test default brackets option (do not change)
		// indent class blocks
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "indent-classes";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsNoneBlocks)
	{
		// test default blocks option (do not change brackets)
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"            bar();\n"
			"        }\n"
			"    else {\n"
			"            anotherBar();\n"
			"        }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "indent-blocks";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsNoneNamespaceBlocks)
	{
		// test default brackets option (do not change brackets)
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"    class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo) {\n"
			"                bar();\n"
			"            }\n"
			"        else {\n"
			"                anotherBar();\n"
			"            }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "indent-blocks, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsNoneBrackets)
	{
		// test default brackets option (do not change)
		// indent brackets
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"    {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else {\n"
			"        anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "indent-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST_FIXTURE(cppText, BracketsNoneNamespaceBrackets)
	{
		// test default brackets option (do not change)
		// indent brackets, indent namespaces
		char text[] =
			"\nnamespace FooName\n"
			"    {\n"
			"\n"
			"    class FooClass\n"
			"        {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"        };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"        {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"            }\n"
			"        else {\n"
			"            anotherBar();\n"
			"            }\n"
			"        }\n"
			"\n"
			"    }   // end FooName\n";
		char options[] = "indent-brackets, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST_FIXTURE(cppText, BracketsNoneEmptyBrackets)
	{
		// test default brackets option (do not change)
		// do not change empty brackets
		char text[] =
			"\nclass FooClass\n"
			"{\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed)\n"
			"    {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

//-------------------------------------------------------------------------
// AStyle C++ Break Bracket Options
//-------------------------------------------------------------------------

	TEST_FIXTURE(cppText, BracketsBreak)
	{
		// test break brackets option
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
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
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=break";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsBreakShort)
	{
		// test break brackets short option
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
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
			"\n"
			"}   // end FooName\n";
		char options[] = "-b";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsBreakNamespace)
	{
		// test break brackets option
		// indented namespace
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"    class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
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
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=break, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsBreakClass)
	{
		// test break brackets option
		// indent class blocks
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
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
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=break, indent-classes";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsBreakBlocks)
	{
		// test break brackets option
		// indent blocks
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo)\n"
			"        {\n"
			"            bar();\n"
			"        }\n"
			"    else\n"
			"        {\n"
			"            anotherBar();\n"
			"        }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=break, indent-blocks";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsBreakNamespaceBlocks)
	{
		// test break brackets option
		// indent blocks, indent namespaces
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"    class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
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
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=break, indent-blocks, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsBreakBrackets)
	{
		// test break brackets option
		// indent brackets
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"    {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo)\n"
			"        {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        {\n"
			"        anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=break, indent-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST_FIXTURE(cppText, BracketsBreakNamespaceBrackets)
	{
		// test break brackets option
		// indent brackets, indent namespaces
		char text[] =
			"\nnamespace FooName\n"
			"    {\n"
			"\n"
			"    class FooClass\n"
			"        {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"        };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
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
			"\n"
			"    }   // end FooName\n";
		char options[] = "brackets=break, indent-brackets, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsBreakEmptyBrackets)
	{
		// test break brackets option
		// do not change empty brackets
		char text[] =
			"\nclass FooClass\n"
			"{\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed)\n"
			"    {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char options[] = "brackets=break";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

//-------------------------------------------------------------------------
// AStyle C++ Attach Bracket Options
//-------------------------------------------------------------------------

	TEST_FIXTURE(cppText, BracketsAttach)
	{
		// test attach brackets option
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsAttachShort)
	{
		// test attach brackets option
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-a";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsAttachNamespace)
	{
		// test attach brackets option
		// indented namespace
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"    class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo) {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsAttachClass)
	{
		// test attach brackets option
		// indent class blocks
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach, indent-classes";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsAttachBlocks)
	{
		// test attach brackets option
		// indent blocks
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"            bar();\n"
			"        }\n"
			"    else {\n"
			"            anotherBar();\n"
			"        }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach, indent-blocks";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsAttachNamespaceBlocks)
	{
		// test attach brackets option
		// indent blocks, indent namespaces
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"    class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo) {\n"
			"        if (isFoo) {\n"
			"                bar();\n"
			"            }\n"
			"        else {\n"
			"                anotherBar();\n"
			"            }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach, indent-blocks, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsAttachBrackets)
	{
		// test attach brackets option
		// indent brackets
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else {\n"
			"        anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach, indent-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST_FIXTURE(cppText, BracketsAttachNamespaceBrackets)
	{
		// test attach brackets option
		// indent brackets, indent namespaces
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"    class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"        };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo) {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"            }\n"
			"        else {\n"
			"            anotherBar();\n"
			"            }\n"
			"        }\n"
			"\n"
			"    }   // end FooName\n";
		char options[] = "brackets=attach, indent-brackets, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST_FIXTURE(cppText, BracketsAttachBreakClosing)
	{
		// test attach brackets option
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    }\n"
			"    else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=attach, break-closing-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsAttachEmptyBrackets)
	{
		// test attach brackets option
		// attach both brackets
		char textIn[] =
			"\nclass FooClass\n"
			"{\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed)\n"
			"    {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char text[] =
			"\nclass FooClass {\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed) {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed) {}\n";
		char options[] = "brackets=attach";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

//-------------------------------------------------------------------------
// AStyle C++ Linux Bracket Options
//-------------------------------------------------------------------------

	TEST_FIXTURE(cppText, BracketsLinux)
	{
		// test linux brackets option
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxShort)
	{
		// test linux brackets option
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-l";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxNamespace)
	{
		// test linux brackets option
		// indented namespace
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"    class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxClass)
	{
		// test linux brackets option
		// indent class blocks
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux, indent-classes";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxBlocks)
	{
		// test linux brackets option
		// indent blocks
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"            bar();\n"
			"        }\n"
			"    else {\n"
			"            anotherBar();\n"
			"        }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux, indent-blocks";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxNamespaceBlocks)
	{
		// test linux brackets option
		// indent blocks, indent namespaces
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"    class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo) {\n"
			"                bar();\n"
			"            }\n"
			"        else {\n"
			"                anotherBar();\n"
			"            }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux, indent-blocks, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxBrackets)
	{
		// test linux brackets option
		// indent brackets
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"    {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else {\n"
			"        anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux, indent-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxNamespaceBrackets)
	{
		// test linux brackets option
		// indent brackets, indent namespaces
		char text[] =
			"\nnamespace FooName\n"
			"    {\n"
			"\n"
			"    class FooClass\n"
			"        {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"        };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"        {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"            }\n"
			"        else {\n"
			"            anotherBar();\n"
			"            }\n"
			"        }\n"
			"\n"
			"    }   // end FooName\n";
		char options[] = "brackets=linux, indent-brackets, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxBreakClosing)
	{
		// test break closing brackets option with linux brackets
		// effective only with attach or lnux brackets
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    }\n"
			"    else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=linux, break-closing-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsLinuxEmptyBrackets)
	{
		// test linux brackets option
		// attach empty attached brackets
		// do not change empty broken brackets
		char textIn[] =
			"\nclass FooClass\n"
			"{\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed)\n"
			"    {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char text[] =
			"\nclass FooClass\n"
			"{\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed) {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char options[] = "brackets=linux";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsLinuxFormatting)
	{
		// test linux brackets option, for non-function top level objects
		// brackets are attached for function definitions within a class
		// brackets are attached for arrays, structs, enums and other top level
		//      objects that are not classes or functions.
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"public:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"private:\n"
			"    // inline class functions are NOT broken\n"
			"    void FooClass {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"};\n"
			"\n"
			"// arrays are NOT broken\n"
			"fooArray[] = {\n"
			"    red,\n"
			"    green,\n"
			"    darkblue\n"
			"};\n"
			"\n"
			"// structs are NOT broken\n"
			"struct fooStruct {\n"
			"    int foo;\n"
			"}\n"
			"\n"
			"// enums are NOT broken\n"
			"enum fooEnum {\n"
			"    foo,\n"
			"    bar\n"
			"}\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}\n";

		char options[] = "brackets=linux";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsLinuxNestedNamespace)
	{
		// test indent nested namespaces with linux brackets
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"class A\n"
			"{\n"
			"public:\n"
			"    namespace B\n"
			"    {\n"
			"    class B\n"
			"    {\n"
			"    public:\n"
			"        namespace C\n"
			"        {\n"
			"        class C\n"
			"        {\n"
			"        public:\n"
			"        }\n"
			"        }\n"
			"    }\n"
			"    }\n"
			"}\n"
			"}\n";

		char options[] = "brackets=linux";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

//-------------------------------------------------------------------------
// AStyle C++ Stroustrup Bracket Options
//-------------------------------------------------------------------------

	TEST_FIXTURE(cppText, BracketsStroustrup)
	{
		// test stroustrup brackets option
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupShort)
	{
		// test stroustrup brackets option
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-u";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupNamespace)
	{
		// test stroustrup brackets option
		// indented namespace
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"    class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupClass)
	{
		// test stroustrup brackets option
		// indent class blocks
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup, indent-classes";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupBlocks)
	{
		// test stroustrup brackets option
		// indent blocks
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"            bar();\n"
			"        }\n"
			"    else {\n"
			"            anotherBar();\n"
			"        }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup, indent-blocks";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupNamespaceBlocks)
	{
		// test stroustrup brackets option
		// indent blocks, indent namespaces
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"    class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"        if (isFoo) {\n"
			"                bar();\n"
			"            }\n"
			"        else {\n"
			"                anotherBar();\n"
			"            }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup, indent-blocks, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupBrackets)
	{
		// test stroustrup brackets option
		// indent brackets
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else {\n"
			"        anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup, indent-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupNamespaceBrackets)
	{
		// test stroustrup brackets option
		// indent brackets, indent namespaces
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"    class FooClass {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"        };\n"
			"\n"
			"    void FooClass::Foo(bool isFoo)\n"
			"        {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"            }\n"
			"        else {\n"
			"            anotherBar();\n"
			"            }\n"
			"        }\n"
			"\n"
			"    }   // end FooName\n";
		char options[] = "brackets=stroustrup, indent-brackets, indent-namespaces";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupBreakClosing)
	{
		// test break closing brackets option with stroustrup brackets
		// effective only with attach, linux, or stroustrup brackets
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"private:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"protected:\n"
			"    bool var2;\n"
			"    void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    }\n"
			"    else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "brackets=stroustrup, break-closing-brackets";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsStroustrupEmptyBrackets)
	{
		// test stroustrup brackets option
		// attach empty attached brackets
		// do not change empty broken brackets
		char textIn[] =
			"\nclass FooClass\n"
			"{\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed)\n"
			"    {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char text[] =
			"\nclass FooClass {\n"
			"public:\n"
			"    FooClass() : ed(ed) {}\n"
			"    FooClass() : ed(ed) {}\n"
			"};\n"
			"\n"
			"FooClass() : ed(ed) {}\n"
			"FooClass() : ed(ed)\n"
			"{}\n";
		char options[] = "brackets=stroustrup";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST_FIXTURE(cppText, BracketsStroustrupFormatting)
	{
		// test stroustrup brackets option, for non-function top level objects
		// brackets are attached for function definitions within a class
		// brackets are attached for arrays, structs, enums and other top level
		//      objects that are not classes or functions.
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"public:\n"
			"    bool var1;\n"
			"    void func1();\n"
			"private:\n"
			"    // inline class functions are NOT broken\n"
			"    void FooClass {\n"
			"        if (isFoo) {\n"
			"            bar();\n"
			"        } else {\n"
			"            anotherBar();\n"
			"        }\n"
			"    }\n"
			"\n"
			"};\n"
			"\n"
			"// arrays are NOT broken\n"
			"fooArray[] = {\n"
			"    red,\n"
			"    green,\n"
			"    darkblue\n"
			"};\n"
			"\n"
			"// structs are NOT broken\n"
			"struct fooStruct {\n"
			"    int foo;\n"
			"}\n"
			"\n"
			"// enums are NOT broken\n"
			"enum fooEnum {\n"
			"    foo,\n"
			"    bar\n"
			"}\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"    } else {\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"\n"
			"}\n";

		char options[] = "brackets=stroustrup";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsStroustrupNestedNamespace)
	{
		// test indent nested namespaces with stroustrup brackets
		char text[] =
			"\nnamespace FooName {\n"
			"class FooClass {\n"
			"public:\n"
			"    namespace B {\n"
			"    class B {\n"
			"    public:\n"
			"        namespace C {\n"
			"        class C {\n"
			"        public:\n"
			"        }\n"
			"        }\n"
			"    }\n"
			"    }\n"
			"}\n"
			"}\n";

		char options[] = "brackets=stroustrup";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

//-------------------------------------------------------------------------
// AStyle C++ Other Bracket Options
//-------------------------------------------------------------------------

	TEST(BracketsOtherConstIndent)
	{
		// no initial indent with indent-blocks when a const function is used
		char text[] =
			"\nint Foo(bool isBar) const\n"
			"{\n"
			"    if (isBar)\n"
			"    {\n"
			"        bar();\n"
			"        return 1;\n"
			"    }\n"
			"    else\n"
			"        return 0;\n"
			"}\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherConstIndentBlocks)
	{
		// no initial indent with indent-blocks when a const function is used
		char text[] =
			"\nint Foo(bool isBar) const\n"
			"{\n"
			"    if (isBar)\n"
			"        {\n"
			"            bar();\n"
			"            return 1;\n"
			"        }\n"
			"    else\n"
			"        return 0;\n"
			"}\n";
		char options[] = "indent-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherConstIndentBrackets)
	{
		// initial indent with indent-brackets when a const function is used
		char text[] =
			"\nint Foo(bool isBar) const\n"
			"    {\n"
			"    if (isBar)\n"
			"        {\n"
			"        bar();\n"
			"        return 1;\n"
			"        }\n"
			"    else\n"
			"        return 0;\n"
			"    }\n";
		char options[] = "indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedClass)
	{
		// test nested classes
		char text[] =
			"\nclass A\n"
			"{\n"
			"public:\n"
			"    int foo1;\n"
			"    class B\n"
			"    {\n"
			"    public:\n"
			"        int foo2;\n"
			"        class C\n"
			"        {\n"
			"        public:\n"
			"            void foo(bool isFoo)\n"
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

		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedClassBlocks)
	{
		// test nested classes and indented blocks
		char text[] =
			"\nclass A\n"
			"{\n"
			"public:\n"
			"    int foo1;\n"
			"    class B\n"
			"    {\n"
			"    public:\n"
			"        int foo2;\n"
			"        class C\n"
			"        {\n"
			"        public:\n"
			"            void foo(bool isFoo)\n"
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

		char options[] = "indent-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedClassBrackets)
	{
		// test nested classes and indented brackets
		char text[] =
			"\nclass A\n"
			"    {\n"
			"public:\n"
			"    int foo1;\n"
			"    class B\n"
			"        {\n"
			"    public:\n"
			"        int foo2;\n"
			"        class C\n"
			"            {\n"
			"        public:\n"
			"            void foo(bool isFoo)\n"
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

		char options[] = "indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedClassIndent)
	{
		// test nested classes with indented classes
		char text[] =
			"\nclass A\n"
			"{\n"
			"    public:\n"
			"        int foo1;\n"
			"        class B\n"
			"        {\n"
			"            public:\n"
			"                int foo2;\n"
			"                class C\n"
			"                {\n"
			"                    public:\n"
			"                        void foo(bool isFoo)\n"
			"                        {\n"
			"                            if (isFoo)\n"
			"                            {\n"
			"                                bar();\n"
			"                            }\n"
			"                            else\n"
			"                                anotherBar();\n"
			"                        }\n"
			"                }\n"
			"        }\n"
			"}\n";

		char options[] = "indent-classes";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedClassIndentBlocks)
	{
		// test nested classes with indented classes and indented blocks
		char text[] =
			"\nclass A\n"
			"{\n"
			"    public:\n"
			"        int foo1;\n"
			"        class B\n"
			"        {\n"
			"            public:\n"
			"                int foo2;\n"
			"                class C\n"
			"                {\n"
			"                    public:\n"
			"                        void foo(bool isFoo)\n"
			"                        {\n"
			"                            if (isFoo)\n"
			"                                {\n"
			"                                    bar();\n"
			"                                }\n"
			"                            else\n"
			"                                anotherBar();\n"
			"                        }\n"
			"                }\n"
			"        }\n"
			"}\n";

		char options[] = "indent-classes, indent-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedClassIndentBrackets)
	{
		// test nested classes with indented classes and indented brackets
		char text[] =
			"\nclass A\n"
			"    {\n"
			"    public:\n"
			"        int foo1;\n"
			"        class B\n"
			"            {\n"
			"            public:\n"
			"                int foo2;\n"
			"                class C\n"
			"                    {\n"
			"                    public:\n"
			"                        void foo(bool isFoo)\n"
			"                            {\n"
			"                            if (isFoo)\n"
			"                                {\n"
			"                                bar();\n"
			"                                }\n"
			"                            else\n"
			"                                anotherBar();\n"
			"                            }\n"
			"                    }\n"
			"            }\n"
			"    }\n";

		char options[] = "indent-classes, indent-brackets";
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
			"void foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo)\n"
			"    {\n"
			"        bar();\n"
			"    }\n"
			"    else\n"
			"        anotherBar();\n"
			"}\n"
			"}\n"
			"}\n"
			"}\n";

		char options[] = "";
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
			"void foo(bool isFoo)\n"
			"{\n"
			"    if (isFoo)\n"
			"        {\n"
			"            bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"}\n"
			"}\n"
			"}\n"
			"}\n";

		char options[] = "indent-blocks";
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
			"void foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo)\n"
			"        {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"    }\n"
			"}\n"
			"}\n"
			"}\n";

		char options[] = "indent-brackets";
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
			"            void foo(bool isFoo)\n"
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

		char options[] = "indent-namespaces";
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
			"            void foo(bool isFoo)\n"
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

		char options[] = "indent-namespaces, indent-blocks";
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
			"            void foo(bool isFoo)\n"
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

		char options[] = "indent-namespaces, indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceClass)
	{
		// test namespaces within a class
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"class A\n"
			"{\n"
			"public:\n"
			"    namespace B\n"
			"    {\n"
			"    class B\n"
			"    {\n"
			"    public:\n"
			"        namespace C\n"
			"        {\n"
			"        class C\n"
			"        {\n"
			"        public:\n"
			"            void foo(bool isFoo)\n"
			"            {\n"
			"                if (isFoo)\n"
			"                {\n"
			"                    bar();\n"
			"                }\n"
			"                else\n"
			"                    anotherBar();\n"
			"            }\n"
			"        }\n"
			"        }\n"
			"    }\n"
			"    }\n"
			"}\n"
			"}\n";

		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceClassBlocks)
	{
		// test namespaces within a class with indented blocks
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"class A\n"
			"{\n"
			"public:\n"
			"    namespace B\n"
			"    {\n"
			"    class B\n"
			"    {\n"
			"    public:\n"
			"        namespace C\n"
			"        {\n"
			"        class C\n"
			"        {\n"
			"        public:\n"
			"            void foo(bool isFoo)\n"
			"            {\n"
			"                if (isFoo)\n"
			"                    {\n"
			"                        bar();\n"
			"                    }\n"
			"                else\n"
			"                    anotherBar();\n"
			"            }\n"
			"        }\n"
			"        }\n"
			"    }\n"
			"    }\n"
			"}\n"
			"}\n";

		char options[] = "indent-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceClassBrackets)
	{
		// test namespaces within a class with indented brackets
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"class A\n"
			"    {\n"
			"public:\n"
			"    namespace B\n"
			"    {\n"
			"    class B\n"
			"        {\n"
			"    public:\n"
			"        namespace C\n"
			"        {\n"
			"        class C\n"
			"            {\n"
			"        public:\n"
			"            void foo(bool isFoo)\n"
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
			"        }\n"
			"    }\n"
			"    }\n"
			"}\n";

		char options[] = "indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceIndentClass)
	{
		// test indented namespaces within a class
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"    class A\n"
			"    {\n"
			"    public:\n"
			"        namespace B\n"
			"        {\n"
			"            class B\n"
			"            {\n"
			"            public:\n"
			"                namespace C\n"
			"                {\n"
			"                    class C\n"
			"                    {\n"
			"                    public:\n"
			"                        void foo(bool isFoo)\n"
			"                        {\n"
			"                            if (isFoo)\n"
			"                            {\n"
			"                                bar();\n"
			"                            }\n"
			"                            else\n"
			"                                anotherBar();\n"
			"                        }\n"
			"                    }\n"
			"                }\n"
			"            }\n"
			"        }\n"
			"    }\n"
			"}\n";

		char options[] = "indent-namespaces";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceIndentClassBlocks)
	{
		// test indented namespaces within a class with indented blocks
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"    class A\n"
			"    {\n"
			"    public:\n"
			"        namespace B\n"
			"        {\n"
			"            class B\n"
			"            {\n"
			"            public:\n"
			"                namespace C\n"
			"                {\n"
			"                    class C\n"
			"                    {\n"
			"                    public:\n"
			"                        void foo(bool isFoo)\n"
			"                        {\n"
			"                            if (isFoo)\n"
			"                                {\n"
			"                                    bar();\n"
			"                                }\n"
			"                            else\n"
			"                                anotherBar();\n"
			"                        }\n"
			"                    }\n"
			"                }\n"
			"            }\n"
			"        }\n"
			"    }\n"
			"}\n";

		char options[] = "indent-namespaces, indent-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceIndentClassBrackets)
	{
		// test indented namespaces within a class with indented brackets
		char text[] =
			"\nnamespace A\n"
			"    {\n"
			"    class A\n"
			"        {\n"
			"    public:\n"
			"        namespace B\n"
			"            {\n"
			"            class B\n"
			"                {\n"
			"            public:\n"
			"                namespace C\n"
			"                    {\n"
			"                    class C\n"
			"                        {\n"
			"                    public:\n"
			"                        void foo(bool isFoo)\n"
			"                            {\n"
			"                            if (isFoo)\n"
			"                                {\n"
			"                                bar();\n"
			"                                }\n"
			"                            else\n"
			"                                anotherBar();\n"
			"                            }\n"
			"                        }\n"
			"                    }\n"
			"                }\n"
			"            }\n"
			"        }\n"
			"    }\n";

		char options[] = "indent-namespaces, indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceIndentClassIndent)
	{
		// test indented namespaces within an indented class
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"    class A\n"
			"    {\n"
			"        public:\n"
			"            namespace B\n"
			"            {\n"
			"                class B\n"
			"                {\n"
			"                    public:\n"
			"                        namespace C\n"
			"                        {\n"
			"                            class C\n"
			"                            {\n"
			"                                public:\n"
			"                                    void foo(bool isFoo)\n"
			"                                    {\n"
			"                                        if (isFoo)\n"
			"                                        {\n"
			"                                            bar();\n"
			"                                        }\n"
			"                                        else\n"
			"                                            anotherBar();\n"
			"                                    }\n"
			"                            }\n"
			"                        }\n"
			"                }\n"
			"            }\n"
			"    }\n"
			"}\n";

		char options[] = "indent-namespaces, indent-classes";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceIndentClassIndentBlocks)
	{
		// test indented namespaces within an indented class with indented blocks
		char text[] =
			"\nnamespace A\n"
			"{\n"
			"    class A\n"
			"    {\n"
			"        public:\n"
			"            namespace B\n"
			"            {\n"
			"                class B\n"
			"                {\n"
			"                    public:\n"
			"                        namespace C\n"
			"                        {\n"
			"                            class C\n"
			"                            {\n"
			"                                public:\n"
			"                                    void foo(bool isFoo)\n"
			"                                    {\n"
			"                                        if (isFoo)\n"
			"                                            {\n"
			"                                                bar();\n"
			"                                            }\n"
			"                                        else\n"
			"                                            anotherBar();\n"
			"                                    }\n"
			"                            }\n"
			"                        }\n"
			"                }\n"
			"            }\n"
			"    }\n"
			"}\n";

		char options[] = "indent-namespaces, indent-classes, indent-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsOtherNestedNamespaceIndentClassIndentBrackets)
	{
		// test indented namespaces within an indented class with indented brackets
		char text[] =
			"\nnamespace A\n"
			"    {\n"
			"    class A\n"
			"        {\n"
			"        public:\n"
			"            namespace B\n"
			"                {\n"
			"                class B\n"
			"                    {\n"
			"                    public:\n"
			"                        namespace C\n"
			"                            {\n"
			"                            class C\n"
			"                                {\n"
			"                                public:\n"
			"                                    void foo(bool isFoo)\n"
			"                                        {\n"
			"                                        if (isFoo)\n"
			"                                            {\n"
			"                                            bar();\n"
			"                                            }\n"
			"                                        else\n"
			"                                            anotherBar();\n"
			"                                        }\n"
			"                                }\n"
			"                            }\n"
			"                    }\n"
			"                }\n"
			"        }\n"
			"    }\n";

		char options[] = "indent-namespaces, indent-classes, indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	//-------------------------------------------------------------------------
	// AStyle C++ Array Bracket Options
	//-------------------------------------------------------------------------

	TEST(BracketsArray1)
	{
		// test array formatting
		char text[] =
			"\nconst char *foos[] = {\n"
			"    \"foo1\",\n"
			"    \"foo2\",\n"
			"    \"foo3\",\n"
			"};";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsArray2)
	{
		// test array formatting
		char text[] =
			"\nstatic tAction StateTable[enStates][enEvents] = {\n"
			"    // IN APPLICATION MODE:         eEventInit       eEventFTPDone\n"
			"    /* eStateIdle              */ { NULL,            FKT(actReturnToIdle) },\n"
			"    /* eStateIdleGetVersion    */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
			"    // IN UPDATE MODE:\n"
			"    /* eStateUpdate            */ { FKT(actUpdate),  FKT(actReturnToIdle) },\n"
			"    /* eStateUpdateGetVersion  */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
			"};\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	// TODO: THE FOLLOWING TEST FAILS
	//TEST(BracketsArray3)
	//{
	//	// test array formatting, opening bracket after a comment
	//	char text[] =
	//		"\nstatic tAction StateTable[enStates][enEvents] =\n"
	//		"    // IN APPLICATION MODE:         eEventInit       eEventFTPDone\n"
	//		"    /* eStateIdle              */{{ NULL,            FKT(actReturnToIdle) },\n"
	//		"    /* eStateIdleGetVersion    */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
	//		"    // IN UPDATE MODE:\n"
	//		"    /* eStateUpdate            */ { FKT(actUpdate),  FKT(actReturnToIdle) },\n"
	//		"    /* eStateUpdateGetVersion  */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
	//		"};\n";
	//	char options[] = "";
	//	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	//	CHECK_EQUAL(text, textOut);
	//	delete [] textOut;
	//}

	TEST(BracketsStruct1)
	{
		// test struct formatting
		// struct with broken brackets
		char text[] =
			"\nstruct\n"
			"{\n"
			"    const char *name;\n"
			"    int id;\n"
			"} idmTable[] =\n"
			"{\n"
			"    {\"IDM_MRUFILE\", IDM_MRUFILE},\n"
			"    {\"IDM_TOOLS\",   IDM_TOOLS},\n"
			"};\n";
		char options[] = "brackets=break";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BracketsStruct2)
	{
		// test struct formatting
		// struct with attached brackets
		char text[] =
			"\nstruct {\n"
			"    const char *name;\n"
			"    int id;\n"
			"} idmTable[] = {\n"
			"    {\"IDM_MRUFILE\", IDM_MRUFILE},\n"
			"    {\"IDM_TOOLS\",   IDM_TOOLS},\n"
			"};\n";
		char options[] = "brackets=attach";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	// TODO: add more tests for array brackets and structs

}   // end SUITE(CppBracketOptions)
