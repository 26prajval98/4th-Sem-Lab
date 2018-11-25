#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close

int main() {
    int fd = creat("chown1.txt", S_IRWXU | S_IWGRP | S_IROTH);
    if(fd < 0) {
        printf("Error creating file.\n");
        exit(1);
    }
    
    if(chown("chown1.txt", 1003, 1002) != 0) {
        perror("");
        exit(1);
    }
    printf("successful\n");
       
    exit(0);
}
