#define _WIN32_WINNT 0x0501

#include <windows.h>
#include <stdio.h>
//#include <strsafe.h>
#include <malloc.h>

#define BUFSIZE MAX_PATH

int main(int argc, char *argv[])
{
    WIN32_FIND_DATA FindFileData;
    LPSTR DirSpec = (LPSTR) malloc (BUFSIZE);

    // Check for command-line parameter; otherwise, print usage.
    if (argc != 2)
    {
        printf("Usage: PrintDir <dir>\n");
        return 2;
    }

    // Check that the input is not larger than allowed.
    size_t length_of_arg = strlen(argv[1]);
    if (length_of_arg > (BUFSIZE - 2))
    {
        printf("Input directory is too large.\n");
        return 3;
    }

    printf ("Target directory is %s.\n", argv[1]);

    // Prepare string for use with FindFile functions.  First,
    // copy the string to a buffer, then append '\*' to the
    // directory name.
    strncpy (DirSpec, argv[1], length_of_arg+1);
    strncat (DirSpec, "\\*", 3);

    // Find the first file in the directory.
    HANDLE hFind = FindFirstFile(DirSpec, &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf ("Invalid file handle. Error is %u.\n", (unsigned) GetLastError());
        return (-1);
    }
    else
    {
        printf ("First file name is %s.\n", FindFileData.cFileName);

        // List all the other files in the directory.
        while (FindNextFile(hFind, &FindFileData) != 0)
        {
            printf ("Next file name is %s.\n", FindFileData.cFileName);
        }

        DWORD dwError = GetLastError();
        FindClose(hFind);
        if (dwError != ERROR_NO_MORE_FILES)
        {
            printf ("FindNextFile error. Error is %u.\n", (unsigned) dwError);
            return (-1);
        }
    }

    free(DirSpec);

    return (0);
}
