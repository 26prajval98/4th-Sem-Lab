#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd;
	long position;

	fd = open("datafile.dat", O_RDONLY);
	if ( fd != -1){
	   position = lseek(fd, 0L, 2);  /* seek 0 bytes from end-of-file */
	   if (position != -1)
	      printf("The length of datafile.dat is %ld bytes.\n", position);
	   else
	      perror("lseek error");
	}
	else
	   printf("can't open datafile.dat\n");
	close(fd);
}
