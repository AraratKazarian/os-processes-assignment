#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, wpid;
    int status;

    pid1 = fork();

    if (pid1 == 0) {
        printf("child 1 (PID=%d) running...\n", getpid());
        exit(10);
    } else {
        wait(&status);
        if (WIFEXITED(status)) {
            printf("child 1 exited with status %d\n", WEXITSTATUS(status));
        }
        pid2 = fork();
        if (pid2 == 0) {
            printf("chlid 2 (PID=%d) running...\n", getpid());
            exit(20);
        } else {
            wpid = waitpid(pid2, &status, 0);
            if (wpid == pid2 && WIFEXITED(status)) {
                printf("child 2 exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }
    return 0;
}

