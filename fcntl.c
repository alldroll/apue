#include "apue.h"
#include <fcntl.h>

/*
 * ./fcntl 0 < /dev/tty
 * ./fcntl 1 > /tmp/t && cat /tmp/t
 * ./fcntl 5 5<>/tmp/t
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        err_quit("Usage: fcntl <descriptor number>");
    }

    int val;
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        err_sys("Fail to call fcntl for %d", atoi(argv[1]));
    }

    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("Only for reading");
            break;
        case O_WRONLY:
            printf("Only for writing");
            break;
        case O_RDWR:
            printf("For reading and writing");
            break;
        default:
            printf("Unknown access mode");
    }

    if (val & O_APPEND) {
        printf(", append to the end of file");
    }

    if (val & O_NONBLOCK) {
        printf(", nonblocking mode");
    }

    if (val & O_SYNC) {
        printf(", sync mode");
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC) {
        printf(", sync mode");
    }
#endif

    putchar('\n');
    exit(0);
}
