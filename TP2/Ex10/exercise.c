/*
*	Example of threads in action
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 3

struct Arg
{
    char* s1;
    char* s2;
    int p;
};

void * print(void * arg) {
    struct Arg *argg = (struct Arg *)arg;
    
    //printf("%d\n", argg->p);
    if (argg->p == 0) {
        printf("%s", argg->s1);
        argg->p = 1;
    }
    else if (argg->p == 1) {
        printf("%s", argg->s2);
    }
    arg = (void*)argg;
    return arg;
}

int main() {
    struct Arg *args;
    pthread_t ids[2];
    args = malloc(sizeof(struct Arg));
    args->p = 0;
    args->s1 = "Operating ";
    args->s2 = "Systems!\n";

    for (int i = 0; i < 2; i++) {
        if (i == 1) sleep(1);
        if (pthread_create(&ids[i],NULL,print,(void*)args) != 0)
            exit(-1);    // here, we decided to end process
    }

    for (int i = 0; i < 2; i++) { //how to wait???
        pthread_join(ids[i],NULL);
    }
    return 0;
}
