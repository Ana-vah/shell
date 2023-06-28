/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_with_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:34:50 by vdescamp          #+#    #+#             */
/*   Updated: 2023/05/18 14:08:39 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	exec_cmd_with_redirection(char *cmd_path, char **cmd, char *input_file, char *output_file)
{
	int		status;
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	status = 0;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
	{
		if (input_file)
		{
			fd_in = open(input_file, O_RDONLY);
			if (fd_in == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			if (dup2(fd_in, STDIN_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			if (close(fd_in) == -1)
			{
				perror("close");
				exit(EXIT_FAILURE);
			}
		}
		if (output_file)
		{
			fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd_out == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			if (dup2(fd_out, STDOUT_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			if (close(fd_out) == -1)
			{
				perror("close");
				exit(EXIT_FAILURE);
			}
		}
		if (execve(cmd_path, cmd, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			printf("Exit status: %d\n", WEXITSTATUS(status));
	}
}
