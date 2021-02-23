#include <stdio.h>


int main()
{
    fprintf(stderr,"%s","Hello ");
    int child = fork();
    switch(child) {
        case 0:
            fprintf(stderr,"%s","World!\n");
            break;
    }
    return 0; 
}