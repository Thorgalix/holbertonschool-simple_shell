#include "shell.h"
/**
 * exe_cmd - Crée un processus enfant et exécute la commande donnée.
 * @line: commande saisie par l'utilisateur
 * @envp: tableau des variables d'environnement
 *
 * Cette fonction lance un fork, exécute la commande dans l'enfant
 * et attend la fin du processus dans le parent.
 */
void exe_cmd(char *line, char **envp)
{
	pid_t child = fork();
	size_t i;

		if (child < 0)
		{
			perror("fork");
			return;
		}
		if (child == 0)
		{
			char **av = split_line(line);

			if (!av)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			if (execve(av[0], av, envp) == -1)
			{
				perror("./shell");
				for (i = 0; av[i]; i++)
					free(av[i]);
				free(av);
				exit(EXIT_FAILURE);
			}
		}
		else
		waitpid(child, NULL, 0);
}
