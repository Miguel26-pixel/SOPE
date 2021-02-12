#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    printf("%d",argc-1);
    for (int n = 0; n < argc; n++)
    {
        printf("%s",argv[n]);
    }
    while (envp[i]!=NULL)
    {
        printf("%s",envp[i]);
        i++;
    }
    return 0;
}