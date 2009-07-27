//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

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
	excludesIn.push_back("--exclude=../testdir1/");
	excludesIn.push_back("--exclude=..\\testdir2");
	excludesIn.push_back("--exclude=../testdir3\\");

#ifdef _WIN32
	vector<string> excludes;
	excludes.push_back("..\\test\\prog1.cpp");
	excludes.push_back("..\\test\\prog2.cpp");
	excludes.push_back("..\\test\\prog3.cpp");
	excludes.push_back("..\\testdir1");
	excludes.push_back("..\\testdir2");
	excludes.push_back("..\\testdir3");
#else
	vector<string> excludes;
	excludes.push_back("../test/prog1.cpp");
	excludes.push_back("../test/prog2.cpp");
	excludes.push_back("../test/prog3.cpp");
	excludes.push_back("../testdir1");
	excludes.push_back("../testdir2");
	excludes.push_back("../testdir3");
#endif

	// build argv array of pointers for input
	char** argv = buildArgv(excludesIn);
	int argc = excludesIn.size() + 1;

	// build and test the vector excludeVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(excludesIn.size(), g_console->excludeVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(excludesIn.size(), g_console->excludeVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(excludes[i], g_console->excludeVector[i]);

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
	CHECK_EQUAL(excludesIn.size(), g_console->excludeHitsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(excludesIn.size(), g_console->excludeHitsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK(!g_console->excludeHitsVector[i]);

	delete [] argv;
	deleteConsoleGlobalObject();
}

TEST(processOptionsFileNameVector)
// test processOptions for fileNameVector
{
	createConsoleGlobalObject();
	vector<string> fileNameIn;
	fileNameIn.push_back("../..\\..\\srccon/*.cpp");

#ifdef _WIN32
	vector<string> fileName;
	fileName.push_back("..\\..\\..\\srccon\\*.cpp");
#else
	vector<string> fileName;
	fileName.push_back("../../../srccon/*.cpp");
#endif

	// build argv array of pointers for input
	char** argv = buildArgv(fileNameIn);
	int argc = fileNameIn.size() + 1;

	// build and test the vector excludeVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(fileName.size(), g_console->fileNameVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileName.size(), g_console->fileNameVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileName[i], g_console->fileNameVector[i]);

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
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(optionsIn.size(), g_console->optionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(optionsIn[i], g_console->optionsVector[i]);

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

	// write the file
#ifdef _MSC_VER
	string optionsFileName = "../../../srccon/astylerc.txt";
#else
	string optionsFileName = "../../srccon/astylerc.txt";
#endif
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(fileIn, optionsFileName))
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
	CHECK_EQUAL(fileOptions.size(), g_console->fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(),g_console->fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], g_console->fileOptionsVector[i]);

	removeOptionsFile(optionsFileName);
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
		systemPause("could not get $HOME directory");
		return;
	}
	string optionsFileName = string(env) + name;
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(fileIn, optionsFileName))
		return;

	// build argv array of pointers for input
	vector<string> optionsIn;
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);
	CHECK_EQUAL(fileOptions.size(), g_console->fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(),g_console->fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], g_console->fileOptionsVector[i]);

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
		systemPause("could not get $HOME directory");
		return;
	}
	string optionsFileName = string(env) + name;
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(fileIn, optionsFileName))
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
	CHECK(g_console->fileOptionsVector.size() == 0);

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

	// write the file
#ifdef _MSC_VER
	string optionsFileName = "../../../srccon/astylerc.txt";
#else
	string optionsFileName = "../../srccon/astylerc.txt";
#endif
	g_console->standardizePath(optionsFileName);

	if (!writeOptionsFile(fileIn, optionsFileName))
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
	CHECK_EQUAL(fileOptions.size(), g_console->fileOptionsVector.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileOptions.size(),g_console->fileOptionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileOptions[i], g_console->fileOptionsVector[i]);

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
	optionsIn.push_back("--preserve-date");
	optionsIn.push_back("--verbose");
	optionsIn.push_back("--formatted");
	optionsIn.push_back("--quiet");
	optionsIn.push_back("--errors-to-stdout");

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);

	CHECK(g_console->noBackup);
	CHECK_EQUAL(string(".old"), g_console->origSuffix);
	CHECK(g_console->isRecursive);
	CHECK(g_console->preserveDate);
	CHECK(g_console->isVerbose);
	CHECK(g_console->isFormattedOnly);
	CHECK(g_console->isQuiet);
	CHECK(_err == &cout);

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
	CHECK_EQUAL(optionsIn.size(), g_console->optionsVector.size());
	// use min size in case the vectors are not equal
	size_t iMax = min(optionsIn.size(), g_console->optionsVector.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(optionsIn[i], g_console->optionsVector[i]);

	delete [] argv;
	delete msgOut;
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
	optionsIn.push_back("-Z");	// preserve-date
	optionsIn.push_back("-v");	// verbose
	optionsIn.push_back("-Q");	// formatted
	optionsIn.push_back("-q");	// quiet
	optionsIn.push_back("-X");	// errors-to-stdout

	// build argv array of pointers for input
	char** argv = buildArgv(optionsIn);
	int argc = optionsIn.size() + 1;

	// build and test the vector optionsVector
	ASFormatter formatter;
	int processReturn = g_console->processOptions(argc, argv, formatter);

	CHECK(processReturn == CONTINUE);

	CHECK(g_console->noBackup);
	CHECK(g_console->isRecursive);
	CHECK(g_console->preserveDate);
	CHECK(g_console->isVerbose);
	CHECK(g_console->isFormattedOnly);
	CHECK(g_console->isQuiet);
	CHECK(_err == &cout);

	delete [] argv;
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
// AStyle test getFilePaths(), wildcmp(), and fileName vector
//----------------------------------------------------------------------------

struct testFilePaths
{
	string fileDirectoryIn;
	vector<string> fileNameOut;

	testFilePaths()
	{
		// wildcards will need a valid file name and path
#ifdef _MSC_VER
		fileDirectoryIn = "../../../srccon/";
#else
		fileDirectoryIn = "../../srccon/";
#endif
		fileNameOut.push_back(fileDirectoryIn + "AStyleTestCon_Console.cpp");
		fileNameOut.push_back(fileDirectoryIn + "AStyleTestCon_Main.cpp");

		for (size_t i = 0; i < fileNameOut.size(); i++)
			g_console->standardizePath(fileNameOut[i]);
	}
};

TEST_FIXTURE(testFilePaths, getFilePaths1)
// test fileName vector and getFilePaths with *.cpp
{
	createConsoleGlobalObject();
	// do not display directories
	g_console->isQuiet = true;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = fileDirectoryIn + "*.cpp";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK_EQUAL(fileNameOut.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNameOut.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNameOut[i], g_console->fileName[i]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePaths2)
// test fileName vector and getFilePaths with *.c??
{
	createConsoleGlobalObject();
	// do not display directories
	g_console->isQuiet = true;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = fileDirectoryIn + "*.c??";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK_EQUAL(fileNameOut.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNameOut.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNameOut[i], g_console->fileName[i]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePaths3)
// test fileName vector and getFilePaths with AStyleTest*.cpp
{
	createConsoleGlobalObject();
	// do not display directories
	g_console->isQuiet = true;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = fileDirectoryIn + "AStyleTestCon*.cpp";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK_EQUAL(fileNameOut.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNameOut.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNameOut[i], g_console->fileName[i]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePaths4)
// test fileName vector and getFilePaths with *.c*
// * at the end WITH remaining data allows complete coverage of wildcmp function
{
	createConsoleGlobalObject();
	// do not display directories
	g_console->isQuiet = true;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = fileDirectoryIn + "*.c*";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK_EQUAL(fileNameOut.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNameOut.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNameOut[i], g_console->fileName[i]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePaths5)
// test fileName vector and getFilePaths with *.cpp*
// * at the end WITHOUT remaining data allows complete coverage of wildcmp function
{
	createConsoleGlobalObject();
	// do not display directories
	g_console->isQuiet = true;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = fileDirectoryIn + "*.cpp*";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK_EQUAL(fileNameOut.size(), g_console->fileName.size());

	// use min size in case the vectors are not equal
	size_t iMax = min(fileNameOut.size(), g_console->fileName.size());
	for (size_t i = 0; i < iMax; i++)
		CHECK_EQUAL(fileNameOut[i], g_console->fileName[i]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePathsSingleFile1)
// test fileName vector and getFilePaths with a single file
// the file includes a path
{
	createConsoleGlobalObject();

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = "../../directory/filein.cpp";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK_EQUAL((size_t)1, g_console->fileName.size());
	CHECK_EQUAL(fileNameIn, g_console->fileName[0]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePathsSingleFile2)
// test fileName vector and getFilePaths with a single file
// the file does NOT include a path
{
	createConsoleGlobalObject();

	// get current directory
	string fileDirectoryIn = getCurrentDirectory();
	if (fileDirectoryIn.length() == 0)
		return;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = "filein.cpp";

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	// the vector should have the current directory attached
	CHECK_EQUAL((size_t)1, g_console->fileName.size());
	string consoleFileName = fileDirectoryIn + '/' + fileNameIn;
	g_console->standardizePath(consoleFileName);
	CHECK_EQUAL(consoleFileName, g_console->fileName[0]);

	deleteConsoleGlobalObject();
}

TEST_FIXTURE(testFilePaths, getFilePathsError)
// test fileName vector and getFilePaths with bad path
{
	createConsoleGlobalObject();
	// do not display directories
	g_console->isQuiet = true;
	// do not display error message
	_err = new stringstream;

	// initialize variables
	ASFormatter formatter;
	string fileNameIn = fileDirectoryIn + "AStyleError*";
	g_console->standardizePath(fileNameIn);

	// build and test the fileName vector
	g_console->getFilePaths(fileNameIn);

	CHECK(g_console->fileName.size() == 0);

	delete _err;
	_err = &cerr;
	deleteConsoleGlobalObject();
}

// TODO: test recursive option into subdirectories
// TODO: test recursive option with excludes
// TODO: test file removes and renames
// TODO: test stringEndsWith function
// TODO: test waitForRemove function
// TODO: test exclude date?
