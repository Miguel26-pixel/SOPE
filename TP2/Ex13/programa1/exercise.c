#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
int main(void)
{
    int   n, fd[2];
    pid_t pid;
    char  line[1024];
    if (pipe(fd)) < 0) 
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
        /* pai */close(fd[0]);           
        /* fecha lado receptor do pipe */
        write(fd[1], "Operating", 9);} 
    else {                      
        /* filho */close(fd[1]);           
        /* fecha lado emissor do pipe */
        n = read(fd[0], line, 1024);
        strcat(line, " Systems");
        fprintf(stdout, line, n);}
    exit(0);
}