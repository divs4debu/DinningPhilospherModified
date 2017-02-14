#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

#include "Semaphore.cpp"
int main(void)
{
    Semaphore mutex(1);
    pid_t child;
    for(int i =0; i< 4; i++){
        child = fork();
        if(child >=0){
            if(child == 0)
                printf("child running\n");
            else{
                printf("Running main\n");
            }
            mutex.wait();
        
            mutex.signal();
        }
    }
    
    return 0;
   
}
