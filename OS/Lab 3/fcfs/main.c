#include <stdio.h>
#include <stdlib.h>

int max(int A, int B){
    if(A>B)
        return A;
    else
        return B;
}

void calculateWT(int *W,int *S,int *A,int n){
    int i;
    for(i=0;i<n;i++){
        W[i] = S[i] - A[i];
    }
}

float calculateTAT(int *T,int *W,int *B,int n){
    int i;
    for(i=0;i<n;i++){
        T[i] = W[i] + B[i];
    }
}

float calculateAvg(int *A, int n){
    int i,avg = 0;
    for(i=0;i<n;i++){
        avg+=A[i];
    }
    return avg;
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int W[n], B[n], A[n],S[n], time=0, T[n], i;
    printf("NOTE: Enter Arrival Time in INCREASING ORDER\n");
    for(i=0;i<n;i++){
        printf("-------------------------------\n\nProcess %d : \nEnter arrival time:",i+1);
        if(i!=0)scanf("%d",&A[i]);
        else {
            printf("0\n");
            A[0] = 0;
        }
        printf("Enter burst time: ");
        scanf("%d",&B[i]);
        if(i>0)S[i] = max(time + B[i-1], A[i]);
        else S[i] = 0;
        time = S[i];
    }
    calculateWT(W,S,A,n);
    calculateTAT(T,W,B,n);
    float avgWT = calculateAvg(W,n);
    float avgTAT = calculateAvg(T,n);
    printf("------------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i+1,A[i],B[i],W[i],T[i]);
    }
    printf("Avg waiting time: %f\nAvg turnaround time: %f ",avgWT/n,avgTAT/n);
    return 0;
}


