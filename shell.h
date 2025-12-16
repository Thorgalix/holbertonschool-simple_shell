#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


ssize_t get_line(char **line, size_t *len);
char *del_space(char *str);
char **split_line(char *line);
int exe_cmd(char *line, char **envp);
char *find_in_path(char *cmd);

#endif
