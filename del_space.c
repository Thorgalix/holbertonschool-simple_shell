#include "shell.h"
/**
 * del_space - Supprime les espaces et tabulations au début
 * et à la fin d'une chaîne.
 * @str: chaîne à nettoyer
 *
 * Return: un pointeur vers le début de la chaîne nettoyée
 */
char *del_space(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str;
	while (*end)
		end++;

	end--;

	while (end > str && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}
	return (str);
}
