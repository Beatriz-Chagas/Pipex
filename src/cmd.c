/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 04:33:06 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/11 21:13:21 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	argv = ft_split(cmd, ' ');
	if (!argv || !argv[0])
	{
		ft_putstr_fd("pipex: empty command\n", 2);
		free_split(argv);
		exit(127);
	}
	path = find_executable(argv[0], envp);
	if (!path)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_split(argv);
		exit(127);
	}
	execve(path, argv, envp);
	perror("execve");
	free(path);
	free_split(argv);
	exit(EXIT_FAILURE);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
