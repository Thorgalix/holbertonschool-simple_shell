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
/**
 * handle_exit - Gère la commande builtin exit
 * @av: tableau des arguments (av[0] == "exit")
 *
 * Cette fonction quitte le shell avec le code fourni
 * ou 0 si aucun argument.
 */
void handle_exit(char **av)
{
	size_t i;
	int status = 0;

	if (av[1])
	{
		/* Vérifie que l’argument est un entier positif ou négatif */
		char *arg = av[1];

		for (i = 0; arg[i]; i++)
		{
			if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
			continue;
			if (!isdigit(arg[i]))
			{
				fprintf(stderr, "%s: exit: %s: numeric argument required\n", SHELL_NAME, arg);
				/* Free memory before exit */
				for (i = 0; av[i]; i++)
					free(av[i]);
				free(av);
				_exit(2); /* code d’erreur pour argument invalide */
			}
		}
		status = atoi(av[1]);
	}
	/* Free memory before exit */
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	_exit(status);
}
