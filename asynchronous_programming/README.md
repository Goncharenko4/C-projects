## Tasks on asynchronous programming

<b> [Squaring by childs](./squaring_by_sons.c): </b><br>
    
    On a standard input stream, three lines of text are entered, each containing
    a 32-bit signed integer. The length of each line is exactly 8 characters,
    including the ending character '\n'.
    The parent process creates three childs that work in a parallel with each other.
    The child receives sequen numbers 1, 2, and 3. Each process processes one of the input data rows.
    Each process outputs its sequence number and the square of the number read
    from the input string to the standard output stream.
    
    Processing consists of reading the value from the file, calculating the value
    and outputting the result. The standard input stream is not a random access file
    (it is a channel). The result of squaring is represented as a 32-bit signed type.
    
    Each result must be written on a separate line. The order in which the rows are output
    does not matter. The parent process must end with the most recent of all processes.

<br> <b> [Current time](./current_time.c): </b><br>
    
    A parent creates a child, a grandchild, and a great-grandchild.
    The great-grandchild sends the current time received
    using system call "time" to the channel in binary form (time_t type).
    
    Parent, child, and grandchild read the time from the channel.
    The father process displays the string "Y:????",
    where ???? replaced with the current year, child — "M:??",
    where ?? are replaced with the current month of the year (from 1 to 12),
    the number is always output with two characters, the grandchild is "D:??",
    where ?? replaced with the number of the day in the month,
    always output with two characters.
    
    The grandchild should print the number first, the child - second,
    the father - third.
    Only a great-grandchild is allowed to write to the channel. The parent must wait
    for all processes to complete and then terminate itself with code 0.
    
    Example output:
    D:11
    M:09
    Y:2001
    
<br> <b> [Two linked channels](./two_linked_channels.c): </b><br>
    
    A parent creates two childs by linking them with two channels.
    The childs start exchanging the numbers 1, 2, 3, ...
    the first child gets the Number 1. When getting a number from
    input channel each child prints to a standard stream
    output the parent's own number (1 or 2) and the resulting number
    and sends back a number that is 1 higher.
    When the number specified in the command line is reached,
    the child does not forward the number to the channel, but shuts down.
    
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
    
<br> <b> [Digital speedometer](./digital_speedometer.c): </b><br>
    
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
