/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:10:00 by bchagas-          #+#    #+#             */
/*   Updated: 2025/12/11 21:07:22 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*join_path(const char *dir, const char *cmd)
{
	int		len_dir;
	int		len_cmd;
	char	*full_path;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	full_path = malloc(len_dir + len_cmd + 2);
	if (!full_path)
		return (NULL);
	ft_memcpy(full_path, dir, len_dir);
	full_path[len_dir] = '/';
	ft_memcpy(full_path + len_dir + 1, cmd, len_cmd);
	full_path[len_dir + len_cmd + 1] = '\0';
	return (full_path);
}

static char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*search_paths(char **paths, char *cmd)
{
	int		i;
	char	*candidate;

	i = 0;
	while (paths[i])
	{
		candidate = join_path(paths[i], cmd);
		if (!candidate)
			return (NULL);
		if (access(candidate, X_OK) == 0)
			return (candidate);
		free(candidate);
		i++;
	}
	return (NULL);
}

static char	*try_direct(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*find_executable(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*found;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (try_direct(cmd));
	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	found = search_paths(paths, cmd);
	free_split(paths);
	return (found);
}
