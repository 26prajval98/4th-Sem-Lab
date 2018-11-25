/*#include <fcntl.h>
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int fd = open("/dev/cdrom", O_RDONLY);

	// Eject the CD-ROM drive
	ioctl(fd, CDROMEJECT);

	close(fd);
}*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    // Path to CD-ROM drive
    char *dev = "/dev/cdrom";
    int fd = open(dev, O_RDONLY | O_NONBLOCK);

    if(fd == -1){
        printf("Failed to open '%s'\n", dev);
        exit(1);
    }

    printf("fd :%d\n", fd);

    // Eject the CD-ROM tray 
    ioctl (fd, CDROMEJECT);
    sleep(2);

    // Close the CD-ROM tray
    ioctl (fd, CDROMCLOSETRAY);
    close(fd);

    return 0;
}
