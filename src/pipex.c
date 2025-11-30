/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:12:57 by bchagas-          #+#    #+#             */
/*   Updated: 2025/11/30 04:46:01 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Outfile error");
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	exec_cmd(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("Infile error");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	close(fd[1]);
	exec_cmd(argv[2], envp);
}

int main(int argc, char **argv, char **envp)
{
	int	fd[2];
	pid_t	pid1;
	
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);	
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
		child_process(argv, envp, fd);
	waitpid(pid1, NULL, 0);
	parent_process(argv, envp, fd);
	return (0);
}
void free_split(char **arr)
{
    int i = 0;
    if (!arr) return;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}