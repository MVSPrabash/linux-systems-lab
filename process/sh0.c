/**
 * Author: MVS Prabash
 * Description: Program to experiment how a shell runs a command
 */

// Standard libs
#include <stdio.h>
#include <string.h>

// Linux libs

#define CMD_BUFFSIZE 100

int main() {
    char cmd[CMD_BUFFSIZE];
    while (1) {
        printf("sh0# ");
        fgets(cmd, CMD_BUFFSIZE, stdin);

        if (strcmp(cmd, "exit\n") == 0) {
            printf("BYE --sh0\n");
            break;
        }

        printf("COMMAND: %s", cmd);
    }
}