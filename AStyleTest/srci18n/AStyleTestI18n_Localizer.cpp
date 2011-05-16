// This module tests the Localizer and Translate classes.
//
// AStyleTestI18n tests the internationalization component of the ASConsole
// class only. It uses the following source files from AStyleTestCon and
// AStyleTest: AStyleTestCon.h, TersePrinter.h AStyleTestCon_Main.cpp,
// AStyleTest_leakFinder.cpp, and TersePrinter.cpp.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#ifdef _WIN32
#include <windows.h>
#endif

#include "AStyleTestCon.h"
#include "ASLocalizer.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//----------------------------------------------------------------------------
// AStyle test ASLocalizer class
//----------------------------------------------------------------------------

TEST(ASLocalizer, LCIDLanguageIdentification)
// Use French LCIDs to test the WINDOWS setLanguage() function.
// http://msdn.microsoft.com/en-us/library/0h88fahh%28v=vs.85%29.aspx
{
#ifdef _WIN32
	size_t lcid[] = { 1036,		// 0x040C  France
					  2060,		// 0x080C  Belgium
					  3084,		// 0x0C0C  Canada
					  5132,		// 0x140C  Luxembourg
					  4108,		// 0x100C  Switzerland
					};
	size_t lcidCount = sizeof(lcid)/sizeof(lcid[0]);
	for (size_t i = 0; i < lcidCount; i++)
	{
		ASLocalizer localizer;
		localizer.setLanguageFromLCID(lcid[i]);
		string langID = localizer.getLanguageID();
		EXPECT_EQ("fr", langID);
	}
#endif
}

TEST(ASLocalizer, NameLanguageIdentification)
// Use French locale names to test the LINUX getLanguage() function.
// http://msdn.microsoft.com/en-us/library/ee797784%28v=cs.20%29.aspx
{
	char localeName[][20] = { "fr",
							  "fr_BE",				// Belgium
							  "fr_CA@euro",			// Canada
							  "fr_FR",				// France
							  "fr_LU.iso1252",		// Luxembourg
							  "fr_MC",				// Monaco
							  "fr_CH.iso1252@euro",	// Switzerland
							};
	size_t localeCount = sizeof(localeName)/sizeof(localeName[0]);
	for (size_t i = 0; i < localeCount; i++)
	{
		ASLocalizer localizer;
		localizer.setLanguageFromName(localeName[i]);
		string langID = localizer.getLanguageID();
		EXPECT_EQ("fr", langID);
	}
}

TEST(ASLocalizer, UnrecognizedTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	// Unrecognized - default to English
	ASLocalizer localizer;
	localizer.setLanguageFromName("xx_XX");
	translation = localizer.getTranslationClass();
	string className = typeid(*translation).name();
	bool foundClassName = className.find("English") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

TEST(ASLocalizer, ChineseTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	string className;
	bool foundClassName;
	// Chinese Simplified (China)
	ASLocalizer ChineseSimplifiedCN;
	ChineseSimplifiedCN.setLanguageFromName("zh_CN");
	translation = ChineseSimplifiedCN.getTranslationClass();
	className = typeid(*translation).name();
	foundClassName = className.find("ChineseSimplified") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
	// Chinese Simplified (Singapore)
	ASLocalizer ChineseSimplifiedSG;
	ChineseSimplifiedSG.setLanguageFromName("zh_SG");
	translation = ChineseSimplifiedSG.getTranslationClass();
	className = typeid(*translation).name();
	foundClassName = className.find("ChineseSimplified") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
	// Chinese (all other) - default to Chinese Traditional
	ASLocalizer ChineseAllOther;
	ChineseAllOther.setLanguageFromName("zh_XX");
	translation = ChineseAllOther.getTranslationClass();
	className = typeid(*translation).name();
	foundClassName = className.find("ChineseTraditional") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

TEST(ASLocalizer, EnglishTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	// English
	ASLocalizer localizer;
	localizer.setLanguageFromName("en_US");
	translation = localizer.getTranslationClass();
	string className = typeid(*translation).name();
	bool foundClassName = className.find("English") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

TEST(ASLocalizer, FrenchTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	// French
	ASLocalizer localizer;
	localizer.setLanguageFromName("fr_FR");
	translation = localizer.getTranslationClass();
	string className = typeid(*translation).name();
	bool foundClassName = className.find("French") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

TEST(ASLocalizer, GermanTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	// German
	ASLocalizer localizer;
	localizer.setLanguageFromName("de_DE");
	translation = localizer.getTranslationClass();
	string className = typeid(*translation).name();
	bool foundClassName = className.find("German") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

TEST(ASLocalizer, HindiTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	// Hindi
	ASLocalizer localizer;
	localizer.setLanguageFromName("hi_IN");
	translation = localizer.getTranslationClass();
	string className = typeid(*translation).name();
	bool foundClassName = className.find("Hindi") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

TEST(ASLocalizer, SpanishTranslation)
// Check that the correct polymorphic class is set by setTranslationClass().
// setTranslationClass() is accessed thru setLanguageFromName();
// Uses "find" because of the different return values from typeid.
{
	const Translation* translation;
	// Hindi
	ASLocalizer localizer;
	localizer.setLanguageFromName("es_ES");
	translation = localizer.getTranslationClass();
	string className = typeid(*translation).name();
	bool foundClassName = className.find("Spanish") != string::npos;
	EXPECT_TRUE(foundClassName) << className;
}

//----------------------------------------------------------------------------
// AStyle test Translate class and translation values
//----------------------------------------------------------------------------

struct TranslationF : public ::testing::Test
{
	vector<string> m_ascii;

	TranslationF()
	{
		// use the acript astyle-localizer.py to check these against astyle_main.cpp
		setlocale(LC_ALL, "C");
		m_ascii.push_back("Formatted  %s\n");		// should align with unchanged
		m_ascii.push_back("Unchanged  %s\n");		// should align with formatted
		m_ascii.push_back("Directory  %s\n");
		m_ascii.push_back("Exclude  %s\n");
		m_ascii.push_back("Exclude (unmatched)  %s\n");
		m_ascii.push_back(" %s formatted   %s unchanged   ");
		m_ascii.push_back(" seconds   ");
		m_ascii.push_back("%d min %d sec   ");
		m_ascii.push_back("%s lines\n");
		m_ascii.push_back("Using default options file %s\n");
		m_ascii.push_back("Invalid option file options:");
		m_ascii.push_back("Invalid command line options:");
		m_ascii.push_back("For help on options type 'astyle -h'");
		m_ascii.push_back("Cannot open options file");
		m_ascii.push_back("Cannot open directory");
		m_ascii.push_back("Cannot process the input stream");
		m_ascii.push_back("Missing filename in %s\n");
		m_ascii.push_back("Recursive option with no wildcard");
		m_ascii.push_back("Did you intend quote the filename");
		m_ascii.push_back("No file to process %s\n");
		m_ascii.push_back("Did you intend to use --recursive");
		m_ascii.push_back("Cannot process UTF-32 encoding");
		m_ascii.push_back("\nArtistic Style has terminated");
	}
	void getPrintSpecifiers(string& stringIn, vector<string>& specifiers)
	// Extract the print specifiers from a string.
	{
		for (size_t i = 0; i < stringIn.length(); i++)
		{
			i = stringIn.find('%', i);
			if (i == string::npos)
				break;
			size_t iStart = i;
			i = stringIn.find_first_not_of(" \t", i + 1);
			string specifier = stringIn.substr(iStart, i - iStart + 1);
			specifiers.push_back(specifier);
		}
	}
	void getPrintSpecifiers(wstring& stringIn, vector<wstring>& specifiers)
	// Extract the print specifiers from a WIDE string.
	{
		for (size_t i = 0; i < stringIn.length(); i++)
		{
			i = stringIn.find('%', i);
			if (i == string::npos)
				break;
			size_t iStart = i;
			i = stringIn.find_first_not_of(L" \t", i + 1);
			wstring specifier = stringIn.substr(iStart, i - iStart + 1);
			specifiers.push_back(specifier);
		}
	}
	template <typename T>	// string and wstring
	bool hasLineEnd(T& stringIn)
	// Check for a ending line end character.
	{
		int lastChar = stringIn.length() - 1;
		if (lastChar > 0 && stringIn[lastChar] == '\n')
			return true;
		return false;
	}
	string removeLineEnd(string& stringIn)
	// Remove an ending line end character.
	{
		string stringOut = stringIn;
		if (hasLineEnd(stringOut))
			stringOut.erase(stringOut.length() - 1);
		return stringOut;
	}
	void testTranslation(Translation& language)
	// Call this to test a language translation.
	{
		// check size of vector
		// less than is OK since missing entries will be checked
		size_t numberOfTranslations = language.getTranslationVectorSize();
		EXPECT_GE(m_ascii.size(), numberOfTranslations) << "translations vector has extra entries";
		for (size_t i = 0; i < m_ascii.size(); i++)
		{
			// remove the line end for printing
			string asciiPrt = removeLineEnd(m_ascii[i]);
			// test that the string is found
			wstring translation;
			bool stringOk = language.getWideTranslation(m_ascii[i], translation);
//			stringOk = false;
			if (!stringOk)
			{
				EXPECT_TRUE(stringOk) << "string not found \"" << asciiPrt << "\"";
				continue;	// no more tests for this string
			}
			// test for line end
			bool asciiHasLineEnd = hasLineEnd(m_ascii[i]);
			bool translationHasLineEnd =  hasLineEnd(translation);
//			translationHasLineEnd = !asciiHasLineEnd;
			EXPECT_TRUE(asciiHasLineEnd == translationHasLineEnd) << "bad line end \"" << asciiPrt << "\"";
			// check the number of print specifiers
			vector<string> asciiSpecifiers;
			vector<wstring> translationSpecifiers;
			getPrintSpecifiers(m_ascii[i], asciiSpecifiers);
			getPrintSpecifiers(translation, translationSpecifiers);
			ASSERT_EQ(asciiSpecifiers.size(), translationSpecifiers.size()) << "number of print specifiers \"" << asciiPrt << "\"";
			// check the type of print specifiers
			for (size_t j = 0; j < asciiSpecifiers.size(); j++)
			{
				// conversion should be OK since specifiers are ascii
				string asciiSpecifier = asciiSpecifiers[j];
				string translationSpecifier = language.convertToMultiByte(translationSpecifiers[j]);
				ASSERT_EQ(asciiSpecifier, translationSpecifier)	<< "print specifiers value \"" << asciiPrt << "\"";
			}
		}
	}
};	// struct TranslationF

TEST_F(TranslationF, ChineseSimplified)
// Test the Chinese Simplified translation.
{
	ChineseSimplified chinese;
	testTranslation(chinese);
}

TEST_F(TranslationF, ChineseTraditional)
// Test the Chinese Traditional translation.
{
	ChineseTraditional chinese;
	testTranslation(chinese);
}

TEST_F(TranslationF, English)
// Test the English translation.
{
	// English does NOT get translated.
	// The original value should be returned.
	English english;
	// check size of vector
	size_t numberOfTranslations = english.getTranslationVectorSize();
	EXPECT_TRUE(numberOfTranslations == 0) << "translations vector should be empty";
	for (size_t i = 0; i < m_ascii.size(); i++)
	{
		// remove the line end for printing
		string asciiPrt = removeLineEnd(m_ascii[i]);
		// use "translate" test that the original string is returned
		string translation = english.translate(m_ascii[i]);
		EXPECT_TRUE(m_ascii[i] == translation) << "translation error \"" << asciiPrt << "\"";
	}
}

TEST_F(TranslationF, French)
// Test the French translation.
{
	French french;
	testTranslation(french);
}

TEST_F(TranslationF, German)
// Test the German translation.
{
	German german;
	testTranslation(german);
}

TEST_F(TranslationF, Hindi)
// Test the Hindi translation.
{
	Hindi hindi;
	testTranslation(hindi);
}

TEST_F(TranslationF, Spanish)
// Test the Spanish translation.
{
	Spanish spanish;
	testTranslation(spanish);
}

//----------------------------------------------------------------------------

}  // namespace
