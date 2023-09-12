#include "shell.h"

/**
 * shell_prompt - displays prompt to user to input data
 *
 * Return: void
 */
void shell_prompt(void)
{
	char cwd[1024];
	char hostname[1024];
	char *username = getlogin();

	getcwd(cwd, sizeof(cwd));
	gethostname(hostname, sizeof(hostname));

	printf("%s@%s:%s$", username, hostname, cwd);
}
