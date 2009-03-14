//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <UnitTest++.h>
// #include <iostream>  // for cout

#include "astyle.h"

//----------------------------------------------------------------------------
// declarations
//----------------------------------------------------------------------------

// AStyleMain callback function declarations
void  STDCALL errorHandler(int errorNumber, char* errorMessage);
char* STDCALL memoryAlloc(unsigned long memoryNeeded);

//----------------------------------------------------------------------------
// AStyle version 1.23 TEST functions
//----------------------------------------------------------------------------

SUITE(Version_123)
{
	TEST(GccMinAndMaxOperators)
	{
		// <? and >? operators should not be space padded
		char text[] =
		    "\nint main()\n"
		    "{\n"
		    "    int min = i <? j;\n"
		    "    int max = i >? j;\n"
		    "}\n";
		char options[] = "pad-oper";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(ExternIndent)
	{
		// no extra indent when extern is used
		char text[] =
		    "\nextern void menu_SetConditionalEntry (uint32 menuId,\n"
		    "                                      CondFunc condFunc);\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StructBitIndent)
	{
		// do not break line when struct bit declaration is used
		// lines following struct should have correct indent
		char text[] =
		    "\nstruct A {\n"
		    "    int a:1;\n"
		    "};\n"
		    "\n"
		    "struct X {\n"
		    "    field x : 1;\n"
		    "    field y : 2;\n"
		    "};\n"
		    "\n"
		    "typedef union _USB_DEVICE_STATUS\n"
		    "{\n"
		    "    byte _byte;\n"
		    "    struct\n"
		    "    {\n"
		    "        unsigned RemoteWakeup:1;\n"
		    "        unsigned ctrl_trf_mem:1;\n"
		    "    };\n"
		    "} USB_DEVICE_STATUS;\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(ClassBitIndent)
	{
		// do not break line when struct bit declaration is used
		// lines following class should have correct indent
		char text[] =
		    "\nclass MainWindow\n"
		    "{\n"
		    "public:\n"
		    "    bool inDebugMode;\n"
		    "    uint guiStuffVisible : 1;\n"
		    "    uint editorsReadOnly : 1;\n"
		    "    uint savePluginPaths : 1;\n"
		    "    bool shStartDialog;\n"
		    "};\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(RegionIndent)
	{
		// no extra indent after a C# #region statement containing a keyword
		char text[] =
		    "\npublic interface IDocument\n"
		    "{\n"
		    "    #region ILineManager interface\n"
		    "    /// <value>\n"
		    "    /// A collection of all line segments\n"
		    "    #endregion\n"
		    "\n"
		    "    #region Nested enumerator class\n"
		    "    private sealed class Enumerator : IEnumerator, IPluginCollectionEnumerator\n"
		    "    {\n"
		    "        private readonly PluginCollection m_collection;\n"
		    "    }\n"
		    "    #endregion\n"
		    "}\n"
		    "\n";
		char options[] = "mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StructIndent)
	{
		// no extra indent when struct declaration is used
		char text[] =
		    "\nstruct foo* bar (void) {\n"
		    "}\n"
		    "\n"
		    "struct foo* bar\n"
		    "(void)\n"
		    "{\n"
		    "}\n"
		    "\n"
		    "struct axt *chainToAxt(struct chain *chain,\n"
		    "                       struct chain chain,\n"
		    "                       struct dnaSeq *qSeq)\n"
		    "/* Convert a chain to a list of axt's. This will break\n"
		    " * where there is a double-sided gap in chain.\n"
		    " */\n"
		    "{\n"
		    "}\n";
		char options[] = "";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(PreprocessorErrorStatement)
	{
		// the ' in mustn't causes end comment to separate
		// and continuation comments to misalign
		// when pad-oper is used.
		// it thinks the ' is an opening quote
		char text[] =
		    "\n#ifdef SLIM_CONFIG_USE_PLATE\n"
		    "#error You mustn't compile this file.\n"
		    "#endif\n"
		    "\n"
		    "/* @param\n"
		    " * callee has in_region's ownership.\n"
		    " */\n";

		char options[] = "pad-oper";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(SharpAccessorsWithElse)
	{
		// test indent of getters and setters
		// #else causes a problem
		char text[] =
		    "\npublic class FooClass\n"
		    "{\n"
		    "#if FRAMEWORK_VER_2x\n"
		    "#else\n"
		    "#endif\n"
		    "\n"
		    "    private bool foo;\n"
		    "\n"
		    "    public int foo\n"
		    "    {\n"
		    "        get\n"
		    "        {\n"
		    "            return foo;\n"
		    "        }\n"
		    "        set\n"
		    "        {\n"
		    "            foo = 1;\n"
		    "        }\n"
		    "    }\n"
		    "}\n";
		char options[] = "mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BreakElseIfWithCatch)
	{
		// break-elseifs should not break C# catch statement with parens
		char text[] =
		    "\nclass Test\n"
		    "{\n"
		    "    int foo()\n"
		    "    {\n"
		    "        try\n"
		    "        {\n"
		    "            bar();\n"
		    "        }\n"
		    "        catch (Exception e)\n"
		    "        {\n"
		    "            Console.WriteLine(e.message);\n"
		    "        }\n"
		    "    }\n"
		    "}\n";
		char options[] = "break-elseifs, mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(IndentBracketsInComment)
	{
		// test indent brackets with brackets in comment
		// should not indent brackets in comments
		char text[] =
		    "\nvoid foo()\n"
		    "    {\n"
		    "    /*if (client == NULL)\n"
		    "    {\n"
		    "        int found = -1;\n"
		    "    }*/\n"
		    "    }\n";
		char options[] = "indent-brackets";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BreakBracketsWithEmptyLine)
	{
		// test break all blocks with an empty line following comments
		// an error in peekNextLine caused a line break before ++lineOpeningBlocksNum;
		char text[] =
		    "\nvoid foo()\n"
		    "{\n"
		    "    for (i = 0; i < 10; i++)\n"
		    "    {\n"
		    "        ++lineOpeningBlocksNum;\n"
		    "//        if (isInClassHeader)\n"
		    "//        isInClassHeader = false;\n"
		    "\n"
		    "        if (isInClassHeaderTab)\n"
		    "            isInClassHeaderTab = false;\n"
		    "    }\n"
		    "}\n";
		char options[] = "break-blocks=all";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(UnmatchedBracketsInPreprocessor1)
	{
		// unmatched brackets in preprocessor directives
		// should not cause formatting problems on following lines
		char text[] =
		    "\n//-----------\n"
		    "namespace fooName\n"
		    "{\n"
		    "\n"
		    "#ifdef fooBar\n"
		    "void foo1()\n"
		    "{\n"
		    "#else\n"
		    "void foo1()\n"
		    "{\n"
		    "#endif\n"
		    "}\n"
		    "\n"
		    "void foo2()\n"
		    "{\n"
		    "}\n"
		    "\n"
		    "}\n";
		char options[] = "brackets=linux";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(UnmatchedBracketsInPreprocessor2)
	{
		// unmatched brackets in preprocessor directives
		// should not cause formatting problems on following lines
		char text[] =
		    "\nnamespace fooName\n"
		    "{\n"
		    "\n"
		    "#ifdef fooBar\n"
		    "void foo1()\n"
		    "{\n"
		    "#else\n"
		    "void foo1()\n"
		    "{\n"
		    "#endif\n"
		    "}\n"
		    "\n"
		    "void foo2()\n"
		    "{\n"
		    "}\n"
		    "\n"
		    "}\n";
		char options[] = "delete-empty-lines";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(DeleteLinesAfterPreprocessor)
	{
		// empty lines after a preprocessor
		// should should NOT be attached to the preprocessor
		char textIn[] =
		    "\nvoid foo()\n"
		    "{\n"
		    "#if 0\n"
		    "\n"
		    "    {\n"
		    "        bar0 = 0;\n"
		    "    }\n"
		    "#endif\n"
		    "\n"
		    "\n"
		    "    {\n"
		    "        bar1 = 1;\n"
		    "    }\n"
		    "}\n";
		char text[] =
		    "\nvoid foo()\n"
		    "{\n"
		    "#if 0\n"
		    "    {\n"
		    "        bar0 = 0;\n"
		    "    }\n"
		    "#endif\n"
		    "    {\n"
		    "        bar1 = 1;\n"
		    "    }\n"
		    "}\n";
		char options[] = "brackets=linux, delete-empty-lines";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(CSharpNullableTypes)
	{
		// C# nullable types should not separate the ? from the variable
		// when pad-oper is used
		char text[] =
		    "\nclass MainClass\n"
		    "{\n"
		    "    static void Main()\n"
		    "    {\n"
		    "        // nullable types\n"
		    "        // any type may be used as a nullable type\n"
		    "        int? i = 10;\n"
		    "        double? d1 = 3.14;\n"
		    "        bool? flag = null;\n"
		    "        char? letter = 'a';\n"
		    "        int?[] arr = new int?[10];\n"
		    "    }\n"
		    "}\n";

		char options[] = "pad-oper, mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(CSharpQuestionQuestionOperator)
	{
		// C# ?? operator should not separate when pad-oper is used
		char text[] =
		    "\nclass MainClass\n"
		    "{\n"
		    "    static void Main()\n"
		    "    {\n"
		    "        // ?? operator example.\n"
		    "        int? x = null;\n"
		    "        // y = x, unless x is null, in which case y = -1.\n"
		    "        int y = x ?? -1;\n"
		    "        int i = GetNullableInt() ?? defaultInt(int);\n"
		    "        string s = GetStringValue();\n"
		    "        Console.WriteLine(s ?? \"Unspecified\");\n"
		    "    }\n"
		    "}\n";
		char options[] = "pad-oper, mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(CSharpNonGenericDefault)
	{
		// C# non-generic default statement should not un-indent the line
		char text[] =
		    "\nclass MainClass\n"
		    "{\n"
		    "    static void Main()\n"
		    "    {\n"
		    "        int i = GetNullableInt() ?? default(int);\n"
		    "    }\n"
		    "}\n";
		char options[] = "pad-oper, mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(BreakBlocksWithPreprocessor)
	{
		// empty lines should not be inserted after the #if
		char text[] =
			"\nvoid foo()\n"
			"{\n"
			"    if ( isFoo )\n"
			"    {\n"
			"        bar1();\n"
			"    }\n"
			"\n"
			"#if 0\n"
			"    bar2();\n"
			"    bar3();\n"
			"    bar4();\n"
			"    bar5();\n"
			"    bar6();\n"
			"#endif\n"
			"}\n";
		char options[] = "break-blocks";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(CSharpBreakBlocksWithKeepOneLineBlocks)
	{
		// C# do NOT break before a block with keep one line blocks
		// NOTE: this is wrong on the last line
		char text[] =
			"\npublic class FooClass\n"
			"{\n"
			"    public bool Foo { get { return Count > 0; } }\n"
			"    }\n";

		char options[] = "break-blocks, keep-one-line-blocks, mode=cs";
		char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(CSharpLambdaExpressionArrow)
	{
		// C# lambda expression arrow (=>) not separated by pad operators
		char textIn[] =
			"\npublic class FooClass\n"
			"{\n"
			"    public bool Foo {\n"
			"        M(x=>x.Length);\n"
			"    }\n"
			"}\n";
		char text[] =
			"\npublic class FooClass\n"
			"{\n"
			"    public bool Foo {\n"
			"        M(x => x.Length);\n"
			"    }\n"
			"}\n";
		char options[] = "pad-oper, mode=cs";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(NoneModeBreakLines)
	{
		// NONE_MODE should break lines after an opening bracket
		// this is the same as the other bracket modes
		char textIn[] =
			"\nvoid Foo1(bool isBar)\n"
			"{\n"
			"    if (isBar1())\n"
			"    {   if (isBar2())\n"
			"        {   fooBar1();\n"
			"            fooBar2();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"\n"
			"void Foo2()\n"
			"{\n"
			"    if (isBar1()) {  if (isBar2()) {\n"
			"            fooBar1();\n"
			"            fooBar2();\n"
			"        }\n"
			"    }\n"
			"}\n";
		char text[] =
			"\nvoid Foo1(bool isBar)\n"
			"{\n"
			"    if (isBar1())\n"
			"    {\n"
			"        if (isBar2())\n"
			"        {\n"
			"            fooBar1();\n"
			"            fooBar2();\n"
			"        }\n"
			"    }\n"
			"}\n"
			"\n"
			"void Foo2()\n"
			"{\n"
			"    if (isBar1()) {\n"
			"        if (isBar2()) {\n"
			"            fooBar1();\n"
			"            fooBar2();\n"
			"        }\n"
			"    }\n"
			"}\n";
		char options[] = "";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(EnumDefinitionPadding)
	{
		// enum should space pad before the definition
		// NOTE: the enum is an array type bracket
		char textIn[] =
			"\n// should space pad after the brackets\n"
			"typedef enum tagSQObjectType{\n"
			"    OT_INTEGER = (_RT_INTEGER),\n"
			"    OT_BOOL =    (_RT_BOOL),\n"
			"}SQObjectType;\n"
			"\n"
			"// should NOT space pad before a semi-colon\n"
			"typedef enum tagSQObjectType{\n"
			"    OT_INTEGER = (_RT_INTEGER),\n"
			"    OT_BOOL =    (_RT_BOOL),\n"
			"};";
		char text[] =
			"\n// should space pad after the brackets\n"
			"typedef enum tagSQObjectType {\n"
			"    OT_INTEGER = (_RT_INTEGER),\n"
			"    OT_BOOL =    (_RT_BOOL),\n"
			"} SQObjectType;\n"
			"\n"
			"// should NOT space pad before a semi-colon\n"
			"typedef enum tagSQObjectType {\n"
			"    OT_INTEGER = (_RT_INTEGER),\n"
			"    OT_BOOL =    (_RT_BOOL),\n"
			"};";
		char options[] = "";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(UnionDefinitionPadding)
	{
		// union should space pad before the definition
		char textIn[] =
			"\n// should space pad after the brackets\n"
			"typedef union tagSQObjectValue{\n"
			"    struct SQTable *pTable;\n"
			"    struct SQArray *pArray;\n"
			"}SQObjectValue;\n"
			"\n"
			"// should NOT space pad before a semi-colon\n"
			"typedef union tagSQObjectValue{\n"
			"    struct SQTable *pTable;\n"
			"    struct SQArray *pArray;\n"
			"};";
		char text[] =
			"\n// should space pad after the brackets\n"
			"typedef union tagSQObjectValue {\n"
			"    struct SQTable *pTable;\n"
			"    struct SQArray *pArray;\n"
			"} SQObjectValue;\n"
			"\n"
			"// should NOT space pad before a semi-colon\n"
			"typedef union tagSQObjectValue {\n"
			"    struct SQTable *pTable;\n"
			"    struct SQArray *pArray;\n"
			"};";
		char options[] = "";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

	TEST(StructDefinitionPadding)
	{
		// struct should space pad before the definition
		char textIn[] =
			"\n// should space pad after the brackets\n"
			"typedef struct tagSQStackInfos{\n"
			"    const SQChar* funcname;\n"
			"    const SQChar* source;\n"
			"}SQStackInfos;\n"
			"\n"
			"// should NOT space pad before a semi-colon\n"
			"typedef struct tagSQStackInfos{\n"
			"    const SQChar* funcname;\n"
			"    const SQChar* source;\n"
			"};";
		char text[] =
			"\n// should space pad after the brackets\n"
			"typedef struct tagSQStackInfos {\n"
			"    const SQChar* funcname;\n"
			"    const SQChar* source;\n"
			"} SQStackInfos;\n"
			"\n"
			"// should NOT space pad before a semi-colon\n"
			"typedef struct tagSQStackInfos {\n"
			"    const SQChar* funcname;\n"
			"    const SQChar* source;\n"
			"};";
		char options[] = "";
		char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
		CHECK_EQUAL(text, textOut);
		delete [] textOut;
	}

}   // end SUITE(Version_123)

//----------------------------------------------------------------------------
// AStyle Character Set Tests
//----------------------------------------------------------------------------

TEST(ExtendedCharacterSet)
{
	// multi-byte characters (c) and ü should not cause assert error with
	//     Visual Studio isalpha(), isalnum(), is punct(), etc.
	// will happen only in the debug build 
	char text[] =
		"\n// © is character 169\n"
		"\n// ü is character 252\n"
		"void foo()\n"
		"{\n"
		"    ©bar1();\n"
		"    barü2();\n"
		"    bar3©();\n"
		"    ba©r4(ü);\n"
		"    cout << \"©ü\" << endl;\n"
		"    ©\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UnicodeCharacterSet)
{
	// unicode characters should not cause assert error with
	//     Visual Studio isalpha(), isalnum(), is punct(), etc.
	// will happen only in the debug build 
	char text[] =
		"\n// \xF0\x80\xA0\xB0 is a unicode UTF-8 character\n"
		"void foo()\n"
		"{\n"
		"    \xF0\x80\xA0\xB0\x62\x61r1();\n"
		"    bar\xF0\x80\xA0\xB0\x32();\n"
		"    bar3(\xF0\x80\xA0\xB0);\n"
		"    ba\xF0\x80\xA0\xB0r4();\n"
		"    cout << \"\xF0\x80\xA0\xB0\" << endl;\n"
		"    \xF0\x80\xA0\xB0\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(UTF8WithBOM)
{
	// UTF-8 BOM should not cause assert error with
	//     Visual Studio isalpha(), isalnum(), is punct(), etc.
	//     and should recognize "namespace" as a keyword
	// will happen only in the debug build 
	char textIn[] =
		"\xEF\xBB\xBFnamespace {\n"
		"}\n";			
	char text[] =
		"\xEF\xBB\xBFnamespace\n"
		"{\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}
