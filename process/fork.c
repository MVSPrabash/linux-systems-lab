#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Forking\n");
    int pid = fork();

    if (pid == 0) {  // Child proc
        int cpid = getpid();
        printf("Child Proc: pid: %d\n", cpid);
        
        int n;
        printf("Child Proc: Enter n: ");
        scanf("%d", &n);
        return n;
    } else {          // Parent proc
        int ppid = getpid();
        printf("Parent proc: pid: %d\n", ppid);
        /// TODO: Retrieve the return value of child proc and print it to stdout
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Parent Proc: n Val = %d\n", exit_status);
        }
    }
}
