#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line)
{
	char *token;
	char **av = NULL;
	size_t count = 0;
	char *line_copy = strdup(line);

	if (!line_copy)
	return (NULL);

	token = strtok(line_copy, " \t");
	while (token)
	{
		av = realloc(av, sizeof(char *) * (count + 2));
		av[count] = strdup(token);
		count++;
		token = strtok(NULL, " \t");
	}
	if (av)
	av[count] = NULL;

	free(line_copy);
	return (av);
}
