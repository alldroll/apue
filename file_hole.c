#include <fcntl.h>
#include "apue.h"

// ls -l file_hole.txt
// od -c file_hole.txt

char buf1[] = "AAAAAAAAAA";
char buf2[] = "BBBBBBBBBB";

int main() {
    int fd = creat("file_hole.txt", FILE_MODE);

    if (fd < 0) {
        err_sys("Fail to call creat");
    }

    if (write(fd, buf1, 10) != 10) {
        err_sys("Fail to write buf1");
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("Fail to call lseek");
    }

    if (write(fd, buf2, 10) != 10) {
        err_sys("Fail to write buf2");
    }

    exit(0);
}
