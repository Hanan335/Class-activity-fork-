#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void managetemperature() {
    printf("Managing home temperature \n");
    sleep(2); 
    printf("Temperature management complete\n");
}

int main() {
    pid_t pid;
    printf("Smart thermostat system starting\n");
     pid = fork();
    if (pid < 0) { 
    printf("Fork failed\n");
    return 1;
    } else if (pid == 0) {
        char *args[] = {"./plugin", NULL};
        execv(args[0], args); 
    } else { 
        managetemperature(); 
        wait(NULL); 
    }
    printf("Smart thermostat system shutting down\n");
    return 0;
}
