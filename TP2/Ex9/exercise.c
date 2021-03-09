/*
*	Example of threads in action
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 3

void *rot(void *a) {
	printf("\ni = %d",*(int*)a);
    *(int*)a *= *(int*)a; 
    printf("\n\t In thread PID: %d ; TID: %lu.", getpid(), (unsigned long) pthread_self());
    sleep(1);
    return a;
	}

int main() {
	int i;	// thread counter
	pthread_t ids[NTHREADS];	// storage of (system) Thread Identifiers

    setbuf (stdout, NULL);	// only for debugging
    printf("\nMain thread PID: %d ; TID: %lu.\n", getpid(), (unsigned long) pthread_self());

    int args[NTHREADS];\

    // new threads creation
    for(i=0; i<NTHREADS; i++) {
        if (pthread_create(&ids[i], NULL, rot, (void*)&args[i]) != 0)
            exit(-1);	// here, we decided to end process
        else
            printf("\nNew thread %d ; TID: %lu.", i, (unsigned long) ids[i]);
        }
    // wait for finishing of created threads
    void *num;
    for(i=0; i<NTHREADS; i++) {
        pthread_join(ids[i], &num);    // Note: threads give no termination code
        printf("\nTermination of thread %d: %lu.", i, (unsigned long)ids[i]);
        printf("\ni * i = %d\n", *(int *)num);
    }

    printf("\n");
    pthread_exit(NULL);	// here, not really necessary...
    return 0;	// will not run this!
}
