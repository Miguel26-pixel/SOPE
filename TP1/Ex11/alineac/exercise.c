#include <stdio.h> 
#include <stdlib.h> // For exit() 



int main(int argc, char *argv[])
{
    FILE *fptr1,  *fptr2;
  
    char c; 
  
    // Open file 
    fptr1 = fopen(argv[1], "r"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 

    if (fptr2 == fopen(argv[2], "r")) 
    { 
        c = fgetc(fptr1); 
        while (c != EOF) 
        { 
            printf ("%c", c); 
            c = fgetc(fptr1); 
        } 
  
        fclose(fptr1);  
        return 0;
    } 
  
    // Read contents from file 
    fptr2 = fopen(argv[2], "w"); 
    c = fgetc(fptr1); 
    while (c != EOF) 
    { 
        fputc(c, fptr2); 
        c = fgetc(fptr1); 
    } 
  
    printf("\nContents copied to %s", argv[2]); 
  
    fclose(fptr1); 
    fclose(fptr2); 
  
    return 0; 
}
