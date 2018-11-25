#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int pid;
    int BT;
    int AT;
    int WT;
    int done;
    int TAT;
    int pri;
} Process;


void doPri(Process *P, int n){
    int complete = 0;
    int t=0;
    while(complete < n){
        int i, index = n+1,min = 1000000,arr=100000;
        for(i=0;i<n;i++){
            if(P[i].done==0&&P[i].AT<=t&&P[i].pri<min){
                //if(i==3)printf("%d %d %d",P[i].done,P[i].AT,remain[i]);
                min = P[i].pri;
            }
        }
        for(i=0;i<n;i++){
            if(P[i].done==0&&P[i].AT<=t&&P[i].pri==min&&P[i].AT<arr){
                arr = P[i].AT;
                index = i;
            }
        }        
        complete++;
        P[index].done = 1;
        P[index].WT = t - P[index].AT;
        t = t + P[index].BT;
        P[index].TAT = P[index].WT  + P[index].BT;    
    }
}

int main()
{
    int i,n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process P[n];
    printf("NOTE: Enter Arrival t in INCREASING ORDER\n");
    for(i=0;i<n;i++){
        printf("-------------------------------\n\nProcess %d : \nEnter arrival t:",i+1);
        P[i].pid = i+1;
        scanf("%d",&P[i].AT);
        printf("Enter burst t: ");
        scanf("%d",&P[i].BT);
        printf("Enter priority: ");
        scanf("%d",&P[i].pri);
        P[i].done = 0;
    }
    doPri(P,n);
    printf("------------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].AT,P[i].BT,P[i].WT,P[i].TAT);
        avgWT += P[i].WT;
        avgTAT += P[i].TAT;
    }
    printf("Avg waiting t: %f\nAvg turnaround t: %f ",avgWT/n,avgTAT/n);
    return 0;
}