//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//-------------------------------------------------------------------------
// AStyle Indent Classes
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(IndentClasses, LongOption)
{
	// test indent class blocks
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
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, ShortOption)
{
	// test indent class blocks short option
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
	char options[] = "-C";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, EmptyClass)
{
	// empty brackets should not receive an extra indent
	char text[] =
		"\nclass FooClass\n"
		"{};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, EmptyClassSans)
{
	// empty brackets should not receive an extra indent
	char text[] =
		"\nclass FooClass\n"
		"{};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunIn)
{
	// test indent class blocks with run-in brackets
	// 'public' 'private' and 'protected' are run-in if class block is indented
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
	char options[] = "indent-classes, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInTab)
{
	// test indent class blocks with run-in brackets and tab indents
	// 'public' 'private' and 'protected' are run-in if class block is indented
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
		"{	private:\n"
		"		bool foo1;\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{		bool foo2;\n"
		"};\n";
	char options[] = "indent-classes, brackets=run-in, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInSans)
{
	// test without indent class blocks with run-in brackets
	// 'public' 'private' and 'protected' are NOT run-in if class block is not indented
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInSansTab)
{
	// test without indent class blocks with run-in brackets and tab indents
	// 'public' 'private' and 'protected' are NOT run-in if class block is not indented
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
		"	bool foo1;\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{	bool foo2;\n"
		"};\n";
	char options[] = "brackets=run-in, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInLineComment)
{
	// test indent class blocks line comment with run-in brackets
	// is run-in if class block is indented and does not start in column 1
	char textIn[] =
		"\nclass fooClass1\n"
		"{\n"
		"    // coment1\n"
		"    public:\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{\n"
		"// comment2\n"
		"    public:\n"
		"};\n";
	char text[] =
		"\nclass fooClass1\n"
		"{   // coment1\n"
		"    public:\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{\n"
		"// comment2\n"
		"    public:\n"
		"};\n";
	char options[] = "indent-classes, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInLineCommentSans)
{
	// test without indent class blocks line comment with run-in brackets
	// currently are run-in and indented one indent if class block is not indented
	char textIn[] =
		"\nclass fooClass1\n"
		"{\n"
		"    // coment1\n"
		"    public:\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{\n"
		"// comment2\n"
		"    public:\n"
		"};\n";
	char text[] =
		"\nclass fooClass1\n"
		"{   // coment1\n"
		"public:\n"
		"};\n"
		"\n"
		"class fooClass2\n"
		"{\n"
		"// comment2\n"
		"public:\n"
		"};\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInComment)
{
	// test indent class blocks comment with run-in brackets
	// is run-in if class block is indented and does not start in column 1
	char textIn[] =
		"\nclass fooClass1\n"
		"{\n"
		"/* coment1 */\n"
		"public:\n"
		"};\n";
	char text[] =
		"\nclass fooClass1\n"
		"{   /* coment1 */\n"
		"    public:\n"
		"};\n";
	char options[] = "indent-classes, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, RunInCommentSans)
{
	// test without indent class blocks comment with run-in brackets
	// currently are run-in and indented one indent if class block is not indented
	char textIn[] =
		"\nclass fooClass1\n"
		"{\n"
		"/* coment1 */\n"
		"public:\n"
		"};\n";
	char text[] =
		"\nclass fooClass1\n"
		"{   /* coment1 */\n"
		"public:\n"
		"};\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, Comment)
{
	// test comment without indent class blocks
	// comment is before the opening bracket
	//     and should NOT receive an extra indent
	char text[] =
		"\nclass FooClass\n"
		"/* PURPOSE:   comment1\n"
		"              comment2\n"
		"*/\n"
		"{\n"
		"};\n"
		"\n"
		"void foo()\n"
		"/* PURPOSE:   comment3\n"
		"   RECEIVES:  comment4\n"
		"   RETURNS:   comment5\n"
		"*/\n"
		"{\n"
		"}\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, CommentSans)
{
	// test comment without indent class blocks
	// comment is before the opening bracket
	//     and should NOT receive an extra indent
	char text[] =
		"\nclass FooClass\n"
		"/* PURPOSE:   comment1\n"
		"              comment2\n"
		"*/\n"
		"{\n"
		"};\n"
		"\n"
		"void foo()\n"
		"/* PURPOSE:   comment3\n"
		"   RECEIVES:  comment4\n"
		"   RETURNS:   comment5\n"
		"*/\n"
		"{\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, Struct)
{
	// struct with access modifiers should have extra indent
	// struct WITHOUT should NOT have extra indent
	char text[] =
		"\nstruct FooClass1\n"
		"{\n"
		"    private:\n"
		"        bool var1;\n"
		"    protected:\n"
		"        bool var2;\n"
		"};\n"
		"\n"
		"struct FooClass2\n"
		"{\n"
		"    bool var1;\n"
		"    bool var2;\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructComment)
{
	// struct with comments containing access modifiers
	// should NOT have extra indent
	char text[] =
		"\nstruct FooClass2\n"
		"{\n"
		"    // private:\n"
		"    bool var1;\n"
		"    /* public:\n"
		"    */\n"
		"    bool var2;\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructQuote)
{
	// struct with quotes containing access modifiers and brackets
	// should NOT have extra indent
	char text[] =
		"\nstruct cppText\n"
		"{\n"
		"    cppText()\n"
		"    {\n"
		"        textStr1 =\n"
		"            \"class FooClass\\n\"\n"
		"            \"{\\n\"\n"
		"            \"private:\\n\"\n"
		"            \"    bool var1;\\n\"\n"
		"            \"};\\n\";\n"
		"\n"
		"        textStr2 =\n"
		"            \"class FooClass {\\n\"\n"
		"            \"private:\\n\"\n"
		"            \"    bool var1;\\n\"\n"
		"            \"};\\n\";\n"
		"\n"
		"        textStr3 =\n"
		"            \"class FooClass\\n\"\n"
		"            \"{   private:\\n\"\n"
		"            \"        bool var1;\\n\"\n"
		"            \"};\\n\";\n"
		"\n"
		"        textIn = textStr1.c_str();\n"
		"    }\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructSansLeadingModifier)
{
	// struct without a leading access modifier
	char text[] =
		"\nstruct FooClass2\n"
		"{\n"
		"        bool var1;\n"
		"\n"
		"    protected:\n"
		"        bool var2;\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructBrackets)
{
	// struct containing non-struct brackets
	char text[] =
		"\nstruct FooClass2\n"
		"{\n"
		"        bool publicFoo()\n"
		"        {\n"
		"            bool var1;\n"
		"        }\n"
		"    private:\n"
		"        bool var2;\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructRunIn)
{
	// struct containing run-in brackets
	char textIn[] =
		"\nstruct FooClass1\n"
		"{\n"
		"    protected:\n"
		"        bool var1;\n"
		"};\n"
		"\n"
		"struct FooClass2\n"
		"{\n"
		"        bool var1;\n"
		"\n"
		"    private:\n"
		"        bool var2;\n"
		"};\n";
	char text[] =
		"\nstruct FooClass1\n"
		"{   protected:\n"
		"        bool var1;\n"
		"};\n"
		"\n"
		"struct FooClass2\n"
		"{       bool var1;\n"
		"\n"
		"    private:\n"
		"        bool var2;\n"
		"};\n";
	char options[] = "indent-classes, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructRunInSans)
{
	// struct containing run-in brackets without indent-classes
	char textIn[] =
		"\nstruct FooClass1\n"
		"{\n"
		"    protected:\n"
		"        bool var1;\n"
		"};\n"
		"\n"
		"struct FooClass2\n"
		"{\n"
		"        bool var1;\n"
		"\n"
		"    private:\n"
		"        bool var2;\n"
		"};\n";
	char text[] =
		"\nstruct FooClass1\n"
		"{\n"
		"protected:\n"
		"    bool var1;\n"
		"};\n"
		"\n"
		"struct FooClass2\n"
		"{   bool var1;\n"
		"\n"
		"private:\n"
		"    bool var2;\n"
		"};\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructUnmatchedBrackets)
{
	// struct with unmatched brackets should not cause an abort
	char textIn[] =
		"\nstruct FooClass2\n"
		"{\n"
		"    bool var1;\n"
		"    bool var2;\n"
		"    bool unmached() {\n"
		"};\n";
	char text[] =
		"\nstruct FooClass2\n"
		"{\n"
		"    bool var1;\n"
		"    bool var2;\n"
		"    bool unmached() {\n"
		"    };\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, StructSans)
{
	// struct without indent-classes should have not extra indent
	char text[] =
		"\nstruct FooClass1\n"
		"{\n"
		"private:\n"
		"    bool var1;\n"
		"protected:\n"
		"    bool var2;\n"
		"};\n"
		"\n"
		"struct FooClass2\n"
		"{\n"
		"    bool var1;\n"
		"    bool var2;\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentClasses, NestedStruct)
{
	// test indent with nested structs
	char text[] =
		"\nstruct RefTable\n"
		"{\n"
		"        struct RefNode0 {\n"
		"            SQObjectPtr obj;\n"
		"        };\n"
		"        RefTable1();\n"
		"        struct RefNode1 {\n"
		"            protected:\n"
		"                SQObjectPtr obj;\n"
		"        };\n"
		"        RefTable2();\n"
		"    private:\n"
		"        RefNode* _nodes;\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Switches
//-------------------------------------------------------------------------

TEST(IndentSwitches, None)
{
	// test without indent switch blocks
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 2:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, LongOption)
{
	// test indent switch blocks
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"\n"
		"        case 2:\n"
		"        {\n"
		"            a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-switches";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, ShortOption)
{
	// test indent switch blocks short option
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"\n"
		"        case 2:\n"
		"        {\n"
		"            a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "-S";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunIn)
{
	// test indent switch blocks with run-in brackets
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"\n"
		"        default:\n"
		"        {\n"
		"            a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   switch (foo)\n"
		"    {   case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"\n"
		"        default:\n"
		"        {   a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-switches, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInTab)
{
	// test indent switch blocks with run-in brackets and tab indents
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"\n"
		"        default:\n"
		"        {\n"
		"            a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{	switch (foo)\n"
		"	{	case 1:\n"
		"			a += 1;\n"
		"			break;\n"
		"\n"
		"		default:\n"
		"		{	a += 2;\n"
		"			break;\n"
		"		}\n"
		"	}\n"
		"}\n";
	char options[] = "indent-switches, brackets=run-in, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInSans)
{
	// test without indent switch blocks with run-in brackets
	// 'case' statements should NOT be run-in
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    default:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    default:\n"
		"    {   a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInSansTab)
{
	// test without indent switch blocks with run-in brackets and tab indents
	// 'case' statements should NOT be run-in
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    default:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{	switch (foo)\n"
		"	{\n"
		"	case 1:\n"
		"		a += 1;\n"
		"		break;\n"
		"\n"
		"	default:\n"
		"	{	a += 2;\n"
		"		break;\n"
		"	}\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=run-in, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInLineComment)
{
	// test indent switch block line comments with run-in brackets
	// should run-in to indented switch blocks
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        // comment1\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   switch (foo)\n"
		"    {       // comment1\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"    }\n"
		"}\n";
	char options[] = "indent-switches, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInLineCommentSans)
{
	// test switch block NOT indented line comments with run-in brackets
	// currently is run-in and indented with switch blocks
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        // comment1\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   switch (foo)\n"
		"    {   // comment1\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInComment)
{
	// test indent switch block comments with run-in brackets
	// should run-in to indented switch blocks
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        /* comment1 */\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   switch (foo)\n"
		"    {       /* comment1 */\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"    }\n"
		"}\n";
	char options[] = "indent-switches, brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches, RunInCommentSans)
{
	// test switch block NOT indented comments with run-in brackets
	// currently is run-in and indented with switch blocks
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        /* comment1 */\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   switch (foo)\n"
		"    {   /* comment1 */\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

struct NestedSwitchesF : public ::testing::Test
{
	string textStr;
	const char* textIn;

	NestedSwitchesF()
	{
		textStr =
			"\nvoid foo(int fooArg)\n"
			"{\n"
			"    int a, b;\n"
			"    switch (fooArg)\n"
			"    {\n"
			"    case 1:\n"
			"        a = 0;\n"
			"    case 2:\n"
			"    {\n"
			"        b = 1;\n"
			"    }\n"
			"    case 3:\n"
			"    {\n"
			"        switch (fooArg)\n"
			"        {\n"
			"        case 1:\n"
			"            a = 0;\n"
			"        case 2:\n"
			"        {\n"
			"            b = 1;\n"
			"        }\n"
			"        case 3:\n"
			"        {\n"
			"            switch (fooArg)\n"
			"            {\n"
			"            case 1:\n"
			"                a = 0;\n"
			"            case 2:\n"
			"            {\n"
			"                b = 1;\n"
			"            }\n"
			"            }\n"
			"        }\n"
			"        }\n"
			"    }\n"
			"    }\n"
			"}";
		textIn = textStr.c_str();
	}
};

TEST_F(NestedSwitchesF, SansIndents)
{
	// test nested switch indent with no options
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(textIn, textOut);
	delete [] textOut;
}

TEST_F(NestedSwitchesF, IndentSwitches)
{
	// test nested switch indent with indented switches
	char text[] =
		"\nvoid foo(int fooArg)\n"
		"{\n"
		"    int a, b;\n"
		"    switch (fooArg)\n"
		"    {\n"
		"        case 1:\n"
		"            a = 0;\n"
		"        case 2:\n"
		"        {\n"
		"            b = 1;\n"
		"        }\n"
		"        case 3:\n"
		"        {\n"
		"            switch (fooArg)\n"
		"            {\n"
		"                case 1:\n"
		"                    a = 0;\n"
		"                case 2:\n"
		"                {\n"
		"                    b = 1;\n"
		"                }\n"
		"                case 3:\n"
		"                {\n"
		"                    switch (fooArg)\n"
		"                    {\n"
		"                        case 1:\n"
		"                            a = 0;\n"
		"                        case 2:\n"
		"                        {\n"
		"                            b = 1;\n"
		"                        }\n"
		"                    }\n"
		"                }\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}";
	char options[] = "indent-switches";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(NestedSwitchesF, IndentCases)
{
	// test nested switch indent with indented cases
	char text[] =
		"\nvoid foo(int fooArg)\n"
		"{\n"
		"    int a, b;\n"
		"    switch (fooArg)\n"
		"    {\n"
		"    case 1:\n"
		"        a = 0;\n"
		"    case 2:\n"
		"        {\n"
		"            b = 1;\n"
		"        }\n"
		"    case 3:\n"
		"        {\n"
		"            switch (fooArg)\n"
		"            {\n"
		"            case 1:\n"
		"                a = 0;\n"
		"            case 2:\n"
		"                {\n"
		"                    b = 1;\n"
		"                }\n"
		"            case 3:\n"
		"                {\n"
		"                    switch (fooArg)\n"
		"                    {\n"
		"                    case 1:\n"
		"                        a = 0;\n"
		"                    case 2:\n"
		"                        {\n"
		"                            b = 1;\n"
		"                        }\n"
		"                    }\n"
		"                }\n"
		"            }\n"
		"        }\n"
		"    }\n"
		"}";
	char options[] = "indent-cases";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST_F(NestedSwitchesF, IndentSwitches_IndentCases)
{
	// test nested switch indent with indented switches and cases
	char text[] =
		"\nvoid foo(int fooArg)\n"
		"{\n"
		"    int a, b;\n"
		"    switch (fooArg)\n"
		"    {\n"
		"        case 1:\n"
		"            a = 0;\n"
		"        case 2:\n"
		"            {\n"
		"                b = 1;\n"
		"            }\n"
		"        case 3:\n"
		"            {\n"
		"                switch (fooArg)\n"
		"                {\n"
		"                    case 1:\n"
		"                        a = 0;\n"
		"                    case 2:\n"
		"                        {\n"
		"                            b = 1;\n"
		"                        }\n"
		"                    case 3:\n"
		"                        {\n"
		"                            switch (fooArg)\n"
		"                            {\n"
		"                                case 1:\n"
		"                                    a = 0;\n"
		"                                case 2:\n"
		"                                    {\n"
		"                                        b = 1;\n"
		"                                    }\n"
		"                            }\n"
		"                        }\n"
		"                }\n"
		"            }\n"
		"    }\n"
		"}";
	char options[] = "indent-switches, indent-cases";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Cases
//-------------------------------------------------------------------------

TEST(IndentCases, LongOption)
{
	// test indent case blocks
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 2:\n"
		"        {\n"
		"            a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-cases";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCases, ShortOption)
{
	// test indent case blocks
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 2:\n"
		"        {\n"
		"            a += 2;\n"
		"            break;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "-K";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCases, Sans1)
{
	// test without indent case blocks
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 2:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCases, Multiple1)
{
	// test multiple case statements per line, with keep one line statements
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:case 2:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 3:case 4:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "keep-one-line-statements";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCases, Multiple2)
{
	// test multiple case statements per line, with break one line statements
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:case 2:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 3:case 4:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"    case 2:\n"
		"        a += 1;\n"
		"        break;\n"
		"\n"
		"    case 3:\n"
		"    case 4:\n"
		"    {\n"
		"        a += 2;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCases, Switches)
{
	// test indent case blocks, with indent switch blocks
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"        case 1:\n"
		"            a += 1;\n"
		"            break;\n"
		"\n"
		"        case 2:\n"
		"            {\n"
		"                a += 2;\n"
		"                break;\n"
		"            }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-switches, indent-cases";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Namespaces
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(IndentNamespaces, LongOption)
{
	// test indent namespaces
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
	char options[] = "indent-namespaces";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentNamespaces, ShortOption)
{
	// test indent namespaces short option
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
	char options[] = "-N";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentNamespaces, RunIn)
{
	// run-in brackets should NOT run-in to namespaces
	char text[] =
		"\nnamespace FooName1\n"
		"{\n"
		"    bool foo;\n"
		"}\n"
		"\n"
		"\nnamespace FooName2\n"
		"{\n"
		"    // comment1\n"
		"}\n"
		"\n"
		"\nnamespace FooName3\n"
		"{\n"
		"    /* comment2 */\n"
		"}\n";
	char options[] = "indent-namespaces, brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Labels
//-------------------------------------------------------------------------

TEST(IndentLabels, LongOption)
{
	// test indent labels
	char textIn[] =
		"\nvoid Foo() {\n"
		"    while (isFoo) {\n"
		"        if (isFoo)\n"
		"            goto error;\n"
		"        bar1();\n"
		"error:\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo() {\n"
		"    while (isFoo) {\n"
		"        if (isFoo)\n"
		"            goto error;\n"
		"        bar1();\n"
		"    error:\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "indent-labels";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentLabels, ShortOption)
{
	// test indent labels short option
	char textIn[] =
		"\nvoid Foo() {\n"
		"    while (isFoo) {\n"
		"        if (isFoo)\n"
		"            goto error;\n"
		"        bar1();\n"
		"error:\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo() {\n"
		"    while (isFoo) {\n"
		"        if (isFoo)\n"
		"            goto error;\n"
		"        bar1();\n"
		"    error:\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "-L";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentLabels, Sans)
{
	// test labels without indent labels option
	char textIn[] =
		"\nvoid Foo() {\n"
		"    while (isFoo) {\n"
		"        if (isFoo)\n"
		"            goto error;\n"
		"        bar1();\n"
		"    error:\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo() {\n"
		"    while (isFoo) {\n"
		"        if (isFoo)\n"
		"            goto error;\n"
		"        bar1();\n"
		"error:\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

// TODO: THE FOLLOWING TEST FAILS
//TEST(IndentLabelsSharp)
//{
//	// test indent labels for C#
//	char textIn[] =
//		"\nvoid Foo() {\n"
//		"    while (isFoo) {\n"
//		"        if (isFoo)\n"
//		"            goto error;\n"
//		"        bar1();\n"
//		"error:\n"
//		"        bar2();\n"
//		"    }\n"
//		"}\n";
//	char text[] =
//		"\nvoid Foo() {\n"
//		"    while (isFoo) {\n"
//		"        if (isFoo)\n"
//		"            goto error;\n"
//		"        bar1();\n"
//		"    error:\n"
//		"        bar2();\n"
//		"    }\n"
//		"}\n";
//	char options[] = "indent-labels, mode=cs";
//	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
//	EXPECT_STREQ(text, textOut);
//	delete [] textOut;
//}

//-------------------------------------------------------------------------
// AStyle Indent Preprocessor
//-------------------------------------------------------------------------

TEST(IndentPreprocessor, LongOption)
{
	// test indent preprocessor
	char textIn[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"(Is_Foo((arg), (a)) \\\n"
		"|| Is_Foo((arg), (b)))\n";
	char text[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"    (Is_Foo((arg), (a)) \\\n"
		"     || Is_Foo((arg), (b)))\n";
	char options[] = "indent-preprocessor";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, ShortOption)
{
	// test indent preprocessor short option
	char textIn[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"(Is_Foo((arg), (a)) \\\n"
		"|| Is_Foo((arg), (b)))\n";
	char text[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"    (Is_Foo((arg), (a)) \\\n"
		"     || Is_Foo((arg), (b)))\n";
	char options[] = "-w";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, InStatement)
{
	// test preprocessor statements with an in-statement indent
	char textIn[] =
		"\n#define wxFORCED_FLAGS (wxSIMPLE_BORDER| \\\n"
		"          wxNO_FULL_REPAINT_ON_RESIZE| \\\n"
		"          wxCLIP_CHILDREN)\n";
	char text[] =
		"\n#define wxFORCED_FLAGS (wxSIMPLE_BORDER| \\\n"
		"                        wxNO_FULL_REPAINT_ON_RESIZE| \\\n"
		"                        wxCLIP_CHILDREN)\n";
	char options[] = "indent-preprocessor";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, Sans)
{
	// test preprocessor statements without indent preprocessor option
	// they should not change
	char text[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"  (Is_Foo((arg), (a)) \\\n"
		"   || Is_Foo((arg), (b)))\n"
		"\n"
		"#define Is_Bar(arg,a,b) \\\n"
		"      (Is_Foo((arg), (a)) \\\n"
		"             || Is_Foo((arg), (b)))\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, SwitchSans1)
{
	// test preprocessor switch statements without indent preprocessor option
	// they should not change
	char text[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"       switch (fail) { \\\n"
		"       case ::DeathTest: { \\\n"
		"          SUPPRESS_CODE(); \\\n"
		"          break; \\\n"
		"          } \\\n"
		"       } \\\n"
		"    }"
		"\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, SwitchSans2)
{
	// test preprocessor switch statements without indent preprocessor option
	// but with indent-switches and indent-cases
	// they should not change
	char text[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"       switch (fail) { \\\n"
		"       case ::DeathTest: { \\\n"
		"          SUPPRESS_CODE(); \\\n"
		"          break; \\\n"
		"          } \\\n"
		"       } \\\n"
		"    }"
		"\n";
	char options[] = "indent-switches, indent-cases";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, SwitchIndent)
{
	// test preprocessor switch statements with switch indent
	// they should be indented
	char textIn[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"       switch (fail) { \\\n"
		"       case ::DeathTest: { \\\n"
		"          SUPPRESS_CODE(); \\\n"
		"          break; \\\n"
		"          } \\\n"
		"       } \\\n"
		"    }"
		"\n";
	char text[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"        switch (fail) { \\\n"
		"            case ::DeathTest: { \\\n"
		"                SUPPRESS_CODE(); \\\n"
		"                break; \\\n"
		"            } \\\n"
		"        } \\\n"
		"    }"
		"\n";
	char options[] = "indent-preprocessor, indent-switches";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, CaseIndent)
{
	// test preprocessor switch statements with case indent
	// they should be indented
	char textIn[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"       switch (fail) { \\\n"
		"       case ::DeathTest: { \\\n"
		"          SUPPRESS_CODE(); \\\n"
		"          break; \\\n"
		"          } \\\n"
		"       } \\\n"
		"    }"
		"\n";
	char text[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"        switch (fail) { \\\n"
		"        case ::DeathTest: { \\\n"
		"                SUPPRESS_CODE(); \\\n"
		"                break; \\\n"
		"            } \\\n"
		"        } \\\n"
		"    }"
		"\n";
	char options[] = "indent-preprocessor, indent-cases";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessor, SwitchCaseIndent)
{
	// test preprocessor switch statements with switch and case indent
	// they should be indented
	char textIn[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"       switch (fail) { \\\n"
		"       case ::DeathTest: { \\\n"
		"          SUPPRESS_CODE(); \\\n"
		"          break; \\\n"
		"          } \\\n"
		"       } \\\n"
		"    }"
		"\n";
	char text[] =
		"\n#define GTEST_DEATH_TEST_(fail) \\\n"
		"    {\\\n"
		"        switch (fail) { \\\n"
		"            case ::DeathTest: { \\\n"
		"                    SUPPRESS_CODE(); \\\n"
		"                    break; \\\n"
		"                } \\\n"
		"        } \\\n"
		"    }"
		"\n";
	char options[] = "indent-preprocessor, indent-switches, indent-cases";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Column one comment
//-------------------------------------------------------------------------

TEST(IndentCol1Comment, LongOption)
{
	// test indent column one comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment 1\n"
		"// comment 2\n"
		" // comment 3\n"
		"   // comment 4\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment 1\n"
		"    // comment 2\n"
		"    // comment 3\n"
		"    // comment 4\n"
		"}\n";
	char options[] = "indent-col1-comments";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCol1Comment, ShortOption)
{
	// test indent column one comment short option
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment 1\n"
		"// comment 2\n"
		" // comment 3\n"
		"   // comment 4\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment 1\n"
		"    // comment 2\n"
		"    // comment 3\n"
		"    // comment 4\n"
		"}\n";
	char options[] = "-Y";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(IndentCol1Comment, Sans)
{
	// test without indent column one comment
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment 1\n"
		"// comment 2\n"
		" // comment 3\n"
		"   // comment 4\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment 1\n"
		"// comment 2\n"
		"// comment 3\n"
		"    // comment 4\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Max Instatement Indent
//-------------------------------------------------------------------------

TEST(MaxInstatementIndent, LongOption)
{
	// test max instatement indent
	char textIn[] =
		"\nvoid Long_40_Byte_Indent_Function_xxxxxxxxxxxxxxxx(bar1,\n"
		"          bar2,\n"
		"          bar3)\n"
		"{\n"
		"    char Long_40_Byte_Indent_Array_xxxxxxxxxxxxxxxxxxxxx[] = { red,\n"
		"            green,\n"
		"            blue\n"
		"    };\n"
		"}\n";
	char text[] =
		"\nvoid Long_40_Byte_Indent_Function_xxxxxxxxxxxxxxxx(bar1,\n"
		"                                                   bar2,\n"
		"                                                   bar3)\n"
		"{\n"
		"    char Long_40_Byte_Indent_Array_xxxxxxxxxxxxxxxxxxxxx[] = { red,\n"
		"                                                               green,\n"
		"                                                               blue\n"
		"                                                             };\n"
		"}\n";
	char options[] = "max-instatement-indent=60";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, ShortOption)
{
	// test max instatement indent short option
	char textIn[] =
		"\nvoid Long_40_Byte_Indent_Function_xxxxxxxxxxxxxxxx(bar1,\n"
		"          bar2,\n"
		"          bar3)\n"
		"{\n"
		"    char Long_40_Byte_Indent_Array_xxxxxxxxxxxxxxxxxxxxx[] = { red,\n"
		"            green,\n"
		"            blue\n"
		"    };\n"
		"}\n";
	char text[] =
		"\nvoid Long_40_Byte_Indent_Function_xxxxxxxxxxxxxxxx(bar1,\n"
		"                                                   bar2,\n"
		"                                                   bar3)\n"
		"{\n"
		"    char Long_40_Byte_Indent_Array_xxxxxxxxxxxxxxxxxxxxx[] = { red,\n"
		"                                                               green,\n"
		"                                                               blue\n"
		"                                                             };\n"
		"}\n";
	char options[] = "-M60";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, Max)
{
	// test max instatement indent with the max value
	char textIn[] =
		"\nvoid Long_80_Byte_Indent_Function_xxxxx12345678901234567890123456789012345678901234567890123456789012345678901234567890(bar1,\n"
		"                                        bar2,\n"
		"                                        bar3)\n"
		"{\n"
		"    char Long_80_Byte_Indent_Array_xx12345678901234567890123456789012345678901234567890123456789012345678901234567890[] = { red,\n"
		"                                            green,\n"
		"                                            blue\n"
		"                                          };\n"
		"}\n";
	char text[] =
		"\nvoid Long_80_Byte_Indent_Function_xxxxx12345678901234567890123456789012345678901234567890123456789012345678901234567890(bar1,\n"
		"                                                                                                                        bar2,\n"
		"                                                                                                                        bar3)\n"
		"{\n"
		"    char Long_80_Byte_Indent_Array_xx12345678901234567890123456789012345678901234567890123456789012345678901234567890[] = { red,\n"
		"                                                                                                                            green,\n"
		"                                                                                                                            blue\n"
		"                                                                                                                          };\n"
		"}\n";
	char options[] = "max-instatement-indent=120";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, Sans)
{
	// test max instatement indent with no value
	// should use the default of 40
	char text[] =
		"\nvoid Long_40_Byte_Indent_Function_xxx(bar1,\n"
		"                                      bar2,\n"
		"                                      bar3)\n"
		"{\n"
		"    char Long_40_Byte_Indent_Array_xx[] = { red,\n"
		"                                            green,\n"
		"                                            blue\n"
		"                                          };\n"
		"}\n";
	char options[] = "max-instatement-indent=";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, Misc1)
{
	// test instatement indent greater than max
	// should use 2 * indent (8)
	char text[] =
		"\nvoid InsertClassMethodDlg::DoFillMethodsFor(wxCheckListBox* clb,\n"
		"        Token* parentToken,\n"
		"        const wxString& ns,\n"
		"        bool includePrivate)\n"
		"{\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, Misc2)
{
	// Text should align on the paren,
	// if max-instatement-indent is large enough.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_pTextFileSearcher = TextFileSearcher::BuildTextFileSearcher ( findData.GetFindText(),\n"
		"                          findData.GetMatchWord(),\n"
		"                          findData.GetRegEx() );\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    m_pTextFileSearcher = TextFileSearcher::BuildTextFileSearcher ( findData.GetFindText(),\n"
		"                                                                    findData.GetMatchWord(),\n"
		"                                                                    findData.GetRegEx() );\n"
		"}\n";
	char options[] = "max-instatement-indent=80";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, Misc3)
{
	// Text should align on the second paren,
	// if max-instatement-indent is large enough.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    lineItemId = m_pTreeLog->AppendItem ( fileItemId, wxString::Format ( wxT ( \"%s: %s\" ),\n"
		"                                          words[i].c_str(),\n"
		"                                          words[i + 1].c_str() ) );\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    lineItemId = m_pTreeLog->AppendItem ( fileItemId, wxString::Format ( wxT ( \"%s: %s\" ),\n"
		"                                                                         words[i].c_str(),\n"
		"                                                                         words[i + 1].c_str() ) );\n"
		"}\n";
	char options[] = "max-instatement-indent=80";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndent, Error)
{
	// test max instatement indent with an invalid value
	// should call the error handler
	char text[] =
		"\nvoid Long_40_Byte_Indent_Function_xxx(bar1,\n"
		"                                      bar2,\n"
		"                                      bar3)\n"
		"{\n"
		"    char Long_40_Byte_Indent_Array_xx[] = { red,\n"
		"                                            green,\n"
		"                                            blue\n"
		"                                          };\n"
		"}\n";
	// use errorHandler2 to verify the error
	char options[] = "max-instatement-indent=121";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Min Conditional Indent
//-------------------------------------------------------------------------

TEST(MinConditionalIndent, LongOption)
{
	// test min conditional indent default
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, ShortOption)
{
	// test min conditional indent short option with a value of zero
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"        || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"        || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "-m0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, Zero)
{
	// test min conditional indent with a value of 0
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"        || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"        || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "min-conditional-indent=0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, One)
{
	// test min conditional indent with a value of 1
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"        || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"        || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "min-conditional-indent=1";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, Two)
{
	// test min conditional indent with a value of 2
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "min-conditional-indent=2";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, Three)
{
	// test min conditional indent with a value of 3
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"        if (a < b\n"
		"            || c < d)\n"
		"                bar++;\n"
		"\n"
		"        if (a < b\n"
		"            || c < d)\n"
		"        {\n"
		"                bar++;\n"
		"        }\n"
		"}\n";
	char options[] = "min-conditional-indent=3, indent=spaces=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, NoValue)
{
	// test min conditional indent with no value
	// should use the default
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "min-conditional-indent=";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, OverMax)
{
	// test min conditional indent over max
	// should use 2 * indent
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!wxUnsetEnv(the_key))\n"
		"    {\n"
		"        Manager::Get()->GetLogManager()->LongLine(noParen,\n"
		"                                                 _(\"Unsetting environment variable failed.\")));\n"
		"        EV_DBGLOG(_T(\"EnvVars: Unsetting environment variable failed.\"));\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!wxUnsetEnv(the_key))\n"
		"    {\n"
		"        Manager::Get()->GetLogManager()->LongLine(noParen,\n"
		"                _(\"Unsetting environment variable failed.\")));\n"
		"        EV_DBGLOG(_T(\"EnvVars: Unsetting environment variable failed.\"));\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, ParenOverMax)
{
	// test min conditional indent over max with line ending in a paren
	// should use 2 * indent
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!wxUnsetEnv(the_key))\n"
		"    {\n"
		"        Manager::Get()->GetLogManager()->Log(F(\n"
		"                                                 _(\"Unsetting environment variable failed.\")));\n"
		"        EV_DBGLOG(_T(\"EnvVars: Unsetting environment variable failed.\"));\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (!wxUnsetEnv(the_key))\n"
		"    {\n"
		"        Manager::Get()->GetLogManager()->Log(F(\n"
		"                _(\"Unsetting environment variable failed.\")));\n"
		"        EV_DBGLOG(_T(\"EnvVars: Unsetting environment variable failed.\"));\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndent, Error)
{
	// test min conditional indent with an invalid value
	// should call the error handler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	// use errorHandler2 to verify the error
	char options[] = "min-conditional-indent=41";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
