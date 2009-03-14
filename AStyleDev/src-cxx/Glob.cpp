
#include <stdlib.h>
#include <stdio.h>

// From The Code Project http://www.codeproject.com/string/wildcmp.asp
// Written by Jack Handy - jakkhandy@hotmail.com
int wildcmp(const char *wild, const char *data)
{
    const char *cp = NULL, *mp = NULL;

    while ((*data) && (*wild != '*')) {
        if ((*wild != *data) && (*wild != '?')) {
            return 0;
        }
        wild++;
        data++;
    }

    while (*data) {
        if (*wild == '*') {
            if (!*++wild) {
                return 1;
            }
            mp = wild;
            cp = data+1;
        } else if ((*wild == *data) || (*wild == '?')) {
            wild++;
            data++;
        } else {
            wild = mp;
            data = cp++;
        }
    }

    while (*wild == '*') {
        wild++;
    }
    return !*wild;
}


int main(int argc, char* argv[])
{
    const char *wild = "bl?h.*";
    const char *data[] =
    {
        "blah.cpp",
        "blbh.cpp",
        "alah.cpp",
        "blah.h",
        "blaaaaaaaah.cpp"
    };

    printf("\nwild  - %s\n\n", wild);
    for (size_t i=0; i<sizeof(data)/sizeof(data[0]); i++)
    {
        if (wildcmp(wild, data[i]))
        {
            printf("match - %s\n",data[i]);
        }
        else
        {
            printf("no    - %s\n",data[i]);
        }
    }

    printf("\n");
    exit(0);
}

