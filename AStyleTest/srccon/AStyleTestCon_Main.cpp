// AStyleTestCon tests the ASConsole class only. This class is used only in
// the console build. It also tests the parseOption function for options used
// by only by the console build (e.g. recursive, preserve-date, verbose). It
// does not explicitely test the ASStreamIterator class or any other part
// of the program.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <unistd.h>
#define min(a, b)  (((a) < (b)) ? (a) : (b))	// as defined in windows.h
#endif

#include "AStyleTestCon.h"

//----------------------------------------------------------------------------
// main function
//----------------------------------------------------------------------------

int main(int /*argc*/, char** /*argv*/)
// run all tests
{
	createTestDirectory(getTestDirectory());
	int retval = UnitTest::RunAllTests();
//	removeTestDirectory(getTestDirectory());
//	system("pause");		// sometimes needed for debug
	return retval;
}

//----------------------------------------------------------------------------
// support functions
//----------------------------------------------------------------------------

char** buildArgv(const vector<string>& argIn)
// build an array of pointers to be used as argv variable in function calls
// the calling program must delete[] argv
// argc will equal (argIn.size() + 1)
{
	// build argv array of pointers for input
	int argc = argIn.size() + 1;

	char** argv = new char* [sizeof(char*) * argc];
	argv[0] = (char*)"AStyleTestCon.exe";	// first value is the program name
	if (argIn.size() > 0)
		for (int i = 1; i < argc; i++)		// next are the options
			argv[i] = const_cast<char*>(argIn[i-1].c_str());
//	for (int i = 0; i < argc; i++)
//		cout << argv[i] << endl;
	return argv;
}

int buildFileNameVector(string fileToProcess, vector<string>& fileNameVector, ASFormatter& formatter)
// build the g_console FileNameVector for testing
// the return should be checked for "CONTINUE"
{
	// build argv array of pointers for input
	fileNameVector.push_back(getTestDirectory() + fileToProcess);
	char** argv = buildArgv(fileNameVector);
	int argc = fileNameVector.size() + 1;
	int processReturn = g_console->processOptions(argc, argv, formatter);
	delete[] argv;
	return processReturn;
}

#ifdef _WIN32
void cleanTestDirectory(const string &directory)
// Windows remove files and sub directories from the test directory
{
	WIN32_FIND_DATA FindFileData;

	// Find the first file in the directory
	string firstFile = directory + "\\*";
	HANDLE hFind = FindFirstFile(firstFile.c_str(), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		systemPause("Cannot open directory for clean: " + directory);
		return;
	}

	// remove files and sub directories
	do
	{
		// skip these
		if (string(FindFileData.cFileName) == "."
				|| string(FindFileData.cFileName) == "..")
			continue;
		// clean and remove sub directories
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			string subDirectoryPath = directory + '\\' + FindFileData.cFileName;
			cleanTestDirectory(subDirectoryPath);
			BOOL isRemoved = RemoveDirectory(subDirectoryPath.c_str());
			if (!isRemoved)
				systemPause("Cannot remove directory for clean: " + subDirectoryPath);
			continue;
		}
		// remove the file
		string filePathName = directory + '\\' + FindFileData.cFileName;
		BOOL isRemoved = DeleteFile(filePathName.c_str());
		if (!isRemoved)
			systemPause("Cannot remove file for clean: " + filePathName);
	}
	while (FindNextFile(hFind, &FindFileData) != 0);

	// check for processing error
	FindClose(hFind);
	DWORD dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		systemPause("Error processing directory for clean: " + directory);
		return;
	}
}
#else
void cleanTestDirectory(const string &directory)
// POSIX remove files and sub directories from the test directory
{
	struct dirent *entry;           // entry from readdir()
	struct stat statbuf;            // entry from stat()
	vector<string> subDirectory;    // sub directories of this directory

	// errno is defined in <errno.h> and is set for errors in opendir, readdir, or stat
	errno = 0;

	// open directory stream
	DIR *dp = opendir(directory.c_str());
	if (errno)
	{
		perror("errno message");
		systemPause("Cannot open directory for clean: " + directory);
		return;
	}

	// remove files and sub directories
	while ((entry = readdir(dp)) != NULL)
	{
		// get file status
		string entryFilepath = directory + '/' + entry->d_name;
		stat(entryFilepath.c_str(), &statbuf);
		if (errno)
		{
			perror("errno message");
			systemPause("Error getting file status for clean: " + directory);
			continue;
		}
		// skip these
		if (string(entry->d_name) == "."
				|| string(entry->d_name) == "..")
			continue;
		// clean and remove sub directories
		if (S_ISDIR(statbuf.st_mode))
		{
			string subDirectoryPath = directory + '/' + entry->d_name;
			cleanTestDirectory(subDirectoryPath);
			rmdir(subDirectoryPath.c_str());
			if (errno)
			{
				perror("errno message");
				systemPause("Cannot remove directory for clean: " + subDirectoryPath);
				return;
			}
			continue;
		}

		// remove the file
		if (S_ISREG(statbuf.st_mode))
		{
			string filePathName = directory + '/' + entry->d_name;
			remove(filePathName.c_str());
			if (errno)
			{
				perror("errno message");
				systemPause("Cannot remove file for clean: " + filePathName);
			}
		}
	}
	closedir(dp);

	if (errno)
	{
		perror("errno message");
		systemPause("Error processing directory for clean: " + directory);
	}
}
#endif

void createConsoleGlobalObject()
// creates the g_console object
{
	if (g_console)
	{
		systemPause("Global object not deleted");
		deleteConsoleGlobalObject();
	}
	g_console = new ASConsole;
}

void createTestDirectory(const string &dirName)
// create a test directory
{
#ifdef _WIN32
	CreateDirectory(dirName.c_str(), NULL);
#else
	mkdir(dirName.c_str(), 00770);
	chmod(dirName.c_str(), 00770);
#endif
	// clean a pre-existing directory
	cleanTestDirectory(dirName);
}

void createTestFile(const string& testFilePath, const char* testFileText, int size /*0*/)
// write a test file to the test directory
// the size option is for 16 and 32 bit UTF files with NULs in the text
{
	// verify test directory
	string testDir = getTestDirectory();
	if (testFilePath.compare(0, testDir.length(), testDir) != 0
			|| !(testFilePath[testDir.length()] == '/'
				 || testFilePath[testDir.length()] == '\\'))
	{
		systemPause("File not written to test directory: " + testFilePath);
		return;
	}
	// write the output file
	ofstream fout(testFilePath.c_str(), ios::binary | ios::trunc);
	if (!fout)
	{
		systemPause("Could not open output file: " + testFilePath);
		return;
	}
	if (size == 0)
		fout << testFileText;
	else
		fout.write(testFileText, size);
	fout.close();
}

void deleteConsoleGlobalObject()
// deletes the g_console object
{
	delete g_console;
	g_console = NULL;
	// check global error display
	if (_err != &cerr)
		systemPause("_err ostream not replaced");
	_err = &cerr;
}

string getCurrentDirectory()
// get the current working directory
{
	bool gotDirectory = true;
	string currentDirectory;
#ifdef _WIN32
	char currdir[MAX_PATH];
	currdir[0] = '\0';
	if (GetCurrentDirectory(sizeof(currdir), currdir))
		currentDirectory = currdir;
	else
		gotDirectory = false;
#else
	char* currdir = getenv("PWD");
	if (currdir != NULL)
		currentDirectory = currdir;
	else
		gotDirectory = false;
#endif
	if (!gotDirectory)
		systemPause("Cannot get current directory");
	return currentDirectory;
}

string getTestDirectory()
// get the file path of the test directory
{
	string dirPath;
	string dirName = "ut-testcon";
#ifdef _WIN32
#ifdef _MSC_VER
	dirPath = "..\\..\\..\\" + dirName;
#else
	dirPath = "..\\..\\" + dirName;
#endif
#else
	dirPath = "../../" + dirName;
#endif
	return dirPath;
}

void removeOptionsFile(const string& optionsFileName)
// remove a test options file
{
	errno = 0;
	remove(optionsFileName.c_str());
	if (errno)
		systemPause("Cannot remove options test file: " + optionsFileName);
}

void removeTestDirectory(const string &dirName)
// remove a test directory
{
	cleanTestDirectory(dirName);
#ifdef _WIN32
	RemoveDirectory(dirName.c_str());
#else
	rmdir(dirName.c_str());
#endif
}

void systemPause(const string& message)
// accept keyboard input to continue
// assures a console message is noticed
{
	cout << message << endl;
#ifdef _WIN32
	system("pause");
#else
	cout << "Press ENTER to continue." << endl;
	system("read x");
#endif
}

bool writeOptionsFile(const string& optionsFileName, const char* fileIn)
// write a test options file
{
	// write the file
	ofstream fileOut(optionsFileName.c_str(), ios::binary);
	if (!fileOut)
	{
		systemPause("Cannot write options test file: " + optionsFileName);
		return false;
	}
	fileOut << fileIn;
	fileOut.close();
	return true;
}
