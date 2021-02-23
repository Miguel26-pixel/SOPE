#include <stdio.h>
#include <time.h>


int main()
{
    clock_t start, end;
    struct tms t;
    int long ticks = sysconf(_SC_CLK_TCK);

    start = times(&t); /* início da medição de tempo */

    for (int i = 0; i < 100000; i++)
        printf("Hello world!\n");

    end = times(&t); 

    printf("Clock: %.5f sec\n",(double)(end - start) / ticks);
    printf("User time: %.5f sec\n",(double)(t.tms_utime)/ticks);
    printf("System time: %.5f sec\n",(double)(t.tms_stime)/ticks);
    return 0;
    
    return 0;
}


//assim ou como eles querem e q corras o exec com "time ./exec"