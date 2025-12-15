#include "shell.h"
#include <sys/wait.h>
/**
 * main - Point d'entrée du programme.
 * @ac: nombre d'arguments passés au programme (non utilisé)
 * @av: tableau des arguments passés au programme (non utilisé)
 * @envp: tableau des variables d'environnement
 *
 * Cette fonction affiche un prompt, lit les commandes de l'utilisateur,
 * puis les exécute en boucle jusqu'à la fin de l'entrée standard.
 *
 * Return: 0 en cas de succès
 */
int main(int ac, char **av, char **envp)
{
	char *cmd, *line = NULL;	/*contient la ligne entrée par l'U*/
	size_t len = 0;				/*taille pour le buffer*/
	ssize_t read;				/*nombre de caractères lus*/
	(void)ac;
	(void)av;

	while (1)
	{
		read = get_line(&line, &len);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
			printf("\n");

			break;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		cmd = del_space(line);
		if (*cmd == '\0')
			continue;
		exe_cmd(cmd, envp);
	}
	free(line);
	return (0);
}
