#include<stdio.h>

typedef struct process{
    int pid;
    int BT;
    int AT;
    int WT;
    int TAT;
    int pri;
    int done; 
}Process;

int findMin(Process *p,int time,int n){
    //printf("Hi %d\n",time);
    int i, min_index = n+1,min = 1000000,arr=100000;
    for(i=0;i<n;i++){
        if(p[i].done==0&&p[i].AT<=time&&p[i].pri<min){
            //if(i==3)printf("%d %d %d",p[i].done,p[i].AT,remain[i]);
            min = p[i].pri;
        }
    }
    for(i=0;i<n;i++){
        if(p[i].done==0&&p[i].AT<=time&&p[i].pri==min&&p[i].AT<arr){
            arr = p[i].AT;
            min_index = i;
        }
    }
    return min_index;
}

int Pri(Process *p, int n){
    //printf("Hi");
    int i,time = 0, complete = 0, remaining[n];
    for(i=0;i<n;i++){
        remaining[i] = p[i].BT;
    }  
    //int count=0;
    while(complete<n){
        i=findMin(p,time,n);
        time++;
        if(i<n){
            remaining[i]--;
            p[i].pri++;
            if(remaining[i]==0){
            p[i].done = 1;
            p[i].TAT = time - p[i].AT;
            p[i].WT = p[i].TAT - p[i].BT;
            complete++;
        }
        printf("Time:%d, Pid:%d , Pri:%d\n",time ,p[i].pid, p[i].pri);
        //printf("%d %d\n",i,remaining[i]);
        }
        //printf("time is :%d and index i %d\n",time-1,i);
    }
}

int main(){
    printf("Enter No of processes: ");
    int n,i;
    scanf("%d",&n);
    Process p[n];
    for(i=0;i<n;i++){
        p[i].pid = i;
        p[i].done = 0;
        printf("PID %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&p[i].AT);
        printf("Burst Time: ");
        scanf("%d",&p[i].BT);
        printf("Priority Time: ");
        scanf("%d",&p[i].pri);
        printf("Arrival Time:%d\tBurst time:%d\tPriority:%d\n",p[i].AT,p[i].BT,p[i].pri);
    }
    Pri(p,n);
    printf("PID\tAT\tBT\tPri\tWT\tTAT\n");
    float avgWT=0, avgTAT=0;
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid+1,p[i].AT,p[i].BT,p[i].pri,p[i].WT,p[i].TAT);
        avgWT+=p[i].WT;
        avgTAT+=p[i].TAT;
    }
    printf("Average WT:%f\nAverage TAT:%f\n",avgWT/n,avgTAT/n);
}
