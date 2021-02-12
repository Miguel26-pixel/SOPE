//to create a environment variable "export NAME=value"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    for (int n = 0; n < argc; n++)
    {
        int i = 0;
        while (envp[i]!=NULL)
        {
            bool fake = true;
            for(int x = 0; x<strlen(argv[n]);x++){
                if(argv[n][x]!=envp[i][x])
                    fake = false;
            }
            if(fake){
                printf("%s",envp[i]);
                i++;
                break;
            }
            i++;
        }

    }
    return 0;
}