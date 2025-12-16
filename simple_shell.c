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
 * Si un fichier de script est passé en argument, il est exécuté à la place.
 *
 * Return: 0 en cas de succès
 */
int main(int ac, char **av, char **envp)
{
	char *cmd, *line = NULL;
	size_t len = 0;
	ssize_t read;
	int status = 0;
	FILE *input = stdin;
	int fd = -1;

	if (ac > 1)			/* Si un fichier de script est passé en argument */
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "%s: 0: Can't open %s\n", av[0], av[1]);
			return (127);
		}
		input = fdopen(fd, "r");
		if (!input)
		{
			close(fd);
			return (127);
		}
	}

	while (1)
	{
		if (input == stdin && isatty(STDIN_FILENO))
			printf("#usr$ ");

		read = getline(&line, &len, input);

		if (read == -1)
		{
			if (input == stdin && isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (line[read - 1] == '\n')
		line[read - 1] = '\0';

		cmd = del_space(line);

		if (*cmd == '\0')
			continue;

		status = exe_cmd(cmd, envp);
	}
	free(line);

	if (input != stdin)
		fclose(input);

	return (status);
}
