#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Forking\n");
    int ppid = fork();

    if (ppid == 0) {  // Child proc
        printf("Child Process\n");
    } else {          // Parent proc
        printf("Parent Process\n");
    }
}
