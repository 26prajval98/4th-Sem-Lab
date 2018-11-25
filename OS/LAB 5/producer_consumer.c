#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t E, F, mutex;

int p,c,sum = 0;

void* producer(void *n){
    int *j = (int *)n;
    int i = *j;
    while(1){
        //waitS();
        sem_wait(&E);
		sem_wait(&mutex);
        printf("Producer Produced\n");
        sum++;
        //signalS();
		sem_post(&mutex);
        sem_post(&F);
        //printf("Producer\n");
        p++;
        if(p>=i){
            //printf("%d ", p);
            printf("Exiting: producer %d \n",p);
            pthread_exit(0);
        }
    }
}

void* consumer(void *n){
    int *j = (int *)n;
    int i = *j;
    while(1){
        //waitS();
        sem_wait(&F);
		sem_wait(&mutex);
        printf("Consumer consumed\n");
        sum--;
        //signalS();
		sem_post(&mutex);
        sem_post(&E);
        //aprintf("Consumer\n");
        c++;
        if(c>=i){
            printf("Exiting Consumer %d \n",c);
            pthread_exit(0);
        }
    }
}


int main(int argc, char* argv[]){

    int n = atoi(argv[1]);
    //printf("%d %d %d\n",n,10,11);
    sem_init(&E,0,n);
    sem_init(&F,0,0);
	sem_init(&mutex, 0, 1);

    //S = 1;

    int pro = n;//atoi(argv[2]);
    int con = n;//atoi(argv[3]);

    pthread_t pid, cid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&pid,&attr,producer,(void *)&pro);
    pthread_create(&cid,&attr,consumer,(void *)&con);

    pthread_join(pid,NULL);
    pthread_join(cid,NULL);

    printf("--------> %d <----------\n",sum);

} 
