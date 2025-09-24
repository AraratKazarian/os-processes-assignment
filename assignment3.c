#include <stdio.h>
#include <stdlib.h>

void goodbye1() {
    printf("cleanup function 1 called at program exit\n");
}

void goodbye2() {
    printf("cleanup function 2 called at program exit\n");
}

int main() {
    atexit(goodbye1);
    atexit(goodbye2);

    printf("main program running\n");

    exit(0);

    return 0;
}

