#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int S;
int E;
int F;

void waitS(){
    //printf("hbasd");
    while(S<=0);
    S--;
}

void signalS(){
    S++;
}

void waitE(){
    while(E<=0);
    E--;
}

void signalE(){
    E++;
}
void waitF(){
    while(F<=0);
    F--;
}

void signalF(){
    F++;
}
int p,c;

void* producer(void *n){
    int *j = (int *)n;
    int i = *j;
    while(1){
        waitS();
        waitE();
        printf("Producer %d\n",E);
        signalS();
        signalF();
        //printf("Producer\n");
        p++;
        if(p>=i){
            printf("Exiting: producer\n");
            pthread_exit(0);
        }
    }
}

void* consumer(void *n){
    int *j = (int *)n;
    int i = *j;
    while(1){
        waitS();
        waitF();
        printf("Consumer %d\n",E);
        signalS();
        signalE();
        //aprintf("Consumer\n");
        c++;
        if(c>=i){
            printf("Exiting Consumer\n");
            pthread_exit(0);
        }
    }
}


int main(int argc, char* argv[]){

    int n = atoi(argv[1]);
    //printf("%d %d %d\n",n,10,11);

    E = n;

    printf("%d\n",E);

    S = 1;
    F = 0;

    int pro = atoi(argv[2]);
    int con = atoi(argv[3]);

    //printf("%d %d %d %d %d\n",S,E,F,pro,con);

    pthread_t pid, cid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&pid,&attr,producer,(void *)&pro);
    pthread_create(&cid,&attr,consumer,(void *)&con);

    pthread_join(pid,NULL);
    pthread_join(cid,NULL);

} 