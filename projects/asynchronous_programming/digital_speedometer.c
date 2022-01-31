#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

long speed = 0;
long distance = 0;

void sig_handler(int sig) {
    printf("speed - %ld\n", speed);
    if (sig == SIGTSTP) {
        printf("%ld\n", distance);
        exit(0);
    } else if (sig == SIGINT) {
        speed++;
    } else if (sig == SIGQUIT) {
        if (speed != 0) {
            speed--;
        }
    }

    if (sig == SIGALRM) {
        distance += 1 * speed;
    }
}

int main(int argc, char **argv) {
    speed = strtol(argv[1], NULL, 10);
    signal(SIGALRM, sig_handler);
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTSTP, sig_handler);

    for (;;) {
        alarm(1);
        sleep(1);
    }
    return 0;
}
