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

TEST_FIXTURE(cppText, CppBracketsNoneNamespace)
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

TEST_FIXTURE(cppText, CppBracketsNoneClass)
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

TEST_FIXTURE(cppText, CppBracketsNoneNamespaceClass)
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

TEST_FIXTURE(cppText, CppBracketsNoneBlocks)
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

TEST_FIXTURE(cppText, CppBracketsNoneNamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsNoneBrackets)
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


TEST_FIXTURE(cppText, CppBracketsNoneNamespaceBrackets)
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


TEST(CppBracketsNoneEmptyBrackets)
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

TEST(CppBracketsNoneBreak)
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

TEST(CppBracketsNoneAttach)
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

TEST(CppBracketsNoneLinux)
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

TEST(CppBracketsNoneHorstmann)
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

TEST(CppBracketsNoneMisc1)
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
		"            }\n"
		"\n"
		"void foo4() { /* comment4\n"
		"               *\n"
		"               */\n"
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
		"}\n"
		"\n"
		"void foo4() {\n"
		"    /* comment4\n"
		"     *\n"
		"     */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsNoneMisc2)
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

TEST(CppBracketsNoneHorstmannIndent1)
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

TEST(CppBracketsNoneHorstmannIndent2)
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

TEST(CppBracketsNoneHorstmannIndentComment1)
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

TEST(CppBracketsNoneHorstmannIndentComment2)
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

TEST(CppBracketsNoneLineCommentsBreak)
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

TEST(CppBracketsNoneLineCommentsAttach)
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

TEST(CppBracketsNoneLineCommentsHorstmann)
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

TEST(CppBracketsNoneCommentsBreak1)
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

TEST(CppBracketsNoneCommentsAttach1)
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

TEST(CppBracketsNoneCommentsHorstmann1)
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


// TODO: mixed tabs and spaces to default (3 tests)

//TEST(CppBracketsNoneCommentsBreak2)
//{
//	// comments following broken brackets should be unchanged
//	char text[] =
//		"\nvoid foo1(bool isFoo) /* comment0 */\n"
//		"{\n"
//		"    /* comment1 */\n"
//		"    if(isFoo)\n"
//		"    {\n"
//		"        /* comment2 */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n"
//		"\n"
//		"void foo2(bool isFoo)\n"
//		"{\n"
//		"    /* comment3\n"
//		"     *\n"
//		"     */\n"
//		"    if(isFoo)\n"
//		"    {\n"
//		"        /* comment4\n"
//		"         *\n"
//		"         */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "";
//	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsNoneCommentsAttach2)
//{
//	// comments following attached brackets should be unchanged
//	// UNLESS they are multi-line
//	char textIn[] =
//		"\nvoid foo1(bool isFoo) { /* comment1 */\n"
//		"    if(isFoo) { /* comment2 */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n"
//		"\n"
//		"void foo2(bool isFoo) { /* comment3\n"
//		"     *\n"
//		"     */\n"
//		"    if(isFoo) { /* comment4\n"
//		"                 *\n"
//		"                 */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid foo1(bool isFoo) { /* comment1 */\n"
//		"    if(isFoo) { /* comment2 */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n"
//		"\n"
//		"void foo2(bool isFoo) {\n"
//		"    /* comment3\n"
//		"    *\n"
//		"    */\n"
//		"    if(isFoo) {\n"
//		"        /* comment4\n"
//		"         *\n"
//		"         */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsNoneCommentsHorstmann2)
//{
//	// comments following horstmann brackets should be unchanged
//	char text[] =
//		"\nvoid foo1(bool isFoo) /* comment0 */\n"
//		"{   /* comment1 */\n"
//		"    if(isFoo)\n"
//		"    {   /* comment2 */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n"
//		"\n"
//		"void foo2(bool isFoo) /* comment0 */\n"
//		"{   /* comment3\n"
//		"     *\n"
//		"     */\n"
//		"    if(isFoo)\n"
//		"    {   /* comment4\n"
//		"         *\n"
//		"         */\n"
//		"        fooBar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "";
//	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

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

TEST_FIXTURE(cppText, CppBracketsBreakShort)
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

TEST_FIXTURE(cppText, CppBracketsBreakNamespace)
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

TEST_FIXTURE(cppText, CppBracketsBreakClass)
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

TEST_FIXTURE(cppText, CppBracketsBreakNamespaceClass)
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

TEST_FIXTURE(cppText, CppBracketsBreakBlocks)
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

TEST_FIXTURE(cppText, CppBracketsBreakNamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsBreakBrackets)
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


TEST_FIXTURE(cppText, CppBracketsBreakNamespaceBrackets)
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

TEST(CppBracketsBreakEmptyBrackets)
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

TEST(CppBracketsBreakBreak)
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

TEST(CppBracketsBreakAttach)
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

TEST(CppBracketsBreakLinux)
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

TEST(CppBracketsBreakHorstmann)
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

TEST(CppBracketsBreakMisc1)
{
	// test break brackets option with the following unusual format
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
		"            }\n"
		"\n"
		"void foo4() { /* comment4\n"
		"               *\n"
		"               */\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()   // comment2\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()   /* comment3 */\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo4()\n"
		"{\n"
		"    /* comment4\n"
		"     *\n"
		"     */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsBreakMisc2)
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

TEST(CppBracketsBreakLineCommentsBreak)
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

TEST(CppBracketsBreakLineCommentsAttach)
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

TEST(CppBracketsBreakLineCommentsHorstmann)
{
	// comments following horstmann brackets should NOT be attached
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

TEST(CppBracketsBreakCommentsBreak1)
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

TEST(CppBracketsBreakCommentsAttach1)
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

TEST(CppBracketsBreakCommentsHorstmann1)
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


// TODO: mixed tabs and spaces to broken (3 tests)

//TEST(CppBracketsBreakCommentsBreak2)
//{
//	// broken brackets with following comments
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=break";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsBreakCommentsAttach2)
//{
//	// break attached brackets with following comments
//	// mixed tabs and spaces
//	char textIn[] ="\nvoid (foo) {\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=break";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsBreakCommentsHorstmann2)
//{
//	// break horstmann brackets with following comments
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {	/*\n"
//		" 	       * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=break";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

TEST(CppBracketsBreakCommentsBreak3)
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

TEST(CppBracketsBreakCommentsAttach3)
{
	// comments following attached brackets should stay attached to the line
	// UNLESS they are multi line
	char textIn[] =
		"\nvoid foo1(bool isFoo) {   /* comment1 */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo) { /* comment3\n"
		"    *\n"
		"    */\n"
		"    if(isFoo) { /* comment4\n"
		"                 *\n"
		"                 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo1(bool isFoo)     /* comment1 */\n"
		"{\n"
		"    if(isFoo)   /* comment2 */\n"
		"    {\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{\n"
		"    /* comment3\n"
		"    *\n"
		"    */\n"
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

TEST(CppBracketsBreakCommentsHorstmann3)
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

TEST_FIXTURE(cppText, CppBracketsAttachShort)
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

TEST_FIXTURE(cppText, CppBracketsAttachNamespace)
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

TEST_FIXTURE(cppText, CppBracketsAttachClass)
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

TEST_FIXTURE(cppText, CppBracketsAttachNamespaceClass)
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

TEST_FIXTURE(cppText, CppBracketsAttachBlocks)
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

TEST_FIXTURE(cppText, CppBracketsAttachNamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsAttachBrackets)
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


TEST_FIXTURE(cppText, CppBracketsAttachNamespaceBrackets)
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


TEST_FIXTURE(cppText, CppBracketsAttachBreakClosing)
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

TEST(CppBracketsAttachEmptyBrackets)
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

TEST(CppBracketsAttachBreak)
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

TEST(CppBracketsAttachAttach)
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

TEST(CppBracketsAttachLinux)
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

TEST(CppBracketsAttachHorstmann)
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

TEST(CppBracketsAttachMisc1)
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
		"            }\n"
		"\n"
		"void foo4() { /* comment4\n"
		"               *\n"
		"               */\n"
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
		"}\n"
		"\n"
		"void foo4() {\n"
		"    /* comment4\n"
		"     *\n"
		"     */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsAttachMisc2)
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

TEST(CppBracketsAttachLineCommentsBreak)
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

TEST(CppBracketsAttachLineCommentsAttach)
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

TEST(CppBracketsAttachLineCommentsHorstmann)
{
	// comments following horstmann brackets should NOT be attached
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

TEST(CppBracketsAttachCommentsBreak1)
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

TEST(CppBracketsAttachCommentsAttach1)
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

TEST(CppBracketsAttachCommentsHorstmann1)
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


// TODO: mixed tabs and spaces to attached (3 tests)

//TEST(CppBracketsAttachCommentsBreak2)
//{
//	// attach broken brackets with following comments
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//		char text[] =
//		"\nvoid (foo) {\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=attach";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsAttachCommentsAttach2)
//{
//	// attached brackets with following comments
//		char textIn[] =
//		"\nvoid (foo) {\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"		/*\n"
//		" 	     * comment2\n"
//		"  	     */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo) {\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=attach";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsAttachCommentsHorstmann2)
//{
//	// attach horstmann brackets with following comments
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {	/*\n"
//		" 	      * comment2\n"
//		"  	     */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo) {\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=attach";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

TEST(CppBracketsAttachCommentsBreak3)
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

TEST(CppBracketsAttachCommentsAttach3)
{
	// comments following attached brackets should be unchanged
	// UNLESS they are multi-line
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
		"    *\n"
		"    */\n"
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

TEST(CppBracketsAttachCommentsHorstmann3)
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

TEST_FIXTURE(cppText, CppBracketsLinuxShort)
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

TEST_FIXTURE(cppText, CppBracketsLinuxNamespace)
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

TEST_FIXTURE(cppText, CppBracketsLinuxClass)
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

TEST_FIXTURE(cppText, CppBracketsLinuxNamespaceClass)
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

TEST_FIXTURE(cppText, CppBracketsLinuxBlocks)
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

TEST_FIXTURE(cppText, CppBracketsLinuxNamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsLinuxBrackets)
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

TEST_FIXTURE(cppText, CppBracketsLinuxNamespaceBrackets)
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

TEST_FIXTURE(cppText, CppBracketsLinuxBreakClosing)
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

TEST(CppBracketsLinuxEmptyBrackets)
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

TEST(CppBracketsLinuxBreak)
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

TEST(CppBracketsLinuxAttach)
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

TEST(CppBracketsLinuxLinux)
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

TEST(CppBracketsLinuxHorstmann)
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

TEST(CppBracketsLinuxMisc1)
{
	// test linux brackets option with the following unusual format

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
		"            }\n"
		"\n"
		"void foo4() { /* comment4\n"
		"               *\n"
		"               */\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()   // comment2\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()   /* comment3 */\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo4()\n"
		"{\n"
		"    /* comment4\n"
		"     *\n"
		"     */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsLinuxMisc2)
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

TEST(CppBracketsLinuxFormatting)
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

TEST(CppBracketsLinuxNestedNamespace)
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

TEST(CppBracketsLinuxLineCommentsBreak)
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

TEST(CppBracketsLinuxLineCommentsAttach)
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

TEST(CppBracketsLinuxLineCommentsHorstmann)
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

TEST(CppBracketsLinuxCommentsBreak1)
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

TEST(CppBracketsLinuxCommentsAttach1)
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

TEST(CppBracketsLinuxCommentsHorstmann1)
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


// TODO: mixed tabs and spaces to horstmann (3 tests)

//TEST(CppBracketsLinuxCommentsBreak2)
//{
//	// broken brackets with following comments to linux
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=linux";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsLinuxCommentsAttach2)
//{
//	// attached brackets with following comments to linux
//	// mixed tabs and spaces
//	char textIn[] ="\nvoid (foo) {\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=linux";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsLinuxCommentsHorstmann2)
//{
//	// horstmann brackets with following comments to linux
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {	/*\n"
//		" 	       * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=linux";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

TEST(CppBracketsLinuxCommentsBreak3)
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

TEST(CppBracketsLinuxCommentsAttach3)
{
	// comments following attached brackets should stay attached to the line
	// UNLESS they are multi-line
	char textIn[] =
		"\nvoid foo1(bool isFoo) { /* comment0 */\n"
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
		"\nvoid foo1(bool isFoo)   /* comment0 */\n"
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
		"    *\n"
		"    */\n"
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

TEST(CppBracketsLinuxCommentsHorstmann3)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupShort)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupNamespace)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupClass)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupNamespaceClass)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupBlocks)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupNamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupBrackets)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupNamespaceBrackets)
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

TEST_FIXTURE(cppText, CppBracketsStroustrupBreakClosing)
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

TEST(CppBracketsStroustrupEmptyBrackets)
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

TEST(CppBracketsStroustrupBreak)
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

TEST(CppBracketsStroustrupAttach)
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

TEST(CppBracketsStroustrupLinux)
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

TEST(CppBracketsStroustrupHorstmann)
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

TEST(CppBracketsStroustrupMisc1)
{
	// test stroustrup brackets option with the following unusual format

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
		"            }\n"
		"\n"
		"void foo4() { /* comment4\n"
		"               *\n"
		"               */\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()   // comment2\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()   /* comment3 */\n"
		"{\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo4()\n"
		"{\n"
		"    /* comment4\n"
		"     *\n"
		"     */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=stroustrup";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsStroustrupMisc2)
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

TEST(CppBracketsStroustrupFormatting)
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

TEST(CppBracketsStroustrupNestedNamespace)
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

TEST(CppBracketsStroustrupLineCommentsBreak)
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

TEST(CppBracketsStroustrupLineCommentsAttach)
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

TEST(CppBracketsStroustrupLineCommentsHorstmann)
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

TEST(CppBracketsStroustrupCommentsBreak1)
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

TEST(CppBracketsStroustrupCommentsAttach1)
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

TEST(CppBracketsStroustrupCommentsHorstmann1)
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


// TODO: mixed tabs and spaces to stroustrup (3 tests)

//TEST(CppBracketsStroustrupCommentsBreak2)
//{
//	// broken brackets with following comments to stroustrup
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=stroustrup";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsStroustrupCommentsAttach2)
//{
//	// attached brackets with following comments to stroustrup
//	// mixed tabs and spaces
//	char textIn[] ="\nvoid (foo) {\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=stroustrup";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsStroustrupCommentsHorstmann2)
//{
//	// horstmann brackets with following comments to stroustrup
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {	/*\n"
//		" 	       * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"    /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"        /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=stroustrup";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

TEST(CppBracketsStroustrupCommentsBreak3)
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

TEST(CppBracketsStroustrupCommentsAttach3)
{
	// comments following attached brackets should stay attached to the line
	// UNLESS they are multi-line
	char textIn[] =
		"\nvoid foo1(bool isFoo) { /* comment0 */\n"
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
		"\nvoid foo1(bool isFoo)   /* comment0 */\n"
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
		"    *\n"
		"    */\n"
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

TEST(CppBracketsStroustrupCommentsHorstmann3)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannShort)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannNamespace)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannClass)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannNamespaceClass)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannBlocks)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannNamespaceBlocks)
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

TEST_FIXTURE(cppText, CppBracketsHorstmannBrackets)
{
	// test horstmann brackets option
	// indent brackets, will NOT indent brackets
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
	char options[] = "brackets=horstmann, indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST_FIXTURE(cppText, CppBracketsHorstmannNamespaceBrackets)
{
	// test horstmann brackets option
	// indent brackets, indent namespaces, will NOT indent brackets
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
	char options[] = "brackets=horstmann, indent-brackets, indent-namespaces";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmannEmptyBrackets)
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

TEST(CppBracketsHorstmannBreak)
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

TEST(CppBracketsHorstmannAttach)
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

TEST(CppBracketsHorstmannLinux)
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

TEST(CppBracketsHorstmannHorstmann)
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

TEST(CppBracketsHorstmannClassSansPrivate1)
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

TEST(CppBracketsHorstmannClassSansPrivate2)
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

TEST(CppBracketsHorstmannMisc1)
{
	// test horstmann brackets option with the following unusual format
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
		"            }\n"
		"\n"
		"void foo4() { /* comment4\n"
		"               *\n"
		"               */\n"
		"              error = false;\n"
		"              errorId = 0;\n"
		"            }\n";
	char text[] =
		"\nvoid foo1()\n"
		"{   error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo2()   // comment2\n"
		"{   error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo3()   /* comment3 */\n"
		"{   error = false;\n"
		"    errorId = 0;\n"
		"}\n"
		"\n"
		"void foo4()\n"
		"{   /* comment4\n"
		"     *\n"
		"     */\n"
		"    error = false;\n"
		"    errorId = 0;\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsHorstmannMisc2)
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

TEST(CppBracketsHorstmannHorstmannIndent1)
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

TEST(CppBracketsHorstmannHorstmannIndent2)
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

TEST(CppBracketsHorstmannLineCommentsBreak)
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

TEST(CppBracketsHorstmannLineCommentsAttach)
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

TEST(CppBracketsHorstmannLineCommentsHorstmann)
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

TEST(CppBracketsHorstmannCommentsBreak1)
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

TEST(CppBracketsHorstmannCommentsAttach1)
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

TEST(CppBracketsHorstmannCommentsHorstmann1)
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


// TODO: mixed tabs and spaces to horstmann (3 tests)

//TEST(CppBracketsHorstmannCommentsBreak2)
//{
//	// broken brackets with following comments to horstmann
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{   /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {   /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=horstmann";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsHorstmannCommentsAttach2)
//{
//	// attached brackets with following comments to horstmann
//	// mixed tabs and spaces
//	char textIn[] ="\nvoid (foo) {\n"
//		"	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo) {\n"
//		"		/*\n"
//		" 	      * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{   /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {   /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=horstmann";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}
//
//TEST(CppBracketsHorstmannCommentsHorstmann2)
//{
//	// horstmann brackets with following comments to horstmann
//	// mixed tabs and spaces
//	char textIn[] =
//		"\nvoid (foo)\n"
//		"{	/*\n"
//		"	 * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {	/*\n"
//		" 	       * comment2\n"
//		"  	    */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid (foo)\n"
//		"{   /*\n"
//		"     * comment1\n"
//		"     */\n"
//		"    if (isFoo)\n"
//		"    {   /*\n"
//		"         * comment2\n"
//		"         */\n"
//		"        bar();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "brackets=horstmann";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

TEST(CppBracketsHorstmannCommentsBreak3)
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

TEST(CppBracketsHorstmannCommentsAttach3)
{
	// comments following attached brackets do NOT attach
	char textIn[] =
		"\nvoid foo1(bool isFoo) { /* comment0 */\n"
		"    if(isFoo) { /* comment1 */\n"
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
		"\nvoid foo1(bool isFoo)   /* comment0 */\n"
		"{   if(isFoo)   /* comment1 */\n"
		"    {   /* comment2 */\n"
		"        fooBar();\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(bool isFoo)\n"
		"{   /* comment3\n"
		"    *\n"
		"    */\n"
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

TEST(CppBracketsHorstmannCommentsHorstmann3)
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


//-------------------------------------------------------------------------
// AStyle C++ Other Bracket Options
//-------------------------------------------------------------------------

TEST(CppBracketsOtherConstIndent)
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

TEST(CppBracketsOtherConstIndentBlocks)
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

TEST(CppBracketsOtherConstIndentBrackets)
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

TEST(CppBracketsOtherNestedClass)
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

TEST(CppBracketsOtherNestedClassBlocks)
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

TEST(CppBracketsOtherNestedClassBrackets)
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

TEST(CppBracketsOtherNestedClassIndent)
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

TEST(CppBracketsOtherNestedClassIndentBlocks)
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

TEST(CppBracketsOtherNestedClassIndentBrackets)
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

TEST(CppBracketsOtherNestedNamespace)
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

TEST(CppBracketsOtherNestedNamespaceBlocks)
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

TEST(CppBracketsOtherNestedNamespaceBrackets)
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

TEST(CppBracketsOtherNestedNamespaceIndent)
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

TEST(CppBracketsOtherNestedNamespaceIndentBlocks)
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

TEST(CppBracketsOtherNestedNamespaceIndentBrackets)
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

TEST(CppBracketsOtherNestedNamespaceClass)
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

TEST(CppBracketsOtherNestedNamespaceClassBlocks)
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

TEST(CppBracketsOtherNestedNamespaceClassBrackets)
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

TEST(CppBracketsOtherNestedNamespaceIndentClass)
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

TEST(CppBracketsOtherNestedNamespaceIndentClassBlocks)
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

TEST(CppBracketsOtherNestedNamespaceIndentClassBrackets)
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

TEST(CppBracketsOtherNestedNamespaceIndentClassIndent)
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

TEST(CppBracketsOtherNestedNamespaceIndentClassIndentBlocks)
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

TEST(CppBracketsOtherNestedNamespaceIndentClassIndentBrackets)
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

TEST(CppBracketsArrayNoneBreak)
{
	// test array formatting with broken bracket
	char text[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayNoneAttach)
{
	// test array formatting with attached brackets
	char text[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayBreak)
{
	// test array formatting
	// should break an attached bracket
	char textIn[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] =\n"
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

TEST(CppBracketsArrayBreakLineComments)
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

TEST(CppBracketsArrayBreakComments)
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

TEST(CppBracketsArrayAttach)
{
	// test array formatting
	// should attach a broken bracket
	char textIn[] =
		"\nconst char *foo[] =\n"
		"{\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char text[] =
		"\nconst char *foo[] = {\n"
		"    \"foo1\",\n"
		"    \"foo2\",\n"
		"    \"foo3\",\n"
		"};\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayAttachLineComments)
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

TEST(CppBracketsArrayAttachComments)
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
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CppBracketsArrayComments1)
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
//TEST(CppBracketsArrayComments2)
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

TEST(CppBracketsStruct1)
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

TEST(CppBracketsStruct2)
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
