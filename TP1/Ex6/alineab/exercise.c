#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    for (int x=0;x < argc;x++)
    {
        int lb = open(argv[x],O_RDONLY);
        if(lb == -1)
        {
            fprintf(stderr, "%s", "File not found\n");
        }
    }
    return 0;
}