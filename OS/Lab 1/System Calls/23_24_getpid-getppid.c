#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close

int main() {
    
    printf("This program demonstrates use of getpid() and getppid()\n");
    
    printf("Using fork() in the program...\n");
    fork();
    
    int pid = getpid();
    int ppid = getppid();
    printf("Current process ID = %d\n", pid);
    printf("Parent process ID = %d\n", ppid);

    exit(0);

}
