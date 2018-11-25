#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for creat, open
#include <unistd.h> // for read, write, close

int main() {
    
    int fd = open("chdir1.txt", O_WRONLY | O_CREAT | O_APPEND);
    printf("Creating file \"chdir1.txt\" in current directory\n");
    int size = write(fd, "This is a line in chdir1\n", 25);
    close(fd);
    
    chdir("..");
    printf("Changed directory from \"28_change\" to \"Proper\".\n");
    
    fd = open("chdir2.txt", O_WRONLY | O_CREAT | O_APPEND);
    printf("Creating file \"chdir2.txt\" in current directory\n");
    size = write(fd, "This is a line in chdir2\n", 25);
    close(fd);
    
    // chdir(
}
