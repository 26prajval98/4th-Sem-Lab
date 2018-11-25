#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close

int main() {
    
    int fd = creat("umask.txt", 0764);
    
    umask(fd);
    system("ls -l umask.txt");
    
}
