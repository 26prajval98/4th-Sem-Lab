//16CO234   
//Prajval M


#include<stdio.h>
#include<stdlib.h>

typedef struct Process{
    int AT;
    int TAT;
    int WT;
    int BT;
    int pid;
    int complete;
    int TOC;
}process;

void LIFO(process * p, int N){
    int i, completed = 0, time = 0;
    int w[N];
    for(i=0;i<N;i++){
        w[i] = p[i].BT;
    }
    while(completed<N){
        int index = 10000, maxAT = -1000;
        for(i=0;i<N;i++){
            if(maxAT <= p[i].AT && time >= p[i].AT && p[i].complete!=1){
                index = i;
                maxAT = p[i].AT;
            }
        }
        time++;
        if(index<10000){
            w[index]--;
            printf("|%d|",index);
            if(w[index]==0){
                p[index].complete  = 1;
                p[index].TAT = time - p[index].AT;
                p[index].WT = p[index].TAT - p[index].BT;
                p[index].TOC = time;    
                completed++;             

            }
        }
    }
}

int main(){
    int N;
    printf("Enter No Of processes:");
    scanf("%d",&N);
    int i;
    process p[N];
    
    for(i=0;i<N;i++){
        p[i].pid = i;
        p[i].complete = 0;
        printf("\n\nEnter Arrival and Burst time for %d process\n",i);
        printf("Arrival Time:");
        scanf("%d",&p[i].AT);
        printf("Burst Time:");
        scanf("%d",&p[i].BT);
    }
   
    LIFO(p,N);
    
    printf("\n\nPID\tAT\tBT\tWT\tTAT\tTOC\n");
    for(i=0;i<N;i++)
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid, p[i].AT, p[i].BT, p[i].WT, p[i].TAT,p[i].TOC);
    
    float avgTAT=0, avgWT=0;
    for(i=0;i<N;i++){
        avgTAT += p[i].TAT;
        avgWT += p[i].WT;
    }
    printf("\n\nAVG TAT: %f\nAVG WT : %f\n", avgTAT/N, avgWT/N);
    return 0;
}
