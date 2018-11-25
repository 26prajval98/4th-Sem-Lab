#include<stdio.h>
#define INFINITY 100000000

int CLOOK(int* A, int n, int start, int si){
    int i, sum = 0;

    if(start>A[0]){
        sum = (start-A[0]);
        sum+= (A[n-1]-A[0]);
        sum+= (A[n-1]-A[si]);
    }
    else{
        sum =(A[n-1]-start);
        sum+= (A[n-1]-A[0]);
    }
    return sum;
}

int main(){
    int A[100], n, i, j, start;

    printf("Enter length of work queue: ");
    scanf("%d",&n);

    printf("\nEnter Work Queue: ");

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("\n");

    printf("Enter Start: ");
    scanf("%d",&start);

    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    int si = 0;
    
    for(i=0;i<n;i++){
        if(A[i]>start)
            break;
    }

    si = i;

    int ret = CLOOK(A,n,start,si);
    printf("Total time is estimated by total arm motion: %d\n", ret);
}