#include <stdio.h>
#include <sys/types.h>
#include <sys/times.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char* argv[], char* envp[]){
    
    if(argc <= 1){
        fprintf(stdout, "Invalid command.");
        return 1;
    }


    DIR * dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("DIR doesn't exist!\n");
        return 1;
    }

    
    struct dirent* dirent;

    struct stat st;

    if (argv[argc - 1][strlen(argv[argc - 1]) - 1] != '/') {
        argv[argc - 1][strlen(argv[argc - 1]) + 1] = '\0';
        argv[argc - 1][strlen(argv[argc - 1])] = '/';
    }

    while((dirent = readdir(dir)) != NULL) {
        if (!strcmp(dirent->d_name, "..")) continue;
        if (!strcmp(dirent->d_name, ".")) continue;
        char* s = malloc(strlen(argv[1]) + strlen(dirent->d_name) +2);

        s = strcat(s,argv[1]);
        s = strcat(s,dirent->d_name);
        stat(s,&st);
        if (S_ISREG(st.st_mode)) {
            printf("NAME: %s        SIZE: %ld bytes\n", s, st.st_size);
        }
        if ( (st.st_mode)) {
            int pid = fork();
            int status;
            if (pid == 0) { //child
                argv[argc - 1] = s;

                execv(argv[0],argv);

                exit(0);
            }
            else waitpid(pid,&status,0);
        }
    }
    return 0;

}