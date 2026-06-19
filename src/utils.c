/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:57:04 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/18 09:51:02 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_free(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

static char	**get_path_matrix(char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*full_path;
	char	*tmp_path;
	int		i;

	paths = get_path_matrix(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		tmp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (access(full_path, X_OK) == 0)
		{
			ft_free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}

void	get_cmd(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		perror("fallo en el path");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve fallo");
		ft_free(cmd);
		free(path);
		exit(1);
	}
}
