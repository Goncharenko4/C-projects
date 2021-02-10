#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int tmp;
    if ((pid = fork()) == 0) {
        scanf("%d", &tmp);
        tmp *= tmp;
        printf("%d\n", tmp);
        fflush(stdout);
        exit(0);
    }
    if ((pid = fork()) == 0) {
        scanf("%d", &tmp);
        tmp *= tmp;
        printf("%d\n", tmp);
        fflush(stdout);
        exit(0);
    }
    if ((pid = fork()) == 0) {
        scanf("%d", &tmp);
        tmp *= tmp;
        printf("%d\n", tmp);
        fflush(stdout);
        exit(0);
    }
    
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}
