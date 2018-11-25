#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close

int main() {
    printf("This program demonstrates use of getgid()\n");
    int gid = getgid();
    printf("Real group ID value = %d\n", gid);
}
