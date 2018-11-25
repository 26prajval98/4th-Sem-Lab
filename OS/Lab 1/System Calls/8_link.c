#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(){
	int n = link("idk.txt", "link.txt"); 
	if(n<0)
		printf("Error\n");
	else
		printf("Successful\n");	
}
