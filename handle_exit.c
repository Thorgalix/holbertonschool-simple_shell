#include "shell.h"
#define SHELL_NAME "./hsh"
/**
 * handle_exit - Gère la commande builtin exit
 * @av: tableau des arguments (av[0] == "exit")
 *
 * Cette fonction quitte le shell avec le code fourni
 * ou 0 si aucun argument.
 */
void handle_exit(char **av)
{
	size_t i;
    int status = 0;

    if (av[1])
    {
        /* Vérifie que l’argument est un entier positif ou négatif */
        char *arg = av[1];
        for (i = 0; arg[i]; i++)
        {
            if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
                continue;
            if (!isdigit(arg[i]))
            {
                fprintf(stderr, "%s: exit: %s: numeric argument required\n", SHELL_NAME, arg);
                /* Free memory before exit */
                for (i = 0; av[i]; i++)
                    free(av[i]);
                free(av);
                _exit(2); /* code d’erreur pour argument invalide */
            }
        }
        status = atoi(av[1]);
    }

    /* Free memory before exit */
    for (i = 0; av[i]; i++)
        free(av[i]);
    free(av);
    _exit(status);
}
