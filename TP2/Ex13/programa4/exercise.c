#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
    int   n, fd1[2],fd2[2];
    pid_t pid;
    char  line[1024];
    bool fake;
    if (mkfifo("p1", 0666) < 0 || mkfifo("p2", 0666) < 0) 
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
        int p1;
        while ((p1 = open("p1", O_WRONLY)) < 0);
        write(p1, "Operating", 9);
        close(p1);

        int p2;
        while ((p2 = open("p2", O_RDONLY)) < 0);
        n = read(p2, line, 10);
        char* st = malloc(sizeof(char) * n);
        memcpy(st, line, n);
        printf("%s Systems\n", st);
        free(st);
        close(p2);

        } 
    else {                      
        int p1;
        while ((p1 = open("p1", O_RDONLY)) < 0);
        n = read(p1, line, 10);
        char* st = malloc(sizeof(char) * n);
        memcpy(st, line, n);
        printf("%s Systems\n", st);
        free(st);
        close(p1);

        int p2;
        while ((p2 = open("p2", O_WRONLY)) < 0);
        write(p2, "Operating", 9);
        close(p2);
    }
    exit(0);
}