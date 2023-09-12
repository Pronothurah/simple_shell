Exercises<br>
0. getppid => (DONE)<br>
Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?<br>

1. /proc/sys/kernel/pid_max => (DONE)<br>
Write a shell script that prints the maximum value a process ID can be.<br>

2. av => (DONE)<br>
Write a program that prints all the arguments, without using ac.<br>

3. Read line => (DONE), #advanced => NOT<br>
Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.<br>
#advanced: Write your own version of getline.<br>

4. command line to av => (DONE), #advanced => NOT<br>
Write a function that splits a string and returns an array of each word of the string.<br>
#advanced: Write the function without strtok<br>

5.fork + wait + execve => (DONE) <br>
Write a program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.<br>

6. find a file in the PATH<br>
Write a program that looks for files in the current PATH.<br>

7. Exercises<br>
  7.0. printenv with environ => (DONE)<br>
  Write a program that prints the environment using the global variable environ.<br>

  7.1. env vs environ<br>
  Write a program that prints the address of env (the third parameter of the main function) and environ (the global variable). Are they they same? Does this make sense?<br>

  7.2. getenv() => (DONE)<br>
  Write a function that gets an environment variable. (without using getenv)<br>
  Prototype: char *_getenv(const char *name);<br>

  7.3. PATH => (DONE)<br>
  Write a function that prints each directory contained in the the environment variable PATH, one directory per line.<br>

  7.4. PATH<br>
  Write a function that builds a linked list of the PATH directories.<br>

  7.5. setenv<br>
  Write a function that changes or adds an environment variable (without using setenv).<br>
  Prototype: int _setenv(const char *name, const char *value, int overwrite);<br>

  7.6. unsetenv<br>
  Write a function that deletes the variable name from the environment (without using unsetenv).<br>
  Prototype: int _unsetenv(const char *name);<br>