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
// AStyle C++ Bracket Options
//-----------------------------------------------------------------------------

//-------------------------------------------------------------------------
// AStyle C++ Default Bracket Options
//-------------------------------------------------------------------------

struct BracketsNoneCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsNoneCppF()
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

TEST_F(BracketsNoneCppF, Default)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneCppF, Namespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneCppF, Class)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneCppF, NamespaceClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneCppF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneCppF, NamespaceBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsNoneCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(BracketsNoneCppF, NamespaceBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(BracketsNoneCpp, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Extern)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Assembler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Horstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Horstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Misc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, HorstmannIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, HorstmannIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, HorstmannIndentComment1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, HorstmannIndentComment2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, LineCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, LineCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, LineCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsBreak1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsAttach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsHorstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsBreak2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsAttach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsHorstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsBreak3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsAttach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, CommentsHorstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, MultipleCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, MultipleCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsNoneCpp, MultipleCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Break Bracket Options
//-------------------------------------------------------------------------

struct BracketsBreakCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsBreakCppF()
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

TEST_F(BracketsBreakCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, Namespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, Class)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, NamespaceClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, NamespaceBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsBreakCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(BracketsBreakCppF, NamespaceBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Extern)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Assembler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Misc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsBreakCpp, LineCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, LineCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, LineCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, LineCommentsClosingHeader)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsBreak1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsAttach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsHorstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}



TEST(BracketsBreakCpp, CommentsBreak2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsAttach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsHorstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsBreak3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsAttach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, CommentsHorstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, MultipleCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, MultipleCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsBreakCpp, MultipleCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Attach Bracket Options
//-------------------------------------------------------------------------

struct BracketsAttachCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsAttachCppF()
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

TEST_F(BracketsAttachCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, Namespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, Class)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, NamespaceClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, NamespaceBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsAttachCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(BracketsAttachCppF, NamespaceBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST_F(BracketsAttachCppF, BreakClosing)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Extern)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Assembler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Misc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, LineCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, LineCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, LineCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, LineCommentsClosingHeader)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsBreak1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsAttach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsHorstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsBreak2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsAttach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsHorstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsBreak3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsAttach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsHorstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, CommentsHorstmann5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, MultipleCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, MultipleCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, MultipleCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Xtra1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Xtra2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Xtra3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Xtra4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsAttachCpp, Xtra5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Linux Bracket Options
//-------------------------------------------------------------------------

struct BracketsLinuxCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsLinuxCppF()
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

TEST_F(BracketsLinuxCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, Namespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, Class)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, NamespaceClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, NamespaceBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, NamespaceBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsLinuxCppF, BreakClosing)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Extern)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Assembler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Misc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Formatting)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, NestedNamespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, LineCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, LineCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, LineCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, LineCommentsClosingHeader)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsBreak1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsAttach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsHorstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsBreak2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsAttach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsHorstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsBreak3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsAttach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, CommentsHorstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, MultipleCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, MultipleCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, MultipleCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Xtra1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Xtra2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Xtra3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Xtra4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsLinuxCpp, Xtra5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Stroustrup Bracket Options
//-------------------------------------------------------------------------

struct BracketsStroustrupCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsStroustrupCppF()
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

TEST_F(BracketsStroustrupCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, Namespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, Class)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, NamespaceClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, NamespaceBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, NamespaceBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsStroustrupCppF, BreakClosing)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Extern)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Assembler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Misc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, Formatting)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, NestedNamespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, LineCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, LineCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, LineCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, LineCommentsClosingHeader)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsBreak1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsAttach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsHorstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsBreak2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsAttach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsHorstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsBreak3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsAttach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, CommentsHorstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, MultipleCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, MultipleCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsStroustrupCpp, MultipleCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Horstmann Bracket Options
//-------------------------------------------------------------------------

struct BracketsHorstmannCppF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	BracketsHorstmannCppF()
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

TEST_F(BracketsHorstmannCppF, LongOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, ShortOption)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, Namespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, Class)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, NamespaceClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, Blocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, NamespaceBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(BracketsHorstmannCppF, NamespaceBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, EmptyBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Extern)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Assembler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Linux)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, ClassSansPrivate1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, ClassSansPrivate2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Misc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, HorstmannIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, HorstmannIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, LineCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, LineCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, LineCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, LineCommentsClosingHeader)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsBreak1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsAttach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsHorstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsBreak2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsAttach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsHorstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsBreak3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsAttach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, CommentsHorstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(BracketsHorstmannCpp, MultipleCommentsBreak)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, MultipleCommentsAttach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsHorstmannCpp, MultipleCommentsHorstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Other Bracket Options
//-------------------------------------------------------------------------

TEST(BracketsOtherCpp, ClassContinuation_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, ClassContinuation_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, ConstIndentBlocks1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, ConstIndentBlocks2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, ConstIndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedClass_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedClass_IndentBracketsBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedClass_IndentClasses)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedClass_IndentClasses_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedClass_IndentClasses_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespace)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespace_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespace_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespace_IndentNamespaces)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespace_IndentNamespacesBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespace_IndentNamespacesBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentNamespaces)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentNamespacesBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentNamespacesBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentNamespacesClasses)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentNamespacesClassesBlocks)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsOtherCpp, NestedNamespaceInClass_IndentNamespacesClassesBrackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle C++ Array Bracket Options
// NOTE: Array brackets are NOT converted TO or FROM Horstmann style
//-------------------------------------------------------------------------

TEST(BracketsArrayNoneCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Horstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Horstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Horstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Horstmann4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Horstmann5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Horstmann6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, HorstmannLineComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, HorstmannComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, InStatement1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, InStatement2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Comments1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayNoneCpp, Comments2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Horstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Horstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Horstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Horstmann4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Horstmann5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Horstmann6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, HorstmannLineComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, HorstmannComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, InStatement1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, InStatement2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, LineComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayBreakCpp, Comments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Horstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Horstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Horstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Horstmann4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Horstmann5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Horstmann6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, HorstmannLineComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, HorstmannComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, InStatement1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, InStatement2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, LineComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Comments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayAttachCpp, Sans)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Break1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Break2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Break3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Break4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Break5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Break6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Attach1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Attach2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Attach3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Attach4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Attach5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Attach6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, AttachLineComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, AttachComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Horstmann1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Horstmann2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}
TEST(BracketsArrayHorstmannCpp, Horstmann3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Horstmann4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Horstmann5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, Horstmann6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, HorstmannLineComments1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, HorstmannLineComments2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, HorstmannComments)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, InStatement1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, InStatement2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BracketsArrayHorstmannCpp, InStatement3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
