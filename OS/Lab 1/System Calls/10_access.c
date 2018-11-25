#include<stdio.h>
#include<unistd.h>

int main(){
	
	int acc = access("idk.txt",F_OK|R_OK);
	
	if(access>0)
		printf("File Accessed %d\n",acc);
	else
		printf("Error\n");
}	
