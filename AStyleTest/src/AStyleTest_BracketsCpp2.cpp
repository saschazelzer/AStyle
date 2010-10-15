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

TEST(BracketsOtherCpp, NestedClass_IndentBlock)
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

TEST(BracketsOtherCpp, NestedClass_IndentBracketsBracket)
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

TEST(BracketsOtherCpp, NestedClass_IndentClass)
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

TEST(BracketsOtherCpp, NestedClass_IndentClass_IndentBlock)
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

TEST(BracketsOtherCpp, NestedClass_IndentClass_IndentBracket)
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

TEST(BracketsOtherCpp, NestedNamespace_IndentBlock)
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

TEST(BracketsOtherCpp, NestedNamespace_IndentBracket)
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

TEST(BracketsOtherCpp, NestedNamespace_IndentNamespace)
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

TEST(BracketsOtherCpp, NestedNamespace_IndentNamespaceBlock)
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

TEST(BracketsOtherCpp, NestedNamespace_IndentNamespaceBracket)
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

TEST(BracketsOtherCpp, NestedNamespaceClass)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentBlock)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentBracket)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentNamespace)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentNamespaceBlock)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentNamespaceBracket)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentNamespaceClass)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentNamespaceClassBlock)
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

TEST(BracketsOtherCpp, NestedNamespaceClass_IndentNamespaceClassBracket)
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

//-------------------------------------------------------------------------
// AStyle C++ Array Bracket Non-In-Statement Options
//-------------------------------------------------------------------------

TEST(BracketsArrayCpp, ClearNonInStatementArray1)
{
	// Setting of clearNonInStatement flag.
	// The isNonInStatementArray flag should be cleared at the end of the array.
	// If it is not, the continuation lines in the "for" statement will not be indented.
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int folderID[nbGrpFolder][nbControl] = {\\\n"
		"        {IDC_FOLDEROPEN_FG, IDC_FOLDEROPEN_BG},\\\n"
		"        {IDC_FOLDERCLOSE_FG, IDC_FOLDERCLOSE_BG}\\\n"
		"    };\n"
		"\n"
		"    for (TiXmlNodeA *childNode = node->ChildElement(Item);\n"
		"            childNode ;\n"
		"            childNode = childNode->NextSibling(Item))\n"
		"    {\n"
		"        TiXmlElementA *element = childNode->ToElement();\n"
		"    }\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
