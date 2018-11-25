#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int pid;
    int BT;
    int priority;
    int WT;
    int done;
    int TAT;
} Process;

void doPri(Process *P, int n){
    int complete = 0;
    int t=0, min_p = 100, index;
    int i;
    while(complete < n){
        for(i=0;i<n;i++){
            if(P[i].priority < min_p && P[i].done == 0){
                //printf("ijfdh\n");
                min_p = P[i].priority;
                index = i;
           }
        }
        printf("%d %d\n",min_p,index);
        P[index].WT = t;
        t+=P[index].BT;
        P[index].done = 1;
        min_p = 100;
        P[index].TAT = P[index].BT + P[index].WT; 
        complete++;
    }
}

int main(){

    int i,n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process P[n];
    printf("NOTE: Enter Arrival Time in INCREASING ORDER\n");
    for(i=0;i<n;i++){
        printf("-------------------------------\n\nProcess %d\nEnter Priority: ",i+1);
        P[i].pid = i+1;
        scanf("%d",&P[i].priority);
        
        //P[i].AT = 0;
        
        printf("Enter burst time: ");
        scanf("%d",&P[i].BT);
        P[i].done = 0;
    }
    doPri(P,n);
    printf("------------------------------------------------------------------\n");
    printf("Process\tPri\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].priority,P[i].BT,P[i].WT,P[i].TAT);
        avgWT += P[i].WT;
        avgTAT += P[i].TAT;
    }
    printf("Avg waiting time: %f\nAvg turnaround time: %f ",avgWT/n,avgTAT/n);
    return 0;
}

