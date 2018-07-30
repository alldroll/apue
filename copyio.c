#include "apue.h"

#define BUFFER_SIZE 4096

int main() {
    int n;
    char buf[BUFFER_SIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("Fail to write buf");
        }
    }

    if (n < 0) {
        err_sys("Fail to read buf");
    }

    exit(0);
}
