/*
    A parent creates a son, a grandchild, and a great-grandson.
    The great-grandson sends the current time received
    using system call "time" to the channel in binary form (time_t type).

    Father, son, and grandson read the time from the channel.
    The father process displays the string "Y:????",
    where ???? replaced with the current year, son — "M:??",
    where ?? are replaced with the current month of the year (from 1 to 12),
    the number is always output with two characters, the grandson is "D:??",
    where ?? replaced with the number of the day in the month,
    always output with two characters.

    The grandson should print the number first, the son - second,
    the father - third.
    Only a great-grandson is allowed to write to the channel. The parent must wait
    for all processes to complete and then terminate itself with code 0.

    Example output:
    D:11
    M:09
    Y:2001
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
#include <time.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);
    if(fork() == 0)
    {
        if(fork() == 0)
        {
            if(fork() == 0)
            {
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
