#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close

int main() {
    printf("This program demonstrates use of getegid()\n");
    int egid = getegid();
    printf("Effective group ID value = %d\n", egid);
}
