//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// AStyle C++ Style options
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

SUITE(CppStyleOptions)
{
	struct cppText
	{
		string textStr;
		const char* text;

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
				"    if (isFoo)\n"
				"    {\n"
				"        bar();\n"
				"    }\n"
				"    else\n"
				"        anotherBar();\n"
				"}\n"
				"\n"
				"}   // end FooName\n";

			text = textStr.c_str();
		}
	};

	TEST(StyleAllman)
	{
		// test allman style option
		cppText cpp;
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
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=allman";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleAllmanBSD)
	{
		// test allman style BSD option
		cppText cpp;
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
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=bsd";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST(StyleAllmanShort)
	{
		// test allman style short option
		cppText cpp;
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
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A1";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleJava)
	{
		// test java style option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=java";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleJavaShort)
	{
		// test java style short option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A2";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKR)
	{
		// test k&r style option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=k&r";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKRAlt)
	{
		// test k&r style alternate k/r option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=k/r";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKRShort)
	{
		// test k&r style short option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A3";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleStroustrup)
	{
		// test stroustrup style option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=stroustrup";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleStroustrupShort)
	{
		// test stroustrup style short option
		cppText cpp;
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
			"    } else\n"
			"        anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A4";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleWhitesmith)
	{
		// test whitesmith style option
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo)\n"
			"        {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=whitesmith";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleWhitesmithShort)
	{
		// test whitesmith style short option
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"    {\n"
			"    private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"    protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"    {\n"
			"    if (isFoo)\n"
			"        {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A5";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleWhitesmithSwitchBlocks)
	{
		// test whitesmith style with switch blocks
		cppText cpp;
		char text[] =
			"\nvoid Foo(int fooBar)\n"
			"    {\n"
			"    switch (fooBar)\n"
			"        {\n"
			"        case 1:\n"
			"            fooBar = 1;\n"
			"            break;\n"
			"        case 2:\n"
			"            {\n"
			"            fooBar = 2;\n"
			"            }\n"
			"        break;\n"
			"        default:\n"
			"            break;\n"
			"        }\n"
			"    int bar = true;\n"
			"    }\n";
		char options[] = "style=whitesmith";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleBanner)
	{
		// test banner style option
		cppText cpp;
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
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=banner";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleBannerShort)
	{
		// test banner style short option
		cppText cpp;
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
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A6";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleBanerSwitchBlocks)
	{
		// test banner style with switch blocks
		cppText cpp;
		char text[] =
			"\nvoid Foo(int fooBar) {\n"
			"    switch (fooBar) {\n"
			"        case 1:\n"
			"            fooBar = 1;\n"
			"            break;\n"
			"        case 2: {\n"
			"            fooBar = 2;\n"
			"            }\n"
			"        break;\n"
			"        default:\n"
			"            break;\n"
			"        }\n"
			"    int bar = true;\n"
			"    }\n";
		char options[] = "style=banner";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleGnu)
	{
		// test gnu style option
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"  bool var1;\n"
			"  void func1();\n"
			"protected:\n"
			"  bool var2;\n"
			"  void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"  if (isFoo)\n"
			"    {\n"
			"      bar();\n"
			"    }\n"
			"  else\n"
			"    anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=gnu";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleGnuShort)
	{
		// test gnu style short option
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"  bool var1;\n"
			"  void func1();\n"
			"protected:\n"
			"  bool var2;\n"
			"  void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"  if (isFoo)\n"
			"    {\n"
			"      bar();\n"
			"    }\n"
			"  else\n"
			"    anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A7";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleLinux)
	{
		// test linux style option
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"        if (isFoo) {\n"
			"                bar();\n"
			"        } else\n"
			"                anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=linux";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleLinuxShort)
	{
		// test linux style short option
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"        bool var1;\n"
			"        void func1();\n"
			"protected:\n"
			"        bool var2;\n"
			"        void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"        if (isFoo) {\n"
			"                bar();\n"
			"        } else\n"
			"                anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "-A8";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StylePrecedence1)
	{
		// the banner style should have precedence over these options
		// should be banner style (attached brackets, no block indent)
		cppText cpp;
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
			"    };\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"    if (isFoo) {\n"
			"        bar();\n"
			"        }\n"
			"    else\n"
			"        anotherBar();\n"
			"    }\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=banner, brackets=break, indent-blocks";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StylePrecedence2)
	{
		// the gnu style should have precedence over these options
		// should be gnu style (broken brackets, no bracket indent, indent=2)
		cppText cpp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"class FooClass\n"
			"{\n"
			"private:\n"
			"  bool var1;\n"
			"  void func1();\n"
			"protected:\n"
			"  bool var2;\n"
			"  void func2();\n"
			"};\n"
			"\n"
			"void FooClass::Foo(bool isFoo)\n"
			"{\n"
			"  if (isFoo)\n"
			"    {\n"
			"      bar();\n"
			"    }\n"
			"  else\n"
			"    anotherBar();\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=gnu, brackets=attach, indent-brackets, indent=spaces";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StylePrecedence3)
	{
		// the banner style should NOT have precedence over this option
		// should be banner style with tab indent
		cppText cpp;
		char text[] =
			"\nnamespace FooName {\n"
			"\n"
			"class FooClass {\n"
			"	private:\n"
			"		bool var1;\n"
			"		void func1();\n"
			"	protected:\n"
			"		bool var2;\n"
			"		void func2();\n"
			"	};\n"
			"\n"
			"void FooClass::Foo(bool isFoo) {\n"
			"	if (isFoo) {\n"
			"		bar();\n"
			"		}\n"
			"	else\n"
			"		anotherBar();\n"
			"	}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=banner, indent=tab=8";
		char* textOut = AStyleMain(cpp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

}   // end SUITE(CppStyleOptions)

//----------------------------------------------------------------------------
// AStyle Java Style options
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

SUITE(JavaStyleOptions)
{
	struct javaText
	{
		string textStr;
		const char* text;

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

			text = textStr.c_str();
		}
	};

	TEST(StyleAllman)
	{
		// test allman style option
		javaText java;
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

		char options[] = "style=allman, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleAllmanBSD)
	{
		// test allman style BSD option
		javaText java;
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

		char options[] = "style=bsd, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleJava)
	{
		// test java style option
		javaText java;
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

		char options[] = "style=java, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKR)
	{
		// test k&r style option
		javaText java;
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

		char options[] = "style=k&r, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKRAlt)
	{
		// test k&r style option
		javaText java;
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

		char options[] = "style=k/r, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleStroustrup)
	{
		// test stroustrup style option
		javaText java;
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

		char options[] = "style=stroustrup, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleWhitesmith)
	{
		// test whitesmith style option
		javaText java;
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

		char options[] = "style=whitesmith, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleBanner)
	{
		// test banner style option
		javaText java;
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

		char options[] = "style=banner, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleGnu)
	{
		// test gnu style option
		javaText java;
		char text[] =
			"\npublic class FooClass\n"
			"{\n"
			"  private bool var1;\n"
			"  private bool var2;\n"
			"\n"
			"  public void foo(bool isFoo)\n"
			"  {\n"
			"    if (isFoo)\n"
			"      {\n"
			"        bar();\n"
			"      }\n"
			"    else\n"
			"      {\n"
			"        anotherBar();\n"
			"      }\n"
			"  }\n"
			"}\n";

		char options[] = "style=gnu, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST(StyleLinux)
	{
		// test linux style option
		javaText java;
		char text[] =
			"\npublic class FooClass\n"
			"{\n"
			"        private bool var1;\n"
			"        private bool var2;\n"
			"\n"
			"        public void foo(bool isFoo)\n"
			"        {\n"
			"                if (isFoo) {\n"
			"                        bar();\n"
			"                } else {\n"
			"                        anotherBar();\n"
			"                }\n"
			"        }\n"
			"}\n";

		char options[] = "style=linux, mode=java";
		char* textOut = AStyleMain(java.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


}   // end SUITE(JavaStyleOptions)

//----------------------------------------------------------------------------
// AStyle C# Style options
// Additional tests are in the Brackets tests
//----------------------------------------------------------------------------

SUITE(SharpStyleOptions)
{
	struct sharpText
	{
		string textStr;
		const char* text;

		sharpText()
		{
			textStr =
				"\nnamespace FooName\n"
				"{\n"
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
				"\n"
				"}   // end FooName\n";

			text = textStr.c_str();
		}
	};

	TEST(StyleAllman)
	{
		// test allman style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
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
			"\n"
			"}   // end FooName\n";
		char options[] = "style=allman, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleAllmanBSD)
	{
		// test allman style BSD option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=bsd, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleJava)
	{
		// test java style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName {\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=java, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKR)
	{
		// test k&r style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=k&r, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleKRAlt)
	{
		// test k&r style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=k/r, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleStroustrup)
	{
		// test stroustrup style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName {\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=stroustrup, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleWhitesmith)
	{
		// test whitesmith style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=whitesmith, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleBanner)
	{
		// test banner style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName {\n"
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
			"\n"
			"}   // end FooName\n";

		char options[] = "style=banner, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StyleGnu)
	{
		// test gnu style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public class FooClass\n"
			"{\n"
			"  private bool var1;\n"
			"  private bool var2;\n"
			"\n"
			"  public void foo(bool isFoo)\n"
			"  {\n"
			"    if (isFoo)\n"
			"      {\n"
			"        bar();\n"
			"      }\n"
			"    else\n"
			"      {\n"
			"        anotherBar();\n"
			"      }\n"
			"  }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";
		char options[] = "style=gnu, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}


	TEST(StyleLinux)
	{
		// test linux style option
		sharpText sharp;
		char text[] =
			"\nnamespace FooName\n"
			"{\n"
			"\n"
			"public class FooClass\n"
			"{\n"
			"        private bool var1;\n"
			"        private bool var2;\n"
			"\n"
			"        public void foo(bool isFoo)\n"
			"        {\n"
			"                if (isFoo) {\n"
			"                        bar();\n"
			"                } else {\n"
			"                        anotherBar();\n"
			"                }\n"
			"        }\n"
			"}\n"
			"\n"
			"}   // end FooName\n";

		char options[] = "style=linux, mode=cs";
		char* textOut = AStyleMain(sharp.text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

}   // end SUITE(SharpStyleOptions)
