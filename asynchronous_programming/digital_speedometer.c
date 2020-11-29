/*
    The program simulates the operation of a digital speedometer.

    The initial speed (a 32-bit signed integer) required
    by this program are specified on the command line.
    The digital speedometer handles timer interrupts that are modeled using the ALRM signal.
    The USR1 and USR2 signals come from the accelerometer,
    USR1 means that the speed has increased by one unit and USR2 means that
    the speed has decreased by one unit.
    At the TERM signal, the program outputs the distance traveled
    (at the time of the last processed ALRM) to the standard output stream and exits.
    All units of measurement (time between timer interrupts, speed, acceleration)
    are consistent with each other, so no scale factors are required.
    Standard input and standard output of the program will be redirected to channels.
    Don't forget to reset the output buffer. On the other side of the channels
    is a process that starts its work as soon as it receives the pid of the process.
    One unit of change time passes from the output of the pid to the arrival of the first ALRM.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

long speed = 0;
long distance = 0;

void sig_handler(int sig)
{
    printf("speed - %ld\n", speed);
    if(sig == SIGTSTP)
    {
        printf("%ld\n", distance);
        exit(0);
    }
    else if(sig == SIGINT)
    {
        speed++;
    }
    else if(sig == SIGQUIT)
    {
        if(speed != 0)
        {
            speed--;
        }
    }
    
    if(sig == SIGALRM)
    {
        distance += 1 * speed;
    }
}

int main(int argc, char **argv)
{
    speed = strtol(argv[1], NULL, 10);
    signal(SIGALRM, sig_handler);
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTSTP, sig_handler);
    
    for(;;)
    {
        alarm(1);
        sleep(1);
    }
    return 0;
}
