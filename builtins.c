#include "shell.h"
/**
*/
int builtin_env(char **environ)
{
int i = 0;
while (environ[i])
{
printf("%s\n", environ[i]);
i++;
}
return (1);
}