#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/file.h>

int main(){
	
	int fd = open("idk.txt", O_RDWR|O_TRUNC), size ;
	
	//int fd_dup = dup(fd);
	
	char buffer[100] = "Some text...DONE USING WRITE CLOSE DUP & READ\n";
	
	if(fd<0){
		printf("Error\n");
		exit(1);
	}
	
	else
		printf("opened file successfully in Readonly mode, fd is %d\n", fd);
	
	size = write(fd, buffer, strlen(buffer));
	
	if(size > 0){
		printf("Write Successful\n");
		//printf("Size:%d \nContent is: %s", size, buffer);
	}
	else	
		printf("Write Error\n");
	
	//close(fd);
	
	fd = open("idk.txt", O_RDONLY), size ;
	
	int fd_dup = dup(fd);
		
	char *buffer2 = (char *)malloc(100*sizeof(char));
	
	int size2 = read(fd_dup, buffer2, 80);
	
	if(size2 > 0){
		buffer2[size2] = '\0';	
		printf("Read Successful\n");
		printf("Size:%d \nContent is: %s", size2, buffer2);
	}
	else
		printf("Read Error\n");
	
	//close(fd);
	/*close(fd1);

	int fd2 = creat("idk2.txt", S_IRWXU);
	
	if(fd2<0)
		printf("Error\n");
	else
		printf("fd2 is %d\n", fd2);*/

}
