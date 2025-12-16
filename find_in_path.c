#include "shell.h"
/**
 * find_in_path - Cherche une commande dans les dossiers du PATH
 * @cmd: commande à chercher
 *
 * Return: chemin complet si trouvé, NULL sinon
 */
char *find_in_path(char *cmd)
{
	char *path, *copy, *token, *full;

	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));

		return (NULL);
	}
	path = getenv("PATH");
	if (!path)
		return (NULL);

	copy = strdup(path);
	if (!copy)
		return (NULL);

	token = strtok(copy, ":");
	while (token)
	{
		full = malloc(strlen(token) + strlen(cmd) + 2);
		if (!full)
			break;

		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}
		free(full);
		token = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}
