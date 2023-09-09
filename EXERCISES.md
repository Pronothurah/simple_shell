Exercises
0. getppid => (DONE)
Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?

1. /proc/sys/kernel/pid_max => (DONE)
Write a shell script that prints the maximum value a process ID can be.

2. av => (DONE)
Write a program that prints all the arguments, without using ac.

3. Read line => (DONE), #advanced => NOT
Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.
#advanced: Write your own version of getline.

4. command line to av => (DONE), #advanced => NOT
Write a function that splits a string and returns an array of each word of the string.
#advanced: Write the function without strtok

5.fork + wait + execve
Write a program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.