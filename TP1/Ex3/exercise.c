#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void bye(void)
{
    printf("That was all, folks\n");
}

int main(void)
{
    int i;

    i = atexit(bye);
    if (i != 0) {
        fprintf(stderr, "cannot set exit function\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}