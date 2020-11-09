/*
    On a standard input stream, three lines of text are entered, each containing
    a 32-bit signed integer. The length of each line is exactly 8 characters,
    including the ending character '\n'.
    The father process creates three sons that work in parallel with each other.
    The sons receive sequence numbers 1, 2, and 3. Each process processes one of the input data rows.
    Each process outputs its sequence number and the square of the number read
    from the input string to the standard output stream.

    Processing consists of reading the value from the file, calculating the value
    and outputting the result. The standard input stream is not a random access file
    (it is a channel). The result of squaring is represented as a 32-bit signed type.

    Each result must be written on a separate line. The order in which the rows are output
    does not matter. The parent process must end with the most recent of all processes.
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

int main()
{
    pid_t pid;
    int tmp;
    if((pid = fork()) == 0)
    {
        scanf("%d", &tmp);
        tmp *= tmp;
        printf("%d\n", tmp);
        fflush(stdout);
        exit(0);
    }
    if((pid = fork()) == 0)
    {
        scanf("%d", &tmp);
        tmp *= tmp;
        printf("%d\n", tmp);
        fflush(stdout);
        exit(0);
    }
    if((pid = fork()) == 0)
    {
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
