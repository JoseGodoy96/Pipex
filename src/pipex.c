/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:56:41 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/09/18 09:45:15 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child(int *fd, char *argv[], char *envp[])
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		perror("error al abrir el archivo");
		exit(1);
	}
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
	get_cmd(argv[2], envp);
}

void	father(int *fd, char *argv[], char *envp[])
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("error al abrir el archivo");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
	get_cmd(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe fallo");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork fallo");
			exit(1);
		}
		if (pid == 0)
			child(fd, argv, envp);
		father(fd, argv, envp);
	}
	else
	{
		perror("mal numero de argumentos");
		exit(1);
	}
}
