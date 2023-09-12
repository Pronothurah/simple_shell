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
	char *path;
	char **directories;
	list_t *list;

	my_pid = _getppid();
	printf("%u\n", my_pid);
	_print_process_id_maximum_value("/proc/sys/kernel/pid_max");
	_av(av);
	_print_line();
	_print_command_line_to_av(text, delim);
	_find_path("a.out");
	_find_path("testmeyeah");
	/* _print_environ(); */
	path = _get_env("PATH");
	directories = _get_directory_in_path(path);
	list = create_linkedlist_from_path_directory(directories);
	_print_directory_in_path(directories);
	_print_linkedlist(list);
	/* _execute_a_program(); */

	printf("\n");

	return (0);
}