#include<stdio.h>
#define INFINITY 100000000

int SSTF(int* A, int n, int start){
    int i, sum = 0, done[n], completed = 0, min, index;

    for( i=0; i<n ; i++ ){
        done[i] = 0;
    } 

    while(completed<n){
        min = INFINITY;
        for(i=0;i<n;i++){
            if(!done[i] && abs(start-A[i])<min){
                min = abs(start-A[i]);
                index = i;
            }
        }
        done[index] = 1;
        start = A[index];
        sum+=min;
        completed++;
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

    printf("Total time is estimated by total arm motion: %d\n", SSTF(A,n,start));
}