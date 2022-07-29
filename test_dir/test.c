#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// return true if the file specified
// by the filename exists
bool file_exists(const char *filename)
{
    return access(filename, F_OK) == 0;
}

int main(int ac,char**av)
{
    char *filename = av[1];

    if (file_exists(filename))
        printf("File %s exists", filename);
    else
        printf("File %s doesn't exist.", filename);

    return 0;
}

