#ifndef PIPEX_H
#define PIPEX_H

#ifndef BONUS
#define BONUS = 0
#endif

#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


void child_input(int *fd, char **argv, char **env);
void child_middle(int **fd, int pos, char **argv, char **env)
void child_output(int *fd, int pos, char **argv, char **env)
void pipex(char **argv, char **env);
void pipex_bonus(int argc, char **argv, char **env);
int path_checker(char **env);
char *path_getter(char *cmd, char **env);
void ft_exec(char *argv, char **env);
void ft_error(void);

#endif
