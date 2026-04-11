#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Forking\n");
    int pid = fork();

    if (pid == 0) {  // Child proc
        int cpid = getpid();
        printf("Child pid: %d\n", cpid);
    } else {          // Parent proc
        int ppid = getpid();
        printf("Parent pid: %d\n", ppid);
    }
}
