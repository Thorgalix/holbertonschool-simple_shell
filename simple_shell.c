#include "shell.h"
#include <sys/wait.h>
#include <fcntl.h>

/**
 * main - Point d'entrée du programme.
 * @ac: nombre d'arguments passés au programme
 * @av: tableau des arguments passés au programme
 * @envp: tableau des variables d'environnement
 *
 * Cette fonction affiche un prompt, lit les commandes de l'utilisateur,
 * puis les exécute en boucle jusqu'à la fin de l'entrée standard.
 * Si un fichier de script est passé en argument,il est exécuté à la place.
 *
 * Return: 0 en cas de succès
 */
int main(int ac, char **av, char **envp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *cmd;
	int status = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#usr$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		cmd = del_space(line);
		if (*cmd == '\0')
			continue;

		if (strncmp(cmd, "exit", 4) == 0)
		{
			av = split_line(cmd);
			handle_exit(av);
		}

		status = exe_cmd(cmd, envp);
	}

	free(line);
	return (status);
}
