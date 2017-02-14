/**
 * This is the Wrapper class for the sem_t.
 * Class provides healthy interface for synchronisation.
 */

#include <semaphore.h>
#include <error.h>
#include <stdlib.h>
#include <stdio.h> 
#include <errno.h>

class Semaphore{
private:
    sem_t *var;
public:
    
    Semaphore(int value){
        var = (sem_t*)malloc(sizeof(sem_t));
        int n = sem_init(var, 0, value);
        if(n != 0) {perror("sem_init failed");exit(-1);}
        printf("Initialised the Semaphore\n");
    }
    
    void wait(){
        int n = sem_wait(var);
        if(n != 0) {perror("sem_wait failed");exit(-1);}
        printf("Waiting for the Semaphore\n");
    }
    
    void signal(){
        int n = sem_post(var);
        if(n != 0) {perror("sem_post failed");exit(-1);}
        printf("Realeasing the Semaphore\n");
    }
    
    
    
    
};
