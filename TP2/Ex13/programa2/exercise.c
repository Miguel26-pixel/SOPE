#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
    int   n;
    pid_t pid;
    char  line[10];
    if (mkfifo("p1", 0666) < 0) {
           perror("ERROR");
        exit(1);
    } 
    if ( (pid = fork()) < 0) {
        perror("ERROR");
        exit(1);
    } 
    else if (pid > 0) {
        int p1;
        while ((p1 = open("p1", O_WRONLY)) < 0);
        write(p1, "Operating", 9);
        close(p1);
    } 
    else {                      
        int p1;
        while ((p1 = open("p1", O_RDONLY)) < 0);
        n = read(p1, line, 10);
        char* st = malloc(sizeof(char) * n);
        memcpy(st, line, n);
        printf("%s Systems", st);
        free(st);
        close(p1);
    }
    return 0;
}