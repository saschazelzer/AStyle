// AStyleTestI18n tests the internationalization component of the ASConsole
// class only. It uses the following source files from AStyleTestCon and
// AStyleTest: AStyleTestCon.h, TersePrinter.h AStyleTestCon_Main.cpp,
// AStyleTest_leakFinder.cpp, and TersePrinter.cpp.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTestCon.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <iconv.h>
#endif

//----------------------------------------------------------------------------
// support functions
//----------------------------------------------------------------------------

int swap16Bit(int value)
// Swap the two low order bytes of a 16 bit integer value.
{
	return ( ((value & 0xff) << 8) | ((value & 0xff00) >> 8) );
}

void convertToBigEndian(char* textIn, size_t textLen)
// convert 16 bit little endian text to big endian format
{
	// convert to wide char variables
	// short is 16 bytes in both Windows and Linux
	short* wcIn = reinterpret_cast<short*>(textIn);
	size_t wcLen = textLen / 2;
	// convert
	for (size_t i = 0; i < wcLen; i++)
		wcIn[i] = static_cast<short>(swap16Bit(wcIn[i]));
}

#ifdef _WIN32
string WideCharToUtf8Str(wchar_t* wcIn, size_t wcLen)
// convert wide char text (16 bit) to an 8 bit utf-8 string
{
	size_t mbLen = WideCharToMultiByte(CP_UTF8, 0, wcIn, wcLen, NULL, 0, NULL, 0);
	if (!mbLen)
		systemAbort("Bad WideCharToMultiByte in Utf16ToUtf8Str()");
	LPSTR mbOut = new char[mbLen + 1];
	WideCharToMultiByte(CP_UTF8, 0, wcIn, wcLen, mbOut, mbLen, NULL, 0);
	mbOut[mbLen] = '\0';
	string mbStr(mbOut);
	delete []mbOut;
	return mbStr;
}
#else
string WideCharToUtf8Str(wchar_t* wcIn, size_t wcLen)
// convert wide char text (32 bit) to an 8 bit utf-8 string
{
	// Linux wchar_t is 32 bits
	iconv_t iconvh = iconv_open("UTF−8", "UTF−32LE");
	if (iconvh == (iconv_t) -1)
		systemAbort("Bad iconv_open in Utf16ToUtf8Str()");
	// allocate memory for output
	size_t mbLen = wcLen * sizeof(wchar_t);
	char* mbOut = new char[mbLen];
	// convert to utf-8
	char* mbConv = mbOut;
	size_t mbLeft = mbLen;
	char* wcConv = reinterpret_cast<char*>(wcIn);
	size_t wcLeft = wcLen * sizeof(wchar_t);
	int iconvval = iconv(iconvh, &wcConv, &wcLeft, &mbConv, &mbLeft);
	if (iconvval == -1)
		systemAbort("Bad iconv in Utf16ToUtf8Str()");
	*mbConv = NULL;
	iconv_close(iconvh);
	string mbStr(mbOut);
	delete []mbOut;
	return mbStr;
}

size_t WideCharToUtf16LE(wchar_t* wcIn, size_t wcLen, char* w16Out, size_t w16Buf)
// convert wide char text (32 bit) to 16 bit little endian text
{
	// Linux wchar_t is 32 bits
	iconv_t iconvh = iconv_open("UTF−16LE", "UTF−32LE");
	if (iconvh == (iconv_t) -1)
		systemAbort("Bad iconv_open in WideCharToUtf16()");
	// convert to utf-16
	char* w16Conv = w16Out;
	size_t w16Left = w16Buf;
	char* wcConv = reinterpret_cast<char*>(wcIn);
	size_t wcLeft = wcLen * sizeof(wchar_t);
	int iconvval = iconv(iconvh, &wcConv, &wcLeft, &w16Conv, &w16Left);
	if (iconvval == -1)
		systemAbort("Bad iconv in WideCharToUtf16()");
	*w16Conv = NULL;
	iconv_close(iconvh);
	return w16Buf - w16Left;
}
#endif

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//----------------------------------------------------------------------------
// AStyle test UTF_8_16 processing
//----------------------------------------------------------------------------

struct Utf_8_16 : public ::testing::Test
// Constructor variables are set using native functions.
// These will be compared to the variables computed by the AStyle functions.
{
	// variables values set using native functions
	ASFormatter formatter;	// formatter object
	string text8BitStr;		// 8 bit text string
	const char* text8Bit;	// 8 bit text char*
	size_t text8Len;		// 8 bit length
	char* text16Bit;		// 16 bit text char* (not wchar_t*)
	size_t text16Len;		// 16 bit length in chars (not wchar_t)

	// c'tor - set the variables
	Utf_8_16()
	{
		// initialize variables
		text8Bit = NULL;
		text8Len = 0;
		text16Bit = NULL;
		text16Len = 0;

		// set textOut variables
		wchar_t textIn[] =
			L"\xfeff"						// 16 bit LE byte order mark (BOM)
			L"\nvoid foo()\n"
			L"{\n"
			L" 	// 文件已经 被修改\n"		// Chinese
			L"	Chinese(\"导出结束\");\n"
			L"\n"
			L" 	// アイウオ カキク\n"		// Japanese
			L"	Japanese(\"スセタチ\");\n"
			L"\n"
			L" 	// 선택된 컨트롤\n"		// Korean
			L"	Korean(\"비트맵 에디터\");\n"
			L"\n"
			L"	// ΓΔΘΛ αβγλ\n"				// Greek
			L"	Greek(\"ξπρσ ΞΦΨΩ\");\n"
			L"\n"
			L"	// АБВГ ДЕЁЖ\n"				// Russian
			L"	Russian(\"ЗИЙК ЛПФЦ\");\n"
			L"\n"
			L"	// ÄÄ ÖÖ ÜÜ ßßßß\n"			// German (ß can cause problem with conversions)
			L"	German(\"ää öö üü\");\n"
			L"}\n";

		// compute 8 bit values using native functions
		text8BitStr = WideCharToUtf8Str(textIn, wcslen(textIn));
		text8Bit = text8BitStr.c_str();
		text8Len = text8BitStr.length();

		// compute 16 bit values using native functions
		size_t text16Buf = wcslen(textIn) * sizeof(wchar_t) + sizeof(wchar_t);
		text16Bit = new char[text16Buf];
#ifdef _WIN32
		// Windows wchar_t is 16 bits and does not need conversion
		wcscpy(reinterpret_cast<wchar_t*>(text16Bit), textIn);
		text16Len = wcslen(reinterpret_cast<wchar_t*>(text16Bit)) * sizeof(wchar_t);
#else
		// Linux wchar_t is 32 bits and must be converted to 16 bits
		text16Len = WideCharToUtf16LE(textIn, wcslen(textIn), text16Bit, text16Buf);
#endif
		createConsoleGlobalObject(formatter);
	}	// end c'tor

	~Utf_8_16()
	{
		delete []text16Bit;
		deleteConsoleGlobalObject();
	}
};

TEST_F(Utf_8_16, DetectEncoding_Utf16)
// test AStyle detectEncoding function for 16 bit encoding
{
	string fileName = "Detect Encoding Test";
	FileEncoding encoding16LE = g_console->detectEncoding(text16Bit, text16Len, fileName);
	EXPECT_TRUE(encoding16LE == UTF_16LE);
	convertToBigEndian(text16Bit, text16Len);
	FileEncoding encoding16BE = g_console->detectEncoding(text16Bit, text16Len, fileName);
	EXPECT_TRUE(encoding16BE == UTF_16BE);
}

TEST_F(Utf_8_16, DetectEncoding_Utf32)
// test AStyle detectEncoding function for 32 bit encoding
{
	// cannot use death test with leak finder
#if GTEST_HAS_DEATH_TEST && !LEAK_FINDER
	string fileName = "Detect Encoding Test";
	// 32 bit LE abort
	const char* Bom32LE = "\xFF\xFE\x00\x00";
	EXPECT_EXIT(g_console->detectEncoding(Bom32LE, sizeof(Bom32LE), fileName),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"UTF-32 LE");
	// 32 bit BE abort
	const char* Bom32BE = "\x00\x00\xFE\xFF";
	EXPECT_EXIT(g_console->detectEncoding(Bom32BE, sizeof(Bom32BE), fileName),
				::testing::ExitedWithCode(EXIT_FAILURE),
				"UTF-32 BE");
#endif
}

TEST_F(Utf_8_16, Utf8_To_Utf16_LE)
// test AStyle Utf8 to Utf16 LE conversion functions
{
	// test Astyle Utf16Length() function
	size_t utf16ComputedSize = g_console->Utf16Length(text8Bit, text8Len);
	EXPECT_EQ(text16Len, utf16ComputedSize);
	// test Astyle Utf8ToUtf16() function return
	char* utf16Out = new char[text8Len * 3];
	size_t utf16ConvertedSize = g_console->Utf8ToUtf16(const_cast<char*>(text8Bit),
								text8Len, UTF_16LE, utf16Out);
	EXPECT_EQ(text16Len, utf16ConvertedSize);
	// test Astyle Utf8ToUtf16() function text conversion
	EXPECT_TRUE(strncmp(utf16Out, text16Bit, text16Len) == 0);
	delete []utf16Out;
}

TEST_F(Utf_8_16, Utf8_To_Utf16_BE)
// test AStyle Utf8 to Utf16 BE conversion functions
{
	convertToBigEndian(text16Bit, text16Len);
	// test Astyle Utf16Length() function
	size_t utf16ComputedSize = g_console->Utf16Length(text8Bit, text8Len);
	EXPECT_EQ(text16Len, utf16ComputedSize);
	// test Astyle Utf8ToUtf16() function return
	char* utf16Out = new char[text8Len * 3];
	size_t utf16ConvertedSize = g_console->Utf8ToUtf16(const_cast<char*>(text8Bit),
								text8Len, UTF_16BE, utf16Out);
	EXPECT_EQ(text16Len, utf16ConvertedSize);
	// test Astyle Utf8ToUtf16() function text conversion
	EXPECT_TRUE(strncmp(utf16Out, text16Bit, text16Len) == 0);
	delete []utf16Out;
}

TEST_F(Utf_8_16, Utf16_LE_To_Utf8)
// test AStyle Utf16 LE to Utf8 conversion functions
{
	// test Astyle Utf8Length() function
	size_t utf8ComputedSize = g_console->Utf8Length(text16Bit, text16Len, UTF_16LE);
	EXPECT_EQ(text8Len, utf8ComputedSize);
	// test Astyle Utf16ToUtf8() function return
	char* utf8Out = new char[text16Len * 2];
	size_t utf8ConvertedSize = g_console->Utf16ToUtf8(const_cast<char*>(text16Bit),
							   text16Len, UTF_16LE, true, utf8Out);
	EXPECT_EQ(text8Len, utf8ConvertedSize);
	// test Astyle Utf16ToUtf8() function text conversion
	EXPECT_TRUE(strncmp(utf8Out, text8Bit, text8Len) == 0);
	delete []utf8Out;
}

TEST_F(Utf_8_16, Utf16_BE_To_Utf8)
// test AStyle Utf16 BE to Utf8 conversion functions
{
	convertToBigEndian(text16Bit, text16Len);
	// test Astyle Utf8Length() function
	size_t utf8ComputedSize = g_console->Utf8Length(text16Bit, text16Len, UTF_16BE);
	EXPECT_EQ(text8Len, utf8ComputedSize);
	// test Astyle Utf16ToUtf8() function return
	char* utf8Out = new char[text16Len * 2];
	size_t utf8ConvertedSize = g_console->Utf16ToUtf8(const_cast<char*>(text16Bit),
							   text16Len, UTF_16BE, true, utf8Out);
	EXPECT_EQ(text8Len, utf8ConvertedSize);
	// test Astyle Utf16ToUtf8() function text conversion
	EXPECT_TRUE(strncmp(utf8Out, text8Bit, text8Len) == 0);
	delete []utf8Out;
}

//----------------------------------------------------------------------------

}  // namespace
