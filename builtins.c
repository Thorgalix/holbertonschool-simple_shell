#include "shell.h"
/**
 * builtin_env - Prints the current environment
 * @envp: array of environment variables
 *
 * Return: 0 on success
 */
int builtin_env(char **envp)
{
	int i = 0;
	int has_shlvl = 0;

	if (!envp)
		return (0);

	/* Check if SHLVL exists in environment */
	while (envp[i])
	{
		if (strncmp(envp[i], "SHLVL=", 6) == 0)
			has_shlvl = 1;
		printf("%s\n", envp[i]);
		i++;
	}

	/* If SHLVL not found, output SHLVL=0 */
	if (!has_shlvl)
		printf("SHLVL=0\n");

	return (0);
}