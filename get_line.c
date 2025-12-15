#include "shell.h"
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
