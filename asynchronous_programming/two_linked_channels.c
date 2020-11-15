/*
    A parent creates two sons by linking them with two channels.
    The sons start exchanging the numbers 1, 2, 3, ...
    the first son gets the Number 1. When getting a number from
    input channel each son prints to a standard stream
    output the parent's own number (1 or 2) and the resulting number
    and sends back a number that is 1 higher.
    When the number specified in the command line is reached,
    the son does not forward the number to the channel, but shuts down.

    The process can terminate either upon receipt
    the maximum number from the channel, or when
    end of file in the channel. Complete the process in other settings
    cases are not allowed.

    The father waits for both processes to complete,
    then outputs the Done string and exits.

    If the number 5 is passed in the command line,
    the pid of the first process is 100, the pid of the second process is 101,
    then the output should be:

    11 
    22 
    13 
    24 
    Done
*/

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

int main(int argc, char **argv)
{
    /* Maximum number from the command line: */
    int max;
    sscanf(argv[1], "%d", &max);
    
    /*
        Channel for writing by the 2nd process to the 1st process
        and reading from the 1st process to the 2nd process:
    */
    int fd[2];
    pipe(fd);
    
    /*
        Channel for writing the 1st process to the 2nd process
        and reading by the 2nd process of the 1st process:
    */
    int fd2[2];
    pipe(fd2);
    
    if(fork() == 0)
    {
        close(fd[1]);
        close(fd2[0]);
        int tmp1;
        while(read(fd[0], &tmp1, sizeof(int)))
        {
            if(tmp1 >= max)
            {
                break;
            }
            printf("1 %d\n", tmp1);
            tmp1++;
            write(fd2[1], &tmp1, sizeof(int));
        }
        close(fd[0]);
        close(fd2[1]);
        exit(0);
    }
    
    if(fork() == 0)
    {
        int init_tmp = 1;
        write(fd[1], &init_tmp, sizeof(int));
        
        close(fd2[1]);
        close(fd[0]);
        int tmp2;
        while(read(fd2[0], &tmp2, sizeof(int)))
        {
            if(tmp2 >= max)
            {
                break;
            }
            printf("2 %d\n", tmp2);
            tmp2++;
            write(fd[1], &tmp2, sizeof(int));
        }
        close(fd[1]);
        close(fd2[0]);
        exit(0);
    }
    
    close(fd[0]);
    close(fd[1]);
    close(fd2[0]);
    close(fd2[1]);
    
    wait(NULL);
    wait(NULL);
    
    printf("Done\n");
    
    return 0;
}
