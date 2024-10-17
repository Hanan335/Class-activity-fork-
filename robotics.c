#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void image_processing() {
    printf("Child Process : image processing \n");
    sleep(2); 
    printf("Child Process image processing complete\n");
}

void arm_movement() {
    printf("Parent Process : robotic arm movement\n");
    sleep(2);  
    printf("Parent Process : arm movement complete\n");
}

int main() {
   pid_t pid;
    printf("Main Process starting the robotics system\n");
    
    pid = fork();  
    
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } 
    else if (pid == 0) {
        image_processing();  
    } 
    else {
    wait(NULL);  
    arm_movement();  
    }
    
    printf("Main Process robotics system operations complete\n");
    return 0;
}
