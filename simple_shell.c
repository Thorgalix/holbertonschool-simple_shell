#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * get_line - Affiche le prompt puis lit une ligne depuis l'entrée standard.
 * @line: pointeur vers le buffer qui contiendra la ligne lue
 * @len: taille du buffer
 *
 * Return: le nombre de caractères lus ou -1 en cas d'erreur ou EOF
 */
ssize_t get_line(char **line, size_t *len)
{
	if (isatty(STDIN_FILENO))
		printf("#usr$ ");

	return (getline(line, len, stdin));
}
/**
 * exe_cde - Crée un processus enfant et exécute la commande donnée.
 * @line: commande saisie par l'utilisateur
 *
 * Cette fonction lance un fork, exécute la commande dans l'enfant
 * et attend la fin du processus dans le parent.
 */
void exe_cde(char *line)
{
	pid_t child = fork();

		if (child < 0)
		{
			perror("fork");
			return;
		}
		if (child == 0)
		{
			char *av[2];

			av[0] = line;
			av[1] = NULL;
			if (execve(line, av, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		waitpid(child, NULL, 0);
}
/**
 * main - Point d'entrée du programme.
 *
 * Cette fonction affiche un prompt, lit les commandes de l'utilisateur,
 * puis les exécute en boucle jusqu'à la fin de l'entrée standard.
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
	char *line = NULL;	/*contient la ligne entrée par l'U*/
	size_t len = 0;		/*taille pour le buffer*/
	ssize_t nread;		/*nombre de caractères lus*/

	while (1)
	{
		nread = get_line(&line, &len);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
			printf("\n");

			break;
		}
		if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

		if (line[0] == '\0')
		continue;
		exe_cde(line);
		/*system(line);*/
	}
	free(line);
	return (0);
}
