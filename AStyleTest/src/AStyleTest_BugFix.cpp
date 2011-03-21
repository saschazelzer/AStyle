//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//----------------------------------------------------------------------------
// AStyle version 2.02 TEST functions
//----------------------------------------------------------------------------

	TEST(BugFix_V202, BreakBlocks_ConstVariableFollowsHeader)
{
	// With break-blocks where a "const" variable follows a header, the lines
	// continued to be inserted. There should not be an empty line between the
	// "const int" and "int b" statements.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (true) { x = 1;}\n"
		"    const int a = bar();\n"
		"    int b = baz();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (true) {\n"
		"        x = 1;\n"
		"    }\n"
		"\n"
		"    const int a = bar();\n"
		"    int b = baz();\n"
		"}";
	char options[] = "break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
	}

TEST(BugFix_V202, RunInBrackets_ColonIdentification)
{
	// With run-in brackets when using indent-namespaces and indent-classes with a class modifier
	// on the same line as the class opening bracket resulted in failure to recognize the class indent.
	// This was a problem only when indent-labels was also used.
	char text[] =
		"\nnamespace\n"
		"{\n"
		"    class wxsNotebookExtra\n"
		"    {   public:\n"				// this line is the problem
		"            void OnEnumProperties(long Flags)\n"
		"            {   WXS_SHORT_STRING(wxsNotebookExtra);\n"
		"                WXS_BOOL(wxsNotebookExtra);\n"
		"            }\n"
		"    };\n"
		"}\n";
	char options[] = "indent-namespaces, indent-classes, indent-labels";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle version 2.01 TEST functions
//----------------------------------------------------------------------------

TEST(BugFix_V201, UnpadParen_PadParenIn)
{
	// Using both --unpad-paren and --pad-paren-in, becomes "if(( isFoo ) )"'
	// The leading paren was unpadded by the unpad-paren option.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if ((isFoo))\n"
		"        bar();\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if( ( isFoo ) )\n"
		"        bar();\n"
		"}";
	char options[] = "unpad-paren, pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, AlignOnBracket)
{
	// Test alignment on a bracket.
	char text[] =
		"\n[Browsable(true),\n"
		" DisplayName(\"Display ordinal\"),\n"
		" CustomAttribute(2)]\n"
		"public int DisplayOrdinal\n"
		"{\n"
		"//...\n"
		"}";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, TwoBracketsOnLine)
{
	// Test bracket alignment with two brackets on a line.
	char text[] =
		"\nvoid LoadToc()\n"
		"{\n"
		"    if (!IsLocalHelp) DataContext = null;\n"
		"    else DataContext = new[] { new TocEntry(-1)\n"
		"        {\n"
		"            Title = StringParser.Parse(\"${HelpLibraryRootTitle}\")\n"
		"        }\n"
		"    };\n"
		"}";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, WhitesmithSingleLineArray)
{
	// Test whitesmith style with a single line array.
	// The last single line entry should be correctly indented.
	char text[] =
		"\npublic void foo()\n"
		"    {\n"
		"    optionSet = new OptionSet ()\n"
		"        {\n"
		"            { 0, \"Assemblies\" },\n"
		"            { 1, \"Namespaces\" },\n"
		"            { 2, \"Help\" }\n"
		"        };\n"
		"    }";
	char options[] = "style=whitesmith, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, NotInTemplate)
{
	// The following statements were incorrectly flagged as templates.
	// This caused add-brackets to attach the opening bracket in the wrong place.
	// The function checkIfTemplateOpener() was corrected.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    for(k=31; k>=0; k-=2)\n"
		"    {\n"
		"        if(hi & (1 << (k >> 1))) y32u += 1 << k;\n"
		"        if(lo & (1 << (k >> 1))) y32u += 1 << (k-1);\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    for(k=31; k>=0; k-=2)\n"
		"    {\n"
		"        if(hi & (1 << (k >> 1))) {\n"
		"            y32u += 1 << k;\n"
		"        }\n"
		"        if(lo & (1 << (k >> 1))) {\n"
		"            y32u += 1 << (k-1);\n"
		"        }\n"
		"    }\n"
		"}";
	char options[] = "add-brackets";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, PointerOrReferenceAtEndOfLine)
{
	// Test align-pointer=name mis-aligining a pointer followed by a space at end of line.
	// The following test has a space after the * and & at end of line.
	// It was causing the * or & to be attached to the type on the first format.
	// Following formats moved it to the correct position.
	char textIn[] =
		"\nconst char * \n"
		"foo1() const\n"
		"{\n"
		"    return bar1;\n"
		"}\n"
		"\n"
		"const Path & \n"
		"foo2() const\n"
		"{\n"
		"    return bar2;\n"
		"}";
	char text[] =
		"\nconst char *\n"
		"foo1() const\n"
		"{\n"
		"    return bar1;\n"
		"}\n"
		"\n"
		"const Path &\n"
		"foo2() const\n"
		"{\n"
		"    return bar2;\n"
		"}";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, ExtraSpaceLineComment_PadParen_DeleteEmptyLines)
{
	// Test pad paren and delete empty lines options.
	// The line before the empty line was receiving an extra space after the semi-colon.
	// The empty line had to be followed by a line comment line for this to happen.
	char textIn[] =
		"\nvoid areaConstruction()\n"
		"{\n"
		"    QCOMPARE(toolViewsPrinter1, QString(\"\\\n"
		"toolview1.1.1 [ left ]\\\n"
		"toolview1.2.1 [ bottom ]\\\n"
		"\"));\n"
		"\n"
		"    // line comment follows empty line\n"
		"    AreaViewsPrinter viewsPrinter2;\n"
		"}";
	char text[] =
		"\nvoid areaConstruction()\n"
		"{\n"
		"    QCOMPARE ( toolViewsPrinter1, QString ( \"\\\n"
		"toolview1.1.1 [ left ]\\\n"
		"toolview1.2.1 [ bottom ]\\\n"
		"\" ) );\n"
		"    // line comment follows empty line\n"
		"    AreaViewsPrinter viewsPrinter2;\n"
		"}";
	char options[] = "pad-paren, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, ExtraSpaceComment_PadParen_DeleteEmptyLines)
{
	// Test pad paren and delete empty lines options.
	// The line before the empty line was receiving an extra space after the semi-colon.
	// The empty line had to be followed by a comment line for this to happen.
	char textIn[] =
		"\nvoid areaConstruction()\n"
		"{\n"
		"    QCOMPARE(toolViewsPrinter1, QString(\"\\\n"
		"toolview1.1.1 [ left ]\\\n"
		"toolview1.2.1 [ bottom ]\\\n"
		"\"));\n"
		"\n"
		"    /* comment follows empty line */\n"
		"    AreaViewsPrinter viewsPrinter2;\n"
		"}";
	char text[] =
		"\nvoid areaConstruction()\n"
		"{\n"
		"    QCOMPARE ( toolViewsPrinter1, QString ( \"\\\n"
		"toolview1.1.1 [ left ]\\\n"
		"toolview1.2.1 [ bottom ]\\\n"
		"\" ) );\n"
		"    /* comment follows empty line */\n"
		"    AreaViewsPrinter viewsPrinter2;\n"
		"}";
	char options[] = "pad-paren, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, Switch_FillEmptyLines_BreakBlocks)
{
	// Test fill empty lines and break blocks options in a switch.
	// This bug was caused by the ASEnhancer object not being called for new empty lines.
	// The line added after "return" should be correctly filled.
	char textIn[] =
		"\nbool foo()\n"
		"{\n"
		"    switch (type) {\n"
		"    case WindowDeactivate:\n"
		"    {\n"
		"        if (insideThis(object))\n"
		"            return false;\n"
		"        break();\n"
		"    }\n"
		"    }\n"
		"}";
	char text[] =
		"\nbool foo()\n"
		"{\n"
		"    switch (type) {\n"
		"    case WindowDeactivate:\n"
		"    {\n"
		"        if (insideThis(object))\n"
		"            return false;\n"
		"            \n"
		"        break();\n"
		"    }\n"
		"    }\n"
		"}";
	char options[] = "fill-empty-lines, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, AppendCharInsideCommentsPostPreprocessor)
{
	// An opening bracket should not be appended to a preprocessor statement.
	// This bug occurred only when comments followed the preprocessor.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"#if wxUSE_UXTHEME\n"
		"    if (isFoo)\n"
		"        bar1();\n"
		"    else\n"
		"#endif //wxUSE_UXTHEME\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid foo() {\n"
		"#if wxUSE_UXTHEME\n"
		"    if (isFoo)\n"
		"        bar1();\n"
		"    else\n"
		"#endif //wxUSE_UXTHEME\n"
		"    {\n"
		"        bar2();\n"
		"    }\n"
		"}";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SwitchBracketInPreprocessor1)
{
	// Test that the bracket before a preprocessor statement in a "switch" is recognized.
	// If enhance is called with the argument isInPreprocessor instead of isImmediatelyPostPreprocessor,
	// the preceeding bracket will not be recognized. This causes the "switch" statement closing
	// bracket to be incorrectly indented.
	char text[] =
		"\nvoid wxsListBox::OnBuildCreatingCode()\n"
		"{\n"
		"    switch(GetLanguage()) {\n"
		"    case wxsCPP: {\n"
		"        if(DefaultSelection == (int)i) {\n"
		"            Codef(ASetSelection));\n"
		"        }\n"
		"#if wxCHECK_VERSION(2, 9, 0)\n"
		"        Codef(ArrayChoices[i].wx_str());\n"
		"#endif\n"
		"        return;\n"
		"    }\n"
		"    } // possible wrong indent\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SwitchBracketInPreprocessor2)
{
	// Test that the bracket after a preprocessor statement in a "switch" is recognized.
	// If the variable isImmediatelyPostPreprocessor is not cleared at a line break
	// and brackets are changed from attached to broken, a bracket will be incorrectly indented.
	char textIn[] =
		"\nvoid OnBuildCreatingCode() {\n"
		"    switch (GetLanguage()) {\n"
		"    case wxsCPP: {\n"
		"        if (!Defaults) {\n"
		"#if wxCHECK_VERSION(2, 9, 0)\n"
		"            Codef(ColourDataName());\n"
		"#endif\n"
		"        } else {\n"
		"            Codef(\"%C(%W);\");\n"
		"        }\n"
		"        return;\n"
		"    }\n"
		"    } // possible wrong indent\n"
		"}";
	char text[] =
		"\nvoid OnBuildCreatingCode()\n"
		"{\n"
		"    switch (GetLanguage())\n"
		"    {\n"
		"    case wxsCPP:\n"
		"    {\n"
		"        if (!Defaults)\n"
		"        {\n"
		"#if wxCHECK_VERSION(2, 9, 0)\n"
		"            Codef(ColourDataName());\n"
		"#endif\n"
		"        }\n"
		"        else\n"
		"        {\n"
		"            Codef(\"%C(%W);\");\n"
		"        }\n"
		"        return;\n"
		"    }\n"
		"    } // possible wrong indent\n"
		"}";
	char options[] = "brackets=break";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, PopParenStackOnBracket)
{
	// Test that paren stack is popped when an attached bracket preceeding a comment is broken.
	// In the test case it caused the bracket following line "public bool ShowingDialog {"
	// to not be broken.
	char textIn[] =
		"\nvoid OnRootMonitorDisposed() {\n"
		"    eventThread.BeginInvoke (\n"
		"    ( Action ) delegate {\n"
		"        if ( rootMonitorIsDisposed ) { // ignore double dispose\n"
		"                return;\n"
		"        }\n"
		"    });\n"
		"}\n"
		"\n"
		"sealed class MonitorImpl : IProgressMonitor {\n"
		"    public bool ShowingDialog\n"
		"    {   get { return collector.ShowingDialog; }\n"
		"\n"
		"        set { collector.SetShowingDialog ( value ); }\n"
		"    }\n"
		"}";
	char text[] =
		"\nvoid OnRootMonitorDisposed()\n"
		"{   eventThread.BeginInvoke (\n"
		"        ( Action ) delegate\n"
		"    {   if ( rootMonitorIsDisposed )   // ignore double dispose\n"
		"        {   return;\n"
		"        }\n"
		"    });\n"
		"}\n"
		"\n"
		"sealed class MonitorImpl : IProgressMonitor\n"
		"{   public bool ShowingDialog\n"
		"    {   get\n"
		"        {   return collector.ShowingDialog;\n"
		"        }\n"
		"\n"
		"        set\n"
		"        {   collector.SetShowingDialog ( value );\n"
		"        }\n"
		"    }\n"
		"}";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SharpBreakSingleLineStatements)
{
	// Test a breaking a sharp abstract method single line block.
	// Both of the ending brackets should be broken.
	// TODO: The bracket in-statement formatting could be improved.
	char textIn[] =
		"\nvoid LoadToc()\n"
		"{\n"
		"    if (!IsLocalHelp) DataContext = null;\n"
		"    else DataContext = new[] { new TocEntry(-1) {Title = StringParser.Parse(\"${HelpLibraryRootTitle}\")}};\n"
		"}";
	char text[] =
		"\nvoid LoadToc()\n"
		"{\n"
		"    if (!IsLocalHelp) DataContext = null;\n"
		"    else DataContext = new[] { new TocEntry(-1) {\n"
		"            Title = StringParser.Parse(\"${HelpLibraryRootTitle}\")\n"
		"        }\n"
		"    };\n"
		"}";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, JavaBreakOneLineBlocks1)
{
	// This tests changes in ASFormatter::isOneLineBlockReached().
	char textIn[] =
		"\npublic class MutableFileProperty extends FileProperty {\n"
		"    public MutableFileProperty(String name, File initialFile, String help) {\n"
		"        super(name,new Thunk<File>() { public File value() { return null; } }, help);\n"
		"    }\n"
		"}";
	char text[] =
		"\npublic class MutableFileProperty extends FileProperty {\n"
		"    public MutableFileProperty(String name, File initialFile, String help) {\n"
		"        super(name,new Thunk<File>() {\n"
		"            public File value() {\n"
		"                return null;\n"
		"            }\n"
		"        }, help);\n"
		"    }\n"
		"}";
	char options[] = "mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, JavaBreakOneLineBlocks2)
{
	// This tests changes in ASFormatter::isOneLineBlockReached().
	char textIn[] =
		"\nprotected void makePopupMenuActions() {\n"
		"    AbstractAction[] acts = new AbstractAction[] {\n"
		"        new AbstractAction() { public void actionPerformed(ActionEvent e) { goToRegion(); } },\n"
		"    };\n"
		"}";
	char text[] =
		"\nprotected void makePopupMenuActions() {\n"
		"    AbstractAction[] acts = new AbstractAction[] {\n"
		"    new AbstractAction() {\n"
		"        public void actionPerformed(ActionEvent e) {\n"
		"            goToRegion();\n"
		"        }\n"
		"    },\n"
		"    };\n"
		"}";
	char options[] = "mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, DontAttachBracketToComment)
{
	// This is for array type brackets.
	// The one line bracket following the comment should not be attached.
	char text[] =
		"\nstatic Dictionary<Gdk.Key, string> keyStringMaps = new Dictionary<Gdk.Key, string> () {\n"
		"    { Gdk.Key.Tab,    \"Tab\"   },\n"
		"    { Gdk.Key.Return, \"Enter\" }, /* CR Return */\n"
		"    { Gdk.Key.Escape, \"Esc\"   },\n"
		"};";
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, DontAttachBracketToLineComment)
{
	// This is for array type brackets.
	// The one line bracket following the line comment should not be attached.
	char text[] =
		"\nstatic Dictionary<Gdk.Key, string> keyStringMaps = new Dictionary<Gdk.Key, string> () {\n"
		"    { Gdk.Key.Tab,    \"Tab\"   },\n"
		"    { Gdk.Key.Return, \"Enter\" }, // CR Return\n"
		"    { Gdk.Key.Escape, \"Esc\"   },\n"
		"};";
	char options[] = "brackets=attach, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SharpTemplateArrayDefinition)
{
	// The second bracket should be identified as an array type.
	// The ending bracket on the second line should not be broken.
	char text[] =
		"\nstatic Dictionary<string, char> stringCharMaps = new Dictionary<string, char> () {\n"
		"    { \"Nul\",   '0' },\n"
		"    { \"Space\", '1'  },\n"
		"    { \"CR\",    '2' },\n"
		"};";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, RunInCommentEndsWithBracket)
{
	// Run-in brackets did not break line if the line ends with a bracket.
	char textIn[] =
		"\npublic CSharpSpanParser ()\n"
		"{\n"
		"/*      foreach (Span span in mode.Spans) {\n"
		"            preprocessorSpan = span;\n"
		"        }\n"
		"    }*/\n"
		"}";
	char text[] =
		"\npublic CSharpSpanParser ()\n"
		"{   /*      foreach (Span span in mode.Spans) {\n"
		"                preprocessorSpan = span;\n"
		"            }\n"
		"        }*/\n"
		"}";
	char options[] = "brackets=run-in, mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, JavaSingleLineAbstractMethod1)
{
	// Single line abstract method should break the closing bracket.
	char textIn[] =
		"\npublic void foo()\n"
		"{\n"
		"    new Runnable()\n"
		"    { public void run() { } }\n"
		"}";
	char text[] =
		"\npublic void foo()\n"
		"{\n"
		"    new Runnable()\n"
		"    {\n"
		"        public void run() { }\n"
		"    }\n"
		"}";
	char options[] = "mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, JavaSingleLineAbstractMethod2)
{
	// Single line abstract method should break the closing bracket.
	// Attached brackets.
	char textIn[] =
		"\npublic void foo()\n"
		"{\n"
		"    new Runnable()\n"
		"    { public void run() { } }\n"
		"}";
	char text[] =
		"\npublic void foo()\n"
		"{\n"
		"    new Runnable() {\n"
		"        public void run() { }\n"
		"    }\n"
		"}";
	char options[] = "brackets=linux, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, JavaStatementFollowsComment)
{
	// With break-blocks and delete-empty-lines this java
	// statement duplicated the "threadPanel, flipPanel);" line.
	// It causes an assert exception in debug configuration.
	char textIn[] =
		"\nprivate void createWindow()\n"
		"{\n"
		"    flipPanel = new JPanel();\n"
		"    {\n"
		"        // do stuff\n"
		"    }\n"
		"\n"
		"    /* JSplitPane */ mainPanel = new JSplitPane(VERTICAL_SPLIT,\n"
		"            threadPanel, flipPanel);\n"
		"\n"
		"}";
	char text[] =
		"\nprivate void createWindow()\n"
		"{\n"
		"    flipPanel = new JPanel();\n"
		"    {\n"
		"        // do stuff\n"
		"    }\n"
		"    /* JSplitPane */ mainPanel = new JSplitPane(VERTICAL_SPLIT,\n"
		"            threadPanel, flipPanel);\n"
		"}";
	char options[] = "break-blocks, delete-empty-lines, mode=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SharpQuestionMarkOperator)
{
	// With vs2010 this test caused a "string subscript out of range" debug assertion.
	// With a C# file the ? must be at the end of the line and pad-oper must be used.
	char text[] =
		"\npublic string LocationName {\n"
		"    get {\n"
		"        return ValidForDeployment ?\n"
		"               fileCopier.FriendlyLocation :\n"
		"               GetString (\"Not set\");\n"
		"    }\n"
		"}";
	char options[] = "pad-oper, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, CommentEnclosesNoIndentLineComment)
{
	// With vs2010 this test caused a "string subscript out of range" debug assertion.
	// With vs2008 this test caused a null to be placed in column 5 of the empty line.
	// must have tab indent for comment
	// must have non-indent line comment
	// must have a line with indent less than comment start indent
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	/*\n"
		"//          no-indent line comment\n"
		"\n"
		"	*/\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    /*\n"
		"    //          no-indent line comment\n"
		"\n"
		"    */\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, CheckSumError)
// Test with --break-blocks and --delete-empty-lines and missing closing bracket
// Caused a checksum assert failure. This must be run in debug configuration.
// This test is also included in AStyleTestCon for the console build.
{
	char text[] =
		// this file is missing a closing bracket
		"\nvoid foo()\n"
		"{\n"
		"    if (isBar)\n"
		"        fooBar1();\n"
		"\n"
		"    fooBar2();";
	char options[] = "break-blocks, delete-empty-lines";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, CloseingBracket_FollowsEndComment)
{
	// A closing bracket following a end comment
	// caused the previous line to be deleted.
	// In version 2.01 it caused an assert failure
	// with the checksum.
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (foo1) {\n"
		"/*      closing bracket following comment end\n"
		"        this line should not be deleted\n"
		"*/  }\n"
		"\n"
		"    if (foo2) {\n"
		"/*      this line should not be deleted\n"
		"*/}\n"
		"}";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (foo1) {\n"
		"        /*      closing bracket following comment end\n"
		"                this line should not be deleted\n"
		"        */\n"
		"    }\n"
		"\n"
		"    if (foo2) {\n"
		"        /*      this line should not be deleted\n"
		"        */\n"
		"    }\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, UnpadParens_ConvertTabs)
{
	// Unpad parens with convert tabs and a paren ending the line
	// caused a "string subscript out of range" with VS2010
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo)\n"
		"        Bar(\n"
		"            foo + 1);\n"
		"}";
	char options[] = "unpad-paren, convert-tabs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, DeleteEmptyLines_BreakBlocks)
{
	// a missing closing bracket with delete-empty-lines and break-blocks
	// should not cause an assert error on the call to sourceIterator->peekNextLine()
	// in the function ASFormatter::commentAndHeaderFollows()
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar()\n"
		"    {\n"
		"\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar()\n"
		"    {\n"
		"    }";      // no end-of-line will be output
	char options[] = "delete-empty-lines, break-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, BreakBlocks_DeleteEmptyLines_Comment)
{
	// the following comment should not abort or duplicate code in the output
	// both break-blocks and delete-empty-lines must be used
	// problem is the beginning comments in the peekNextText() function
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"\n"
		"/*//BEGIN debug\n"
		"    kdDebug() << endl << endl;\n"
		"//END debug*/\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"    /*//BEGIN debug\n"
		"        kdDebug() << endl << endl;\n"
		"    //END debug*/\n"
		"}\n";
	char options[] = "break-blocks, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SharpLambdaOperatorIndent)
{
	// C# => is not an assignment operator
	// following lines should not be aligned on the =>
	char textIn[] =
		"\npublic static bool Foo()\n"
		"{\n"
		"    return @class.Attributes(\n"
		"               att =>\n"
		"                    att.AttributeType() &&\n"
		"                    att.PositionalArg == 2 &&\n"
		"                    String.Equals(\"System\")\n"
		"           );\n"
		"}\n";
	char text[] =
		"\npublic static bool Foo()\n"
		"{\n"
		"    return @class.Attributes(\n"
		"               att =>\n"
		"               att.AttributeType() &&\n"
		"               att.PositionalArg == 2 &&\n"
		"               String.Equals(\"System\")\n"
		"           );\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, KeywordsNotHeaders)
{
	// header is not a keyword if part of a definition
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"    ADD_KEYWORD(return, TK_RETURN);\n"
		"    ADD_KEYWORD(switch, TK_SWITCH);\n"
		"    ADD_KEYWORD(case,   TK_CASE);\n"
		"    ADD_KEYWORD(default,TK_DEFAULT);\n"
		"}\n";
	char options[] = "pad-header";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, TwoGreaterSymblolsClosingTemplate)
{
	// two >> symbols closing a template
	char text[] =
		"\npublic Foo<KeyValuePair<string, string>> SpecialTypes {\n"
		"    get {\n"
		"        return typeConversionTable;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, Col1ElseWithPreceedingBracket)
{
	// else in col 1 with preceeding bracket tests a seldom used branch
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo)\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"else    // comment\n"
		"        bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if(isFoo)\n"
		"    {\n"
		"        bar1();\n"
		"    }\n"
		"    else    // comment\n"
		"        bar2();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, TryCatchInHeader)
{
	// try-catch within a header
	// header must be restored from lastTempStack in ASBeautifier
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (foo1)\n"
		"        bar1;\n"
		"    else\n"
		"        try {\n"
		"            bar();\n"
		"        } catch (int e) {\n"
		"            cerr << \"error\" << endl;\n"
		"        }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, TryCatchFinallyInHeader)
{
	// try-catch within a header
	// header must be restored from lastTempStack in ASBeautifier
	char text[] =
		"\nprivate void foo()\n"
		"{\n"
		"    if (foo1)\n"
		"        bar1;\n"
		"    else\n"
		"        try {\n"
		"            bar();\n"
		"        } catch (int e) {\n"
		"            Console.WriteLine(\"error\");\n"
		"        } finally (int e) {\n"
		"            closefile();\n"
		"        }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, DoWhileInHeader)
{
	// do-while within a header
	// header must be restored from lastTempStack in ASBeautifier
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (foo1)\n"
		"        bar1;\n"
		"    else\n"
		"        do {\n"
		"            bar();\n"
		"        } while (int x < 9);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, TemplateASBeautifier)
{
	// template on multiple lines should be recognized by ASBeautifier
	// template within a template should be recognized by ASBeautifier
	char text[] =
		"\ntemplate<typename T, template<typename E,\n"
		"         typename Allocator = allocator<E> >\n"
		"         class Container = vector >\n"
		"class Foo\n"
		"{\n"
		"};\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, ExtraClosingBrackets)
{
	// should not abort with extra closing brackets
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        int bar = 1;\n"
		"    }\n"
		"}\n"
		"}\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, ExtraClosingParens)
{
	// should not abort with extra closing parens
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo))))\n"
		"    {\n"
		"        bar()));\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, ExtraClosingBlockParens)
{
	// should not abort with extra closing block parens
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo))))\n"
		"    {\n"
		"        fooBar = bar[2]]];\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, DefinitionsNotHeaders)
{
	// definitions are not headers
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    ADD_KEYWORD ( if, TK_IF );\n"
		"    ADD_KEYWORD ( while, TK_WHILE );\n"
		"    ADD_KEYWORD ( else );\n"
		"    ADD_KEYWORD ( for );\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SharpPeekNextTextMultiLineComment)
{
	// test C# peekNextText() with multi-ine comment before the text
	char text[] =
		"\npublic interface FooInterface {\n"
		"    int FooGet {\n"
		"        /* comment\n"
		"           comment */\n"
		"        get;\n"
		"        set;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, SharpNotPotentialHeader)
{
	// test C# isNextWordSharpNonParenHeader() for !isCharPotentialHeader()
	char text[] =
		"\nprivate void foo()\n"
		"{\n"
		"    string[] lines = text.Split(new char[] {'.'});\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, EmptyLineComment)
{
	// test recognition of an empty line comment
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    //\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V201, ColZeroPointerOrReference)
{
	// test pointer or reference in column zero
	char textIn[] =
		"\nvoid foo(char *foo1, char\n"
		"*foo2, char *foo3)\n"
		"{\n"
		"    bar();\n"
		"}\n"
		"\n"
		"void foo(char &foo1, char\n"
		"&foo2, char &foo3)\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char text[] =
		"\nvoid foo(char *foo1, char\n"
		"         *foo2, char *foo3)\n"
		"{\n"
		"    bar();\n"
		"}\n"
		"\n"
		"void foo(char &foo1, char\n"
		"         &foo2, char &foo3)\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle version 1.24 TEST functions
//----------------------------------------------------------------------------

TEST(BugFix_V124, AddBracketsRunInNestedIfStatements)
{
	// add on line brackets to nested "if" statements
	// with keep one line brackets
	// should not break the statement (a variable was not reset)
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isBar1)\n"
		"        if (isBar2) return true;\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{   if (isBar1)\n"
		"        if (isBar2) { return true; }\n"
		"}\n";
	char options[] = "add-brackets, brackets=run-in, keep-one-line-blocks";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, ClassRunInComment)
{
	// handle special case of run-in comment in a class statement
	char text[] =
		"\nclass Foo\n"
		"{   /*enum ResolutionFlags {\n"
		"           NoFlag = 0,\n"
		"           HadTypedef = 1,\n"
		"           HadAlias = 2\n"
		"         };*/\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, ClassIndentRunInComment)
{
	// handle special case of run-in comment in an indented class statement
	char text[] =
		"\nclass Foo\n"
		"{   /*enum ResolutionFlags {\n"
		"           NoFlag = 0,\n"
		"           HadTypedef = 1,\n"
		"           HadAlias = 2\n"
		"         };*/\n"
		"}\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, AppendAttachedBracketInsideCommentsLineBreak)
{
	// should not insert an empty line after appending a bracket inside comments
	char textIn[] =
		"\nvoid foo()\n"
		"{   switch(req) {\n"
		"    case REQ_if:   // groff(7) \"IF\"\n"
		"    {   /* .if c anything\n"
		"         * .if N anything\n"
		"         */\n"
		"        c = c + j;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char text[] =
		"\nvoid foo() {\n"
		"    switch(req) {\n"
		"    case REQ_if: { // groff(7) \"IF\"\n"
		"        /* .if c anything\n"
		"         * .if N anything\n"
		"         */\n"
		"        c = c + j;\n"
		"        break;\n"
		"    }\n"
		"    }\n"
		"}\n";
	char options[] = "brackets=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, ElseAttachedToLineComment)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BreakOneLineBlocks_Comment1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BreakOneLineBlocks_Comment2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, SharpDelegate)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, SharpAccessors)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, SharpNonParenHeader_UnEXPECT_TRUEed)
{
	// 'unEXPECT_TRUEed' should be recognized as a header, not an array
	char text[] =
		"\npublic override void foo()\n"
		"{\n"
		"    unEXPECT_TRUEed {\n"
		"        if (isBar)\n"
		"            bar += 1;\n"
		"    }\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, SharpNonParenHeader_Delegate)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, PadCommentBeforeTab)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsBreak_PadParen)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsAttach_CommentsMisc1)
{
	// attach bracket inside a line end comment
	// when multi-line comments follow a run-in bracket
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsAttach_CommentMisc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsAttach_CommentMisc3)
{
	// when a bracket is NOT attached
	// following run-in comments should be broken and correctly formatted
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsAttach_CommentMisc4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Tabs)
{
	// test run-in brackets with tab indents
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
	char options[] = "brackets=run-in, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Array1)
{
	// test run-in brackets with single line array
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Array2)
{
	// test run-in brackets with structs and arrays
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Spaces1)
{
	// test run-in brackets with extra spaces
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Spaces2)
{
	// test multiple run-in brackets runs
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
	char options[] = "brackets=run-in";
	char* textOne = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	char* textOut = AStyleMain(textOne, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOne;
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Preprocessor)
{
	// test run-in brackets with preprocessor
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_EmptyLine)
{
	// test run-in brackets with following empty line
	// empty line should NOT be deleted
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"\n"
		"    if (isFoo())\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment1)
{
	// test run-in brackets with following comment
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment2)
{
	// test run-in brackets with following comment in column 1
	// the comment should NOT be attached
	char text[] =
		"\nvoid Foo()\n"
		"{\n"
		"// comment1 does not attach\n"
		"// comment2\n"
		"    if (isFoo())\n"
		"        bar();\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment3)
{
	// test run-in brackets with following comment
	// the comment should NOT be attached to the previous line
	char text[] =
		"\nvoid foo()\n"
		"{   foo1();\n"
		"    /* comment */\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment4)
{
	// test run-in brackets with following comment
	// the comment should NOT be attached to the previous line
	char text[] =
		"\nvoid foo()\n"
		"{   // comment1\n"
		"    /*comment2*/\n"
		"}\n";
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment5)
{
	// test run-in brackets with following comment
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
	char text[] =
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment6)
{
	// test run-in brackets with following comment
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
	char text[] =
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
	char options[] = "brackets=run-in, indent-namespaces";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_Comment7)
{
	// test run-in brackets with comment following line comment
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
	char options[] = "brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_BreakAllBlocks1)
{
	// test run-in brackets with break all blocks
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
	char options[] = "brackets=run-in, break-blocks=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_BreakAllBlocks2)
{
	// test run-in brackets with break all blocks and delete empty lines
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
	char options[] = "brackets=run-in, break-blocks=all, delete-empty-lines";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_UnpadParen1)
{
	// test run-in brackets with unpad parens
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
	char options[] = ", brackets=run-in, unpad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_UnpadParen2)
{
	// test run-in brackets with unpad parens and pad-parens
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
	char options[] = ", brackets=run-in, unpad-paren, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_UnpadParen3)
{
	// test run-in brackets with unpad parens and pad-parens
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
	char options[] = ", brackets=run-in, unpad-paren, pad-paren, indent=tab";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_SingleLineBlock1)
{
	// test run-in brackets with single line block
	char textIn[] =
		"\nvoid foo()\n"
		"{ bar1(); bar2() }\n";
	char text[] =
		"\nvoid foo()\n"
		"{   bar1();\n"
		"    bar2()\n"
		"}\n";
	char options[] = ", brackets=run-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V124, BracketsRunIn_SingleLineBlock2)
{
	// test run-in brackets with single line block
	char text[] =
		"\nvoid foo()\n"
		"{ bar1(); bar2() }\n";
	char options[] = ", brackets=run-in, keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle version 1.23 TEST functions
//----------------------------------------------------------------------------

TEST(BugFix_V123, ExternIndent)
{
	// no extra indent when extern is used
	char text[] =
		"\nextern void foo (bool bar2,\n"
		"                 bool bar2);\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, StructBitIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, ClassBitIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, StructIndent)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, PreprocessorErrorStatement)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, SharpAccessorsWithElse)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, BreakElseIfWithCatch)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, WhitesmithInComment)
{
	// test whitesmith style with brackets in comment
	// should not indent brackets in comments
	char text[] =
		"\nvoid foo()\n"
		"    {\n"
		"    /*if (client == NULL)\n"
		"    {\n"
		"        int found = -1;\n"
		"    }*/\n"
		"    }\n";
	char options[] = "style=whitesmith";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, BreakBlocksWithEmptyLine)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, UnmatchedBracketsInPreprocessor1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, UnmatchedBracketsInPreprocessor2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, DeleteLinesAfterPreprocessor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, CSharp_NullableTypes)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, CSharp_QuestionQuestionOperator)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, CSharp_NonGenericDefault)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, BreakBlocksWithPreprocessor)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, CSharp_BreakBlocks_KeepOneLineBlocks)
{
	// C# do NOT break before a block with keep one line blocks
	char text[] =
		"\npublic class FooClass\n"
		"{\n"
		"    public bool Foo { get { return Count > 0; } }\n"
		"}\n";
	char options[] = "break-blocks, keep-one-line-blocks, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, EnumDefinitionPadding)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, UnionDefinitionPadding)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(BugFix_V123, StructDefinitionPadding)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
