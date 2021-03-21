#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
int main(void)
{
    int   n, fd1[2],fd2[2];
    pid_t pid;
    char  line[1024];
    bool fake;
    if (pipe(fd1) < 0 || pipe(fd2)<0) 
    {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
    if ( (pid = fork()) < 0) 
    {
        fprintf(stderr, "fork error\n");
        exit(2);}
    else if (pid > 0) 
    {           
        /* filho */close(fd1[0]);           
        /* fecha lado receptor do pipe */
        write(fd1[1], "Operating", 9);

        close(fd2[1]);           
        n = read(fd2[0], line, 1024);
        printf("Recebido do filho :Operating %s\n",line);
        } 
    else {                      
        /* pai */close(fd1[1]);           
        /* fecha lado emissor do pipe */
        n = read(fd1[0], line, 1024);
        strcat(line, " Systems\n");
        fprintf(stdout, line, n);
        close(fd2[0]); 
        write(fd2[1], "Systems", 7);
    }
    exit(0);
}