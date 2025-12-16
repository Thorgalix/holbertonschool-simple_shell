#include "shell.h"
#define SHELL_NAME "./hsh"
/**
 * exe_cmd - Crée un processus enfant et exécute la commande donnée.
 * @line: commande saisie par l'utilisateur
 * @envp: tableau des variables d'environnement
 *
 * Cette fonction lance un fork, exécute la commande dans l'enfant
 * et attend la fin du processus dans le parent.
 * Return: 1
 */
int exe_cmd(char *line, char **envp)
{
	pid_t child = fork();
	size_t i;
	char *cmd_path;

	int status;

	if (child < 0)
	{
		perror("fork");
		return (1);
	}
	if (child == 0)
	{
		char **av = split_line(line);

		if (!av || !av[0])
			_exit(0);

		if (strcmp(av[0], "exit") == 0)
			handle_exit(av);

		if (strcmp(av[0], "env") == 0)
		{
		builtin_env(envp);
		return (1);
		}
		cmd_path = find_in_path(av[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", SHELL_NAME, 1, av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			_exit(127);
		}
		execve(cmd_path, av, envp);
		free(cmd_path);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		_exit(126);
	}
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
