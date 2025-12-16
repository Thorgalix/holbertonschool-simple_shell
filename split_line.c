#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line)
{
    char *token, *line_copy;
    char **av = NULL;
    size_t i, count = 0;

    if (!line)
        return NULL;

    line_copy = strdup(line);
    if (!line_copy)
        return NULL;

    token = strtok(line_copy, " \t");
    while (token)
    {
        char **tmp = realloc(av, sizeof(char *) * (count + 2));
        if (!tmp)
        {
            for (i = 0; i < count; i++)
                free(av[i]);
            free(av);
            free(line_copy);
            return NULL;
        }
        av = tmp;

        av[count] = strdup(token);
        if (!av[count])
        {
            for (i = 0; i < count; i++)
                free(av[i]);
            free(av);
            free(line_copy);
            return NULL;
        }

        count++;
        token = strtok(NULL, " \t");
    }

    if (av)
        av[count] = NULL;

    free(line_copy);
    return av;
}

