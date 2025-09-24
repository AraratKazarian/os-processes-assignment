#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        printf("child process (PID=%d) exiting \n", getpid());
        exit(0);
    } else {
        wait(&status);
        printf("parent reaped child, so no zombie created\n");
        sleep(30);
    }

    return 0;
}
