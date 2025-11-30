#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

char    **split_args(const char *cmd);
char    *find_executable(char *cmd, char **envp);
void    exec_cmd(char *cmd, char **envp);
void    free_split(char **arr);

#endif