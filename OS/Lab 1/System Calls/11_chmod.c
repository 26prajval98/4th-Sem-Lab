#include<stdio.h>
#include<sys/file.h>
#include<sys/stat.h>

int main(){
	int create = creat("changeMode.txt",S_IRWXU);
	
	if(access>0)
		printf("File Accessed %d\n",acc);
	else
		printf("Error\n");
}
