//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// AStyle version 1.24 TEST functions
//----------------------------------------------------------------------------

TEST(v124ElseAttachedToLineComment)
{
	// else should not be attached to a line coment
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( x == 'G')\n"
		"        y = 1;\n"
		"    else\n"
		"//  if ( x == 'W')\n"
		"//      y= 3;\n"
		"//  else\n"
		"        if ( x == 'H')\n"
		"            y = 4;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BreakOneLineBloksComment1)
{
	// comment should be moved to the previous line
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    { bar(); } // comment\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();    // comment\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BreakOneLineBloksComment2)
{
	// comment should be moved to the previous line
	// option keep-one-line-statements is used
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    { bar(); } // comment\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();    // comment\n"
		"    }\n"
		"}\n";
	char options[] = "keep-one-line-statements";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124SharpDelegate)
{
	// sharp 'delegate' should be recognized as a keyword
	// the Linux brackets should be attached
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    delegate {\n"
		"        if (isFoo)\n"
		"        {\n"
		"            bar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    delegate {\n"
		"        if (isFoo) {\n"
		"            bar();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=linux, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124JavaInStatementLineCommentClear)
{
	// isNonInStatementArray should be cleared when a // follows a }
	// if not cleared the "? ERROR" line will not be correctly indented
	char text[] =
		"\npublic enum KeyboardCommand\n"
		"{\n"
		"    TAB_OUT_FORWARD,\n"
		"    TAB_OUT_BACK\n"
		"} // this comment\n"
		"\n"
		"static class Entry\n"
		"{\n"
		"    Entry(PluginJAR jar)\n"
		"    {\n"
		"        if (plugin != null)\n"
		"        {\n"
		"            status = plugin instanceof EditPlugin.Broken\n"
		"                     ? ERROR : LOADED;\n"
		"            clazz = plugin.getClassName();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124JavaInStatementCommentClear)
{
	// isNonInStatementArray should be cleared when a /* follows a }
	// if not cleared the "? ERROR" line will not be correctly indented
	char text[] =
		"\npublic enum KeyboardCommand\n"
		"{\n"
		"    TAB_OUT_FORWARD,\n"
		"    TAB_OUT_BACK\n"
		"} /* this comment */\n"
		"\n"
		"static class Entry\n"
		"{\n"
		"    Entry(PluginJAR jar)\n"
		"    {\n"
		"        if (plugin != null)\n"
		"        {\n"
		"            status = plugin instanceof EditPlugin.Broken\n"
		"                     ? ERROR : LOADED;\n"
		"            clazz = plugin.getClassName();\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124SharpAccessors)
{
	// get is preceded by []
	char text[] =
		"\npublic static MyApplication Application\n"
		"{\n"
		"    [DebuggerStepThrough]\n"
		"    get\n"
		"    {\n"
		"        if (isBar)\n"
		"            bar();\n"
		"        return application;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124SharpNonParenHeaderUnchecked)
{
	// 'unchecked' should be recognized as a header, not an array
	char text[] =
		"\npublic override void foo()\n"
		"{\n"
		"    unchecked {\n"
		"        if (isBar)\n"
		"            bar += 1;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124SharpNonParenHeaderDelegate)
{
	// 'delegate' should be recognized as a header, not an array
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int fooBar = delegate {\n"
		"        if (isBar1) {\n"
		"            bar = 1;\n"
		"        } else if (isBar2) {\n"
		"            bar = 2;\n"
		"        } else if (isBar3) {\n"
		"            bar = 3;\n"
		"        }\n"
		"    };\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124PadCommentBeforeTab)
{
	// space padding the bracket should NOT pad a comment
	//     when the commet is preceeded by a tab
	//     but should delete a space when preceded spaces
	char textIn[] =
		"\nvoid foo() {\n"
		"    if (isBar1){	// comment\n"
		"        bar1();\n"
		"    }\n"
		"    if (isBar2){   // comment\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isBar1) {	// comment\n"
		"        bar1();\n"
		"    }\n"
		"    if (isBar2) {  // comment\n"
		"        bar2();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsBreakPadParen)
{
	// break attached brackets with pad-paren
	// comments should be moved with one padded space
	char textIn[] =
		"\nvoid foo() { // comment0\n"
		"    if ((isFoo())) { // comment1\n"
		"        bar1();\n"
		"        bar2(fooBar); // comment2\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2(){// comment0\n"
		"    if ((isFoo())){// comment1\n"
		"        bar1();\n"
		"        bar2(fooBar);// comment2\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()   // comment0\n"
		"{\n"
		"    if ( ( isFoo() ) ) // comment1\n"
		"    {\n"
		"        bar1();\n"
		"        bar2 ( fooBar ); // comment2\n"
		"    }\n"
		"}\n"
		"\n"
		"void foo2() // comment0\n"
		"{\n"
		"    if ( ( isFoo() ) ) // comment1\n"
		"    {\n"
		"        bar1();\n"
		"        bar2 ( fooBar ); // comment2\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsAttachCommentsMisc1)
{
	// attach bracket inside a line end comment
	// when multi-line comments follow a horstmann bracket
	char textIn[] =
		"\nvoid foo2(bool isFoo) /* comment0 */\n"
		"{   /* comment1\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) /* comment2 */\n"
		"    {   /* comment3\n"
		"         *\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo2(bool isFoo) { /* comment0 */\n"
		"    /* comment1\n"
		"     *\n"
		"     */\n"
		"    if(isFoo) { /* comment2 */\n"
		"        /* comment3\n"
		"         *\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsAttachCommentMisc2)
{
	// do NOT attach bracket inside a line end comment
	// when two comments are on the line
	char text[] =
		"\nvoid foo() {\n"
		"    if (isBar())   /* comment0 */ // comment0line\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsAttachCommentMisc3)
{
	// when a bracket is NOT attached
	// following horstmann comments should be broken and correctly formatted
	char textIn[] =
		"\nvoid foo() {\n"
		"    if (isBar())   /* comment0 */ // comment0line\n"
		"    {   /*\n"
		"         * comment1\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isBar())   /* comment0 */ // comment0line\n"
		"    {\n"
		"        /*\n"
		"         * comment1\n"
		"         */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsAttachCommentMisc4)
{
	// attached brackets with following comments
	// the second comment should be correctly formatted
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment1\n"
		"        {\n"
		"            bar1();\n"
		"        }\n"
		"        /*else\n"
		"        {\n"
		"            bar2();\n"
		"        }*/\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo) {\n"
		"        // comment1\n"
		"        {\n"
		"            bar1();\n"
		"        }\n"
		"        /*else\n"
		"        {\n"
		"            bar2();\n"
		"        }*/\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannTabs)
{
	// test horstmann brackets with tab indents
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{	if (isFoo())\n"
		"	{	bar();\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannArray1)
{
	// test horstmann brackets with single line array
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    wxChar name[MAX_PATH] = {0};\n"
		"    bar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   wxChar name[MAX_PATH] = {0};\n"
		"    bar();\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannArray2)
{
	// test horstmann brackets with structs and arrays
	char textIn[] =
		"\nstruct runinClass2\n"
		"{\n"
		"    bool bar;\n"
		"};\n"
		"\n"
		"const char *contributors[] =\n"
		"{\n"
		"    \"Bugs\",\n"
		"    \"Daffy\",\n"
		"};\n";
	char text[] =
		"\nstruct runinClass2\n"
		"{   bool bar;\n"
		"};\n"
		"\n"
		"const char *contributors[] =\n"
		"{   \"Bugs\",\n"
		"    \"Daffy\",\n"
		"};\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannSpaces1)
{
	// test horstmann brackets with extra spaces
	// extra spaces should be deleted
	char textIn[] =
		"\nvoid Foo()\n"
		"{     if (isFoo())\n"
		"      {     bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo())\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannSpaces2)
{
	// test multiple horstmann brackets runs
	// extra spaces should not be added on subsequent runs
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isFoo())\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   if (isFoo())\n"
		"    {   bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOne = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	char* textOut = AStyleMain(textOne, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOne;
	delete [] textOut;
}

TEST(v124BracketsHorstmannPreprocessor)
{
	// test horstmann brackets with preprocessor
	// preprocessor should NOT be attached
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"#ifdef xxx\n"
		"    bar1();\n"
		"#else\n"
		"    bar2();\n"
		"#endif\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"#ifdef xxx\n"
		"    bar1();\n"
		"#else\n"
		"    bar2();\n"
		"#endif\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannEmptyLine)
{
	// test horstmann brackets with following empty line
	// empty line should NOT be deleted
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"\n"
		"    if (isFoo())\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannComment1)
{
	// test horstmann brackets with following comment
	// second comment should NOT be attached to the first
	char textIn[] =
		"\nvoid Foo()\n"
		"{\n"
		"    // comment1\n"
		"    // comment2\n"
		"    if (isFoo())\n"
		"        bar();\n"
		"}\n";
	char text[] =
		"\nvoid Foo()\n"
		"{   // comment1\n"
		"    // comment2\n"
		"    if (isFoo())\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannComment2)
{
	// test horstmann brackets with following comment in column 1
	// the comment should NOT be attached
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"// comment1 does not attach\n"
		"// comment2\n"
		"    if (isFoo())\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannComment3)
{
	// test horstmann brackets with following comment
	// the comment should NOT be attached to the previous line
	char text[] =
		"\nvoid foo()\n"
		"{   foo1();\n"
		"    /* comment */\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannComment4)
{
	// test horstmann brackets with following comment
	// the comment should NOT be attached to the previous line
	char text[] =
		"\nvoid foo()\n"
		"{   // comment1\n"
		"    /*comment2*/\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannComment5)
{
	// test horstmann brackets with following comment
	// the comment on unattached lines should be correctly indented
	char textIn[] =
		"\nnamespace fooName\n"
		"{\n"
		"    /**\n"
		"     * comment1\n"
		"     */\n"
		"    class fooClass\n"
		"    {\n"
		"        /**\n"
		"         * comment1\n"
		"         */\n"
		"    }\n"
		"}\n";
	char text1[] =
		"\nnamespace fooName\n"
		"{\n"
		"/**\n"
		" * comment1\n"
		" */\n"
		"class fooClass\n"
		"{   /**\n"
		"     * comment1\n"
		"     */\n"
		"}\n"
		"}\n";
	char text2[] =
		"\nnamespace fooName\n"
		"{\n"
		"    /**\n"
		"     * comment1\n"
		"     */\n"
		"    class fooClass\n"
		"    {   /**\n"
		"         * comment1\n"
		"         */\n"
		"    }\n"
		"}\n";
	char options1[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options1, errorHandler, memoryAlloc);
	CHECK_EQUAL(text1, textOut);
	delete [] textOut;
	char options2[] = "brackets=horstmann, indent-namespaces";
	textOut = AStyleMain(textIn, options2, errorHandler, memoryAlloc);
	CHECK_EQUAL(text2, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannComment6)
{
	// test horstmann brackets with comment following line comment
	// the comment should NOT be attached to the previous line
	char textIn[] =
		"\nvoid foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        // comment\n"
		"/* FIXME comment in column 1 */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo(bool isFoo)\n"
		"{   if (isFoo)\n"
		"    {   // comment\n"
		"        /* FIXME comment in column 1 */\n"
		"        bar();\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannBreakAllBlocks1)
{
	// test horstmann brackets with break all blocks
	// the blocks should be correctly broken
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar1();\n"
		"    if (isBar)  // comment\n"
		"    {\n"
		"        bar2();\n"
		"        return;\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"        bar3();\n"
		"    }\n"
		"    bar4();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   bar1();\n"
		"\n"
		"    if (isBar)  // comment\n"
		"    {   bar2();\n"
		"        return;\n"
		"    }\n"
		"\n"
		"    else\n"
		"    {   bar3();\n"
		"    }\n"
		"\n"
		"    bar4();\n"
		"}\n";
	char options[] = "brackets=horstmann, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannBreakAllBlocks2)
{
	// test horstmann brackets with break all blocks and delete empty lines
	// and comments separated by an empty line
	// the empty line should NOT be deleted
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    // comment1\n"
		"\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   // comment1\n"
		"\n"
		"    // comment2\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=horstmann, break-blocks=all, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannUnpadParen1)
{
	// test horstmann brackets with unpad parens
	// the indent should NOT be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ( isBar )\n"
		"    {\n"
		"        ( *_err ) << endl; // comment1\n"
		"        ( *_err ) << arg;  // comment2\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if(isBar)\n"
		"    {   (*_err) << endl;   // comment1\n"
		"        (*_err) << arg;    // comment2\n"
		"    }\n"
		"}\n";
	char options[] = ", brackets=horstmann, unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannUnpadParen2)
{
	// test horstmann brackets with unpad parens and pad-parens
	// the indent should NOT be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isBar)\n"
		"    {\n"
		"        (*_err) << endl; // comment1\n"
		"        (*_err) << arg;  // comment2\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if ( isBar )\n"
		"    {   ( *_err ) << endl; // comment1\n"
		"        ( *_err ) << arg; // comment2\n"
		"    }\n"
		"}\n";
	char options[] = ", brackets=horstmann, unpad-paren, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannUnpadParen3)
{
	// test horstmann brackets with unpad parens and pad-parens
	//	and tab indents
	// the indent should NOT be removed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isBar)\n"
		"    {\n"
		"        (*_err) << endl; // comment1\n"
		"        (*_err) << arg;  // comment2\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{	if ( isBar )\n"
		"	{	( *_err ) << endl; // comment1\n"
		"		( *_err ) << arg; // comment2\n"
		"	}\n"
		"}\n";
	char options[] = ", brackets=horstmann, unpad-paren, pad-paren, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannSingleLineBlock1)
{
	// test horstmann brackets with single line block
	char textIn[] =
		"\nvoid foo()\n"
		"{ bar1(); bar2() }\n";
	char text[] =
		"\nvoid foo()\n"
		"{   bar1();\n"
		"    bar2()\n"
		"}\n";
	char options[] = ", brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v124BracketsHorstmannSingleLineBlock2)
{
	// test horstmann brackets with single line block
	char text[] =
		"\nvoid foo()\n"
		"{ bar1(); bar2() }\n";
	char options[] = ", brackets=horstmann, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle version 1.23 TEST functions
//----------------------------------------------------------------------------

TEST(v123ExternIndent)
{
	// no extra indent when extern is used
	char text[] =
		"\nextern void foo (bool bar2,\n"
		"                 bool bar2);\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v123StructBitIndent)
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

TEST(v123ClassBitIndent)
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

TEST(v123RegionIndent)
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

TEST(v123StructIndent)
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

TEST(v123PreprocessorErrorStatement)
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

TEST(v123SharpAccessorsWithElse)
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

TEST(v123BreakElseIfWithCatch)
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

TEST(v123IndentBracketsInComment)
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

TEST(v123BreakBracketsWithEmptyLine)
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

TEST(v123UnmatchedBracketsInPreprocessor1)
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

TEST(v123UnmatchedBracketsInPreprocessor2)
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

TEST(v123DeleteLinesAfterPreprocessor)
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

TEST(v123CSharpNullableTypes)
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

TEST(v123CSharpQuestionQuestionOperator)
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

TEST(v123CSharpNonGenericDefault)
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

TEST(v123BreakBlocksWithPreprocessor)
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

TEST(v123CSharpBreakBlocksWithKeepOneLineBlocks)
{
	// C# do NOT break before a block with keep one line blocks
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public bool Foo { get { return Count > 0; } }\n"
		"}\n";

	char options[] = "break-blocks, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v123EnumDefinitionPadding)
{
	// enum should space pad before the definition
	// NOTE: the enum is an array type bracket
	char textIn[] =
		"\n// should space pad after the closing bracket\n"
		"typedef enum tagSQObjectType{\n"
		"    OT_INTEGER = (_RT_INTEGER),\n"
		"    OT_BOOL =    (_RT_BOOL),\n"
		"}SQObjectType;\n"
		"\n"
		"// should NOT space pad before the closing semi-colon\n"
		"typedef enum tagSQObjectType{\n"
		"    OT_INTEGER = (_RT_INTEGER),\n"
		"    OT_BOOL =    (_RT_BOOL),\n"
		"};";
	char text[] =
		"\n// should space pad after the closing bracket\n"
		"typedef enum tagSQObjectType {\n"
		"    OT_INTEGER = (_RT_INTEGER),\n"
		"    OT_BOOL =    (_RT_BOOL),\n"
		"} SQObjectType;\n"
		"\n"
		"// should NOT space pad before the closing semi-colon\n"
		"typedef enum tagSQObjectType {\n"
		"    OT_INTEGER = (_RT_INTEGER),\n"
		"    OT_BOOL =    (_RT_BOOL),\n"
		"};";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(v123UnionDefinitionPadding)
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

TEST(v123StructDefinitionPadding)
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

//----------------------------------------------------------------------------
// AStyle Virgin Line Tests
//----------------------------------------------------------------------------

TEST(VirginLine)
{
	// test bracket on second line
	// linux bracket should not attach
	char text[] =
		"void Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=linux";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Input Error Tests
// Test error reporting conditions in astyle_main
//----------------------------------------------------------------------------

TEST(NullErrorHandlerPointer)
{
	// test error handling for NULL error handler pointer
	// this cannot call the error handler, check only for NULL return
	// memory has NOT been allocated for this error
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, NULL, memoryAlloc);
	CHECK(textOut == NULL);
}

TEST(NullPointerToSource)
{
	// test error handling for NULL pointer to source
	// memory has NOT been allocated for this error
	char options[] = "";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(NULL, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut == NULL);
}

TEST(NullPointerToOptions)
{
	// test error handling for NULL pointer to options
	// memory has NOT been allocated for this error
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, NULL, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut == NULL);
}

TEST(NullPointerToMemoryAlloc)
{
	// test error handling for NULL memory allocation pointer
	// memory has NOT been allocated for this error
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, NULL);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut == NULL);
}

TEST(InvalidOption)
{
	// test error handling for an invalid option
	// memory HAS been allocated for this error
	// the source will be formatted without the option
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	bar();\n"
		"}\n";
	char options[] = "invalid-option, indent=tab";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(textIn, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Macro formatting
// Test macros recognized by AStyle
//----------------------------------------------------------------------------

TEST(wxWidgetsEventHandler)
{
	// wxWidgets event handler should be indented
	char text[] =
		"\nBEGIN_EVENT_TABLE(JP5Frm,wxFrame)\n"
		"    EVT_CLOSE(JP5Frm::WindowClose)\n"
		"    EVT_PAINT(JP5Frm::WindowPaint)\n"
		"    EVT_MENU(ID_MENU_FILE_OPEN, JP5Frm::MenuFileOpen)\n"
		"    EVT_MENU(ID_MENU_FILE_EXIT, JP5Frm::MenuFileExit)\n"
		"END_EVENT_TABLE()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(wxWidgetsEventHandlerNonIndentComment)
{
	// wxWidgets event handler should be indented
	// but not the comments
	char text[] =
		"\nBEGIN_EVENT_TABLE(JP5Frm,wxFrame)\n"
		"//    EVT_CLOSE(JP5Frm::WindowClose)\n"
		"    EVT_PAINT(JP5Frm::WindowPaint)\n"
		"    EVT_MENU(ID_MENU_FILE_OPEN, JP5Frm::MenuFileOpen)\n"
		"//    EVT_MENU(ID_MENU_FILE_EXIT, JP5Frm::MenuFileExit)\n"
		"END_EVENT_TABLE()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(MfcMessageMap)
{
	// MFC message map should be indented
	char text[] =
		"\nBEGIN_MESSAGE_MAP(CMainJPWnd, CFrameWnd)\n"
		"    ON_WM_CLOSE()\n"
		"    ON_WM_PAINT()\n"
		"    ON_COMMAND(IDM_ABOUT, OnAbout)\n"
		"    ON_COMMAND(IDM_EXIT,  OnExit)\n"
		"END_MESSAGE_MAP()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle short options used only by console
// should get an error unless they have been duplicated by another option
//----------------------------------------------------------------------------

TEST(SuffixNoneShort)
{
	// test suffix=none short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-n";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(Recursive1Short)
{
	// test recursive short option1
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-r";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(Recursive2Short)
{
	// test recursive short option2
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-R";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(ErrorsToStdoutShort)
{
	// test errors-to-stdout short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-X";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(PreserveDateShort)
{
	// test preserve-date short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-Z";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(VerboseShort)
{
	// test verbose short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-v";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(FormattedShort)
{
	// test formatted short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-Q";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(QuietShort)
{
	// test preserve-date short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-q";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(VersionShort)
{
	// test version short option
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-V";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(Help1Short)
{
	// test help short option1
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-h";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

TEST(Help2Short)
{
	// test help short option2
	// should get an error unless it has been duplicated by another option
	// the source will be formatted without the option
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "-?";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	CHECK_EQUAL(errorsIn + 1, errorsOut);
	CHECK(textOut != NULL);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Quotes
//----------------------------------------------------------------------------

TEST(Quote)
{
	// test quotes
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    char* quote = \"this	is a quote \\\n"
		"  	quote	continuation  \\\n"
		"	quote continuation\";\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(QuoteSingle)
{
	// test single quotes
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (ch == \'\\r\')\n"
		"        eolWindows++;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(QuoteVerbatim1)
{
	// test C# verbatim quotes
	// whitespace should not change
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    string program = @\"using System;\n"
		"class Test {\n"
		"  void M(DerivedClass d) {\n"
		"    \n"
		"  }\n"
		"}\n"
		"class BaseClass<T> {\n"
		"	public T value;\n"
		"}\n"
		"class DerivedClass : BaseClass<string> {\n"
		"			\n"
		"}\n"
		";\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(QuoteVerbatim2)
{
	// test C# verbatim quotes with """" and ""
	// whitespace should not change
	char text[] =
		"\nconst string CodeEmptyResourceSetName = @\"using System.Resources;\n"
		"class A {\n"
		"    void B()\n"
		"    {\n"
		"        ResourceManager mgr = new ResourceManager(\"\"\"\", GetAssembly());\n"
		"        mgr.GetString(\"\"TestKey\"\");\n"
		"    }\n"
		"}\n"
		";\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(QuoteEmpty)
{
	// test C# empty quotes with """"
	// whitespace should not change
	char text[] =
		"\npublic static string GetString(string key)\n"
		"{\n"
		"    return \"\"\"\";\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(QuoteMisc)
{
	// test C# strange looking quotes with """
	// whitespace should not change
	char text[] =
		"\npublic void TestString()\n"
		"{\n"
		"    CheckToken(@\"@\"\"-->\"\"\"\"<--\"\"\", @\"-->\"\"<--\");\n"
		"    CheckToken(@\"\"\"-->\\\"\"<--\"\"\", \"-->\\\"<--\");\n"
		"\n"
		"    CheckToken(@\"\"\"\\U00000041\"\"\", \"\\U00000041\");\n"
		"    CheckToken(@\"\"\"\\U00010041\"\"\", \"\\U00010041\");\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Enum
//----------------------------------------------------------------------------

TEST(EnumNamespace1)
{
	// test indent of enum in a namespace
	char text[] =
		"\nnamespace fooName\n"
		"{\n"
		"enum dStyle\n"
		"{\n"
		"    OK = 0,\n"
		"    YES_NO,\n"
		"};\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumNamespace2)
{
	// test indent of enum in a namespace
	// with in-statement indent
	char text[] =
		"\nnamespace fooName\n"
		"{\n"
		"enum dStyle { OK = 0,\n"
		"              YES_NO,\n"
		"            };\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumNamespaceIndent1)
{
	// test indent of enum in an indented namespace
	char text[] =
		"\nnamespace fooName\n"
		"{\n"
		"    enum dStyle\n"
		"    {\n"
		"        OK = 0,\n"
		"        YES_NO,\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumNamespaceIndent2)
{
	// test indent of enum in an indented namespace
	// with in-statement indent
	char text[] =
		"\nnamespace fooName\n"
		"{\n"
		"    enum dStyle { OK = 0,\n"
		"                  YES_NO,\n"
		"                };\n"
		"}\n";
	char options[] = "indent-namespaces";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumClassTypeSafe)
{
	// type safe enum class should be formatted as an enum
	char text[] =
		"\nenum class Day\n"
		"{\n"
		"    NoDays=0,\n"
		"    Sunday=1,\n"
		"    Monday,\n"
		"    FirstDay = Day::Sunday\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumClass1)
{
	// test indent of enum in a class
	char text[] =
		"\nclass fooClass\n"
		"{\n"
		"public:\n"
		"    enum dStyle\n"
		"    {\n"
		"        OK = 0,\n"
		"        YES_NO,\n"
		"    };\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumClass2)
{
	// test indent of enum in a class
	// with in-statement indent
	char text[] =
		"\nclass fooClass\n"
		"{\n"
		"public:\n"
		"    enum dStyle { OK = 0,\n"
		"                  YES_NO,\n"
		"                };\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumClassIndent1)
{
	// test indent of enum in an indented class
	char text[] =
		"\nclass fooClass\n"
		"{\n"
		"    public:\n"
		"        enum dStyle\n"
		"        {\n"
		"            OK = 0,\n"
		"            YES_NO,\n"
		"        };\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumClassIndent2)
{
	// test indent of enum in an indented class
	// with in-statement indent
	char text[] =
		"\nclass fooClass\n"
		"{\n"
		"    public:\n"
		"        enum dStyle { OK = 0,\n"
		"                      YES_NO,\n"
		"                    };\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumClassIndent3)
{
	// test indent of enum in an indented class
	// within a #else preprocessor
	char text[] =
		"\n#if VERSION(2)\n"
		"#else\n"
		"class fooClass\n"
		"{\n"
		"    public:\n"
		"        enum wxPaneState\n"
		"        {\n"
		"            optionFloating = 1 << 0,\n"
		"            optionHidden   = 1 << 1,\n"
		"        };\n"
		"};\n"
		"#endif\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(EnumJava)
{
	// test indent of java enum
	char text[] =
		"\npublic enum KeyboardCommand\n"
		"{   NONE,\n"
		"    TAB_OUT_FORWARD,\n"
		"    TAB_OUT_BACK\n"
		"}\n";
	char options[] = "mode=java";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Struct
//----------------------------------------------------------------------------

TEST(StructBreak)
{
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

TEST(StructAttach)
{
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

TEST(StructHorstmann)
{
	// struct with attached brackets
	char text[] =
		"\nstruct\n"
		"{   const char *name;\n"
		"    int id;\n"
		"} idmTable[] =\n"
		"{   {\"IDM_MRUFILE\", IDM_MRUFILE},\n"
		"    {\"IDM_TOOLS\",   IDM_TOOLS},\n"
		"};\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Preprocessor
//----------------------------------------------------------------------------

TEST(PreprocessorCommandType)
{
	// check indentation
	// correctly identifying as a COMMND_TYPE bracket
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"#if wxUSE_UNICODE\n"
		"        if (c < 128)\n"
		"#else\n"
		"        if (c < 256)\n"
		"#endif\n"
		"        {\n"
		"            w += 1000;\n"
		"        }\n"
		"        else\n"
		"        {\n"
		"            w += 2000;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorMissingOpener)
{
	// #else with missing #if
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int foo = 1;\n"
		"#else\n"
		"    int foo = 2;\n"
		"#endif\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorWxWidgetsMacro)
{
	// preprocessor should NOT be indented
	char text[] =
		"\nBEGIN_EVENT_TABLE(ClassWizardDlg, wxDialog)\n"
		"    EVT_BUTTON(XRCID(\"btnCommonDir\"), ClassWizardDlg::OnCommonDirClick)\n"
		"#ifdef LOGGING\n"
		"    EVT_CHECKBOX(XRCID(\"chkLowerCase\"), ClassWizardDlg::OnLowerCaseClick)\n"
		"    EVT_BUTTON(XRCID(\"btnIncludeDir\"), ClassWizardDlg::OnIncludeDirClick)\n"
		"#endif\n"
		"    EVT_BUTTON(XRCID(\"btnImplDir\"), ClassWizardDlg::OnImplDirClick)\n"
		"END_EVENT_TABLE()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorArrayType)
{
	// check indentation
	// correctly identifying as an ARRAY_TYPE bracket
	char text[] =
		"\nstatic SQRegFunction base_funcs[] = {\n"
		"    {_SC(\"seterrorhandler\"),base_seterrorhandler,2, NULL},\n"
		"    {_SC(\"setdebughook\"),base_setdebughook,2, NULL},\n"
		"#ifndef NO_GARBAGE_COLLECTOR\n"
		"    {_SC(\"collectgarbage\"),base_collectgarbage,1, NULL},\n"
		"#endif\n"
		"    {0,0}\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorArrayMissingOpener)
{
	// array #else with missing #if
	char text[] =
		"\nchar *section_list[] =\n"
		"{\n"
		"// #ifdef Q_OS_SOLARIS\n"
		"    \"1B\", \"SunOS/BSD\",\n"
		"#else\n"
		"    \"2\", \"System Calls\",\n"
		"#endif\n"
		"    NULL, \"Misc. Reference\",\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorArrayHorstmannBreak)
{
	// check broken brackets to horstmann
	// should NOT run-in a preprocessor directive
	char text[] =
		"\nchar *section_list[] =\n"
		"{\n"
		"#ifdef Q_OS_SOLARIS\n"
		"    // for Solaris\n"
		"    \"1B\", \"SunOS/BSD\",\n"
		"#else\n"
		"    // Other OS\n"
		"    \"2\", \"System Calls\",\n"
		"#endif\n"
		"};\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorArrayHorstmannAttach)
{
	// check attached brackets to horstmann
	// should NOT run-in a preprocessor directive
	char textIn[] =
		"\nchar *section_list[] = {\n"
		"#ifdef Q_OS_SOLARIS\n"
		"    // for Solaris\n"
		"    \"1B\", \"SunOS/BSD\",\n"
		"#else\n"
		"    // Other OS\n"
		"    \"2\", \"System Calls\",\n"
		"#endif\n"
		"};\n";
	char text[] =
		"\nchar *section_list[] =\n"
		"{\n"
		"#ifdef Q_OS_SOLARIS\n"
		"    // for Solaris\n"
		"    \"1B\", \"SunOS/BSD\",\n"
		"#else\n"
		"    // Other OS\n"
		"    \"2\", \"System Calls\",\n"
		"#endif\n"
		"};\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(PreprocessorArrayHorstmannHorstmann)
{
	// check horstmann brackets to horstmann
	// should NOT run-in a preprocessor directive
	char text[] =
		"\nchar *section_list[] =\n"
		"{\n"
		"#ifdef Q_OS_SOLARIS\n"
		"    // for Solaris\n"
		"    \"1B\", \"SunOS/BSD\",\n"
		"#else\n"
		"    // Other OS\n"
		"    \"2\", \"System Calls\",\n"
		"#endif\n"
		"};\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Comments
//----------------------------------------------------------------------------

TEST(CommentNoneNamespaceClassIndentNone)
{
	// comments should indent with namespaces and classes
	// brackets=none with default brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass\n"
		"    {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNoneNamespaceClassIndentBreak)
{
	// comments should indent with namespaces and classes
	// brackets=none with broken brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass\n"
		"    {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNoneNamespaceClassIndentAttach)
{
	// comments should indent with namespaces and classes
	// brackets=none with attached brackets
	char textIn[] =
		"\nnamespace FooName {\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass {\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo() {\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName {\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo() {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNoneNamespaceClassIndentHorstmann)
{
	// comments should indent with namespaces and classes
	// brackets=none with with horstmann brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{/*\n"
		"  * comment2\n"
		"  */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {   /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentBreakNamespaceClassIndentBreak)
{
	// comments should indent with namespaces and classes
	// brackets=break with broken brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass\n"
		"    {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=break, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentBreakNamespaceClassIndentAttach)
{
	// comments should indent with namespaces and classes
	// brackets=break with attached brackets
	char textIn[] =
		"\nnamespace FooName {\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass {\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo() {\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass\n"
		"    {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=break, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentBreakNamespaceClassIndentHorstmann)
{
	// comments should indent with namespaces and classes
	// brackets=break with horstmann brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{/*\n"
		"  * comment2\n"
		"  */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=break, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentAttachNamespaceClassIndentBreak)
{
	// comments should indent with namespaces and classes
	// brackets=attach with broken brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName {\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo() {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=attach, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentAttachNamespaceClassIndentAttach)
{
	// comments should indent with namespaces and classes
	// brackets=attach with attached brackets
	char textIn[] =
		"\nnamespace FooName {\n"
		"/*\n"
		" * comment0\n"
		" */\n"
		"class FooClass {\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo() {\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName {\n"
		"    /*\n"
		"     * comment0\n"
		"     */\n"
		"    class FooClass {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo() {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=attach, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentAttachNamespaceClassIndentHorstmann)
{
	// comments should indent with namespaces and classes
	// brackets=attach with horstmann brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{/*\n"
		"  * comment2\n"
		"  */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName {\n"
		"    class FooClass {\n"
		"        public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo() {\n"
		"                /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=attach, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentHorstmannNamespaceClassIndentBreak)
{
	// comments should indent with namespaces and classes
	// brackets=horstmann with broken brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    {   public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {   /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=horstmann, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentHorstmannNamespaceClassIndentAttach)
{
	// comments should indent with namespaces and classes
	// brackets=horstmann with attached brackets
	char textIn[] =
		"\nnamespace FooName {\n"
		"class FooClass {\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo() {\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    {   public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {   /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=horstmann, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentHorstmannNamespaceClassIndentHorstmann)
{
	// comments should indent with namespaces and classes
	// brackets=horstmann with horstmann brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"{\n"
		"public:\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"void foo()\n"
		"{/*\n"
		"  * comment2\n"
		"  */\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    {   public:\n"
		"            /*\n"
		"             * comment1\n"
		"             */\n"
		"            void foo()\n"
		"            {   /*\n"
		"                 * comment2\n"
		"                 */\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "brackets=horstmann, indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(CommentNamespaceMisc1)
{
	// comments should indent with namespaces
	// comments precede the brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"{\n"
		"public:\n"
		"void foo()\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"{\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    {\n"
		"    public:\n"
		"        void foo()\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        {\n"
		"        }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNamespaceClassMisc2)
{
	// comments should indent with namespaces and classes
	// comments precede the brackets
	char textIn[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"{\n"
		"public:\n"
		"void foo()\n"
		"/*\n"
		" * comment2\n"
		" */\n"
		"{\n"
		"}\n"
		"};\n"
		"}\n";
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    {\n"
		"        public:\n"
		"            void foo()\n"
		"            /*\n"
		"             * comment2\n"
		"             */\n"
		"            {\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces, indent-classes";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNestedClassMisc3)
{
	// comments should indent with classes
	// comments precede the brackets
	char text[] =
		"\nclass A\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"{\n"
		"public:\n"
		"    int foo1;\n"
		"    class B\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    {\n"
		"    public:\n"
		"        int foo2;\n"
		"        class C\n"
		"        /*\n"
		"         * comment1\n"
		"         */\n"
		"        {\n"
		"        public:\n"
		"        };\n"
		"    };\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNestedClassMisc4)
{
	// comments should indent with classes
	// comments precede the brackets in indented classes
	char text[] =
		"\nclass A\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"{\n"
		"    public:\n"
		"        int foo1;\n"
		"        class B\n"
		"        /*\n"
		"         * comment1\n"
		"         */\n"
		"        {\n"
		"            public:\n"
		"                int foo2;\n"
		"                class C\n"
		"                /*\n"
		"                 * comment1\n"
		"                 */\n"
		"                {\n"
		"                    public:\n"
		"                };\n"
		"        };\n"
		"};\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNamespaceClassMisc5)
{
	// comments should indent with classes with inheritance
	// comments precede the brackets
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"class FooClass\n"
		"    : public FooBase\n"
		"/*\n"
		" * comment1\n"
		" */\n"
		"{\n"
		"public:\n"
		"    void foo()\n"
		"    /*\n"
		"     * comment2\n"
		"     */\n"
		"    {\n"
		"    }\n"
		"};\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentNamespaceClassMisc6)
{
	// comments should indent with classes with inheritance
	// comments precede the brackets
	char text[] =
		"\nnamespace FooName\n"
		"{\n"
		"    class FooClass\n"
		"        : public FooBase\n"
		"    /*\n"
		"     * comment1\n"
		"     */\n"
		"    {\n"
		"    public:\n"
		"        void foo()\n"
		"        /*\n"
		"         * comment2\n"
		"         */\n"
		"        {\n"
		"        }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(CommentBeforeStatementMisc7)
{
	// comments before a statement should not be broken
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    if (isBar) {\n"
		"        /*bool result =*/ Bar();\n"
		"        return;\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Continuation Lines
//----------------------------------------------------------------------------

TEST(ContinuationNoneBreak)
{
	// continuation lines
	// brackets=none and input of broken brackets
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationNoneAttach)
{
	// continuation lines
	// brackets=none and input of attached brackets
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo1()) {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2()) {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationNoneHorstmann)
{
	// continuation lines
	// brackets=none and input of horstmann brackets
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo1())\n"
		"    {   wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {   wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationBreakBreak)
{
	// continuation lines
	// brackets=break and input of broken brackets
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationBreakAttach)
{
	// continuation lines
	// brackets=break and input of attached brackets
	char textIn[] =
		"\nvoid foo() {\n"
		"    if (isFoo1()) {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2()) {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationBreakHorstmann)
{
	// continuation lines
	// brackets=break and input of horstmann brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{   if (isFoo1())\n"
		"    {   wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {   wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationAttachBreak)
{
	// continuation lines
	// brackets=attach and input of broken brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo1()) {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2()) {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationAttachAttach)
{
	// continuation lines
	// brackets=attach and input of attached brackets
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo1()) {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2()) {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationAttachHorstmann)
{
	// continuation lines
	// brackets=attach and input of horstmann brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{   if (isFoo1())\n"
		"    {   wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {   wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    if (isFoo1()) {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2()) {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationHorstmannBreak)
{
	// continuation lines
	// brackets=horstmann and input of broken brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo1())\n"
		"    {   wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {   wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationHorstmannAttach)
{
	// continuation lines
	// brackets=horstmann and input of attached brackets
	char textIn[] =
		"\nvoid foo() {\n"
		"    if (isFoo1()) {\n"
		"        wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2()) {\n"
		"        wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo1())\n"
		"    {   wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {   wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationHorstmannHorstmann)
{
	// continuation lines
	// brackets=horstmann and input of horstmann brackets
	char text[] =
		"\nvoid foo()\n"
		"{   if (isFoo1())\n"
		"    {   wxPoint bar(Xpos,\n"
		"                    Ypos);\n"
		"    }\n"
		"    if (isFoo2())\n"
		"    {   wxPoint bar ( Xpos,\n"
		"                      Ypos);\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=horstmann";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}


TEST(ContinuationInlineTab1)
{
	// continuation lines
	// with inline tabs

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPointx	barx	( Xpos,\n"
		"                              Ypos );\n"
		"\n"
		"        wxPointxx	barxx	( Xpos,\n"
		"                              Ypos );\n"
		"\n"
		"        wxPointxxx	barxxx	( Xpos,\n"
		"                              Ypos );\n"
		"\n"
		"        wxPointxxxx	barxxxx	( Xpos,\n"
		"                              Ypos );\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationInlineTab2)
{
	// continuation lines with tabs after the paren
	// with inline tabs
	// NOTE: this all aligns when the quotes are removed
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo1())\n"
		"    {\n"
		"        wxPoint bar (	Xpos,\n"
		"                        Ypos );\n"
		"\n"
		"        wxPoint barx (	Xpos,\n"
		"                        Ypos );\n"
		"\n"
		"        wxPoint barxx (	Xpos,\n"
		"                        Ypos );\n"
		"\n"
		"        wxPoint barxxx (	Xpos,\n"
		"                            Ypos );\n"
		"\n"
		"        wxPoint barxx (		Xpos,\n"
		"                            Ypos );\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Continuation Lines with Tabs
//----------------------------------------------------------------------------

TEST(ContinuationTabNoneBreak)
{
	// continuation lines with tabs
	// brackets=none and input of broken brackets
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabNoneAttach)
{
	// continuation lines with tabs
	// brackets=none and input of attached brackets
	char text[] =
		"\nvoid foo() {\n"
		"	if (isFoo1()) {\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2()) {\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabNoneHorstmann)
{
	// continuation lines with tabs
	// brackets=none and input of horstmann brackets
	char text[] =
		"\nvoid foo()\n"
		"{	if (isFoo1())\n"
		"	{	wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{	wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabBreakBreak)
{
	// continuation lines with tabs
	// brackets=break and input of broken brackets
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabBreakAttach)
{
	// continuation lines with tabs
	// brackets=break and input of attached brackets
	char textIn[] =
		"\nvoid foo() {\n"
		"	if (isFoo1()) {\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2()) {\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabBreakHorstmann)
{
	// continuation lines with tabs
	// brackets=break and input of horstmann brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{	if (isFoo1())\n"
		"	{	wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{	wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=break, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabAttachBreak)
{
	// continuation lines with tabs
	// brackets=attach and input of broken brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"	if (isFoo1()) {\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2()) {\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabAttachAttach)
{
	// continuation lines with tabs
	// brackets=attach and input of attached brackets
	char text[] =
		"\nvoid foo() {\n"
		"	if (isFoo1()) {\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2()) {\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabAttachHorstmann)
{
	// continuation lines with tabs
	// brackets=attach and input of horstmann brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{	if (isFoo1())\n"
		"	{	wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{	wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"	if (isFoo1()) {\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2()) {\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=attach, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabHorstmannBreak)
{
	// continuation lines with tabs
	// brackets=horstmann and input of broken brackets
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{	if (isFoo1())\n"
		"	{	wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{	wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabHorstmannAttach)
{
	// continuation lines with tabs
	// brackets=horstmann and input of attached brackets
	char textIn[] =
		"\nvoid foo() {\n"
		"	if (isFoo1()) {\n"
		"		wxPoint bar(Xpos,\n"
		"	            Ypos);\n"
		"	}\n"
		"	if (isFoo2()) {\n"
		"		wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{	if (isFoo1())\n"
		"	{	wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{	wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabHorstmannHorstmann)
{
	// continuation lines with tabs
	// brackets=horstmann and input of horstmann brackets
	char text[] =
		"\nvoid foo()\n"
		"{	if (isFoo1())\n"
		"	{	wxPoint bar(Xpos,\n"
		"		            Ypos);\n"
		"	}\n"
		"	if (isFoo2())\n"
		"	{	wxPoint bar ( Xpos,\n"
		"		              Ypos);\n"
		"	}\n"
		"}\n";
	char options[] = "brackets=horstmann, indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabInlineTab1)
{
	// continuation lines with tabs
	// with inline tabs
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPointx	barx	( Xpos,\n"
		"		                      Ypos );\n"
		"\n"
		"		wxPointxx	barxx	( Xpos,\n"
		"		                      Ypos );\n"
		"\n"
		"		wxPointxxx	barxxx	( Xpos,\n"
		"		                      Ypos );\n"
		"\n"
		"		wxPointxxxx	barxxxx	( Xpos,\n"
		"		                      Ypos );\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTabInlineTab2)
{
	// continuation lines with tabs
	// with inline tabs after the paren
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar (	Xpos,\n"
		"		                Ypos );\n"
		"\n"
		"		wxPoint barx (	Xpos,\n"
		"		                Ypos );\n"
		"\n"
		"		wxPoint barxx (	Xpos,\n"
		"		                Ypos );\n"
		"\n"
		"		wxPoint barxxx (	Xpos,\n"
		"		                    Ypos );\n"
		"\n"
		"		wxPoint barxx (		Xpos,\n"
		"		                    Ypos );\n"
		"	}\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationForceTabInlineTab1)
{
	// continuation lines with force tabs
	// with inline tabs

	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPointx	barx	( Xpos,\n"
		"							  Ypos );\n"
		"\n"
		"		wxPointxx	barxx	( Xpos,\n"
		"							  Ypos );\n"
		"\n"
		"		wxPointxxx	barxxx	( Xpos,\n"
		"							  Ypos );\n"
		"\n"
		"		wxPointxxxx	barxxxx	( Xpos,\n"
		"							  Ypos );\n"
		"	}\n"
		"}\n";
	char options[] = "indent=force-tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(ContinuationForceTabInlineTab2)
{
	// continuation lines with force tabs
	// with inline tabs after the paren
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"	if (isFoo1())\n"
		"	{\n"
		"		wxPoint bar (	Xpos,\n"
		"						Ypos );\n"
		"\n"
		"		wxPoint barx (	Xpos,\n"
		"						Ypos );\n"
		"\n"
		"		wxPoint barxx (	Xpos,\n"
		"						Ypos );\n"
		"\n"
		"		wxPoint barxxx (	Xpos,\n"
		"							Ypos );\n"
		"\n"
		"		wxPoint barxx (		Xpos,\n"
		"							Ypos );\n"
		"	}\n"
		"}\n";
	char options[] = "indent=force-tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// C++ operators << and >>
//----------------------------------------------------------------------------

TEST(AlignmentOperatorCout)
{
	// Alignment of the operator<<
	char text[] =
		"\nvoid foo(std::ostream& os)\n"
		"{\n"
		"    os << \"Foo\"\n"
		"       << \"Bar\"\n"
		"       << std::endl;\n"
		"\n"
		"    cout << \"Foo\"\n"
		"         << \"Bar\"\n"
		"         << std::endl;\n"
		"\n"
		"    helpText << wxT(\"text1\")\n"
		"             << wxT(\"text2\")\n"
		"             << wxT(\"text3\");\n"
		"\n"
		"    int i = 0;\n"
		"    if (i)\n"
		"        i = 0;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(AlignmentOperatorCin)
{
	// Alignment of the operator<<
	char text[] =
		"\nvoid foo(std::istream& someinputstream)\n"
		"{\n"
		"    someinputstream >> \"Foo\"\n"
		"                    >> \"Bar\"\n"
		"                    >> std::endl;\n"
		"\n"
		"    cin >> \"Foo\"\n"
		"        >> \"Bar\"\n"
		"        >> std::endl;\n"
		"\n"
		"    int i = 0;\n"
		"    if (i)\n"
		"        i = 0;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle SQL
//----------------------------------------------------------------------------

TEST(SQL)
{
	// standard SQL statements
	char text[] =
		"\nEXEC SQL INCLUDE sqlca;\n"
		"\n"
		"void Connect()\n"
		"{\n"
		"    EXEC SQL BEGIN DECLARE SECTION;\n"
		"        char userid[64];\n"
		"        char password[64];\n"
		"        char *DBname = \"@ug\";\n"
		"    EXEC SQL END DECLARE SECTION;\n"
		"\n"
		"    EXEC SQL CONECT :userid IDENTIFIED BY :password;\n"
		"}\n"
		"\n"
		"void Insert_Branch()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"             INTO   branch (branch_id, branch_name, branch_addr,\n"
		"                            branch_city, branch_phone)\n"
		"             VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"\n"
		"    EXEC SQL COMMIT WORK;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLComment)
{
	// SQL statements with comment
	char text[] =
		"\nvoid Insert_Branch()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"             /*\n"
		"              *\n"
		"              */\n"
		"             INTO   branch (branch_id, branch_name, branch_addr,\n"
		"                            branch_city, branch_phone)\n"
		"             VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLLineComment)
{
	// SQL statements with line comment
	char text[] =
		"\nvoid Insert_Branch()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"             //\n"
		"             INTO   branch (branch_id, branch_name, branch_addr,\n"
		"                            branch_city, branch_phone)\n"
		"             VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLNonIndentingTabs)
{
	// SQL statements with non-indenting tabs
	char textIn[] =
		"\nvoid Insert_Branch()\n"
		"{\n"
		"  	 	  EXEC SQL INSERT\n"
		"	           INTO   branch (branch_id, branch_name, branch_addr,\n"
		"	 	  	   		  branch_city, branch_phone)\n"
		"    	       VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char text[] =
		"\nvoid Insert_Branch()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"         INTO   branch (branch_id, branch_name, branch_addr,\n"
		"                branch_city, branch_phone)\n"
		"         VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLNonHangingIndent)
{
	// SQL statements with a non-hanging indent
	// should format as a block
	char textIn[] =
		"\nvoid Insert_Branch()\n"
		"{\n"
		"          EXEC SQL INSERT\n"
		"      INTO   branch (branch_id, branch_name, branch_addr,\n"
		"             branch_city, branch_phone)\n"
		"      VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char text[] =
		"\nvoid Insert_Branch()\n"
		"{\n"
		"    EXEC SQL INSERT\n"
		"    INTO   branch (branch_id, branch_name, branch_addr,\n"
		"       branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLLowerCaseExtraSpaces)
{
	// SQL statements in lower case with extra spaces
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"      exec  sql   begin   declare   section;\n"
		"      char userid[64];\n"
		"      char password[64];\n"
		"      exeC  SqL   End   Declare  Section;\n"
		"\n"
		"      Exec   Sql SELECT BLP_PIN_TYPE\n"
		"                 INTO :m_Pin_Type;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    exec  sql   begin   declare   section;\n"
		"        char userid[64];\n"
		"        char password[64];\n"
		"    exeC  SqL   End   Declare  Section;\n"
		"\n"
		"    Exec   Sql SELECT BLP_PIN_TYPE\n"
		"               INTO :m_Pin_Type;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLEndOfLine)
{
	// SQL statements with EXEC SQL at end of line
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    EXEC SQL\n"
		"         SELECT BLP_PIN_TYPE\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLBreakAfterSemi)
{
	// SQL statements should break line after the semi-colon
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    {\n"
		"        EXEC SQL SELECT BLP_PIN_TYPE,\n"
		"             INTO :m_Pin_Type;}\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    {\n"
		"        EXEC SQL SELECT BLP_PIN_TYPE,\n"
		"             INTO :m_Pin_Type;\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLSwitch)
{
	// SQL statements in switch
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        EXEC SQL SELECT BLP_PIN_TYPE\n"
		"             INTO :m_Pin_Type;\n"
		"\n"
		"    case 2:\n"
		"    {\n"
		"        EXEC SQL SELECT BLP_PIN_TYPE\n"
		"             INTO :m_Pin_Type;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLSwitchIndentCase)
{
	// SQL statements in switch with indent case
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    switch (foo)\n"
		"    {\n"
		"    case 1:\n"
		"        EXEC SQL SELECT BLP_PIN_TYPE\n"
		"             INTO :m_Pin_Type;\n"
		"\n"
		"    case 2:\n"
		"        {\n"
		"            EXEC SQL SELECT BLP_PIN_TYPE\n"
		"                 INTO :m_Pin_Type;\n"
		"        }\n"
		"    }\n"
		"}\n";
	char options[] = "indent-cases";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}

TEST(SQLBracketsHorstmann)
{
	// SQL statements in horstmann brackets
	char text[] =
		"\nvoid foo()\n"
		"{   EXEC SQL SELECT BLP_PIN_TYPE\n"
		"             INTO :m_Pin_Type;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	CHECK_EQUAL(text, textOut);
	delete [] textOut;
}