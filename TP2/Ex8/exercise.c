/*
*	Example of signals in action (with SIGACTION)
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void func(int signo) {
	fprintf(stderr, "\nReceived signal %d!\n", signo);
	}

int main() {
	struct sigaction new, old;
	sigset_t smask;	// defines signals to block while func() is running
    pid_t pid;
    int estado;

// prepare struct sigaction
    if (sigemptyset(&smask)==-1)	// block no signal
        perror ("sigsetfunctions");
    new.sa_handler = func;
    new.sa_mask = smask;
    new.sa_flags = 0;	// usually works

    if(sigaction(SIGUSR1, &new, &old) == -1)
        perror ("sigaction");

    pid = fork();

    if (pid < 0 )
    {
        printf("Erro!!!\n");
        exit (-1);
    }
    
    switch(pid) {
        case 0:
            sleep(3);
            fprintf(stderr,"%s","Hello!\n");
            break;
        default:
            fprintf(stderr,"%s","World!\n");
            kill(pid, SIGUSR1); /* envia ao processo filho o sinalbreak;*/
            wait(NULL);
            break;
    }

    //printf("\nSIGUSR1 handler is ready...");
    //printf("\n\t Try: \"sh> kill -SIGUSR1 %d\".\n", getpid());

    //pause();	// wait

    return 0;
}
