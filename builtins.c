#include "shell.h"
/**
*/
int builtin_env(char **envp)
{
int i = 0;
if (!envp)
return (0);
while (envp[i])
{
printf("%s\n", envp[i]);
i++;
}
return (0);
}