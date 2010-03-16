//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-----------------------------------------------------------------------------
// AStyle C++ Bracket Options
//-----------------------------------------------------------------------------

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

TEST_FIXTURE(cppText, CppBracketsNone)
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

TEST_FIXTURE(cppText, CppBracketsNone_Namespace)
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

TEST_FIXTURE(cppText, CppBracketsNone_Class)
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

TEST_FIXTURE(cppText, CppBracketsNone_NamespaceClass)
{
	// test default brackets option (do not change)
	// indented namespace and class
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    class FooClass\n"
		"    {\n"
		"        private:\n"
		"            bool var1;\n"
		"            void func1();\n"
		"        protected:\n"
		"            bool var2;\n"
		"            void func2();\n"
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
	char options[] = "indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsNone_Blocks)
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

TEST_FIXTURE(cppText, CppBracketsNone_NamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsNone_Brackets)
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


TEST_FIXTURE(cppText, CppBracketsNone_NamespaceBrackets)
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


TEST(CppBracketsNone_EmptyBrackets)
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

TEST(CppBracketsNone_Extern)
{
	// test default brackets option (do not change)
	// extern statement should not change its bracket type
	// and should NOT use in-statement indents
	char text[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Assembler)
{
	// assembler statement should be formatted
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm\n"
		"    {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Break)
{
	// test default brackets option with broken brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
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
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Attach)
{
	// test default brackets option with attached brackets
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Linux)
{
	// test default brackets option with linux brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Horstmann1)
{
	// test default brackets option with horstmann brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Horstmann2)
{
	// test default brackets option with horstmann brackets
	// and 2 brackets on the same line
	char text[] =
		"\nvoid foo()\n"
		"{   if(isFoo) {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Misc1)
{
	// test default brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo1() { error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo2() { // comment2\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo3() { /* comment3 */\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1() {\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2() { // comment2\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3() { /* comment3 */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Misc2)
{
	// test default brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {/* dummy */}\n"
		"\n"
		"    if (bar1()) {;/* dummy */}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {\n"
		"        /* dummy */\n"
		"    }\n"
		"\n"
		"    if (bar1()) {\n"
		"        ;/* dummy */\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_Misc3)
{
	// test default brackets option with a macro
	// bracket type will be incorrectly classified as an array
	// but should not break at the semi colon
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    YY_RULE_SETUP\n"
		"    { BEGIN(list); return CONT; }\n"
		"    YY_BREAK\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_HorstmannIndent1)
{
	// test default brackets option with horstmann brackets
	// with the indent changed from 2 to 4
	char textIn[] =
		"\nvoid Foo()\n"
		"{ if (isFoo)\n"
		"  { foo();\n"
		"  }\n"
		"  else\n"
		"  { // comment\n"
		"    bar();\n"
		"  }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   foo();\n"
		"    }\n"
		"    else\n"
		"    {   // comment\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_HorstmannIndent2)
{
	// test default brackets option with horstmann brackets
	// with the indent changed from 6 to 4
	char textIn[] =
		"\nvoid Foo()\n"
		"{     if (isFoo)\n"
		"      {     foo();\n"
		"      }\n"
		"      else\n"
		"      {     // comment\n"
		"            bar();\n"
		"      }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   foo();\n"
		"    }\n"
		"    else\n"
		"    {   // comment\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_HorstmannIndentComment1)
{
	// test default brackets option with horstmann brackets
	// with the indent changed from 2 to 4
	char textIn[] =
		"\nvoid Foo()\n"
		"{ if (isFoo)\n"
		"  { /* comment1 */\n"
		"    foo();\n"
		"  }\n"
		"  else\n"
		"  { /* comment2\n"
		"     *\n"
		"     */\n"
		"    bar();\n"
		"  }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   /* comment1 */\n"
		"        foo();\n"
		"    }\n"
		"    else\n"
		"    {   /* comment2\n"
		"         *\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_HorstmannIndentComment2)
{
	// test default brackets option with horstmann brackets
	// with the indent changed from 6 to 4
	char textIn[] =
		"\nvoid Foo()\n"
		"{     if (isFoo)\n"
		"      {     /* comment1 */\n"
		"            foo();\n"
		"      }\n"
		"      else\n"
		"      {     /* comment2\n"
		"             *\n"
		"             */\n"
		"            bar();\n"
		"      }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   /* comment1 */\n"
		"        foo();\n"
		"    }\n"
		"    else\n"
		"    {   /* comment2\n"
		"         *\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_LineCommentsBreak)
{
	// line comments following broken brackets should be unchanged
	char text[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_LineCommentsAttach)
{
	// line comments following attached brackets should be unchanged
	char text[] =
		"\nvoid foo(bool isFoo) {    // comment1\n"
		"    if (isFoo) {          // comment2\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_LineCommentsHorstmann)
{
	// line comments following horstmann brackets should be unchanged
	char text[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsBreak1)
{
	// broken brackets should not change
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment\n"
		"     */\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsAttach1)
{
	// attached brackets should not change
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment\n"
		"     */\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsHorstmann1)
{
	// horstmann brackets should not change
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment\n"
		"     */\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsBreak2)
{
	// broken brackets with following comments
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsAttach2)
{
	// attached brackets with following comments
	// mixed tabs and spaces
	char textIn[] ="\nvoid (foo) {\n"
				   "	/*\n"
				   "	 * comment1\n"
				   "     */\n"
				   "    if (isFoo) {\n"
				   "		/*\n"
				   " 	     * comment2\n"
				   "  	     */\n"
				   "        bar();\n"
				   "    }\n"
				   "}\n";
	char text[] ="\nvoid (foo) {\n"
				 "    /*\n"
				 "     * comment1\n"
				 "     */\n"
				 "    if (isFoo) {\n"
				 "        /*\n"
				 "         * comment2\n"
				 "         */\n"
				 "        bar();\n"
				 "    }\n"
				 "}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsHorstmann2)
{
	// horstmann brackets with following comments
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {	/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsBreak3)
{
	// comments following broken brackets should be unchanged
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsAttach3)
{
	// comments following attached brackets should be unchanged
	// multi-line comments following attached brackets break
	//    but are NOT aligned
	char textIn[] =
		"\nvoid foo1(bool isFoo) { /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) { /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) { /* comment4\n"
		"                 *\n"
		"                 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) { /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) {\n"
		"    /* comment3\n"
		"         *\n"
		"         */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"                     *\n"
		"                     */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_CommentsHorstmann3)
{
	// comments following horstmann brackets should be unchanged
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) /* comment0 */\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_MultipleCommentsBreak)
{
	// multiple comments with broken brackets should remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_MultipleCommentsAttach)
{
	// multiple comments with attached brackets remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNone_MultipleCommentsHorstmann)
{
	// multiple comments with horstmann brackets remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Comments1)
{
	// test array formatting with preceeding comments
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic tAction StateTable[enStates][enEvents] = {\n"
		"    // IN APPLICATION MODE:         eEventInit       eEventFTPDone\n"
		"    /* eStateIdle              */ { NULL,            FKT(actReturnToIdle) },\n"
		"    /* eStateIdleGetVersion    */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"    // IN UPDATE MODE:\n"
		"    /* eStateUpdate            */ { FKT(actUpdate),  FKT(actReturnToIdle) },\n"
		"    /* eStateUpdateGetVersion  */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"};\n";
	char text[] =
		"\nstatic tAction StateTable[enStates][enEvents] = {\n"
		"	// IN APPLICATION MODE:         eEventInit       eEventFTPDone\n"
		"	/* eStateIdle              */ { NULL,            FKT(actReturnToIdle) },\n"
		"	/* eStateIdleGetVersion    */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"	// IN UPDATE MODE:\n"
		"	/* eStateUpdate            */ { FKT(actUpdate),  FKT(actReturnToIdle) },\n"
		"	/* eStateUpdateGetVersion  */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Comments2)
{
	// test array formatting, opening bracket after a comment
	// TODO: Fix the following array
	char textIn[] =
		"\nstatic tAction StateTable[enStates][enEvents] =\n"
		"    // IN APPLICATION MODE:         eEventInit       eEventFTPDone\n"
		"    /* eStateIdle              */{{ NULL,            FKT(actReturnToIdle) },\n"
		"    /* eStateIdleGetVersion    */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"    // IN UPDATE MODE:\n"
		"    /* eStateUpdate            */ { FKT(actUpdate),  FKT(actReturnToIdle) },\n"
		"    /* eStateUpdateGetVersion  */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"};\n";
	char text[] =
		"\nstatic tAction StateTable[enStates][enEvents] =\n"
		"    // IN APPLICATION MODE:         eEventInit       eEventFTPDone\n"
		"/* eStateIdle              */ {{ NULL,            FKT(actReturnToIdle) },\n"
		"    /* eStateIdleGetVersion    */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"    // IN UPDATE MODE:\n"
		"    /* eStateUpdate            */ { FKT(actUpdate),  FKT(actReturnToIdle) },\n"
		"    /* eStateUpdateGetVersion  */ { FKT(actCrashed), FKT(actReturnToIdle) },\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Break Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(cppText, CppBracketsBreak)
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

TEST_FIXTURE(cppText, CppBracketsBreak_Short)
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

TEST_FIXTURE(cppText, CppBracketsBreak_Namespace)
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

TEST_FIXTURE(cppText, CppBracketsBreak_Class)
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

TEST_FIXTURE(cppText, CppBracketsBreak_NamespaceClass)
{
	// test break brackets option
	// indented namespace and class
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    class FooClass\n"
		"    {\n"
		"        private:\n"
		"            bool var1;\n"
		"            void func1();\n"
		"        protected:\n"
		"            bool var2;\n"
		"            void func2();\n"
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
	char options[] = "brackets=break, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsBreak_Blocks)
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

TEST_FIXTURE(cppText, CppBracketsBreak_NamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsBreak_Brackets)
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


TEST_FIXTURE(cppText, CppBracketsBreak_NamespaceBrackets)
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

TEST(CppBracketsBreak_EmptyBrackets)
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

TEST(CppBracketsBreak_Extern)
{
	// extern statement should not change its bracket type
	// and should NOT use in-statement indents
	char textIn[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nextern \"C\" {\n"
		"	extern void foo1()\n"
		"	{\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab, brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Assembler)
{
	// assembler statement should be formatted
	char textIn[] =
		"\nvoid foo() {\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm\n"
		"    {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Break)
{
	// test break brackets option with broken brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
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
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Attach)
{
	// test break brackets option with attached brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
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
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Linux)
{
	// test break brackets option with linux brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
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
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Horstmann)
{
	// test break brackets option with horstmann brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
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
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Misc1)
{
	// test break brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo1() { error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo2() {  // comment2\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo3() {  /* comment3 */\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()    // comment2\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()    /* comment3 */\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Misc2)
{
	// test break brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {/* dummy */}\n"
		"\n"
		"    if (bar1()) {;/* dummy */}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1())\n"
		"    {\n"
		"        /* dummy */\n"
		"    }\n"
		"\n"
		"    if (bar1())\n"
		"    {\n"
		"        ;/* dummy */\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_Misc3)
{
	// test break brackets option with a macro
	// bracket type will be incorrectly classified as an array
	// but should not break at the semi colon
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    YY_RULE_SETUP\n"
		"    { BEGIN(list); return CONT; }\n"
		"    YY_BREAK\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(CppBracketsBreak_LineCommentsBreak)
{
	// comments following broken brackets should be unchanged
	char text[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_LineCommentsAttach)
{
	// comments following attached brackets should stay attached to the line
	char textIn[] =
		"\nvoid foo(bool isFoo) {  // comment1\n"
		"    if(isFoo) {           // comment2\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)    // comment1\n"
		"{\n"
		"    if(isFoo)             // comment2\n"
		"    {\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_LineCommentsHorstmann)
{
	// comments following horstmann brackets should be broken
	char textIn[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_LineCommentsClosingHeader)
{
	// test comment alignment when a closing header is broken from a closing bracket
	char textIn[] =
		"\nvoid foo() {     // comment0\n"
		"    if (isFoo) { // comment1\n"
		"        bar1();  // comment2\n"
		"    } else {     // comment3\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo)   // comment1\n"
		"    {\n"
		"        bar1();  // comment2\n"
		"    }\n"
		"    else         // comment3\n"
		"    {\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsBreak1)
{
	// broken brackets should not change
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsAttach1)
{
	// break attached brackets with following comments
	char textIn[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsHorstmann1)
{
	// break horstmann brackets with following comments
	char textIn[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}



TEST(CppBracketsBreak_CommentsBreak2)
{
	// broken brackets with following comments
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsAttach2)
{
	// break attached brackets with following comments
	// mixed tabs and spaces
	char textIn[] ="\nvoid (foo) {\n"
				   "	/*\n"
				   "	 * comment1\n"
				   "     */\n"
				   "    if (isFoo) {\n"
				   "		/*\n"
				   " 	     * comment2\n"
				   "  	     */\n"
				   "        bar();\n"
				   "    }\n"
				   "}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsHorstmann2)
{
	// break horstmann brackets with following comments
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {	/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsBreak3)
{
	// comments following broken brackets should be unchanged
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsAttach3)
{
	// test comments following brackets
	// multi-line comments following attached brackets break
	//    but are NOT aligned
	char textIn[] =
		"\nvoid foo1(bool isFoo) {   /* comment1 */\n"
		"    if(isFoo) {  /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) { /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) { /* comment4\n"
		"                 *\n"
		"                 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)     /* comment1 */\n"
		"{\n"
		"    if(isFoo)    /* comment2 */\n"
		"    {\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"         *\n"
		"         */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"                     *\n"
		"                     */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_CommentsHorstmann3)
{
	// comments following horstmann brackets should be broken
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_MultipleCommentsBreak)
{
	// multiple comments with broken brackets should remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_MultipleCommentsAttach)
{
	// multiple comments with attached brackets should remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreak_MultipleCommentsHorstmann)
{
	// multiple comments with horstmann brackets should be broken
	char textIn[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Attach Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(cppText, CppBracketsAttach)
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

TEST_FIXTURE(cppText, CppBracketsAttach_Short)
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

TEST_FIXTURE(cppText, CppBracketsAttach_Namespace)
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

TEST_FIXTURE(cppText, CppBracketsAttach_Class)
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

TEST_FIXTURE(cppText, CppBracketsAttach_NamespaceClass)
{
	// test attach brackets option
	// indented namespace and class
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"    class FooClass {\n"
		"        private:\n"
		"            bool var1;\n"
		"            void func1();\n"
		"        protected:\n"
		"            bool var2;\n"
		"            void func2();\n"
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
	char options[] = "brackets=attach, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsAttach_Blocks)
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

TEST_FIXTURE(cppText, CppBracketsAttach_NamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsAttach_Brackets)
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


TEST_FIXTURE(cppText, CppBracketsAttach_NamespaceBrackets)
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


TEST_FIXTURE(cppText, CppBracketsAttach_BreakClosing)
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

TEST(CppBracketsAttach_EmptyBrackets)
{
	// test attach brackets option
	// do not change empty brackets
	char text[] =
		"\nclass FooClass {\n"
		"public:\n"
		"    FooClass() : ed(ed) {}\n"
		"    FooClass() : ed(ed)\n"
		"    {}\n"
		"};\n"
		"\n"
		"FooClass() : ed(ed) {}\n"
		"FooClass() : ed(ed)\n"
		"{}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Extern)
{
	// extern statement should not change its bracket type
	// and should NOT use in-statement indents
	char textIn[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2() {\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab, brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Assembler)
{
	// assembler statement should be formatted
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm\n"
		"    {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Break)
{
	// test attach brackets option with broken brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
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
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Attach)
{
	// test attach brackets option with attached brackets
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Linux)
{
	// test attach brackets option with linux brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Horstmann)
{
	// test attach brackets option with horstmann brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Misc1)
{
	// test attach brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo1() { error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo2() { // comment2\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo3() { /* comment3 */\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1() {\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2() { // comment2\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3() { /* comment3 */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Misc2)
{
	// test attach brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {/* dummy */}\n"
		"\n"
		"    if (bar1()) {;/* dummy */}\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (bar1()) {\n"
		"        /* dummy */\n"
		"    }\n"
		"\n"
		"    if (bar1()) {\n"
		"        ;/* dummy */\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Misc3)
{
	// test attach brackets option with a macro
	// bracket type will be incorrectly classified as an array
	// but should not break at the semi colon
	char text[] =
		"\nvoid foo() {\n"
		"    YY_RULE_SETUP\n"
		"    { BEGIN(list); return CONT; }\n"
		"    YY_BREAK\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_LineCommentsBreak)
{
	// comments following broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if(isFoo)\n"
		"    {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo) { // comment0\n"
		"    // comment1\n"
		"    if(isFoo) {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_LineCommentsAttach)
{
	char text[] =
		"\nvoid foo(bool isFoo) {    // comment1\n"
		"    if (isFoo) {          // comment2\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_LineCommentsHorstmann)
{
	// comments following horstmann brackets should be attached
	char textIn[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo) { // comment0\n"
		"    // comment1\n"
		"    if (isFoo) {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_LineCommentsClosingHeader)
{
	// test comment alignment when a closing header is attached to a closing bracket
	char textIn[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo)   // comment1\n"
		"    {\n"
		"        bar1();  // comment2\n"
		"    }\n"
		"    else         // comment3\n"
		"    {\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {     // comment0\n"
		"    if (isFoo) { // comment1\n"
		"        bar1();  // comment2\n"
		"    } else {     // comment3\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsBreak1)
{
	// attach broken brackets with following comments
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsAttach1)
{
	// attached brackets should not change
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsHorstmann1)
{
	// attach horstmann brackets with following comments
	char textIn[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsBreak2)
{
	// attach broken brackets with following comments
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsAttach2)
{
	// attached brackets with following comments
	char textIn[] =
		"\nvoid (foo) {\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsHorstmann2)
{
	// attach horstmann brackets with following comments
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {	/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsBreak3)
{
	// comments following broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) { /* comment0 */\n"
		"    /* comment1 */\n"
		"    if(isFoo) {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) {\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsAttach3)
{
	// test comments following brackets
	// multi-line comments following attached brackets break
	//    but are NOT aligned
	char textIn[] =
		"\nvoid foo1(bool isFoo) { /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) { /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) { /* comment4\n"
		"                 *\n"
		"                 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) { /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) {\n"
		"    /* comment3\n"
		"         *\n"
		"         */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"                     *\n"
		"                     */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsHorstmann3)
{
	// comments following horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) { /* comment0 */\n"
		"    /* comment1 */\n"
		"    if(isFoo) {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) {\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_CommentsHorstmann5)
{
	// attached brackets with following comments
	// if NOT attached the run-in statement should be broken
	char textIn[] =
		"\n// -------------\n"
		"void foo()\n"
		"// ----------------\n"
		"{ /* comment1 */\n"
		"}\n";
	char text[] =
		"\n// -------------\n"
		"void foo()\n"
		"// ----------------\n"
		"{\n"
		"    /* comment1 */\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_MultipleCommentsBreak)
{
	// multiple comments with broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_MultipleCommentsAttach)
{
	// multiple comments with attached brackets should remain unchanged
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_MultipleCommentsHorstmann)
{
	// multiple comments with horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Xtra1)
{
	// don't attach brackets if previous line is empty
	char text[] =
		"\nvoid foo()\n"
		"\n"
		"{\n"
		"    if (isFoo)\n"
		"\n"
		"    {\n"
		"        bar = 1;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Xtra2)
{
	// can attach brackets if previous empty line is deleted
	char textIn[] =
		"\nvoid foo()\n"
		"\n"
		"{\n"
		"    if (isFoo)\n"
		"\n"
		"    {\n"
		"        bar = 1;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar = 1;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Xtra3)
{
	// cannot attach brackets following a semi-colon
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1();\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    bar1();\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Xtra4)
{
	// cannot attach brackets following a "{" or "}"
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttach_Xtra5)
{
	// attach to a tabbed comment
	char textIn[] =
		"\nvoid foo()			// comment\n"
		"{\n"
		"    if (isFoo)			// comment\n"
		"    {\n"
		"        bar = 0;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {		// comment\n"
		"    if (isFoo) {		// comment\n"
		"        bar = 0;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Linux Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(cppText, CppBracketsLinux)
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

TEST_FIXTURE(cppText, CppBracketsLinux_Short)
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

TEST_FIXTURE(cppText, CppBracketsLinux_Namespace)
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

TEST_FIXTURE(cppText, CppBracketsLinux_Class)
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

TEST_FIXTURE(cppText, CppBracketsLinux_NamespaceClass)
{
	// test linux brackets option
	// indented namespace and class
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    class FooClass\n"
		"    {\n"
		"        private:\n"
		"            bool var1;\n"
		"            void func1();\n"
		"        protected:\n"
		"            bool var2;\n"
		"            void func2();\n"
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
	char options[] = "brackets=linux, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsLinux_Blocks)
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

TEST_FIXTURE(cppText, CppBracketsLinux_NamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsLinux_Brackets)
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

TEST_FIXTURE(cppText, CppBracketsLinux_NamespaceBrackets)
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

TEST_FIXTURE(cppText, CppBracketsLinux_BreakClosing)
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

TEST(CppBracketsLinux_EmptyBrackets)
{
	// test linux brackets option
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
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Extern)
{
	// extern statement should not change its bracket type
	// and should NOT use in-statement indents
	char textIn[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nextern \"C\" {\n"
		"	extern void foo1()\n"
		"	{\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab, brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Assembler)
{
	// assembler statement should be formatted
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm\n"
		"    {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Break)
{
	// test linux brackets option with broken brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
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
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Attach)
{
	// test linux brackets option with attached brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Linux)
{
	// test linux brackets option with linux brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Horstmann)
{
	// test linux brackets option with horstmann brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Misc1)
{
	// test linux brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo1() { error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo2() {  // comment2\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo3() {  /* comment3 */\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()    // comment2\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()    /* comment3 */\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Misc2)
{
	// test linux brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {/* dummy */}\n"
		"\n"
		"    if (bar1()) {;/* dummy */}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {\n"
		"        /* dummy */\n"
		"    }\n"
		"\n"
		"    if (bar1()) {\n"
		"        ;/* dummy */\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Misc3)
{
	// test linux brackets option with a macro
	// bracket type will be incorrectly classified as an array
	// but should not break at the semi colon
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    YY_RULE_SETUP\n"
		"    { BEGIN(list); return CONT; }\n"
		"    YY_BREAK\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Formatting)
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
		"    void FooClass() {\n"
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

TEST(CppBracketsLinux_NestedNamespace)
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

TEST(CppBracketsLinux_LineCommentsBreak)
{
	// comments following broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo) // comment2\n"
		"    {\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo) // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo) { // comment2\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_LineCommentsAttach)
{
	// comments following attached brackets should stay attached to the line
	char textIn[] =
		"\nvoid foo(bool isFoo) {    // comment0\n"
		"    // comment1\n"
		"    if (isFoo) {          // comment2\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)      // comment0\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo) {          // comment2\n"
		"        // comment3\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_LineCommentsHorstmann)
{
	// comments following horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo(bool isFoo) /* comment0 */\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo) /* comment0 */\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo) {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_LineCommentsClosingHeader)
{
	// test comment alignment when a closing header is attached to a closing bracket
	char textIn[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo)   // comment1\n"
		"    {\n"
		"        bar1();  // comment2\n"
		"    }\n"
		"    else         // comment3\n"
		"    {\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo) { // comment1\n"
		"        bar1();  // comment2\n"
		"    } else {     // comment3\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsBreak1)
{
	// broken brackets with following comments to linux
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsAttach1)
{
	// attached brackets with following comments to linux
	char textIn[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsHorstmann1)
{
	// horstmann brackets with following comments to linux
	char textIn[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsBreak2)
{
	// broken brackets with following comments to linux
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsAttach2)
{
	// attached brackets with following comments to linux
	// mixed tabs and spaces
	char textIn[] ="\nvoid (foo) {\n"
				   "	/*\n"
				   "	 * comment1\n"
				   "     */\n"
				   "    if (isFoo) {\n"
				   "		/*\n"
				   " 	     * comment2\n"
				   "  	     */\n"
				   "        bar();\n"
				   "    }\n"
				   "}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsHorstmann2)
{
	// horstmann brackets with following comments to linux
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {	/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsBreak3)
{
	// comments following broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo) {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsAttach3)
{
	// test comments following brackets
	// multi-line comments following attached brackets break
	//    but are NOT aligned
	char textIn[] =
		"\nvoid foo1(bool isFoo) {  /* comment0 */\n"
		"    /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) {  /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) { /* comment4\n"
		"                 *\n"
		"                 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)    /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"         *\n"
		"         */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"                     *\n"
		"                     */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_CommentsHorstmann3)
{
	// comments following horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo) {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_MultipleCommentsBreak)
{
	// multiple comments with broken brackets should remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_MultipleCommentsAttach)
{
	// multiple comments with attached brackets remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_MultipleCommentsHorstmann)
{
	// multiple comments with horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Xtra1)
{
	// don't attach brackets if previous line is empty
	char text[] =
		"\nvoid foo()\n"
		"\n"
		"{\n"
		"    if (isFoo)\n"
		"\n"
		"    {\n"
		"        bar = 1;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Xtra2)
{
	// can attach brackets if previous empty line is deleted
	char textIn[] =
		"\nvoid foo()\n"
		"\n"
		"{\n"
		"    if (isFoo)\n"
		"\n"
		"    {\n"
		"        bar = 1;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar = 1;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Xtra3)
{
	// cannot attach brackets following a semi-colon
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1();\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1();\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Xtra4)
{
	// cannot attach brackets following a "{" or "}"
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinux_Xtra5)
{
	// attach to a tabbed comment
	char textIn[] =
		"\nvoid foo()			// comment\n"
		"{\n"
		"    if (isFoo)			// comment\n"
		"    {\n"
		"        bar = 0;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()			// comment\n"
		"{\n"
		"    if (isFoo) {		// comment\n"
		"        bar = 0;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Stroustrup Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(cppText, CppBracketsStroustrup)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_Short)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_Namespace)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_Class)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_NamespaceClass)
{
	// test stroustrup brackets option
	// indented namespace and class
	char text[] =
		"\nnamespace FooName {\n"
		"\n"
		"    class FooClass {\n"
		"        private:\n"
		"            bool var1;\n"
		"            void func1();\n"
		"        protected:\n"
		"            bool var2;\n"
		"            void func2();\n"
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
	char options[] = "brackets=stroustrup, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsStroustrup_Blocks)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_NamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_Brackets)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_NamespaceBrackets)
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

TEST_FIXTURE(cppText, CppBracketsStroustrup_BreakClosing)
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

TEST(CppBracketsStroustrup_EmptyBrackets)
{
	// test stroustrup brackets option
	// do not change empty brackets
	char text[] =
		"\nclass FooClass {\n"
		"public:\n"
		"    FooClass() : ed(ed) {}\n"
		"    FooClass() : ed(ed)\n"
		"    {}\n"
		"};\n"
		"\n"
		"FooClass() : ed(ed) {}\n"
		"FooClass() : ed(ed)\n"
		"{}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Extern)
{
	// extern statement should not change its bracket type
	// and should NOT use in-statement indents
	char textIn[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nextern \"C\" {\n"
		"	extern void foo1()\n"
		"	{\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab, brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Assembler)
{
	// assembler statement should be formatted
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm\n"
		"    {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Break)
{
	// test stroustrup brackets option with broken brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
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
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Attach)
{
	// test stroustrup brackets option with attached brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Linux)
{
	// test stroustrup brackets option with linux brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Horstmann)
{
	// test stroustrup brackets option with horstmann brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Misc1)
{
	// test stroustrup brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo1() { error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo2() {  // comment2\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo3() {  /* comment3 */\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()    // comment2\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()    /* comment3 */\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Misc2)
{
	// test stroustrup brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {/* dummy */}\n"
		"\n"
		"    if (bar1()) {;/* dummy */}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {\n"
		"        /* dummy */\n"
		"    }\n"
		"\n"
		"    if (bar1()) {\n"
		"        ;/* dummy */\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Misc3)
{
	// test stroustrup brackets option with a macro
	// bracket type will be incorrectly classified as an array
	// but should not break ay the semi colon
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    YY_RULE_SETUP\n"
		"    { BEGIN(list); return CONT; }\n"
		"    YY_BREAK\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_Formatting)
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
		"    void FooClass() {\n"
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

TEST(CppBracketsStroustrup_NestedNamespace)
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

TEST(CppBracketsStroustrup_LineCommentsBreak)
{
	// comments following broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo) {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_LineCommentsAttach)
{
	// comments following attached brackets should stay attached to the line
	char textIn[] =
		"\nvoid foo(bool isFoo) {    // comment1\n"
		"    if (isFoo) {          // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)      // comment1\n"
		"{\n"
		"    if (isFoo) {          // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_LineCommentsHorstmann)
{
	// comments following horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo) {\n"
		"        // comment2\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_LineCommentsClosingHeader)
{
	// test comment alignment when a closing header is attached to a closing bracket
	char textIn[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo)   // comment1\n"
		"    {\n"
		"        bar1();  // comment2\n"
		"    }\n"
		"    else         // comment3\n"
		"    {\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo) { // comment1\n"
		"        bar1();  // comment2\n"
		"    } else {     // comment3\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsBreak1)
{
	// broken brackets with following comments to linux
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsAttach1)
{
	// attached brackets with following comments to linux
	char textIn[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsHorstmann1)
{
	// stroustrup brackets with following comments to linux
	char textIn[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsBreak2)
{
	// broken brackets with following comments to stroustrup
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsAttach2)
{
	// attached brackets with following comments to stroustrup
	// mixed tabs and spaces
	char textIn[] ="\nvoid (foo) {\n"
				   "	/*\n"
				   "	 * comment1\n"
				   "     */\n"
				   "    if (isFoo) {\n"
				   "		/*\n"
				   " 	     * comment2\n"
				   "  	     */\n"
				   "        bar();\n"
				   "    }\n"
				   "}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsHorstmann2)
{
	// horstmann brackets with following comments to stroustrup
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {	/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsBreak3)
{
	// comments following broken brackets should NOT be attached
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo) {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsAttach3)
{
	// test comments following brackets
	// multi-line comments following attached brackets break
	//    but are NOT aligned
	char textIn[] =
		"\nvoid foo1(bool isFoo) {  /* comment0 */\n"
		"    /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) { /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) { /* comment4\n"
		"                 *\n"
		"                 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)    /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"         *\n"
		"         */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"                     *\n"
		"                     */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_CommentsHorstmann3)
{
	// comments following horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo) {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_MultipleCommentsBreak)
{
	// multiple comments with broken brackets should remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_MultipleCommentsAttach)
{
	// multiple comments with attached brackets remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrup_MultipleCommentsHorstmann)
{
	// multiple comments with horstmann brackets should NOT be attached
	char textIn[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Horstmann Bracket Options
//-------------------------------------------------------------------------

TEST_FIXTURE(cppText, CppBracketsHorstmann)
{
	// test horstmann brackets option
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
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_Short)
{
	// test horstmann brackets short option
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
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-g";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_Namespace)
{
	// test horstmann brackets option
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
		"    {   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"        else\n"
		"        {   anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-namespaces";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_Class)
{
	// test horstmann brackets option
	// indent class blocks
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"class FooClass\n"
		"{   private:\n"
		"        bool var1;\n"
		"        void func1();\n"
		"    protected:\n"
		"        bool var2;\n"
		"        void func2();\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_NamespaceClass)
{
	// test horstmann brackets option
	// indented namespace and class
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"\n"
		"    class FooClass\n"
		"    {   private:\n"
		"            bool var1;\n"
		"            void func1();\n"
		"        protected:\n"
		"            bool var2;\n"
		"            void func2();\n"
		"    };\n"
		"\n"
		"    void FooClass::Foo(bool isFoo)\n"
		"    {   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"        else\n"
		"        {   anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_Blocks)
{
	// test horstmann brackets option
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
		"{   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"    else\n"
		"        {   anotherBar();\n"
		"        }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_NamespaceBlocks)
{
	// test horstmann brackets option
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
		"    {   if (isFoo)\n"
		"            {   bar();\n"
		"            }\n"
		"        else\n"
		"            {   anotherBar();\n"
		"            }\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-blocks, indent-namespaces";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_Brackets)
{
	// test horstmann brackets option
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
		"    {   if (isFoo)\n"
		"        {   bar();\n"
		"        }\n"
		"    else\n"
		"        {   anotherBar();\n"
		"        }\n"
		"    }\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "brackets=horstmann, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmann_NamespaceBrackets)
{
	// test horstmann brackets option
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
		"        {   if (isFoo)\n"
		"            {   bar();\n"
		"            }\n"
		"        else\n"
		"            {   anotherBar();\n"
		"            }\n"
		"        }\n"
		"\n"
		"    }   // end FooName\n";
	char options[] = "brackets=horstmann, indent-brackets, indent-namespaces";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_EmptyBrackets)
{
	// test horstmann brackets option
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Extern)
{
	// extern statement should not change its bracket type
	// and should NOT use in-statement indents
	char textIn[] =
		"\nextern \"C\" {\n"
		"	extern void foo1() {\n"
		"		bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{\n"
		"	void foo2()\n"
		"	{\n"
		"		bar2();\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nextern \"C\"\n"
		"{	extern void foo1()\n"
		"	{	bar1();\n"
		"	}\n"
		"}\n"
		"\n"
		"extern \"C\"\n"
		"{	void foo2()\n"
		"	{	bar2();\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Assembler)
{
	// assembler statement should be formatted
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   _asm\n"
		"    {   mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Break)
{
	// test horstmann brackets option with broken brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
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
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Attach)
{
	// test horstmann brackets option with attached brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo) {\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Linux)
{
	// test horstmann brackets option with linux brackets
	char textIn[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo) {\n"
		"        bar();\n"
		"    } else {\n"
		"        anotherBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Horstmann)
{
	// test horstmann brackets option with horstmann brackets
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   bar();\n"
		"    }\n"
		"    else\n"
		"    {   anotherBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_ClassSansPrivate1)
{
	// test horstmann brackets without class indent
	// with and without 'private' class modifier
	char textIn[] =
		"\nclass fooClass1\n"
		"{\n"
		"private:\n"
		"    bool foo1;\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{\n"
		"    bool foo2;\n"
		"};\n";
	char text[] =
		"\nclass fooClass1\n"
		"{\n"
		"private:\n"
		"    bool foo1;\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{   bool foo2;\n"
		"};\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_ClassSansPrivate2)
{
	// test horstmann brackets with class indent
	// with and without 'private' class modifier
	char textIn[] =
		"\nclass fooClass1\n"
		"{\n"
		"private:\n"
		"    bool foo1;\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{\n"
		"    bool foo2;\n"
		"};\n";
	char text[] =
		"\nclass fooClass1\n"
		"{   private:\n"
		"        bool foo1;\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{       bool foo2;\n"
		"};\n";
	char options[] = "brackets=horstmann, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Misc1)
{
	// test horstmann brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo1() { error = false;\n"
		"              errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo2() {  // comment2\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n"
		"\n"
		"void foo3() {  /* comment3 */\n"
		"               error = false;\n"
		"               errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{   error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()    // comment2\n"
		"{   error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()    /* comment3 */\n"
		"{   error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Misc2)
{
	// test horstmann brackets option with the following unusual format
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (bar1()) {/* dummy */}\n"
		"\n"
		"    if (bar1()) {;/* dummy */}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if (bar1())\n"
		"    {   /* dummy */\n"
		"    }\n"
		"\n"
		"    if (bar1())\n"
		"    {   ;/* dummy */\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_Misc3)
{
	// test horstmann brackets option with a macro
	// bracket type will be incorrectly classified as an array
	// but should not break ay the semi colon
	char text[] =
		"\nvoid foo()\n"
		"{   YY_RULE_SETUP\n"
		"    { BEGIN(list); return CONT; }\n"
		"    YY_BREAK\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_HorstmannIndent1)
{
	// test horstmann brackets option with horstmann brackets
	// with the indent changed from 2 to 4
	char textIn[] =
		"\nvoid Foo()\n"
		"{ if (isFoo)\n"
		"  { foo();\n"
		"  }\n"
		"  else\n"
		"  { // comment\n"
		"    bar();\n"
		"  }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   foo();\n"
		"    }\n"
		"    else\n"
		"    {   // comment\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_HorstmannIndent2)
{
	// test horstmann brackets option with horstmann brackets
	// with the indent changed from 6 to 4
	char textIn[] =
		"\nvoid Foo()\n"
		"{     if (isFoo)\n"
		"      {     foo();\n"
		"      }\n"
		"      else\n"
		"      {     // comment\n"
		"            bar();\n"
		"      }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo)\n"
		"    {   foo();\n"
		"    }\n"
		"    else\n"
		"    {   // comment\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_LineCommentsBreak)
{
	// comments following broken brackets should be attached
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    // comment1\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment2\n"
		"        while (isBar)\n"
		"        {\n"
		"            // comment3\n"
		"            fooBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        while (isBar)\n"
		"        {   // comment3\n"
		"            fooBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_LineCommentsAttach)
{
	// comments following attached brackets should stay attached to the line
	char textIn[] =
		"\nvoid foo(bool isFoo) {    // comment1\n"
		"    if (isFoo) {          // comment2\n"
		"        while (isBar) {   // comment3\n"
		"            fooBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)      // comment1\n"
		"{   if (isFoo)            // comment2\n"
		"    {   while (isBar)     // comment3\n"
		"        {   fooBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_LineCommentsHorstmann)
{
	// comments following horstmann brackets should be unchanged
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{   // comment1\n"
		"    if (isFoo)\n"
		"    {   // comment2\n"
		"        while (isBar)\n"
		"        {   // comment3\n"
		"            fooBar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_LineCommentsClosingHeader)
{
	// test comment alignment when a closing header is attached to a closing bracket
	char textIn[] =
		"\nvoid foo()       // comment0\n"
		"{\n"
		"    if (isFoo) { // comment1\n"
		"        bar1();  // comment2\n"
		"    } else {     // comment3\n"
		"        bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()       // comment0\n"
		"{   if (isFoo)   // comment1\n"
		"    {   bar1();  // comment2\n"
		"    }\n"
		"    else         // comment3\n"
		"    {   bar2();  // comment4\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsBreak1)
{
	// broken brackets with following comments to horstmann
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsAttach1)
{
	// attached brackets with following comments to horstmann
	char textIn[] =
		"\nvoid (foo) {\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo) {\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsHorstmann1)
{
	// horstmann brackets should not change
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsBreak2)
{
	// broken brackets with following comments to horstmann
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{\n"
		"	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {\n"
		"		/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsAttach2)
{
	// attached brackets with following comments to horstmann
	// mixed tabs and spaces
	char textIn[] ="\nvoid (foo) {\n"
				   "	/*\n"
				   "	 * comment1\n"
				   "     */\n"
				   "    if (isFoo) {\n"
				   "		/*\n"
				   " 	     * comment2\n"
				   "  	     */\n"
				   "        bar();\n"
				   "    }\n"
				   "}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsHorstmann2)
{
	// horstmann brackets with following comments to horstmann
	// mixed tabs and spaces
	char textIn[] =
		"\nvoid (foo)\n"
		"{	/*\n"
		"	 * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {	/*\n"
		" 	     * comment2\n"
		"  	     */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid (foo)\n"
		"{   /*\n"
		"     * comment1\n"
		"     */\n"
		"    if (isFoo)\n"
		"    {   /*\n"
		"         * comment2\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsBreak3)
{
	// comments following broken brackets should attach to the bracket
	char textIn[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{\n"
		"    /* comment1 */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsAttach3)
{
	// test comments following brackets
	// multi-line comments following attached brackets break
	//    but are NOT aligned
	char textIn[] =
		"\nvoid foo1(bool isFoo) {  /* comment0 */\n"
		"    if(isFoo) {  /* comment1 */\n"
		"    /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) { /* comment3\n"
		"    *\n"
		"    */\n"
		"    if(isFoo) {\n"
		"        /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)    /* comment0 */\n"
		"{   if(isFoo)    /* comment1 */\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"        *\n"
		"        */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_CommentsHorstmann3)
{
	// comments following horstmann brackets should be unchanged
	char text[] =
		"\nvoid foo1(bool isFoo) /* comment0 */\n"
		"{   /* comment1 */\n"
		"    if(isFoo)\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"     *\n"
		"     */\n"
		"    if(isFoo)\n"
		"    {   /* comment4\n"
		"         *\n"
		"         */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(CppBracketsHorstmann_MultipleCommentsBreak)
{
	// multiple comments with broken brackets should be run-in
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo) /* comment1 */  // comment2\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_MultipleCommentsAttach)
{
	// multiple comments with attached brackets should not be broken
	char textIn[] =
		"\nvoid foo() {\n"
		"    if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo) { /* comment1 */  // comment2\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmann_MultipleCommentsHorstmann)
{
	// multiple comments with horstmann brackets should remain unchanged
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo) /* comment1 */  // comment2\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Other Bracket Options
//-------------------------------------------------------------------------

TEST(CppBracketsOther_ClassContinuationAttached)
{
	// test with class continuaton and attached brackets
	char text[] =
		"\nclass Foo :\n"
		"    public Bar {\n"
		"public:\n"
		"    Foo(T *in);\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsOther_ClassContinuationBoken)
{
	// test with class continuaton and broken brackets
	char text[] =
		"\nclass Foo :\n"
		"    public Bar\n"
		"{\n"
		"public:\n"
		"    Foo(T *in);\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsOther_ConstIndent)
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

TEST(CppBracketsOther_ConstIndentBlocks)
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

TEST(CppBracketsOther_ConstIndentBrackets)
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

TEST(CppBracketsOther_NestedClass)
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

TEST(CppBracketsOther_NestedClassBlocks)
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

TEST(CppBracketsOther_NestedClassBrackets)
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

TEST(CppBracketsOther_NestedClassIndent)
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

TEST(CppBracketsOther_NestedClassIndentBlocks)
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

TEST(CppBracketsOther_NestedClassIndentBrackets)
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

TEST(CppBracketsOther_NestedNamespace)
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

TEST(CppBracketsOther_NestedNamespaceBlocks)
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

TEST(CppBracketsOther_NestedNamespaceBrackets)
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

TEST(CppBracketsOther_NestedNamespaceIndent)
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

TEST(CppBracketsOther_NestedNamespaceIndentBlocks)
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

TEST(CppBracketsOther_NestedNamespaceIndentBrackets)
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

TEST(CppBracketsOther_NestedNamespaceClass)
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

TEST(CppBracketsOther_NestedNamespaceClassBlocks)
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

TEST(CppBracketsOther_NestedNamespaceClassBrackets)
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

TEST(CppBracketsOther_NestedNamespaceIndentClass)
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

TEST(CppBracketsOther_NestedNamespaceIndentClassBlocks)
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

TEST(CppBracketsOther_NestedNamespaceIndentClassBrackets)
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

TEST(CppBracketsOther_NestedNamespaceIndentClassIndent)
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

TEST(CppBracketsOther_NestedNamespaceIndentClassIndentBlocks)
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

TEST(CppBracketsOther_NestedNamespaceIndentClassIndentBrackets)
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
// NOTE: Array brackets are NOT converted TO or FROM Horstmann style
//-------------------------------------------------------------------------

TEST(CppBracketsArrayNone_Break)
{
	// test array formatting with broken bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Attach)
{
	// test array formatting with attached brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Horstmann1)
{
	// test array formatting with horstmann brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int foo[] =\n"
		"{   FOO1,\n"
		"    FOO2,\n"
		"    FOO3,\n"
		"};\n";
	char text[] =
		"\nconst int foo[] =\n"
		"{	FOO1,\n"
		"	FOO2,\n"
		"	FOO3,\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Horstmann2)
{
	// test array formatting with horstmann brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Horstmann3)
{
	// test array formatting with multiple brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic wxString codes[2][4] =\n"
		"{   {   _T(\"0001101\"),_T(\"0100011\"),\n"
		"        _T(\"0110001\"),_T(\"0001011\")\n"
		"    },\n"
		"    {   _T(\"1110010\"),_T(\"1011100\"),\n"
		"        _T(\"1001110\"),_T(\"1110100\")\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nstatic wxString codes[2][4] =\n"
		"{	{	_T(\"0001101\"),_T(\"0100011\"),\n"
		"		_T(\"0110001\"),_T(\"0001011\")\n"
		"	},\n"
		"	{	_T(\"1110010\"),_T(\"1011100\"),\n"
		"		_T(\"1001110\"),_T(\"1110100\")\n"
		"	}\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Horstmann4)
{
	// test array formatting with multiple one-line-statement brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{   {{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"    {{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char text[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{	{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"	{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Horstmann5)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int Chunks[][8] =\n"
		"{   { 1,1,1,1,\n"
		"      0,0,0,0 }\n"
		"};\n";
	char text[] =
		"\nconst int Chunks[][8] =\n"
		"{	{	1,1,1,1,\n"
		"		0,0,0,0\n"
		"	}\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_Horstmann6)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{   // C++\n"
		"    {   _T(\"C++\"),\n"
		"        _T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"        wxSCI_LEX_CPP,\n"
		"        {   {TOKEN_DEFAULT, NULL},\n"
		"            {TOKEN_COMMENT, NULL},\n"
		"        }\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{	// C++\n"
		"	{	_T(\"C++\"),\n"
		"		_T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"		wxSCI_LEX_CPP,\n"
		"		{	{TOKEN_DEFAULT, NULL},\n"
		"			{TOKEN_COMMENT, NULL},\n"
		"		}\n"
		"	}\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_HorstmannLineComments)
{
	// test array formatting with following comments
	// should not change horstmann line comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	// comment\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_HorstmannComments)
{
	// test array formatting with following comment
	// should not change horstmann comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   /* comment */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	/* comment */\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_InStatement1)
{
	// in-statement arrays should remain unchanged
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* a[] = { \"one\", \"two\",\n"
		"                  \"uno\", \"dos\"\n"
		"                };\n"
		"};\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	char* a[] = { \"one\", \"two\",\n"
		"	              \"uno\", \"dos\"\n"
		"	            };\n"
		"};\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNone_InStatement2)
{
	// test array formatting with horstmann brackets
	// and a non in-statement bracket on the same line
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{   wxChar* names[] = {\n"
		"        _T(\"cvt \"),\n"
		"        NULL\n"
		"    };\n"
		"\n"
		"    bar1();\n"
		"    bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{	wxChar* names[] = {\n"
		"		_T(\"cvt \"),\n"
		"		NULL\n"
		"	};\n"
		"\n"
		"	bar1();\n"
		"	bar2();\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Break)
{
	// test array formatting with broken brackets
	// should not change a broken bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Attach)
{
	// test array formatting with attached brackets
	// should break an attached bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Horstmann1)
{
	// test array formatting with horstmann brackets
	// should break horstmann run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int foo[] =\n"
		"{   FOO1,\n"
		"    FOO2,\n"
		"    FOO3,\n"
		"};\n";
	char text[] =
		"\nconst int foo[] =\n"
		"{\n"
		"	FOO1,\n"
		"	FOO2,\n"
		"	FOO3,\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Horstmann2)
{
	// test array formatting with horstmann brackets
	// should break horstmann run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Horstmann3)
{
	// test array formatting with multiple brackets
	// should break horstmann run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic wxString codes[2][4] =\n"
		"{   {   _T(\"0001101\"),_T(\"0100011\"),\n"
		"        _T(\"0110001\"),_T(\"0001011\")\n"
		"    },\n"
		"    {   _T(\"1110010\"),_T(\"1011100\"),\n"
		"        _T(\"1001110\"),_T(\"1110100\")\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nstatic wxString codes[2][4] =\n"
		"{\n"
		"	{\n"
		"		_T(\"0001101\"),_T(\"0100011\"),\n"
		"		_T(\"0110001\"),_T(\"0001011\")\n"
		"	},\n"
		"	{\n"
		"		_T(\"1110010\"),_T(\"1011100\"),\n"
		"		_T(\"1001110\"),_T(\"1110100\")\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Horstmann4)
{
	// test array formatting with multiple one-line-statement brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{   {{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"    {{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char text[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{\n"
		"	{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"	{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Horstmann5)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int Chunks[][8] =\n"
		"{   { 1,1,1,1,\n"
		"      0,0,0,0 }\n"
		"};\n";
	char text[] =
		"\nconst int Chunks[][8] =\n"
		"{\n"
		"	{\n"
		"		1,1,1,1,\n"
		"		0,0,0,0\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Horstmann6)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{   // C++\n"
		"    {   _T(\"C++\"),\n"
		"        _T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"        wxSCI_LEX_CPP,\n"
		"        {   {TOKEN_DEFAULT, NULL},\n"
		"            {TOKEN_COMMENT, NULL},\n"
		"        }\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{\n"
		"	// C++\n"
		"	{\n"
		"		_T(\"C++\"),\n"
		"		_T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"		wxSCI_LEX_CPP,\n"
		"		{	{TOKEN_DEFAULT, NULL},\n"
		"			{TOKEN_COMMENT, NULL},\n"
		"		}\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_HorstmannLineComments)
{
	// test array formatting with following line comment
	// should break horstmann line comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"	// comment\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_HorstmannComments)
{
	// test array formatting with following comment
	// should break horstmann comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   /* comment */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"	/* comment */\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_InStatement1)
{
	// in-statement arrays should remain unchanged
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* a[] = { \"one\", \"two\",\n"
		"                  \"uno\", \"dos\"\n"
		"                };\n"
		"};\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	char* a[] = { \"one\", \"two\",\n"
		"	              \"uno\", \"dos\"\n"
		"	            };\n"
		"};\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_InStatement2)
{
	// test array formatting with horstmann brackets
	// and a non in-statement bracket on the same line
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{   wxChar* names[] = {\n"
		"        _T(\"cvt \"),\n"
		"        NULL\n"
		"    };\n"
		"\n"
		"    bar1();\n"
		"    bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	wxChar* names[] =\n"
		"	{\n"
		"		_T(\"cvt \"),\n"
		"		NULL\n"
		"	};\n"
		"\n"
		"	bar1();\n"
		"	bar2();\n"
		"}\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_LineComments)
{
	// test array formatting with line-end comments
	// should break an attached bracket
	char textIn[] =
		"\nconst char *foo[] = { // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =   // comment\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak_Comments)
{
	// test array formatting with comments
	// should break an attached bracket
	// UNLESS it is multi-line
	// TODO: Fix indentation of multi-line comment
	char textIn[] =
		"\nconst char *foo[] = { /* comment */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n"
		"\n"
		"\nconst char *foo[] = { /* comment\n"
		"    */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =   /* comment */\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n"
		"\n"
		"\nconst char *foo[] = { /* comment\n"
		"    */\n"
		"                        \"foo1\",\n"	// fix indentation
		"                        \"foo2\",\n"
		"                        \"foo3\",\n"
		"                    };\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Break)
{
	// test array formatting with broken brackets
	// should attach a broken bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Attach)
{
	// test array formatting with attached brackets
	// should not change an attached bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Horstmann1)
{
	// test array formatting with horstamnn brackets
	// should attach a horstmann bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int foo[] =\n"
		"{   FOO1,\n"
		"    FOO2,\n"
		"    FOO3,\n"
		"};\n";
	char text[] =
		"\nconst int foo[] = {\n"
		"	FOO1,\n"
		"	FOO2,\n"
		"	FOO3,\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Horstmann2)
{
	// test array formatting with horstamnn brackets
	// should attach a horstmann bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Horstmann3)
{
	// test array formatting with multiple brackets
	// should break horstmann run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic wxString codes[2][4] =\n"
		"{   {   _T(\"0001101\"),_T(\"0100011\"),\n"
		"        _T(\"0110001\"),_T(\"0001011\")\n"
		"    },\n"
		"    {   _T(\"1110010\"),_T(\"1011100\"),\n"
		"        _T(\"1001110\"),_T(\"1110100\")\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nstatic wxString codes[2][4] = {\n"
		"	{\n"
		"		_T(\"0001101\"),_T(\"0100011\"),\n"
		"		_T(\"0110001\"),_T(\"0001011\")\n"
		"	},\n"
		"	{\n"
		"		_T(\"1110010\"),_T(\"1011100\"),\n"
		"		_T(\"1001110\"),_T(\"1110100\")\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Horstmann4)
{
	// test array formatting with multiple one-line-statement brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{   {{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"    {{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char text[] =
		"\nconst ct_data static_ltree[L_CODES+2] = {\n"
		"	{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"	{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Horstmann5)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int Chunks[][8] =\n"
		"{   { 1,1,1,1,\n"
		"      0,0,0,0 }\n"
		"};\n";
	char text[] =
		"\nconst int Chunks[][8] = {\n"
		"	{\n"
		"		1,1,1,1,\n"
		"		0,0,0,0\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Horstmann6)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{   // C++\n"
		"    {   _T(\"C++\"),\n"
		"        _T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"        wxSCI_LEX_CPP,\n"
		"        {   {TOKEN_DEFAULT, NULL},\n"
		"            {TOKEN_COMMENT, NULL},\n"
		"        }\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nconst LanguageInfo g_LanguagePrefs [] = {\n"
		"	// C++\n"
		"	{\n"
		"		_T(\"C++\"),\n"
		"		_T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"		wxSCI_LEX_CPP,\n"
		"		{	{TOKEN_DEFAULT, NULL},\n"
		"			{TOKEN_COMMENT, NULL},\n"
		"		}\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_HorstmannLineComments)
{
	// test array formatting wih following line comments
	// should attach horstmann line comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"	// comment\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_HorstmannComments)
{
	// test array formatting wih following comments
	// should attach horstmann comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   /* comment */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"	/* comment */\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_InStatement1)
{
	// in-statement arrays should remain unchanged
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo() {\n"
		"    char* a[] = { \"one\", \"two\",\n"
		"                  \"uno\", \"dos\"\n"
		"                };\n"
		"};\n";
	char text[] =
		"\nvoid foo() {\n"
		"	char* a[] = { \"one\", \"two\",\n"
		"	              \"uno\", \"dos\"\n"
		"	            };\n"
		"};\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_InStatement2)
{
	// test array formatting with horstmann brackets
	// and a non in-statement bracket on the same line
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{   wxChar* names[] = {\n"
		"        _T(\"cvt \"),\n"
		"        NULL\n"
		"    };\n"
		"\n"
		"    bar1();\n"
		"    bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"	wxChar* names[] = {\n"
		"		_T(\"cvt \"),\n"
		"		NULL\n"
		"	};\n"
		"\n"
		"	bar1();\n"
		"	bar2();\n"
		"}\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_LineComments)
{
	// test array formatting with line-end comments
	// should attach a broken bracket
	char textIn[] =
		"\nconst char *foo[] = // comment\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = { // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Comments)
{
	// test array formatting with comments
	// should attach a broken bracket
	// UNLESS it is multi-line
	// TODO: Attach bracket to line-end comment
	char textIn[] =
		"\nconst char *foo[] = /* comment */\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n"
		"\n"
		"\nconst char *foo[] = /* comment\n"
		"    */\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = /* comment */\n"
		"{\n"				//bracket should attach
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n"
		"\n"
		"\nconst char *foo[] = /* comment\n"
		"    */\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttach_Sans)
{
	// test array formatting
	// should not attach if preceeded by an empty line
	char text[] =
		"\nconst char *foo[] =\n"
		"\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Break1)
{
	// test array formatting with broken brackets
	// should run-in a broken bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int foo[] =\n"
		"{\n"
		"    FOO1,\n"
		"    FOO2,\n"
		"    FOO3,\n"
		"};\n";
	char text[] =
		"\nconst int foo[] =\n"
		"{	FOO1,\n"
		"	FOO2,\n"
		"	FOO3,\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Break2)
{
	// test array formatting with quotes
	// should run-in a broken bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Break3)
{
	// test array formatting with multiple brackets
	// should run-in all brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic wxString codes[2][4] =\n"
		"{\n"
		"    {\n"
		"        _T(\"0001101\"),_T(\"0100011\"),\n"
		"        _T(\"0110001\"),_T(\"0001011\")\n"
		"    },\n"
		"    {\n"
		"        _T(\"1110010\"),_T(\"1011100\"),\n"
		"        _T(\"1001110\"),_T(\"1110100\")\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nstatic wxString codes[2][4] =\n"
		"{	{	_T(\"0001101\"),_T(\"0100011\"),\n"
		"		_T(\"0110001\"),_T(\"0001011\")\n"
		"	},\n"
		"	{	_T(\"1110010\"),_T(\"1011100\"),\n"
		"		_T(\"1001110\"),_T(\"1110100\")\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Break4)
{
	// test array formatting with multiple one-line-statement brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{\n"
		"    {{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"    {{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char text[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{	{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"	{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Break5)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int Chunks[][8] =\n"
		"{\n"
		"    {\n"
		"      1,1,1,1,\n"
		"      0,0,0,0 }\n"
		"};\n";
	char text[] =
		"\nconst int Chunks[][8] =\n"
		"{	{	1,1,1,1,\n"
		"		0,0,0,0\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Break6)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{\n"
		"    // C++\n"
		"    {\n"
		"        _T(\"C++\"),\n"
		"        _T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"        wxSCI_LEX_CPP,\n"
		"        {\n"
		"            {TOKEN_DEFAULT, NULL},\n"
		"            {TOKEN_COMMENT, NULL},\n"
		"        }\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{	// C++\n"
		"	{	_T(\"C++\"),\n"
		"		_T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"		wxSCI_LEX_CPP,\n"
		"		{	{TOKEN_DEFAULT, NULL},\n"
		"			{TOKEN_COMMENT, NULL},\n"
		"		}\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Attach1)
{
	// test array formatting with attached brackets
	// should run-in an attached bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int foo[] = {\n"
		"    FOO1,\n"
		"    FOO2,\n"
		"    FOO3,\n"
		"};\n";
	char text[] =
		"\nconst int foo[] =\n"
		"{	FOO1,\n"
		"	FOO2,\n"
		"	FOO3,\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Attach2)
{
	// test array formatting with quotes
	// should run-in an attached bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Attach3)
{
	// test array formatting with multiple brackets
	// should run-in all brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic wxString codes[2][4] = {\n"
		"    {\n"
		"        _T(\"0001101\"),_T(\"0100011\"),\n"
		"        _T(\"0110001\"),_T(\"0001011\")\n"
		"    },\n"
		"    {\n"
		"        _T(\"1110010\"),_T(\"1011100\"),\n"
		"        _T(\"1001110\"),_T(\"1110100\")\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nstatic wxString codes[2][4] =\n"
		"{	{	_T(\"0001101\"),_T(\"0100011\"),\n"
		"		_T(\"0110001\"),_T(\"0001011\")\n"
		"	},\n"
		"	{	_T(\"1110010\"),_T(\"1011100\"),\n"
		"		_T(\"1001110\"),_T(\"1110100\")\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Attach4)
{
	// test array formatting with multiple one-line-statement brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst ct_data static_ltree[L_CODES+2] = {\n"
		"    {{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"    {{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char text[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{	{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"	{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Attach5)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int Chunks[][8] = {\n"
		"    {\n"
		"      1,1,1,1,\n"
		"      0,0,0,0 }\n"
		"};\n";
	char text[] =
		"\nconst int Chunks[][8] =\n"
		"{	{	1,1,1,1,\n"
		"		0,0,0,0\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Attach6)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst LanguageInfo g_LanguagePrefs [] = {\n"
		"    // C++\n"
		"    {\n"
		"        _T(\"C++\"),\n"
		"        _T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"        wxSCI_LEX_CPP,\n"
		"        {\n"
		"            {TOKEN_DEFAULT, NULL},\n"
		"            {TOKEN_COMMENT, NULL},\n"
		"        }\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{	// C++\n"
		"	{	_T(\"C++\"),\n"
		"		_T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"		wxSCI_LEX_CPP,\n"
		"		{	{TOKEN_DEFAULT, NULL},\n"
		"			{TOKEN_COMMENT, NULL},\n"
		"		}\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_AttachLineComments)
{
	// test array formatting with attach to horstmann with following comments
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] = { // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =   // comment\n"
		"{	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_AttachComments)
{
	// test array formatting with attach to horstmann with following comments
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] = { /* comment */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =   /* comment */\n"
		"{	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Horstmann1)
{
	// test array formatting
	// should NOT change a horstmann bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int foo[] =\n"
		"{   FOO1,\n"
		"    FOO2,\n"
		"    FOO3,\n"
		"};\n";
	char text[] =
		"\nconst int foo[] =\n"
		"{	FOO1,\n"
		"	FOO2,\n"
		"	FOO3,\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Horstmann2)
{
	// test array formatting with quotes
	// should NOT change a horstmann bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(CppBracketsArrayHorstmann_Horstmann3)
{
	// test array formatting with multiple brackets
	// should NOT change a horstmann bracket
	// use indent=tab to check indent character
	char textIn[] =
		"\nstatic wxString codes[2][4] =\n"
		"{   {   _T(\"0001101\"),_T(\"0100011\"),\n"
		"        _T(\"0110001\"),_T(\"0001011\")\n"
		"    },\n"
		"    {   _T(\"1110010\"),_T(\"1011100\"),\n"
		"        _T(\"1001110\"),_T(\"1110100\")\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nstatic wxString codes[2][4] =\n"
		"{	{	_T(\"0001101\"),_T(\"0100011\"),\n"
		"		_T(\"0110001\"),_T(\"0001011\")\n"
		"	},\n"
		"	{	_T(\"1110010\"),_T(\"1011100\"),\n"
		"		_T(\"1001110\"),_T(\"1110100\")\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Horstmann4)
{
	// test array formatting with multiple one-line-statement brackets
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{   {{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"    {{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char text[] =
		"\nconst ct_data static_ltree[L_CODES+2] =\n"
		"{	{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},\n"
		"	{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Horstmann5)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst int Chunks[][8] =\n"
		"{   { 1,1,1,1,\n"
		"      0,0,0,0 }\n"
		"};\n";
	char text[] =
		"\nconst int Chunks[][8] =\n"
		"{	{	1,1,1,1,\n"
		"		0,0,0,0\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_Horstmann6)
{
	// test array formatting
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{   // C++\n"
		"    {   _T(\"C++\"),\n"
		"        _T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"        wxSCI_LEX_CPP,\n"
		"        {   {TOKEN_DEFAULT, NULL},\n"
		"            {TOKEN_COMMENT, NULL},\n"
		"        }\n"
		"    }\n"
		"};\n";
	char text[] =
		"\nconst LanguageInfo g_LanguagePrefs [] =\n"
		"{	// C++\n"
		"	{	_T(\"C++\"),\n"
		"		_T(\"*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma\"),\n"
		"		wxSCI_LEX_CPP,\n"
		"		{	{TOKEN_DEFAULT, NULL},\n"
		"			{TOKEN_COMMENT, NULL},\n"
		"		}\n"
		"	}\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_HorstmannLineComments1)
{
	// test array formatting
	// should not change horstmann line comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   // comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	// comment\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_HorstmannLineComments2)
{
	// test array formatting
	// should NOT run-in a non-indent line comment
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"// comment\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"// comment\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_HorstmannComments)
{
	// test array formatting
	// should not change horstmann comment run-ins
	// use indent=tab to check indent character
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{   /* comment */\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
		"{	/* comment */\n"
		"	\"foo1\",\n"
		"	\"foo2\",\n"
		"	\"foo3\",\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_InStatement1)
{
	// in-statement arrays should remain unchanged
	// use indent=tab to check indent character
	char text[] =
		"\nvoid foo()\n"
		"{	char* a[] = { \"one\", \"two\",\n"
		"	              \"uno\", \"dos\"\n"
		"	            };\n"
		"};\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_InStatement2)
{
	// test array formatting with horstmann brackets
	// and a non in-statement bracket on the same line
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxChar* names[] = {\n"
		"        _T(\"cvt \"),\n"
		"        NULL\n"
		"    };\n"
		"\n"
		"    bar1();\n"
		"    bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{	wxChar* names[] =\n"
		"	{	_T(\"cvt \"),\n"
		"		NULL\n"
		"	};\n"
		"\n"
		"	bar1();\n"
		"	bar2();\n"
		"}\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayHorstmann_InStatement3)
{
	// test array formatting with horstmann brackets
	// and a non in-statement bracket on the same line
	// use indent=tab to check indent character
	char textIn[] =
		"\nvoid foo()\n"
		"{   wxChar* names[] = {\n"
		"        _T(\"cvt \"),\n"
		"        NULL\n"
		"    };\n"
		"\n"
		"    bar1();\n"
		"    bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{	wxChar* names[] =\n"
		"	{	_T(\"cvt \"),\n"
		"		NULL\n"
		"	};\n"
		"\n"
		"	bar1();\n"
		"	bar2();\n"
		"}\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

