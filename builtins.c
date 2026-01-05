#include "shell.h"
/**
 * builtin_env - affiche l'environnement actuel
 * @envp: chaîne de variable d'environnement
 *
 * Return: 0 en cas de succès
 */
int builtin_env(char **envp)
{
	int i = 0;
	int has_shlvl = 0;

	if (!envp)
		return (0);

	/* Check si SHLVL existe dans l'environnement*/
	while (envp[i])
	{
		if (strncmp(envp[i], "SHLVL=", 6) == 0)
			has_shlvl = 1;
		printf("%s\n", envp[i]);
		i++;
	}

	/**
	* si SHLVL n'existe pas on affiche 0 pour indiquer que
	* c'est le premier niveau de shell
	*/
	if (!has_shlvl)
		printf("SHLVL=0\n");

	return (0);
}
