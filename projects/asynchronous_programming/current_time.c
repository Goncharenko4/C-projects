#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        if (fork() == 0) {
            if (fork() == 0) {
                close(fd[0]);
                time_t time_now = time(NULL);
                write(fd[1], &time_now, sizeof(time_t));
                write(fd[1], &time_now, sizeof(time_t));
                write(fd[1], &time_now, sizeof(time_t));

                close(fd[1]);
                exit(1);
            }
            wait(NULL);
            time_t time;
            read(fd[0], &time, sizeof(time_t));
            struct tm *pt = localtime(&time);

            printf("D:%02d\n", pt->tm_mday + 1);

            close(fd[0]);
            close(fd[1]);
            exit(1);
        }

        wait(NULL);
        time_t time;
        read(fd[0], &time, sizeof(time_t));
        struct tm *pt2 = localtime(&time);

        printf("M:%02d\n", pt2->tm_mon + 1);

        close(fd[0]);
        close(fd[1]);
        exit(1);
    }

    wait(NULL);
    time_t time;
    read(fd[0], &time, sizeof(time_t));
    close(fd[0]);
    close(fd[1]);

    struct tm *pt3 = localtime(&time);
    printf("Y:%04d\n", pt3->tm_year + 1900);

    return 0;
}
