// AStyleTestCon tests the ASConsole class only. This class is used only in
// the console build. It also tests the parseOption function for options used
// by only by the console build (e.g. recursive, preserve-date, verbose). It
// does not explicitely test the ASStreamIterator class or any other part
// of the program.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <time.h>
#include "AStyleTestCon.h"

//----------------------------------------------------------------------------
// AStyle test processOptions() for console and file options
// test vectors excludeVector, excludeHitsVector, fileNameVector, optionsVector, fileOptionsVector
//----------------------------------------------------------------------------

TEST(processOptionsExcludeVector)
// test processOptions for excludeVector
{
	createConsoleGlobalObject();

	vector<string> excludesIn;
	excludesIn.push_back("--exclude=../test/prog1.cpp");
	excludesIn.push_back("--exclude=../test\\prog2.cpp");
	excludesIn.push_back("--exclude=../test/prog3.cpp");
	excludesIn.push_back("--exclude=prog4.cpp");
	excludesIn.push_back("--exclude=/prog5.cpp");
	excludesIn.push_back("--exclude=\\prog6.cpp");
	excludesIn.push_back("--exclude=../testdir1/");
	excludesIn.push_back("--exclude=..\\testdir2");
	excludesIn.push_back("--exclude=../testdir3\\");
	excludesIn.push_back("--exclude=testdir4");
	excludesIn.push_back("--exclude=/testdir5");
	excludesIn.push_back("--exclude=\\testdir6");

	// build vector for checking results
	vector<string> excludes;
	for (size_t i = 0; i < excludesIn.size(); i++)
	{
		excludes.push_back(excludesIn[i].substr(10));
		g_console->standardizePath(excludes[i], true);
	}

	// build argv array of pointers for input
	char** argv = buildArgv(excludesIn);
	int argc = excludesIn.size() + 1;

	// build and test the vector excludeVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	// check excludeVector
	vector<string> excludeVector = g_console->getExcludeVector();
	CHECK_EQUAL(excludesIn.size(), excludeVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(excludesIn.size(), excludeVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(excludes[i], excludeVector[i]);

	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsExcludeHitsVector)
// test processOptions for excludeHitsVector
{
	createConsoleGlobalObject();

	vector<string> excludesIn;
	excludesIn.push_back("--exclude=../test/prog1.cpp");
	excludesIn.push_back("--exclude=../test\\prog2.cpp");
	excludesIn.push_back("--exclude=../test/prog3.cpp");
	excludesIn.push_back("--exclude=../testdir1/");
	excludesIn.push_back("--exclude=..\\testdir2");
	excludesIn.push_back("--exclude=../testdir3\\");

	// build argv array of pointers for input
	char** argv = buildArgv(excludesIn);
	int argc = excludesIn.size() + 1;

	// build and test the vector excludeHitsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	// check excludeHitsVector
	vector<bool> excludeHitsVector = g_console->getExcludeHitsVector();
	CHECK_EQUAL(excludesIn.size(), excludeHitsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(excludesIn.size(), excludeHitsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK(!excludeHitsVector[i]);

	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileNameVector)
// test processOptions for fileNameVector
{
	createConsoleGlobalObject();
	vector<string> fileNameIn;
	fileNameIn.push_back("../..\\..\\srccon/*.cpp");

	vector<string> fileName;
	fileName.push_back("../../../srccon/*.cpp");
	g_console->standardizePath(fileName.back());

	// build argv array of pointers for input
	char** argv = buildArgv(fileNameIn);
	int argc = fileNameIn.size() + 1;

	// build and test the vector fileNameVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);
	vector<string> fileNameVector = g_console->getFileNameVector();
	CHECK_EQUAL(fileName.size(), fileNameVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileName.size(), fileNameVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileName[i], fileNameVector[i]);

	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsOptionsVector)
// test processOptions for optionsVector
{
	createConsoleGlobalObject();
	vector<string> optionsIn;
	optionsIn.push_back("--style=allman");
	optionsIn.push_back("--indent-classes");
	optionsIn.push_back("-OoP");
	optionsIn.push_back("-Ewc");
	optionsIn.push_back("--align-pointer=type");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	vector<string> optionsVector = g_console->getOptionsVector();
	CHECK_EQUAL(optionsIn.size(), optionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(optionsIn.size(), optionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(optionsIn[i], optionsVector[i]);

	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVector)
// test processOptions for fileOptionsVector with --options=###
{
	createConsoleGlobalObject();
	char fileIn[] =
		"# this line is a comment\n"
		"--brackets=attach   # this is a line-end comment\n"
		"\n"
		"# long options can be written without the preceding '--'\n"
		"indent-switches     # cannot do this on the command line\n"
		"\n"
		"# short options must have the preceding '-'\n"
		"-t -p\n"
		"\n"
		"# short options can be concatenated together\n"
		"-M65Ucv\n"
		"\n"
		"# options can be separated with commas\n"
		"indent-classes,-K\n";

	vector<string> fileOptions;
	fileOptions.push_back("--brackets=attach");
	fileOptions.push_back("indent-switches");
	fileOptions.push_back("-t");
	fileOptions.push_back("-p");
	fileOptions.push_back("-M65Ucv");
	fileOptions.push_back("indent-classes");
	fileOptions.push_back("-K");

	// write the options file
	string optionsFileName = getTestDirectory() + "/astylerc.txt";
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(optionsFileName, fileIn))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	CHECK_EQUAL(fileOptions.size(), fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(), fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], fileOptionsVector[i]);

	removeOptionsFile(optionsFileName);
	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorEnvVar)
// test processOptions for fileOptionsVector
//     with ARTISTIC_STYLE_OPTIONS enviromnent variable
{
	createConsoleGlobalObject();
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes\n";

	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-classes");

	// set the new environment variable
	string envFilePath =  getTestDirectory() + "/astylexx";
	string envValue = "ARTISTIC_STYLE_OPTIONS=" + envFilePath;
	g_console->standardizePath(envFilePath);
	g_console->standardizePath(envValue);
	int isError = putenv(const_cast<char*>(envValue.c_str()));
	if (isError)
	{
		systemPause("Could not set ARTISTIC_STYLE_OPTIONS environment variable");
		return;
	}

	// write the options file
	if (!writeOptionsFile(envFilePath.c_str(), fileIn))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	CHECK_EQUAL(fileOptions.size(), fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(), fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], fileOptionsVector[i]);

	// clear the environment variable
	string envClear = "ARTISTIC_STYLE_OPTIONS=";
	putenv(const_cast<char*>(envClear.c_str()));

	// cleanup
	removeOptionsFile(envFilePath);
	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorHome)
// test processOptions for fileOptionsVector with $HOME options
{
	createConsoleGlobalObject();
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes\n";

	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-classes");

	// write the file
#ifdef _WIN32
	char* env = getenv("USERPROFILE");
	char name[] = "/astylerc";
#else
	char* env = getenv("HOME");
	char name[] = "/.astylerc";
#endif
	if (env == NULL)
	{
		systemPause("Could not get $HOME directory");
		return;
	}

	// write the options file
	string optionsFileName = string(env) + name;
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(optionsFileName, fileIn))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	CHECK_EQUAL(fileOptions.size(), fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(), fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], fileOptionsVector[i]);

	removeOptionsFile(optionsFileName);
	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorNone)
// test processOptions for fileOptionsVector with --options=none
// should not process the astylerc file
{
	createConsoleGlobalObject();
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes\n";

	// write the file
#ifdef _WIN32
	char* env = getenv("USERPROFILE");
	char name[] = "/astylerc";
#else
	char* env = getenv("HOME");
	char name[] = "/.astylerc";
#endif
	if (env == NULL)
	{
		systemPause("Could not get $HOME directory");
		return;
	}
	string optionsFileName = string(env) + name;
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(optionsFileName, fileIn))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	optionsIn.push_back("--options=none");
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	CHECK(fileOptionsVector.size() == 0);

	removeOptionsFile(optionsFileName);
	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorNoLineEnd)
// test processOptions for fileOptionsVector with --options=###
//    and NO final line end
{
	createConsoleGlobalObject();
	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-classes";		// *** no final line end ***

	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-classes");

	// write the options file
	string optionsFileName = getTestDirectory() + "/astylerc";
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(optionsFileName, fileIn))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	CHECK_EQUAL(fileOptions.size(), fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(), fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], fileOptionsVector[i]);

	removeOptionsFile(optionsFileName);
	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorError)
// test processOptions for fileOptionsVector for an options error
// input with --options=###
// --indent-invalid is not a valid option
{
	createConsoleGlobalObject();
	// capture the error message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	char fileIn[] =
		"--style=allman\n"
		"-OoP\n"
		"--indent-invalid\n"
		"--indent-classes\n";

	vector<string> fileOptions;
	fileOptions.push_back("--style=allman");
	fileOptions.push_back("-OoP");
	fileOptions.push_back("--indent-invalid");
	fileOptions.push_back("--indent-classes");

	// write options the file
	string optionsFileName = getTestDirectory() + "/astylerc.txt";
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(optionsFileName, fileIn))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_FAILURE);
	string errMsg = "Invalid option in default options file: indent-invalid";
	string outMsg = msgOut->str().substr(0, errMsg.length());
	CHECK_EQUAL(errMsg, outMsg);

	// a vector containing the options should still be built
	vector<string> fileOptionsVector = g_console->getFileOptionsVector();
	CHECK_EQUAL(fileOptions.size(), fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(), fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], fileOptionsVector[i]);

	removeOptionsFile(optionsFileName);
	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorFileError1)
// test processOptions with an options file error
// input with --options=###
// invalidrc.txt is not a valid file
{
	createConsoleGlobalObject();
	// capture the error message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	// build argv array of pointers for input
	string optionsFileName = "../../srccon/invalidrc.txt";
	g_console->standardizePath(optionsFileName);
	vector<string> optionsIn;
	optionsIn.push_back("--options=" + optionsFileName);

	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_FAILURE);
	string errMsg = "Could not open options file: " + optionsFileName;
	string outMsg = msgOut->str().substr(0, errMsg.length());
	CHECK_EQUAL(errMsg, outMsg);

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileOptionsVectorFileError2)
// test processOptions with an options file error
// input with --options= (no filename)
{
	createConsoleGlobalObject();
	// capture the error message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	// build argv array of pointers for input
	vector<string> optionsIn;
	optionsIn.push_back("--options=");

	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_FAILURE);
	string errMsg = "Could not open options file: ";
	string outMsg = msgOut->str().substr(0, errMsg.length());
	CHECK_EQUAL(errMsg, outMsg);

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsConsoleOptions)
// test processOptions for console options
{
	createConsoleGlobalObject();

	vector<string> optionsIn;
	optionsIn.push_back("--suffix=none");
	optionsIn.push_back("--suffix=.old");
	optionsIn.push_back("--recursive");
	optionsIn.push_back("--verbose");
	optionsIn.push_back("--formatted");
	optionsIn.push_back("--quiet");
	optionsIn.push_back("--errors-to-stdout");
	optionsIn.push_back("--preserve-date");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);

	CHECK(g_console->getNoBackup());
	CHECK_EQUAL(string(".old"), g_console->getOrigSuffix());
	CHECK(g_console->getIsRecursive());
	CHECK(g_console->getIsVerbose());
	CHECK(g_console->getIsFormattedOnly());
	CHECK(g_console->getIsQuiet());
	CHECK(_err == &cout);
	CHECK(g_console->getPreserveDate());

	delete [] argv;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsConsoleOptionsShort)
// test processOptions for short console options
{
	createConsoleGlobalObject();

	vector<string> optionsIn;
	optionsIn.push_back("-n");	// suffix=none
	optionsIn.push_back("-r");	// recursive
	optionsIn.push_back("-R");	// recursive
	optionsIn.push_back("-v");	// verbose
	optionsIn.push_back("-Q");	// formatted
	optionsIn.push_back("-q");	// quiet
	optionsIn.push_back("-X");	// errors-to-stdout
	optionsIn.push_back("-Z");	// preserve-date

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);

	CHECK(g_console->getNoBackup());
	CHECK(g_console->getIsRecursive());
	CHECK(g_console->getIsVerbose());
	CHECK(g_console->getIsFormattedOnly());
	CHECK(g_console->getIsQuiet());
	CHECK(_err == &cout);
	CHECK(g_console->getPreserveDate());

	delete [] argv;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsConsoleOptionsError)
// test processOptions for an options error
// --indent-invalid is not a valid option
{
	createConsoleGlobalObject();
	// capture the error message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	vector<string> optionsIn;
	optionsIn.push_back("--style=allman");
	optionsIn.push_back("-OoP");
	optionsIn.push_back("--indent-invalid");
	optionsIn.push_back("--indent-classes");


	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_FAILURE);
	string errMsg = "Invalid command line option: indent-invalid";
	string outMsg = msgOut->str().substr(0, errMsg.length());
	CHECK_EQUAL(errMsg, outMsg);

	// a vector containing the options should still be built
	vector<string> optionsVector = g_console->getOptionsVector();
	CHECK_EQUAL(optionsIn.size(), optionsVector.size());
	// use min size in case the vectors are not equal
	size_t iMax = min(optionsIn.size(), optionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(optionsIn[i], optionsVector[i]);

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle test --help and --version options
//----------------------------------------------------------------------------

TEST(processOptionsHelpOption)
// test processOptions for help option
{
	createConsoleGlobalObject();
	// capture the help message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	vector<string> optionsIn;
	optionsIn.push_back("--help");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_SUCCESS);
	CHECK(msgOut->str().length() > 5000);
//	cout << msgOut->str().length() << endl;

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsHelpOptionShort1)
// test processOptions for help short option -h
{
	createConsoleGlobalObject();
	// capture the help message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	vector<string> optionsIn;
	optionsIn.push_back("-h");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_SUCCESS);
	CHECK(msgOut->str().length() > 5000);
//	cout << msgOut->str().length() << endl;

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsHelpOptionShort2)
// test processOptions for help short option -?
{
	createConsoleGlobalObject();
	// capture the help message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	vector<string> optionsIn;
	optionsIn.push_back("-?");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_SUCCESS);
	CHECK(msgOut->str().length() > 5000);
//	cout << msgOut->str().length() << endl;

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsVersionOption)
// test processOptions for version option
{
	createConsoleGlobalObject();
	// capture the help message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	vector<string> optionsIn;
	optionsIn.push_back("--version");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_SUCCESS);
	CHECK(msgOut->str().length() < 100);
//	cout << msgOut->str().length() << endl;

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

TEST(processOptionsVersionOptionShort)
// test processOptions for version short option
{
	createConsoleGlobalObject();
	// capture the version message
	stringstream* msgOut = new stringstream;
	_err = msgOut;

	vector<string> optionsIn;
	optionsIn.push_back("-V");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == END_SUCCESS);
	CHECK(msgOut->str().length() > 10);
	CHECK(msgOut->str().length() < 100);
//	cout << msgOut->str().length() << endl;

	delete [] argv;
	delete msgOut;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle test --suffix option
//----------------------------------------------------------------------------

struct testSuffix
{
	vector<string> fileNames;

	// build fileNames vector and write the output files
	testSuffix()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();
		fileNames.push_back(getTestDirectory() + "/suffix1.cpp");

		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
		}
	}

	~testSuffix()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testSuffix, suffixNone)
// test suffix=none option on files
{
	assert(g_console != NULL);

	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);		// test variable

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// all files should be formatted
	CHECK_EQUAL((int)fileNames.size(), g_console->getFilesFormatted());

	// check for .orig file on disk
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string origFileName = fileNames[0] + ".orig";
		struct stat stBuf;
		// display error if file is present
		if (stat(origFileName.c_str(), &stBuf) != -1)
			CHECK_EQUAL("\"no file\"", origFileName.c_str());
	}
}

TEST_FIXTURE(testSuffix, suffixDotOld)
// test suffix=.old option on files (with dot)
{
	assert(g_console != NULL);

	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setOrigSuffix(".old"); 	// test variable (with dot)

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// all files should be formatted
	CHECK(fileNames.size() > 0);
	CHECK_EQUAL((int)fileNames.size(), g_console->getFilesFormatted());

	// check for .old file on disk
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string origFileName = fileNames[0] + ".old";
		struct stat stBuf;
		// display error if file is not present
		if (stat(origFileName.c_str(), &stBuf) == -1)
			CHECK_EQUAL(origFileName.c_str(), "\"no file\"");
	}
}

TEST_FIXTURE(testSuffix, suffixXXX)
// test suffix=xxx option on files (no dot)
{
	assert(g_console != NULL);

	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setOrigSuffix("xxx"); 	// test variable (no dot)

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// all files should be formatted
	CHECK(fileNames.size() > 0);
	CHECK_EQUAL((int)fileNames.size(), g_console->getFilesFormatted());

	// check for xxx file on disk
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		string origFileName = fileNames[0] + "xxx";
		struct stat stBuf;
		// display error if file is not present
		if (stat(origFileName.c_str(), &stBuf) == -1)
			CHECK_EQUAL(origFileName.c_str(), "\"no file\"");
	}
}

//----------------------------------------------------------------------------
// AStyle test getCurrentDirectory function
//----------------------------------------------------------------------------

TEST(getCurrentDirectory)
// test getCurrentDirectory function
{
	createConsoleGlobalObject();
	g_console->setNoBackup(true);
	g_console->setIsQuiet(true);		// change this to see results

	char textIn[] = "void foo(){}\n";

	// a file without a path will call the g_console->getCurrentDirectory
	string testFile = "/testGetCurrentDirectory.cpp";
	string testFilePath = getCurrentDirectory() + testFile;
	g_console->standardizePath(testFilePath);

	// write the output file
	ofstream fout(testFilePath.c_str(), ios::binary | ios::trunc);
	if (!fout)
	{
		systemPause("Could not open output file: " + testFilePath);
		return;
	}
	fout << textIn;
	fout.close();

	// build the fileNameVector
	// cannot use buildFileNameVector() function for getCurrentDirectory()
	ASFormatter formatter;
	vector<string> fileNameVector;
	fileNameVector.push_back(testFilePath);
	char** argv = buildArgv(fileNameVector);
	int argc = fileNameVector.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);
	delete[] argv;

	// process entries in the fileNameVector
	g_console->processFiles(formatter);
	vector<string> fileName = g_console->getFileName();
	CHECK_EQUAL(testFilePath, fileName[0]);

	// remove test file
	errno = 0;
	remove(testFilePath.c_str());
	if (errno)
	{
		perror("errno message");
		systemPause("Cannot remove getCurrentDirectory file: " + testFile);
	}
	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle test stringEndsWith function
//----------------------------------------------------------------------------

TEST(stringEndsWith)
{
	createConsoleGlobalObject();

	bool result1 = g_console->stringEndsWith("fileName.cpp", string(".cpp"));
	CHECK(result1);
	bool result2 = g_console->stringEndsWith("fileName.cpp", string(".xxx"));
	CHECK(!result2);
	bool result3 = g_console->stringEndsWith("fileNamenoextension", string("noextension"));
	CHECK(result3);
	bool result4 = g_console->stringEndsWith("wholename", string("wholename"));
	CHECK(result4);
	bool result5 = g_console->stringEndsWith("long", string("xlong"));
	CHECK(!result5);

	deleteConsoleGlobalObject();
}

//----------------------------------------------------------------------------
// AStyle test file encoding
//----------------------------------------------------------------------------

struct testEncoding
{
	vector<string> fileNames;

	// build fileNames vector and write the output files
	testEncoding()
	{
		char textIn[] = "this text will not be readable";
		int textsize = sizeof(textIn);
		char textBOM[50];

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();
		// NOTE: some string functions don't work with NULLs (e.g. length())
		// UTF-16BE
		memcpy(textBOM, "\xFE\xFF", 2);
		memcpy(textBOM+2, textIn, sizeof(textIn));
		fileNames.push_back(getTestDirectory() + "/UTF-16BE.cpp");
		createTestFile(fileNames.back(), textBOM, textsize);
		// UTF-16LE
		memcpy(textBOM, "\xFF\xFE", 2);
		memcpy(textBOM+2, textIn, sizeof(textIn));
		fileNames.push_back(getTestDirectory() + "/UTF-16LE.cpp");
		createTestFile(fileNames.back(), textBOM, textsize);
		// UTF-32BE
		memcpy(textBOM, "\x00\x00\xFE\xFF", 4);
		memcpy(textBOM+4, textIn, sizeof(textIn));
		fileNames.push_back(getTestDirectory() + "/UTF-32BE.cpp");
		createTestFile(fileNames.back(), textBOM, textsize);
		// UTF-32LE
		memcpy(textBOM, "\xFF\xFE\x00\x00", 4);
		memcpy(textBOM+4, textIn, sizeof(textIn));
		fileNames.push_back(getTestDirectory() + "/UTF-32LE.cpp");
		createTestFile(fileNames.back(), textBOM, textsize);
		// no encoding
		memcpy(textBOM, textIn, sizeof(textIn));
		fileNames.push_back(getTestDirectory() + "/NoEncoding.cpp");
		createTestFile(fileNames.back(), textBOM, textsize);
		// zero length line
		memcpy(textBOM, "\n", 4);
		memcpy(textBOM+1, textIn, sizeof(textIn));
		fileNames.push_back(getTestDirectory() + "/ZeroLength.cpp");
		createTestFile(fileNames.back(), textBOM, textsize);
	}

	~testEncoding()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testEncoding, encodingUTF16BE)
// test encoding with UTF-16BE BOM
{
	ifstream in(fileNames[0].c_str(), ios::binary);
	int encoding = g_console->getFileEncoding(in);
	CHECK_EQUAL(UTF_16BE, encoding);
}

TEST_FIXTURE(testEncoding, encodingUTF16LE)
// test encoding with UTF-16LE BOM
{
	ifstream in(fileNames[1].c_str(), ios::binary);
	int encoding = g_console->getFileEncoding(in);
	CHECK_EQUAL(UTF_16LE, encoding);
}

TEST_FIXTURE(testEncoding, encodingUTF32BE)
// test encoding with UTF-32BE BOM
{
	ifstream in(fileNames[2].c_str(), ios::binary);
	int encoding = g_console->getFileEncoding(in);
	CHECK_EQUAL(UTF_32BE, encoding);
}

TEST_FIXTURE(testEncoding, encodingUTF32LE)
// test encoding with UTF-32LE BOM
{
	ifstream in(fileNames[3].c_str(), ios::binary);
	int encoding = g_console->getFileEncoding(in);
	CHECK_EQUAL(UTF_32LE, encoding);
}

TEST_FIXTURE(testEncoding, encodingNone)
// test encoding with no encoding
{
	ifstream in(fileNames[4].c_str(), ios::binary);
	int encoding = g_console->getFileEncoding(in);
	CHECK_EQUAL(ENCODING_OK, encoding);
}

TEST_FIXTURE(testEncoding, encodingZeroLength)
// test encoding with no encoding
{
	ifstream in(fileNames[5].c_str(), ios::binary);
	int encoding = g_console->getFileEncoding(in);
	CHECK_EQUAL(ENCODING_OK, encoding);
}

TEST_FIXTURE(testEncoding, encodingFileTest)
// test rejection of UTF-16 and UTF-32 files
{
	assert(g_console != NULL);

	// initialize variables
	g_console->setIsQuiet(true);		// change this to see results

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// all files should be unformatted
	CHECK_EQUAL((int)fileNames.size(), g_console->getFilesUnchanged());
}

//----------------------------------------------------------------------------
// AStyle test preserve-date option
//----------------------------------------------------------------------------

struct testPreserveDate
{
	vector<string> fileNames;
	struct utimbuf ut;

	// build fileNames vector and write the output files with an old date
	testPreserveDate()
	{
		char textIn[] =
			"\nvoid foo()\n"
			"{\n"
			"bar();\n"
			"}\n";

		// Jan 1, 2008
		struct tm t;
		t.tm_mday  = 1;
		t.tm_mon   = 0;
		t.tm_year  = 108;
		t.tm_hour  = 0;
		t.tm_min   = 0;
		t.tm_sec   = 0;
		t.tm_isdst = 0;
		ut.actime = ut.modtime = mktime(&t);

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();
		fileNames.push_back(getTestDirectory() + "/PreserveDate1.cpp");
		fileNames.push_back(getTestDirectory() + "/PreserveDate2.cpp");

		// write files and change the date
		for (size_t i = 0; i < fileNames.size(); i++)
		{
			g_console->standardizePath(fileNames[i]);
			createTestFile(fileNames[i], textIn);
			utime(fileNames[i].c_str(), &ut);
		}
	}

	~testPreserveDate()
	{
		deleteConsoleGlobalObject();
	}

	// get the date from time_t
	string getMDY(time_t dateIn)
	{
		string date = ctime(&dateIn);
		string dateMDY = date.erase(11,9);	// remove the time
		// cout << dateMDY << endl;
		return dateMDY;
	}
};

TEST_FIXTURE(testPreserveDate, preserveDate)
// test formatting with preserve-date option
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	g_console->setPreserveDate(true);

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// loop thru fileNames vector checking the dates
	// difference is added in preserveFileDate() in astyle_main
	struct stat s;
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		stat(fileNames[i].c_str(), &s);
		CHECK_EQUAL(10, difftime(s.st_mtime, ut.modtime));
	}
}

TEST_FIXTURE(testPreserveDate, preserveDateSans)
// test formatting without preserve-date option
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);
	g_console->setPreserveDate(false);

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// loop thru fileNames vector checking the dates
	string currMDY = getMDY(time(NULL));
	struct stat s;
	for (size_t i = 0; i < fileNames.size(); i++)
	{
		stat(fileNames[i].c_str(), &s);
		string fileMDY = getMDY(s.st_mtime);
		CHECK_EQUAL(currMDY, fileMDY);
	}
}

//----------------------------------------------------------------------------
// AStyle test checksum procedure
//----------------------------------------------------------------------------

struct testChecksum
{
	string fileName;
	size_t textChecksum;

	// build fileNames vector and write the output file
	testChecksum()
	{
		textChecksum = 9699;
		char textIn[] =
			"\n#include <stdio.h>\n"
			"\n"
			"void foo(int a)\n"
			"{\n"
			"    int i = 10;\n"
			"    int i2 = 12;\n"
			"    int i3 = i + i2;\n"
			"    printf(\"i3 = %d\", i3);\n"
			"    // for add-brackets test\n"
			"    if (a == 0)\n"
			"        x = 0;\n"
			"}";

		cleanTestDirectory(getTestDirectory());
		createConsoleGlobalObject();
		fileName = getTestDirectory() + "/TestChecksum.cpp";
		createTestFile(fileName, textIn);
	}

	~testChecksum()
	{
		deleteConsoleGlobalObject();
	}
};

TEST_FIXTURE(testChecksum, checksum)
// test checksum procedure
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);

	// build the fileNameVector
	ASFormatter formatter;
	vector<string> fileNameVector;
	int processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// verify the checksums
	size_t checksumIn = formatter.getChecksumIn();;
	size_t checksumOut = formatter.getChecksumOut();;
#ifdef NDEBUG
	CHECK_EQUAL(0U, checksumIn);
	CHECK_EQUAL(0U, checksumOut);
#else
	CHECK_EQUAL(textChecksum, checksumIn);
	CHECK_EQUAL(textChecksum, checksumOut);
#endif
	CHECK(formatter.getChecksumDiff() == 0);
}

TEST_FIXTURE(testChecksum, checksumAddBrackets)
// test checksum procedure with add-brackets
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);

	// options for test
	ASFormatter formatter;
	vector<string> optionsIn;
	optionsIn.push_back("--add-brackets");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build the vector optionsVector
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	// build the fileNameVector
	vector<string> fileNameVector;
	processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// verify the checksums
	textChecksum += '{' + '}';
	size_t checksumIn = formatter.getChecksumIn();
	size_t checksumOut = formatter.getChecksumOut();
#ifdef NDEBUG
	CHECK_EQUAL(0U, checksumIn);
	CHECK_EQUAL(0U, checksumOut);
#else
	CHECK_EQUAL(textChecksum, checksumIn);
	CHECK_EQUAL(textChecksum, checksumOut);
#endif
	CHECK(formatter.getChecksumDiff() == 0);

	delete [] argv;
}

TEST_FIXTURE(testChecksum, checksumAddOneLineBrackets)
// test checksum procedure with add-one-line-brackets
{
	assert(g_console != NULL);
	g_console->setIsQuiet(true);		// change this to see results
	g_console->setNoBackup(true);

	// options for test
	ASFormatter formatter;
	vector<string> optionsIn;
	optionsIn.push_back("--add-one-line-brackets");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build the vector optionsVector
	int processReturn = g_console->processOptions(argc, argv, formatter);
	CHECK(processReturn == CONTINUE);

	// build the fileNameVector
	vector<string> fileNameVector;
	processReturn = buildFileNameVector("/*.cpp", fileNameVector, formatter);
	CHECK(processReturn == CONTINUE);

	// process entries in the fileNameVector
	g_console->processFiles(formatter);

	// verify the checksums
	textChecksum += '{' + '}';
	size_t checksumIn = formatter.getChecksumIn();
	size_t checksumOut = formatter.getChecksumOut();
#ifdef NDEBUG
	CHECK_EQUAL(0U, checksumIn);
	CHECK_EQUAL(0U, checksumOut);
#else
	CHECK_EQUAL(textChecksum, checksumIn);
	CHECK_EQUAL(textChecksum, checksumOut);
#endif
	CHECK(formatter.getChecksumDiff() == 0);

	delete [] argv;
}

//----------------------------------------------------------------------------
// AStyle test ASResources operator vectors sequence
//----------------------------------------------------------------------------

TEST(buildOperatorsSequence)
// check the sequence of ASResource::buildOperators
{
	// build the operators vector
	ASResource resource;
	vector<const string*> operators;
	resource.buildOperators(&operators);

	// test the operators vector sequence
	// vector sequence is descending length of the operators
	size_t prevOperatorLength = 9;
	for (size_t i = 0; i < operators.size(); i++)
	{
		CHECK(prevOperatorLength >= (*operators[i]).length());
		prevOperatorLength = (*operators[i]).length();
	}
}

TEST(buildAssignmentOperatorsSequence)
// check the sequence of ASResource::buildAssignmentOperators
{
	// build the assignmentOperators vector
	ASResource resource;
	vector<const string*> assignmentOperators;
	resource.buildAssignmentOperators(&assignmentOperators);

	// test the assignmentOperators vector sequence
	// vector sequence is descending length of the operators
	size_t prevOperatorLength = 9;
	for (size_t i = 0; i < assignmentOperators.size(); i++)
	{
		CHECK(prevOperatorLength >= (*assignmentOperators[i]).length());
		prevOperatorLength = (*assignmentOperators[i]).length();
	}
}

TEST(buildNonAssignmentOperatorsSequence)
// check the sequence of ASResource::buildNonAssignmentOperators
{
	// build the nonAssignmentOperators vector
	ASResource resource;
	vector<const string*> nonAssignmentOperators;
	resource.buildNonAssignmentOperators(&nonAssignmentOperators);

	// test the nonAssignmentOperators vector sequence
	// vector sequence is descending length of the operators
	size_t prevOperatorLength = 9;
	for (size_t i = 0; i < nonAssignmentOperators.size(); i++)
	{
		CHECK(prevOperatorLength >= (*nonAssignmentOperators[i]).length());
		prevOperatorLength = (*nonAssignmentOperators[i]).length();
	}
}

//----------------------------------------------------------------------------
// AStyle test ASResources header vectors sequence
//----------------------------------------------------------------------------

TEST(buildCastOperatorsSequence)
// check the sequence of ASResource::buildCastOperators
{
	// build the castOperators vector
	ASResource resource;
	vector<const string*> castOperators;
	resource.buildCastOperators(&castOperators);

	// test the castOperators vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < castOperators.size(); i++)
	{
		CHECK(prevHeader < (*castOperators[i]));
		prevHeader = (*castOperators[i]);
	}
}

TEST(buildHeadersSequence)
// check the sequence of ASResource::buildHeaders
{
	// build the headers vector
	ASResource resource;
	vector<const string*> headers;
	resource.buildHeaders(&headers, SHARP_TYPE, true);

	// test the headers vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < headers.size(); i++)
	{
		CHECK(prevHeader < (*headers[i]));
		prevHeader = (*headers[i]);
	}
}

TEST(buildIndentableHeadersSequence)
// check the sequence of ASResource::buildIndentableHeaders
{
	// build the indentableHeaders vector
	ASResource resource;
	vector<const string*> indentableHeaders;
	resource.buildIndentableHeaders(&indentableHeaders);

	// test the indentableHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < indentableHeaders.size(); i++)
	{
		CHECK(prevHeader < (*indentableHeaders[i]));
		prevHeader = (*indentableHeaders[i]);
	}
}

TEST(buildNonParenHeadersSequence)
// check the sequence of ASResource::buildNonParenHeaders
{
	// build the nonParenHeaders vector
	ASResource resource;
	vector<const string*> nonParenHeaders;
	resource.buildNonParenHeaders(&nonParenHeaders, SHARP_TYPE, true);

	// test the nonParenHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < nonParenHeaders.size(); i++)
	{
		CHECK(prevHeader < (*nonParenHeaders[i]));
		prevHeader = (*nonParenHeaders[i]);
	}
}

TEST(buildPreBlockStatementsSequence)
// check the sequence of ASResource::buildPreBlockStatements
{
	// build the preBlockStatements vector
	ASResource resource;
	vector<const string*> preBlockStatements;
	resource.buildPreBlockStatements(&preBlockStatements, SHARP_TYPE);

	// test the preBlockStatements vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < preBlockStatements.size(); i++)
	{
		CHECK(prevHeader < (*preBlockStatements[i]));
		prevHeader = (*preBlockStatements[i]);
	}
}

TEST(buildPreCommandHeadersSequence)
// check the sequence of ASResource::buildPreCommandHeaders
{
	// build the preCommandHeaders vector
	ASResource resource;
	vector<const string*> preCommandHeaders;
	resource.buildPreCommandHeaders(&preCommandHeaders, SHARP_TYPE);

	// test the preCommandHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < preCommandHeaders.size(); i++)
	{
		CHECK(prevHeader < (*preCommandHeaders[i]));
		prevHeader = (*preCommandHeaders[i]);
	}
}

TEST(buildPreDefinitionHeadersSequence)
// check the sequence of ASResource::buildPreDefinitionHeaders
{
	// build the preDefinitionHeaders vector
	ASResource resource;
	vector<const string*> preDefinitionHeaders;
	resource.buildPreDefinitionHeaders(&preDefinitionHeaders, SHARP_TYPE);

	// test the preDefinitionHeaders vector sequence
	// vector sequence is ascending header value
	string prevHeader;
	for (size_t i = 0; i < preDefinitionHeaders.size(); i++)
	{
		CHECK(prevHeader < (*preDefinitionHeaders[i]));
		prevHeader = (*preDefinitionHeaders[i]);
	}
}
