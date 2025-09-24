#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("child process (PID=%d) exiting \n", getpid());
        exit(0);
    } else {
        printf("parent process (PID=%d) sleeping\n", getpid());
        sleep(30);
    }
    return 0;
}

