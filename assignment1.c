#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        printf("child process: PID = %d\n", getpid());
        exit(0);
    } 
    else {
        printf("parent process: PID = %d\n", getpid());
    }

    return 0;
}
