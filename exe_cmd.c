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
	char *cmd_path;

	if (child < 0)
	{
		perror("fork");
		return;
	}
	if (child == 0)
	{
		char **av = split_line(line);

		if (!av || !av[0])
			exit(EXIT_FAILURE);

		cmd_path = find_in_path(av[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "./shell: %s: not found\n", av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			exit(127);
		}
		execve(cmd_path, av, envp);
		perror("./shell");
		free(cmd_path);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		exit(EXIT_FAILURE);
	}
	else
	waitpid(child, NULL, 0);
}
