#include "main.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(__attribute__((__unused__)) int ac, char **av)
{
	pid_t my_pid;
	char text[] = "test-for-fun";
	char delim[] = "-";

	my_pid = _getppid();
	printf("%u\n", my_pid);
	_print_process_id_maximum_value("/proc/sys/kernel/pid_max");
	_av(av);
	_print_line();
	_print_command_line_to_av(text, delim);

	printf("\n");

	return (0);
}