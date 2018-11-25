#include<stdio.h>

typedef struct Process{	
	int si;
	int ei;
	int size;
	int pid;
	int pri;
	int remove;
	int flag;
}process;  

typedef struct Free{
	int si;
	int ei;
}free;

void minimize(free *F, int *end){

	int i, j;

	for(i=0;i< *end - 1; i++){
		for(j=0;j< *end - 1; j++){
			if(F[i].si == F[j].ei+1){
				F[i].si = F[j].si;
				F[j].si = -1;
				F[j].ei = -1;
			}
			if(F[i].ei+1 == F[j].si){
				F[i].ei = F[j].ei;
				F[j].si = -1;
				F[j].ei = -1;
			}
		}	
	}
}

void fr(process *P, int k, free * F, int * end){
	int i,j, flag = 0;
	
	if(P[k].remove == 0){	
	
		for(i=0;i<*end;i++){
			if(F[i].ei == P[k].si+1){
				F[i].ei = P[k].ei;
				P[k].remove = 1;
				flag = 1;
			}
		}
		if(!flag){
			F[(*end)].si = P[k].si;
			F[(*end)].ei = P[k].ei;
			(*end) = (*end)+1;
			P[k].remove = 1;
		}
	}		
}

void allocate(process *P, int n, free *F, int e){
	
	int size = -1, pri = 100000000, index = -1, indexF = -1, i, sizeF = -1, times = 0;

	for(i=0;i<n;i++){
		if(P[i].remove == -1){
			P[i].flag = 0;	
			times++;
		}
	}
	while(times){
		size = -1; pri = 100000000; index = -1; indexF = -1;sizeF = -1;
		
		for(i=0;i<n;i++){
			if(P[i].flag==0 && P[i].remove == -1 && P[i].pri <= pri){
				if(P[i].pri == pri && P[i].size > size){
					pri = P[i].pri;
					size = P[i].size; 
					index = i;
				}
				else if(P[i].pri!=pri){
					pri = P[i].pri;
					size = P[i].size; 
					index = i;
				}
			}
		}

		for(i=0;i<e;i++){
			if((F[i].ei-F[i].si + 1)<sizeF||e==1)
				indexF = i;
		}

		if((F[indexF].ei-F[indexF].si+1)>= P[index].size){
			P[index].si = F[indexF].si ;
			P[index].ei = P[index].si + P[index].size - 1;
			F[indexF].si = P[index].ei + 1;
			P[index].flag = 1;
			P[index].remove = 0;
			minimize(F,&e);
			printf("\nProcess:%d-%d-%d\n ",P[index].pid,P[index].si,P[index].ei);
		}
		else{
			P[index].flag = 1;
			P[index].remove = -1;
			printf("\nProcess:%d--NOT alooc\n",P[index].pid);
		}
		times--;
	}	
}

int main(){
	int mem, i;
	printf("TOTAL MEMORY: ");
	scanf("%d",&mem);

	process P[1000];
	free F[100];
	F[0].si = 0;
	F[0].ei = mem-1; 
	int end = 1;
	int pNo = 0;
	
	while(1){
		int a;
		printf("\nEnter your choice: 1ADD 2REMOVE  ");
		scanf("%d",&a);
		if(a==1){
			int n;
			printf("ENTER NUMBER OF PROCESSES: ");
			scanf("%d",&n);
			printf("Enter process and priority\n");
			for(i=0;i<n;i++){
				scanf("%d",&P[pNo].pid);	
				scanf("%d",&P[pNo].size);	
				scanf("%d",&P[pNo].pri);
				P[pNo].si = -1;
				P[pNo].ei = -1;
				P[pNo].remove = -1;
				pNo++;
			}
			allocate(P,pNo,F,end);
		}
		else{
			printf("No: ");
			int n;
			scanf("%d",&n);
			for(i=0;i<n;i++){
				int k;
				scanf("%d",&k);
				fr(P,k-1,F,&end);
			}
			allocate(P,pNo,F,end);
		}
	}
} 