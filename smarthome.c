#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int armed = 1;
    int doorOpened = 1;
    
    if (armed && doorOpened) {
        printf("System is armed, and the door has been opened!\n");

        pid_t pid = fork();
        
        if (pid < 0) {
            printf("Fork failed !!! \n");
            return 1;
        }
        else if (pid == 0) {
            printf("Sending notification to homeowner's smartphone...\n");
        }
        else {
            printf("Sounding alarm...\n");
        }
    }

    return 0;
}
