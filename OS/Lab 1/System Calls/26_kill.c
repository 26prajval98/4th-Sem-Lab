#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close
#include <signal.h>

int main() {
    int pid = getpid();
    
    if(kill(pid, 0) != 0) {
        printf("Error sending signal!\n");
        exit(1);
    }
    printf("Succeeded\n");
    exit(0)
}
