#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifdef __MINGW32__
int _CRT_glob = 0;    // turn off MinGW automatic file globbing
#endif

bool g_isRecursive = true;

using namespace std;

void getFileNames(const string &directory, const string &wildcard, vector<string> &filename);
int  wildcmp(const char *wild, const char *data);
void error(const char *why, const char* what);

// Windows specific functions
// MinGW can also do POSIX
#if defined(_WIN32) && !defined(MINGW_POSIX)
#include <windows.h>  // for FindFirstFile and FindNextFile
const char* g_type = "Win32";
void getFileNames(const string &directory, const string &wildcard, vector<string> &filename)
{
    vector<string> subDirectory;    // sub directories of directory
    WIN32_FIND_DATA FindFileData;   // for FindFirstFile and FindNextFile

    // Find the first file in the directory
    string firstFile = directory + "\\*";
    HANDLE hFind = FindFirstFile(firstFile.c_str(), &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        error("Cannot open directory", directory.c_str());

    // save files and sub directories
    do
    {
        // skip hidden or read only
        if (FindFileData.cFileName[0] == '.'
                || (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
                || (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY))
            continue;

        // if recursive, save sub directory
        if (g_isRecursive && (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            subDirectory.push_back(directory + '\\' + FindFileData.cFileName);
            continue;
        }

        // save file name if wildcard match
        if (wildcmp(wildcard.c_str(), FindFileData.cFileName))
        {
//            cout << "file name  " << FindFileData.cFileName << endl;
            filename.push_back(directory + '\\' + FindFileData.cFileName);
        }
    }
    while (FindNextFile(hFind, &FindFileData) != 0);

    DWORD dwError = GetLastError();
    FindClose(hFind);
    if (dwError != ERROR_NO_MORE_FILES)
        error("Error processing directory", directory.c_str());

    // recurse into sub directories
    // if not doing recursive subDirectory is empty
    for (unsigned i = 0; i < subDirectory.size(); i++)
    {
//        cout << "directory  " << subDirectory[i] << endl;
        getFileNames(subDirectory[i], wildcard, filename);
        continue;
    }

    return;
}

#else
#include <dirent.h>
#include <sys/stat.h>
const char* g_type = "POSIX";
void getFileNames(const string &directory, const string &wildcard, vector<string> &filename)
{
    struct dirent *entry;           // entry from readdir()
    struct stat statbuf;            // entry from lstat()
    vector<string> subDirectory;    // sub directories of this directory

    DIR *dp = opendir(directory.c_str());
    if (dp == NULL)
        error("Cannot open directory", directory.c_str());

    // first entry for this recursion
    const unsigned firstEntry = filename.size();
    // save files and sub directories
    while ((entry = readdir(dp)) != NULL)
    {
        // get file status
        string entryFilepath = directory + '/' + entry->d_name;
        stat(entryFilepath.c_str(), &statbuf);
        // want only files and directories
        if (!(S_ISREG(statbuf.st_mode) || S_ISDIR(statbuf.st_mode)))
            continue;
        // skip hidden or read only
        if (entry->d_name[0] == '.' || !(statbuf.st_mode & S_IWUSR))
            continue;
        // save sub directory if doing recursive
        if (g_isRecursive && S_ISDIR(statbuf.st_mode))
        {
            subDirectory.push_back(directory + '/' + entry->d_name);
            continue;
        }

        // save file name if wildcard match
        if (wildcmp(wildcard.c_str(), entry->d_name))
        {
//            cout << "file name  " << entry->d_name << endl;
            filename.push_back(directory + '/' + entry->d_name);
        }
    }
    closedir(dp);

    // sort the current entries for filename
    if (firstEntry < filename.size())
        sort(&filename[firstEntry], &filename[filename.size()]);

    // recurse into sub directories
    // if not doing recursive, subDirectory is empty
    if (subDirectory.size() > 1)
        sort(subDirectory.begin(), subDirectory.end());
    for (unsigned i = 0; i < subDirectory.size(); i++)
    {
//        cout << "directory  " << subDirectory[i] << endl;
        getFileNames(subDirectory[i], wildcard, filename);
        continue;
    }

    return;
}

#endif  // _WIN32


// From The Code Project http://www.codeproject.com/string/wildcmp.asp
// Written by Jack Handy - jakkhandy@hotmail.com
int wildcmp(const char *wild, const char *data)
{
    const char *cp = NULL, *mp = NULL;

    while ((*data) && (*wild != '*'))
    {
        if ((*wild != *data) && (*wild != '?'))
        {
            return 0;
        }
        wild++;
        data++;
    }

    while (*data)
    {
        if (*wild == '*')
        {
            if (!*++wild)
            {
                return 1;
            }
            mp = wild;
            cp = data+1;
        }
        else if ((*wild == *data) || (*wild == '?'))
        {
            wild++;
            data++;
        }
        else
        {
            wild = mp;
            data = cp++;
        }
    }

    while (*wild == '*')
    {
        wild++;
    }
    return !*wild;
}

// On Win32, look at <conio.h> and kbhit(), on POSIX, look at <curses.h> and cbreak()
// #include <conio.h>
void error(const char *why, const char* what)
{
    cout << why << ' ' << what << '\n' << endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    // Check for command-line parameter
    if (argc != 2)
    {
		cout << argv[0] << endl;
        cout << "Usage: PrintDirTest <dir> " << endl;
        return 2;
    }

    for (int x = 1; x < argc; x++)
    {
#ifdef _WIN32
        char fileSeparator = '\\';
#else
        char fileSeparator = '/';
#endif
        string fileSpec(argv[x]);
        size_t separator = fileSpec.find_last_of("/\\");
        if (separator == string::npos)
            separator = 0;
        string targetDirectory = fileSpec.substr(0, separator);
        string targetFilename  = fileSpec.substr(separator+1);
        if (targetFilename.length() == 0)
            error("Missing filename in", fileSpec.c_str());

        vector<string> filename;
        bool isWildcard = false;
        size_t wildcard = targetFilename.find_first_of("*?");
        if (wildcard == string::npos)
        {
            filename.push_back(targetDirectory + fileSeparator + targetFilename);
        }
        else
        {
            isWildcard = true;
            cout << "==================================================" << endl;
            cout << "Directory  " << targetDirectory << endl;
            getFileNames(targetDirectory, targetFilename, filename);
        }

        // print files to process
        if (filename.size() > 0)
        {
            if (isWildcard)
            {
                int count = 0;
                for (unsigned i = 0; i < filename.size(); i++)
                {
                    // remove targetDirectory from filename
                    string displayName = filename[i].substr(targetDirectory.length() + 1);
                    cout << "file name  " << displayName << endl;
                    count++;
                }
                cout << "total      " << count << endl;
            }
            else
            {
                cout << "only file name " << filename.back() << endl;
            }
			cout << "type       " <<  g_type << endl;
        }
    }

    return 0;
}
