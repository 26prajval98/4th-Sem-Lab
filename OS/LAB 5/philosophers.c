#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t ct[100], room;
int N;

void * philosopher(void * arg){
    int i = *(int *)arg;
	sem_wait(&room);
    sem_wait(&ct[i]);    
    sem_wait(&ct[(i+1)%N]);
    printf("Philosopher %d eating...\n",i);
    sem_post(&ct[i]);
    sem_post(&ct[(i+1)%N]);
    printf("Philosopher %d Finished Eating \n",i);
	sem_post(&room);
	printf("Philosopher %d Thinkig now \n\n",i);
    pthread_exit(0);
}

int main(int argc, char *argv[]){
    N = atoi(argv[1]);
    int i,A[N];
    pthread_t Phil[N];
    for(i=0;i<N;i++){
        sem_init(&ct[i],0,1);
		A[i] = i;
    }
	sem_init(&room,0, N-1);
    for(i=0;i<N;i++){
        pthread_create(&Phil[i],NULL,philosopher,&A[i]);
    }
    for(i=0;i<N;i++){
        pthread_join(Phil[i],NULL);
    }
}
