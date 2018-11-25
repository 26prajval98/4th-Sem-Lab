#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int pid;
    int BT;
    int WT;
    int done;
    int TAT;
} Process;


void doRR(Process *P, int n, int qt){
    int complete = 0;
    int t=0, min_time = 100, index, R[n];
    int i,j=0;
    for(i=0;i<n;i++){
        R[i] = P[i].BT;
    }
    while(complete < n){
        for(i=0;i<n;i++){
            if(P[i].done == 0){
                if(R[i]>qt){
                    t+=qt;
                    R[i]-=qt;
                }
                else if(R[i]<qt){
                    t+=R[i];
                    P[i].TAT = t; 
                    P[i].WT = P[i].TAT - P[i].BT;
                    P[i].done = 1;                    
                    complete++;
                }
                else{
                    t += qt; 
                    P[i].TAT = t; 
                    P[i].WT = P[i].TAT - P[i].BT;
                    P[i].done = 1;
                    complete++;
                }
            }
        }
    }
}

int main()
{
    int i,n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process P[n];
    int qt;
    printf("Enter Quantum Time: ");
    scanf("%d",&qt);
    for(i=0;i<n;i++){
        printf("-------------------------------\n\nProcess %d :",i+1);
        P[i].pid = i+1;
        printf("Enter burst time: ");
        scanf("%d",&P[i].BT);
        P[i].done = 0;    
    }
    doRR(P,n,qt);
    printf("------------------------------------------------------------------\n");
    printf("Process\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t\n",P[i].pid,P[i].BT,P[i].WT,P[i].TAT);
        avgWT += P[i].WT;
        avgTAT += P[i].TAT;
    }
    printf("Avg waiting time: %f\nAvg turnaround time: %f ",avgWT/n,avgTAT/n);
    return 0;
}


