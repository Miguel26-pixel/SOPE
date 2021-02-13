#include <stdio.h>
#include <time.h>


int main()
{
    clock_t begin = clock();


    for (int x=0;x < 100000;x++)
    {
        printf("%s","Hello world!\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%.6f\n",time_spent);
    
    return 0;
}