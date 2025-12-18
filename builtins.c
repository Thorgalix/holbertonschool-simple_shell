#include "shell.h"
/**
 * builtin_env - Affiche l'environnement courant
 * @envp: tableau des variables d'environnement
 *
 * Return: 0 en cas de succès
 */
int builtin_env(char **envp)
{
	int i = 0;
	int has_shlvl = 0;

	if (envp)
	{
		while (envp[i])
		{
			if (strncmp(envp[i], "SHLVL=", 6) == 0)
				has_shlvl = 1;
			printf("%s\n", envp[i]);
			i++;
		}
	}

	if (!has_shlvl)
		printf("SHLVL=0\n");

	return (0);
}