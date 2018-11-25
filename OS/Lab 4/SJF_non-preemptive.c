#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int pid;
    int BT;
    int AT;
    int WT;
    int done;
    int TAT;
} Process;


void doSJF(Process *P, int n){
    int complete = 0;
    int t=0, min_time = 100, index;
    int i;
    while(complete < n){
        for(i=0;i<n;i++){
            if(P[i].AT <= t && P[i].BT < min_time && P[i].done == 0){
                min_time = P[i].BT;
                index = i;
            }
        }
        printf("%d,%d,%d\n",index,min_time,t);
        if(min_time == 100){
            t++;
        }
        else{
            min_time = 100;
            complete++;
            P[index].done = 1;
            P[index].WT = t - P[index].AT;
            t = t + P[index].BT;
            P[index].TAT = P[index].WT  + P[index].BT;
        }
    }
}

int main()
{
    int i,n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process P[n];
    printf("NOTE: Enter Arrival Time in INCREASING ORDER\n");
    for(i=0;i<n;i++){
        printf("-------------------------------\n\nProcess %d : \nEnter arrival time:",i+1);
        P[i].pid = i+1;
        scanf("%d",&P[i].AT);
        printf("Enter burst time: ");
        scanf("%d",&P[i].BT);
        P[i].done = 0;
    }
    doSJF(P,n);
    printf("------------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].AT,P[i].BT,P[i].WT,P[i].TAT);
        avgWT += P[i].WT;
        avgTAT += P[i].TAT;
    }
    printf("Avg waiting time: %f\nAvg turnaround time: %f ",avgWT/n,avgTAT/n);
    return 0;
}



