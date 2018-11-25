#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int no_readers,no_readers_left,writers;

sem_t w, readers;

/*void waitR(){
    while(readers<=0);
    readers--;
}

void signalR(){
    readers++;
}

void waitW(){
    while(w<=0);
    w--;
}

void signalW(){
    w++;
}
*/
void * reader(void *n){
    //Entry
    sem_wait(&readers);
    if(++no_readers == 1)
        sem_wait(&w);
	int i = *(int *)n;
    printf("Reader-->%d Entered\n",no_readers);
    sem_post(&readers);

    //Leaving
    sem_wait(&readers);
    if(no_readers-(++no_readers_left) == 0)
    	sem_post(&w);
    printf("Reader---->%d Left\n", no_readers_left); 
    if(no_readers_left==i){
        printf("Reader %d finished\n\n",i);
		sem_post(&readers);
        pthread_exit(0);
    }  
    sem_post(&readers);
}

void * writer(void * n){
    sem_wait(&w);
	int i = *(int *)n;
    printf("Writing-------------->Finished Writing\n");
    if(++writers == i){
        printf("Writers finished\n");
		sem_post(&w);
        pthread_exit(0);
    }
    sem_post(&w);
}

int main(int argc, char *argv[]){
    int read = atoi(argv[1]), write = atoi(argv[2]);
	int i, j;
    sem_init(&w,0,1);
    sem_init(&readers,0,1);
    printf("%d   %d\n",read,write);
    pthread_t wid[write], rid[read];
	int a[read], b[write];
	
	for(i=0;i<read;i++)
		a[i] = i;
	for(i=0;i<write;i++)
		b[i] = i;
	
	for(i=0;i<read;i++)
    	pthread_create(&rid[i],NULL,reader,(void *)&a[i]);    
	for(i=0;i<write;i++)
		pthread_create(&wid[i],NULL,writer,(void *)&b[i]);

	for(i=0;i<read;i++)
    	pthread_join(rid[i],NULL);
	for(i=0;i<write;i++)
    	pthread_join(wid[i],NULL);

}
