#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();

    if (pid1 == 0) {
        printf("child 1 (PID=%d) exiting with code 5\n", getpid());
        exit(5);
    }

    pid2 = fork();

    if (pid2 == 0) {
        printf("Child 2 (PID=%d) exiting with code 10\n", getpid());
        exit(10);
    }

    waitpid(pid1, &status, 0);
    if (WIFEXITED(status)) {
        printf("child 1 exited normaly with code %d\n", WEXITSTATUS(status));
    } else {
        printf("child 1 did not exit normally\n");
    }

    waitpid(pid2, &status, 0);
    if (WIFEXITED(status)) {
        printf("child 2 exited normaly with code %d\n", WEXITSTATUS(status));
    } else {
        printf("child 2 did not exit normally\n");
    }

    return 0;
}

