//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//-------------------------------------------------------------------------
// AStyle Indent Classes
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(IndentClasses)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesEmptyClass)
{
	// empty brackets should not receive an extra indent
	char text[] =
		"\nclass FooClass\n"
		"{};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesEmptyClassSans)
{
	// empty brackets should not receive an extra indent
	char text[] =
		"\nclass FooClass\n"
		"{};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesHorstmann)
{
	// test indent class blocks with horstmann brackets
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
	char options[] = "indent-classes, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesHorstmannSans)
{
	// test without indent class blocks with horstmann brackets
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesHorstmannLineComment)
{
	// test indent class blocks line comment with horstmann brackets
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
	char options[] = "indent-classes, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesHorstmannLineCommentSans)
{
	// test without indent class blocks line comment with horstmann brackets
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesHorstmannComment)
{
	// test indent class blocks comment with horstmann brackets
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
	char options[] = "indent-classes, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesHorstmannCommentSans)
{
	// test without indent class blocks comment with horstmann brackets
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesComment)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesCommentSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStruct)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructComment)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructSansLeadingModifier)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructHorstmann)
{
	// struct containing horstmann brackets
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
	char options[] = "indent-classes, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructHorstmannSans)
{
	// struct containing horstmann brackets without indent-classes
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructUnmatchedBrackets)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesStructSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentClassesNestedStruct)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Switches
//-------------------------------------------------------------------------

TEST(IndentSwitchesNone)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitches)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesHorstmann)
{
	// test indent switch blocks with horstmann brackets
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
	char options[] = "indent-switches, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesHorstmannSans)
{
	// test without indent switch blocks with horstmann brackets
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesHorstmannLineComment)
{
	// test indent switch block line comments with horstmann brackets
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
	char options[] = "indent-switches, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesHorstmannLineCommentSans)
{
	// test switch block NOT indented line comments with horstmann brackets
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesHorstmannComment)
{
	// test indent switch block comments with horstmann brackets
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
	char options[] = "indent-switches, brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentSwitchesHorstmannCommentSans)
{
	// test switch block NOT indented comments with horstmann brackets
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
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Cases
//-------------------------------------------------------------------------

TEST(IndentCases)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCasesShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCasesSans1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCasesMultiple1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCasesMultiple2)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCasesSwitches)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Blocks
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(IndentBlocks)
{
	// test indent blocks
	// per GNU standards the only extra indent is within function blocks
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
		"    void inlineFunc()\n"
		"    {\n"
		"        if (isBar)\n"
		"            {\n"
		"                bar();\n"
		"                if (isAnotherBar)\n"
		"                    {\n"
		"                        anotherBar();\n"
		"                        if (isXtraBar)\n"
		"                            {\n"
		"                                xtraBar();\n"
		"                            }\n"
		"                    }\n"
		"            }\n"
		"    }\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"\n"
		"    if (isBar)\n"
		"        {\n"
		"            bar();\n"
		"            if (isAnotherBar)\n"
		"                {\n"
		"                    anotherBar();\n"
		"                    if (isXtraBar)\n"
		"                        {\n"
		"                            xtraBar();\n"
		"                        }\n"
		"                }\n"
		"        }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "indent-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentBlocksShort)
{
	// test indent blocks short option
	// per GNU standards the only extra indent is within function blocks
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
		"    void inlineFunc()\n"
		"    {\n"
		"        if (isBar)\n"
		"            {\n"
		"                bar();\n"
		"                if (isAnotherBar)\n"
		"                    {\n"
		"                        anotherBar();\n"
		"                        if (isXtraBar)\n"
		"                            {\n"
		"                                xtraBar();\n"
		"                            }\n"
		"                    }\n"
		"            }\n"
		"    }\n"
		"};\n"
		"\n"
		"void FooClass::Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"    else\n"
		"        anotherBar();\n"
		"\n"
		"    if (isBar)\n"
		"        {\n"
		"            bar();\n"
		"            if (isAnotherBar)\n"
		"                {\n"
		"                    anotherBar();\n"
		"                    if (isXtraBar)\n"
		"                        {\n"
		"                            xtraBar();\n"
		"                        }\n"
		"                }\n"
		"        }\n"
		"}\n"
		"\n"
		"}   // end FooName\n";
	char options[] = "-G";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentBlocksBrackets)
{
	// test indent blocks and brackets
	// these are mutually exclusive - indent blocks will be used
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
	char options[] = "indent-brackets, indent-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentBlocksStruct)
{
	// test indent blocks with structs and unions
	// the opening bracket should NOT be indented
	char text[] =
		"\nstruct b_type\n"
		"{\n"
		"    int i;\n"
		"    int j;\n"
		"};\n"
		"\n"
		"struct a_type {\n"
		"    int i;\n"
		"    int j;\n"
		"};\n"
		"\n"
		"union b_type\n"
		"{\n"
		"    int i;\n"
		"    int j;\n"
		"};\n"
		"\n"
		"union a_type {\n"
		"    int i;\n"
		"    int j;\n"
		"};\n"
		"\n"
		"// struct with inheritence and method\n"
		"struct b_fooStruct : public bar\n"
		"{\n"
		"    Foobar(bool isBar)\n"
		"    {\n"
		"        if (isBar)\n"
		"            {\n"
		"                Foo();\n"
		"            }\n"
		"        else\n"
		"            bar();\n"
		"        index = i;\n"
		"    }\n"
		"    long index;\n"
		"};\n"
		"\n"
		"// struct with inheritence and method\n"
		"struct a_fooStruct : public bar {\n"
		"    Foobar(bool isBar) {\n"
		"        if (isBar) {\n"
		"                Foo();\n"
		"            }\n"
		"        else\n"
		"            bar();\n"
		"        index = i;\n"
		"    }\n"
		"    long index;\n"
		"};\n";
	char options[] = "indent-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Brackets
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(IndentBrackets)
{
	// test indent brackets
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
	char options[] = "indent-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
TEST(IndentBracketsShort)
{
	// test indent brackets short option
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
	char options[] = "-B";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentBracketsBlocks)
{
	// test indent brackets and blocks
	// these are mutually exclusive - indent blocks will be used
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
	char options[] = "indent-blocks, indent-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentBracketsHorstmannComments)
{
	// test indent brackets with Horstmann comments
	// will probably not be used, but it needs to work
	char textIn[] =
		"\nbool foo()\n"
		"{   while (confs)\n"
		"    {   /*Replace all '|' with '_'.\n"
		"         * This is vital.\n"
		"         */\n"
		"        ConfigName = Attribute(name);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nbool foo()\n"
		"    {   while (confs)\n"
		"        {   /*Replace all '|' with '_'.\n"
		"             * This is vital.\n"
		"             */\n"
		"        ConfigName = Attribute(name);\n"
		"        }\n"
		"    }\n";
	char options[] = "indent-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentBracketsArrays)
{
	// test indent brackets with arrays
	char text[] =
		"\nconst int cmdLineDesc[] =\n"
		"    {\n"
		"        { CMD_LINE_SWITCH1 },\n"
		"        { CMD_LINE_SWITCH2 },\n"
		"\n"
		"        { CMD_LINE_SWITCH3 },\n"
		"        { CMD_LINE_SWITCH4 },\n"
		"\n"
		"        { CMD_LINE_SWITCH5 },\n"
		"        { CMD_LINE_SWITCH6 },\n"
		"        { CMD_LINE_NONE }\n"
		"    };\n";
	char options[] = "indent-brackets";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Namespaces
// Additional tests are in the Brackets tests
//-------------------------------------------------------------------------

TEST(IndentNamespaces)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentNamespacesShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentNamespacesHorstmann)
{
	// horstmann brackets should NOT run-in to namespaces
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
	char options[] = "indent-namespaces, brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Labels
//-------------------------------------------------------------------------

TEST(IndentLabels)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentLabelsShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentLabelsSans)
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
	CHECK_EQUAL(text, textOut);
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
//	CHECK_EQUAL(text, textOut);
//	delete [] textOut;
//}

//-------------------------------------------------------------------------
// AStyle Indent Preprocessor
//-------------------------------------------------------------------------

TEST(IndentPreprocessor)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessorShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentPreprocessorSans)
{
	// test preprocessor statements without indent preprocessor option
	// they should not change
	char textIn[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"  (Is_Foo((arg), (a)) \\\n"
		"   || Is_Foo((arg), (b)))\n"
		"\n"
		"#define Is_Bar(arg,a,b) \\\n"
		"      (Is_Foo((arg), (a)) \\\n"
		"             || Is_Foo((arg), (b)))\n";
	char text[] =
		"\n#define Is_Bar(arg,a,b) \\\n"
		"  (Is_Foo((arg), (a)) \\\n"
		"   || Is_Foo((arg), (b)))\n"
		"\n"
		"#define Is_Bar(arg,a,b) \\\n"
		"      (Is_Foo((arg), (a)) \\\n"
		"             || Is_Foo((arg), (b)))\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Column one comment
//-------------------------------------------------------------------------

TEST(IndentCol1Comment)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCol1CommentShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(IndentCol1CommentSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Max Instatement Indent
//-------------------------------------------------------------------------

TEST(MaxInstatementIndent)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndentShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndentMax)
{
	// test max instatement indent with the max value
	char textIn[] =
		"\nvoid Long_80_Byte_Indent_Function_xxx1234567890123456789012345678901234567890(bar1,\n"
		"                                        bar2,\n"
		"                                        bar3)\n"
		"{\n"
		"    char Long_80_Byte_Indent_Array_xx1234567890123456789012345678901234567890[] = { red,\n"
		"                                            green,\n"
		"                                            blue\n"
		"                                          };\n"
		"}\n";
	char text[] =
		"\nvoid Long_80_Byte_Indent_Function_xxx1234567890123456789012345678901234567890(bar1,\n"
		"                                                                              bar2,\n"
		"                                                                              bar3)\n"
		"{\n"
		"    char Long_80_Byte_Indent_Array_xx1234567890123456789012345678901234567890[] = { red,\n"
		"                                                                                    green,\n"
		"                                                                                    blue\n"
		"                                                                                  };\n"
		"}\n";
	char options[] = "max-instatement-indent=80";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndentSans)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndentMisc1)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MaxInstatementIndentError)
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
	char options[] = "max-instatement-indent=81";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Min Conditional Indent
//-------------------------------------------------------------------------

TEST(MinConditionalIndent)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentShort)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentHorstmann)
{
	// test min conditional indent with horstmann brackets
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
		"{   if (a < b\n"
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {   bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentZero)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentEight)
{
	// test min conditional indent with a value of 8
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
		"            || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"            || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "min-conditional-indent=8";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentTwelve)
{
	// test min conditional indent with a value of 12
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
		"                || c < d)\n"
		"        bar++;\n"
		"\n"
		"    if (a < b\n"
		"                || c < d)\n"
		"    {\n"
		"        bar++;\n"
		"    }\n"
		"}\n";
	char options[] = "min-conditional-indent=12";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentNoValue)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalOverMax)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalParenOverMax)
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
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MinConditionalIndentError)
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
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	delete [] textOut;
}

//-------------------------------------------------------------------------
// AStyle Indent Misc
// Additional tests that are not specific options
//-------------------------------------------------------------------------

TEST(IndentMiscIndentableHeaders)
{
	// test indentable headers (return, cout, cin, cerr)
	// these headers use InStatementIndent like an operator
	char text[] =
		"\nint foo () {\n"
		"    if (foo1 == bar1)\n"
		"        return xxx +\n"
		"               yyy -\n"
		"               zzz;\n"
		"\n"
		"    return (xxx +\n"
		"            yyy -\n"
		"            zzz);\n"
		"\n"
		"    cout << xxx << xxx\n"
		"         << xxx << xxx << xxx;\n"
		"    cin >> xxx >> xxx\n"
		"        >> xxx >> xxx >> xxx;\n"
		"    cerr << xxx << xxx\n"
		"         << xxx << xxx << xxx;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
