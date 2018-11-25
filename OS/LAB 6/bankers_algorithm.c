#include<stdio.h>
#include<stdlib.h>

typedef struct P{
    int A;
    int B;
    int C;
}p;


void sub(p *A, p *B, p *C, int n){
    int i;    
    for(i=0;i<n;i++){
        C[i].A = B[i].A - A[i].A;
        C[i].B = B[i].B - A[i].B;
        C[i].C = B[i].C - A[i].C;
    }    
}

void add(p *A, p *B, p *C, int n){
    int i;    
    for(i=0;i<n;i++){
        C[i].A = B[i].A + A[i].A;
        C[i].B = B[i].B + A[i].B;
        C[i].C = B[i].C + A[i].C;
    }    
}


int check(p A, p B){
    if(B.A>=A.A&&B.B>=A.B&&B.C>=A.C)
        return 1;
    else return 0;
}

void safety(p Available, p* A, p *Need, int N){
    
    p Work = Available;
    int done[N],completed = 0,safety[N];
    int i;
    for(i=0;i<N;i++){
        done[i] = 0;
    }
    
    while(completed<N){
        int flag = 1;
        
        for(i=0; i<N; i++){ 
            if(check(Need[i],Work)&&done[i]!=1){
                flag = 0;
                done[i]=1;
                safety[completed] = i;
                completed++;
                printf("%d P:%d %d %d    W:%d %d %d\n", i,Need[i].A,Need[i].B,Need[i].C, Work.A, Work.B, Work.C );
                add(&Work,&A[i],&Work,1);
            }
        }
        
        if(flag==1)
            break;
    }
    
    if(completed==N){
        printf("Safe\n");
        printf("Safety Sequence: ");
        for(i=0;i<N;i++)
            printf("%d-> ",safety[i]);
        printf("Done\n");
    }            
    else
        printf("Unsafe\n");
}

int main(){
    
    int pro = 5;
    //printf("Enter processes: ");
    //scanf("%d",&pro);
    
    p A[] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    p Max[]= {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    p Need[pro],Available = {3,3,2};
    
    printf("Enter Allocation\n");
    
    int i;
   
    /*for(i=0;i<pro;i++){
        printf("Enter resource for A: ");
        scanf("%d",&A[i].A);
        printf("Enter resource for B: ");
        scanf("%d",&A[i].B);
        printf("Enter resource for C: ");
        scanf("%d",&A[i].C);
        printf("\n\n");
    }
    printf("-----------------------------------------------------------------------");
    
    printf("Enter MAX\n");
    
    for(i=0;i<pro;i++){
        printf("Enter resource for A: ");
        scanf("%d",&Max[i].A);
        printf("Enter resource for B: ");
        scanf("%d",&Max[i].B);
        printf("Enter resource for C: ");
        scanf("%d",&Max[i].C);
        printf("\n\n");
    }
    
    
    printf("-----------------------------------------------------------------\n Enter available resources\n");
    
    printf("Enter resource for A: ");
    scanf("%d",&Available.A);
    printf("Enter resource for B: ");
    scanf("%d",&Available.B);
    printf("Enter resource for C: ");
    scanf("%d",&Available.C);
    printf("\n\n");
    */
    sub(A,Max,Need,pro);
    
    for(i=0;i<pro;i++)
        printf("%d %d %d\n",Need[i].A, Need[i].B, Need[i].C);
    
    printf("________________________________________________________________________________\n");
    
    printf("Request\n");
    int pid; 
    printf("Process No: ");
    scanf("%d",&pid);
 
    p Req;
    
    printf("Enter resource for A: ");
    scanf("%d",&Req.A);
    printf("Enter resource for B: ");
    scanf("%d",&Req.B);
    printf("Enter resource for C: ");
    scanf("%d",&Req.C);
    
    int flag = 1;
    
    //printf("%d\n",check(Available,Need[0]));
    //printf("%d %d %d\n",Need[0].A,Need[0].B,Need[0].C);
    //printf("%d %d %d\n",Available.A,Available.B,Available.C);
    if(check(Req,Need[pid])){
        if(check(Req,Available)){
            flag = 0;
            sub(&Req,&Need[pid],&Need[pid],1);
            //printf("%d %d %d\n",Need[pid].A,Need[pid].B,Need[pid].C);
            sub(&Req,&Available,&Available,1);
            add(&A[pid],&Req,&A[pid],1);
            safety(Available,A,Need,pro);
        }
    }
    
    if(flag != 0){
        printf("Request cannot be done\n");
    }
}
            
    
    
    
    
    
    
    
    
    
    
