#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line)
{
	char *token, *line_copy, *line_count;
	char **av = NULL;
	size_t i, count = 0;

	if (!line)
		return (NULL);

	line_count = strdup(line);
	if (!line_count)
		return (NULL);

	token = strtok(line_count, " \t");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t");
	}
	free(line_count);

	av = malloc(sizeof(char *) * (count + 1));
	if (!av)
		return (NULL);

	line_copy = strdup(line);
	if (!line_copy)
	{
		free(av);
		return (NULL);
	}

	token = strtok(line_copy, " \t");
	for (i = 0; i < count; i++)
	{
		av[i] = strdup(token);
		if (!av[i])
		{
			while (i > 0)
				free(av[--i]);
			free(av);
			free(line_copy);
			return (NULL);
		}
		token = strtok(NULL, " \t");
	}
	av[count] = NULL;
	free(line_copy);

	return (av);
}

