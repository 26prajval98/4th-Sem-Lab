#include<stdio.h>


int FCFS(int* A, int n, int start){
    int i;
    int sum = 0;

    for( i=0; i<n ; i++ ){
        sum += abs(start-A[i]);
        start = A[i];
    } 
    return sum;
}

int main(){
    int A[100], n, i, start;

    printf("Enter length of work queue: ");
    scanf("%d",&n);

    printf("\nEnter Work Queue: ");

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("\n");

    printf("Enter Start: ");
    scanf("%d",&start);

    printf("Total time is estimated by total arm motion: %d\n", FCFS(A,n,start));
}