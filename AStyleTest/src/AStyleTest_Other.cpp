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
// AStyle Character Set Tests
//----------------------------------------------------------------------------

TEST(CharacterSet, ExtendedCharacterSet)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(CharacterSet, UnicodeCharacterSet)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(CharacterSet, UTF8WithBOM)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Virgin Line Tests
//----------------------------------------------------------------------------

TEST(VirginLine, Brackets)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Input Error Tests
// Test error reporting conditions in astyle_main
//----------------------------------------------------------------------------

TEST(AStyleMainInputError, NullErrorHandlerPointer)
{
	// test error handling for NULL error handler pointer
	// this cannot call the error handler, EXPECT_TRUE only for NULL return
	// memory has NOT been allocated for this error
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, NULL, memoryAlloc);
	EXPECT_TRUE(textOut == NULL);
}

TEST(AStyleMainInputError, NullPointerToSource)
{
	// test error handling for NULL pointer to source
	// memory has NOT been allocated for this error
	char options[] = "";
	int errorsIn = getErrorHandler2Calls();
	char* textOut = AStyleMain(NULL, options, errorHandler2, memoryAlloc);
	int errorsOut = getErrorHandler2Calls();
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut == NULL);
}

TEST(AStyleMainInputError, NullPointerToOptions)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut == NULL);
}

TEST(AStyleMainInputError, NullPointerToMemoryAlloc)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut == NULL);
}

TEST(AStyleMainInputError, InvalidOption)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Macro formatting
// Test wxWidgets and MFC macros recognized by AStyle
//----------------------------------------------------------------------------

TEST(Macro, wxWidgetsEventHandler)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Macro, wxWidgetsEventHandlerNonIndentComment)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Macro, MfcDispatchMap)
{
	// MFC dispatch map should be indented
	char text[] =
		"\nBEGIN_DISPATCH_MAP(CblahCtrl, COleControl)\n"
		"    DISP_FUNCTION_ID(CMySink,\"Quit\",2,OnObjQuit,VT_EMPTY,VTS_I4 VTS_I4)\n"
		"    DISP_FUNCTION_ID(CblahCtrl,\"AboutBox\",2,AboutBox,VT_EMPTY,VTS_NONE)\n"
		"END_DISPATCH_MAP()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Macro, MfcEventMap)
{
	// MFC event map should be indented
	char text[] =
		"\nBEGIN_EVENT_MAP(CDataqSdkCtrl, COleControl)\n"
		"    EVENT_CUSTOM(\"NewData\", FireNewData, VTS_I2)\n"
		"    EVENT_CUSTOM(\"OverRun\", FireOverRun, VTS_NONE)\n"
		"    EVENT_CUSTOM(\"ControlError\", FireControlError, VTS_I4)\n"
		"END_EVENT_MAP()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Macro, MfcMessageMap)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Macro, MfcPropertyPages)
{
	// MFC property pages should be indented
	char text[] =
		"\nBEGIN_PROPPAGEIDS(CblahCtrl, 1)\n"
		"    PROPPAGEID( CLSID_CFontPropPage )\n"
		"    PROPPAGEID( CLSID_CColorPropPage )\n"
		"END_PROPPAGEIDS(CblahCtrl)\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler2, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle short options used only by console
// should get an error unless they have been duplicated by another option
//----------------------------------------------------------------------------

TEST(ConsoleShortOption, SuffixNoneShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, Recursive1Short)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, Recursive2Short)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, ErrorsToStdoutShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, PreserveDateShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, VerboseShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, FormattedShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, QuietShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, VersionShort)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, Help1Short)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

TEST(ConsoleShortOption, Help2Short)
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
	EXPECT_EQ(errorsIn + 1, errorsOut);
	EXPECT_TRUE(textOut != NULL);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Quotes
//----------------------------------------------------------------------------

TEST(Quote, Continuation)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Quote, Single)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Quote, Sharp_Verbatim1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Quote, CSharp_Verbatim2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Quote, CSharp_Empty)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Quote, CSharp_Misc)
{
	// test C# strange looking quotes with """
	// whitespace should not change
	char text[] =
		"\npublic void TestString()\n"
		"{\n"
		"    EXPECT_TRUEToken(@\"@\"\"-->\"\"\"\"<--\"\"\", @\"-->\"\"<--\");\n"
		"    EXPECT_TRUEToken(@\"\"\"-->\\\"\"<--\"\"\", \"-->\\\"<--\");\n"
		"\n"
		"    EXPECT_TRUEToken(@\"\"\"\\U00000041\"\"\", \"\\U00000041\");\n"
		"    EXPECT_TRUEToken(@\"\"\"\\U00010041\"\"\", \"\\U00010041\");\n"
		"}\n";
	char options[] = "mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Enum
//----------------------------------------------------------------------------

TEST(Enum, Namespace1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, Namespace2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, NamespaceIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, NamespaceIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, ClassTypeSafe)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, Class1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, Class2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, ClassIndent1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, ClassIndent2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, ClassIndent3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Enum, Java)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Struct
//----------------------------------------------------------------------------

TEST(Struct, Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Struct, Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Struct, Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Volatile Type Qualifier
//----------------------------------------------------------------------------

TEST(Volatile, ConstVolatile)
{
	// Test with "const volatile".
	// The keyword "Volatile" used as a  type qualifier caused the data after the "if"
	// statement to receive 1 less indent than needed.
	char text[] =
		"\nbool MDMsgBatchManager::IsReindexRequired () const volatile\n"
		"{\n"
		"    bool result = false;\n"
		"    if (isReindexed)\n"
		"    {\n"
		"        result = true;\n"
		"    }\n"
		"    return result;\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Volatile, VolatileConst)
{
	// Test with "volatile const".
	// The keyword "Volatile" used as a  type qualifier caused the data after the "if"
	// statement to receive 1 less indent than needed.
	char text[] =
		"\nbool MDMsgBatchManager::IsReindexRequired () volatile const\n"
		"{\n"
		"    bool result = false;\n"
		"    if (isReindexed)\n"
		"    {\n"
		"        result = true;\n"
		"    }\n"
		"    return result;\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Volatile, VolatileOnly)
{
	// Test with "volatile" only.
	// The keyword "Volatile" used as a  type qualifier caused the data after the "if"
	// statement to receive 1 less indent than needed.
	char text[] =
		"\nbool MDMsgBatchManager::IsReindexRequired () volatile\n"
		"{\n"
		"    bool result = false;\n"
		"    if (isReindexed)\n"
		"    {\n"
		"        result = true;\n"
		"    }\n"
		"    return result;\n"
		"}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Volatile, ConstVolatile_IndentBlocks)
{
	// Test with "const volatile" and indent-blocks.
	// The keyword "Volatile" used as a  type qualifier caused the data after the "if"
	// statement to receive 1 less indent than needed.
	char text[] =
		"\nbool MDMsgBatchManager::IsReindexRequired () const volatile\n"
		"{\n"
		"    bool result = false;\n"
		"    if (isReindexed)\n"
		"        {\n"
		"            result = true;\n"
		"        }\n"
		"    return result;\n"
		"}";
	char options[] = "indent-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Volatile, VolatileConst_IndentBlocks)
{
	// Test with "volatile const" and indent-blocks.
	// The keyword "Volatile" used as a  type qualifier caused the data after the "if"
	// statement to receive 1 less indent than needed.
	char text[] =
		"\nbool MDMsgBatchManager::IsReindexRequired () volatile const\n"
		"{\n"
		"    bool result = false;\n"
		"    if (isReindexed)\n"
		"        {\n"
		"            result = true;\n"
		"        }\n"
		"    return result;\n"
		"}";
	char options[] = "indent-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Volatile, VolatileOnly_IndentBlocks)
{
	// Test with "volatil" only and indent-blocks.
	// The keyword "Volatile" used as a  type qualifier caused the data after the "if"
	// statement to receive 1 less indent than needed.
	char text[] =
		"\nbool MDMsgBatchManager::IsReindexRequired () volatile\n"
		"{\n"
		"    bool result = false;\n"
		"    if (isReindexed)\n"
		"        {\n"
		"            result = true;\n"
		"        }\n"
		"    return result;\n"
		"}";
	char options[] = "indent-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Preprocessor
//----------------------------------------------------------------------------

TEST(Preprocessor, CommandType)
{
	// EXPECT_TRUE indentation
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, Elif)
{
	// #elif updates the waitingBeautifierStack
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"#if USE64\n"
		"        if (c < 64)\n"
		"#elif USE128\n"
		"        if (c < 128)\n"
		"#elif USE256\n"
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, EndOnEmptyLine)
{
	// TODO: AStyle adds a space to the empty line
	// preprocessor define ends with an empty line
	char textIn[] =
		"\n#define ITEM_ITERATION_UVC_LOOP_END(BOTTOMY) \\\n"
		"    } while ( p->m_y < BOTTOMY ); \\\n"
		"\n"
		"\n";
	char text[] =
		"\n#define ITEM_ITERATION_UVC_LOOP_END(BOTTOMY) \\\n"
		"    } while ( p->m_y < BOTTOMY ); \\\n"
		" \n"
		"\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, Assembler)
{
	// can have preprocessor in a assembler block
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    __asm {\n"
		"        mov eax, fs:[0x8]\n"
		"#ifdef _WIN32\n"
		"        mov dx, 0xD007\n"
		"#else\n"
		"        mov dx, 0xD008\n"
		"#endif\n"
		"        out dx, al\n"
		"    }\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, MissingOpener)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, WxWidgetsMacro)
{
	// preprocessor should NOT be indented
	char text[] =
		"\nBEGIN_EVENT_TABLE(ClassWizardDlg, wxDialog)\n"
		"    EVT_BUTTON(XRCID(\"btnCommonDir\"), ClassWizardDlg::OnCommonDirClick)\n"
		"#ifdef LOGGING\n"
		"    EVT_EXPECT_TRUEBOX(XRCID(\"chkLowerCase\"), ClassWizardDlg::OnLowerCaseClick)\n"
		"    EVT_BUTTON(XRCID(\"btnIncludeDir\"), ClassWizardDlg::OnIncludeDirClick)\n"
		"#endif\n"
		"    EVT_BUTTON(XRCID(\"btnImplDir\"), ClassWizardDlg::OnImplDirClick)\n"
		"END_EVENT_TABLE()\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, ArrayType)
{
	// EXPECT_TRUE indentation
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, ArrayMissingOpener)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, ArrayHorstmann_Break)
{
	// EXPECT_TRUE broken brackets to horstmann
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, ArrayHorstmann_Attach)
{
	// EXPECT_TRUE attached brackets to horstmann
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Preprocessor, ArrayHorstmann_Horstmann)
{
	// EXPECT_TRUE horstmann brackets to horstmann
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Comments
//----------------------------------------------------------------------------

TEST(Comment, BracketsNone_NamespaceClassIndent_None)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsNone_NamespaceClassIndent_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsNone_NamespaceClassIndent_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsNone_NamespaceClassIndent_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsBreak_NamespaceClassIndent_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsBreak_NamespaceClassIndent_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsBreak_NamespaceClassIndent_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsAttach_NamespaceClassIndent_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsAttach_NamespaceClassIndent_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsAttach_NamespaceClassIndent_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsHorstmann_NamespaceClassIndent_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsHorstmann_NamespaceClassIndent_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BracketsHorstmann_NamespaceClassIndent_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(Comment, Namespace_Misc1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, Namespace_ClassMisc2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, NestedClass_Misc3)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, NestedClass_Misc4)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, NamespaceClass_Misc5)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, NamespaceClass_Misc6)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, BeforeStatement_Misc7)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, LeadingSpaceCorrection1)
{
	// comment where the leading spaces need correction
	// will adjust the first line
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"       /*   EXEC SQL INSERT\n"
		"    INTO   branch (branch_id, branch_name, branch_addr,\n"
		"             branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"    */\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    /*   EXEC SQL INSERT\n"
		"    INTO   branch (branch_id, branch_name, branch_addr,\n"
		"             branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"    */\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, LeadingSpaceCorrection2)
{
	// comment where the leading spaces need correction
	// text has tabs
	// will adjust the first line
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"	   /*   EXEC SQL INSERT\n"
		"	INTO   branch (branch_id, branch_name, branch_addr,\n"
		"	         branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"	*/\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    /*   EXEC SQL INSERT\n"
		"    INTO   branch (branch_id, branch_name, branch_addr,\n"
		"             branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"    */\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Comment, LeadingSpaceCorrection3)
{
	// comment where the leading spaces need correction
	// and indent needs adjusting
	// will adjust the first line
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"         /*   EXEC SQL INSERT\n"
		"      INTO   branch (branch_id, branch_name, branch_addr,\n"
		"               branch_city, branch_phone)\n"
		"      VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"      */\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    /*   EXEC SQL INSERT\n"
		"    INTO   branch (branch_id, branch_name, branch_addr,\n"
		"             branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"    */\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Continuation Lines
//----------------------------------------------------------------------------

TEST(Continuation, BracketsNone_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsNone_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsNone_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsBreak_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsBreak_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsBreak_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsAttach_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsAttach_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsAttach_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsHorstmann_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsHorstmann_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, BracketsHorstmann_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(Continuation, InlineTab1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Continuation, InlineTab2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Continuation Lines with Tabs
//----------------------------------------------------------------------------

TEST(ContinuationTab, BracketsNone_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsNone_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsNone_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsBreak_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsBreak_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsBreak_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsAttach_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsAttach_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsAttach_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsHorstmann_Break)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsHorstmann_Attach)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, BracketsHorstmann_Horstmann)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, InlineTab1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationTab, InlineTab2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationForceTab, InlineTab1)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(ContinuationForceTab, InlineTab2)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// C++ operators << and >>
//----------------------------------------------------------------------------

TEST(AlignmentOperator, Cout)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignmentOperator, Cin)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(AlignmentOperator, CoutBeginLine)
{
	// Alignment of the operator<< when it begins the line
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    Context->m_EventsConnectingCode\n"
		"            << _T(\"Connect(\")\n"
		"            << m_EventArray[i].Type\n"
		"            << _T(\");\") << endl;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(AlignmentOperator, Cout2)
{
	// Alignment of the operator<<
	char text[] =
		"\nstd::ostream& operator<<(std::ostream& os)\n"
		"{\n"
		"    os << foo\n"
		"       << std::endl;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle SQL
//----------------------------------------------------------------------------

TEST(SQL, Standard)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, Comment)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, LineComment)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, NonIndentingTabs)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, NonHangingIndent)
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
		"           branch_city, branch_phone)\n"
		"    VALUES (:bid, :bname, :baddr:baddr_ind);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, LowerCaseExtraSpaces)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, EndOfLine)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, BreakAfterSemi)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, Switch)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, SwitchIndentCase)
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
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, BracketsHorstmann)
{
	// SQL statements in horstmann brackets
	char text[] =
		"\nvoid foo()\n"
		"{   EXEC SQL SELECT BLP_PIN_TYPE\n"
		"             INTO :m_Pin_Type;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(SQL, Sans)
{
	// not SQL statements (macros?)
	// SQL statements will not be changed
	char textIn[] =
		"\nvoid foo()\n"
		"{\n"
		"    EXEC\n"
		"        bar1();\n"
		"    EXEC SQX\n"
		"        bar2();\n"
		"}\n";
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    EXEC\n"
		"    bar1();\n"
		"    EXEC SQX\n"
		"    bar2();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------
// AStyle Assembler
//----------------------------------------------------------------------------

TEST(Assembler, Embedded1)
{
	// embedded assembler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    asm (\"\n"
		"         movl -4(%ebp), %eax	; comment1\n"
		"         sarl %ebx				; comment2\n"
		"         \");\n"
		"\n"
		"    if (foo()) {\n"
		"        asm(\"int3\"); /*trap*/\n"
		"    }\n"
		"\n"
		"    int data;\n"
		"    asm volatile (\"mcr\t\" \"14, 0, %0, c1, c0\"::\"r\" (data));\n"
		"\n"
		"    if (bar())\n"
		"        { asm(\"int3\"); }\n"
		"}\n";
	char options[] = "keep-one-line-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Assembler, Embedded2)
{
	// embedded assembler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    asm (\"sar1 %1\n"
		"         movl %1, %0\": \"=r\"(res[i]) :\"r\" (res[i]), \"memory\");\n"
		"\n"
		"    __asm__ (\"sarl %0\"\n"
		"             : \"=r\" (res[i]) :\"r\" (num[i]), \"r\" (num[i]): \"memory\");\n"
		"\n"
		"    asm (\"addl %%ebx, %%eax;\"\n"
		"         : \"=a\" (add)\n"
		"         : \"a\" (arg1), \"b\" (arg2) );\n"
		"\n"
		"    __asm__ (\"addl %%ebx, %%eax;\" : \"=a\" (add) : \"a\" (arg1), \"b\" (arg2));\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Assembler, MS1)
{
	// microsoft specific embedded assembler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm mov eax, fs:[0x8]\n"
		"    __asm push edp\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Assembler, MS2)
{
	// microsoft specific embedded assembler
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    _asm {\n"
		"        mov eax, fs:[0x8]\n"
		"        mov dx, 0xD007\n"
		"        out dx, al\n"
		"    }\n"
		"\n"
		"    __asm {\n"
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

//----------------------------------------------------------------------------
// AStyle Multiple Varables separated by commas
//----------------------------------------------------------------------------

TEST(MultipleVariableAssignments, Standard)
{
	// multiple assignments are aligned on the first variable
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bool bName  = false,\n"
		"         bFile  = true,\n"
		"         bSize  = true,\n"
		"         bWidth = false;\n"
		"\n"
		"    m_x = (D*E - B*F) / G,\n"
		"    m_y = (A*F - C*E) / G,\n"
		"    m_z = (A*G - F*B) / G;\n"
		"\n"
		"    double rstep = Red() / size, rf = 0,\n"
		"           gstep = Green() / size, gf = 0,\n"
		"           bstep = Blue() / size, bf = 0;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariableAssignments, Comments)
{
	// multiple assignments are aligned on the first variable
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    bool bName   =  false,   // comment1\n"
		"         bFile   =  true,    // comment2\n"
		"         bSize   =  true,    // comment3\n"
		"         bWidth  =  false;   // comment4\n"
		"\n"
		"    bool bName   =  false,   /* comment1 */\n"
		"         bFile   =  true,    /* comment2 */\n"
		"         bSize   =  true,    /* comment3 */\n"
		"         bWidth  =  false;   /* comment4 */\n"
		"\n"
		"    bool bName   =  /* comment1 */ false,\n"
		"         bFile   =  /* comment2 */  true,\n"
		"         bSize   = true  /* comment3 */,\n"
		"         bWidth  = false /* comment3 */;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariableAssignments, Sans)
{
	// these are not multiple assignments
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    // functions are not multiple assignments\n"
		"    int code = GetCode(m_Header,\n"
		"                       m_Code,\n"
		"                       m_Language,\n"
		"                       false);\n"
		"\n"
		"    // arrays are not multiple assignments\n"
		"    bar[] = \"one\",\n"
		"            \"two\";\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}


TEST(MultipleVariable, Standard)
{
	// multiple variables are aligned on first variable
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int var1,\n"
		"        var2,   // comment1\n"
		"        var3;   /* comment2 */\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, MultipleStatementsPerLine)
{
	// multiple variables with multiple statements per line
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    wxString m_bar1, m_bar2,\n"
		"             m_bar3, m_bar4,\n"
		"             m_bar5, m_bar6;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, ClassInitializer1)
{
	// class initializers are aligned on first variable
	char text[] =
		"\nFoo::Foo()\n"
		"    : m_bar1(0),\n"
		"      m_bar2(this, id),\n"
		"      m_bar3(0)\n"
		"{\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, ClassInitializer2)
{
	// class initializers are aligned on first variable
	// colon on previous line
	char text[] =
		"\nFoo::Foo() :\n"
		"    m_bar1(0),\n"
		"    m_bar2(this, id),\n"
		"    m_bar3(0)\n"
		"{\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, ClassInitializer3)
{
	// class initializers are aligned on first variable
	// multiple variables per line
	char text[] =
		"\nFoo::Foo()\n"
		"    : m_bar1(0), m_bar2(0),\n"
		"      m_bar3(0), m_bar4(0), m_bar5(0),\n"
		"      m_bar6(-100), m_bar7(50)\n"
		"{\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, ClassInitializer4)
{
	// class initializers are aligned on first variable
	// comments after comma
	char text[] =
		"\nFoo::Foo()\n"
		"    : m_FileGroups(*fgam), // comment\n"
		"      m_pOrigFileGroups(fgam),\n"
		"      m_LastListSelection(0)\n"
		"{\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, ClassInitializer5)
{
	// class initializers are aligned on first variable
	// last line with brackets should be indented
	char text[] =
		"\nFooBar(int width = 1, int style = wxSOLID,\n"
		"       int cap = wxCAP_ROUND)\n"
		"    : m_bar1(0), m_bar2(0),\n"
		"      m_bar3(0), m_bar4(0),\n"
		"      m_bar5(0), m_bar6(NULL) {}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, ClassInitializer6)
{
	// class initializers are aligned on first variable
	// this EXPECT_TRUEs if the variables have been reset
	char text[] =
		"\nFoo1::Foo1()\n"
		"    : bar1(cmd),\n"
		"      bar2(driver),\n"
		"{}\n"
		"\n"
		"Foo2::Foo2()\n"
		"    : bar3(branch),\n"
		"      bar4(tree)\n"
		"{}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, Misc1)
{
	// this EXPECT_TRUEs if the inStatementIndentStack is correctly popped
	char text[] =
		"\nListBoxImpl::ListBoxImpl()\n"
		"    : unicodeMode(false),\n"
		"      desiredVisibleRows(5)\n"
		"{\n"
		"}\n"
		"\n"
		"void ListBoxImpl::Create (Window &parent,\n"
		"                          int lineHeight_) {\n"
		"    lineHeight =  lineHeight_;\n"
		"}\n"
		"\n"
		"long Platform::SendScintilla(WindowID w,\n"
		"                             unsigned long wParam,\n"
		"                             long lParam) {\n"
		"    wxScintilla* sci = (wxScintilla*)w;\n"
		"    return sci->SendMsg(msg, wParam, lParam);\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(MultipleVariable, Misc2)
{
	// this EXPECT_TRUEs for various conditions in getInStatementIndentComma()
	char text[] =
		"\nvoid foo()\n"
		"{\n"
		"    int\n"
		"    var1\n"
		"    ,\n"
		"    var2;\n"
		"}\n"
		"\n"
		"void foo()\n"
		"{\n"
		"    int\n"
		"    var1,\n"
		"    var2\n"
		"    , var3;\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
