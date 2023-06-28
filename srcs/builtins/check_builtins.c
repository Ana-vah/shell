/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:25:49 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/10 07:53:34 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	redirect_input(t_command *cmd)
{
	int	in_fd;

	if (cmd->input_file)
	{
		in_fd = open(cmd->input_file, O_RDONLY);
		if (in_fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
}

void	redirect_output(t_command *cmd)
{
	int	out_fd;

	if (cmd->output_file)
	{
		out_fd = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}

void	exec_builtin_with_redirection(t_command *cmd, t_env_list *env_list)
{
	int	stdin_copy;
	int	stdout_copy;

	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	redirect_input(cmd);
	redirect_output(cmd);
	exec_builtin(cmd, env_list);
	dup2(stdin_copy, STDIN_FILENO);
	dup2(stdout_copy, STDOUT_FILENO);
	close(stdin_copy);
	close(stdout_copy);
}

void	exec_builtin(t_command *cmd, t_env_list *env_list)
{
	if (cmd->args[0] == NULL)
		return ;
	if (strcmp(cmd->args[0], "echo") == 0)
		echo_builtin(cmd->args);
	else if (strcmp(cmd->args[0], "cd") == 0)
		cd_builtin(cmd->args);
	else if (strcmp(cmd->args[0], "pwd") == 0)
		pwd_builtin();
	else if (strcmp(cmd->args[0], "export") == 0)
		export_builtin(cmd->args, env_list);
	else if (strcmp(cmd->args[0], "unset") == 0)
		unset_builtin(*cmd->args, env_list);
	else if (strcmp(cmd->args[0], "env") == 0)
		env_builtin(env_list);
	else if (strcmp(cmd->args[0], "exit") == 0)
		exit_builtin();
}

int	check_builtins(t_command	*cmd)
{
	char	**arg;

	arg = cmd->args;
	if (strcmp(arg[0], "echo") == 0 || strcmp(arg[0], "cd") == 0 || \
	strcmp(arg[0], "pwd") == 0 || strcmp(arg[0], "export") == 0 || \
	strcmp(arg[0], "unset") == 0 || strcmp(arg[0], "env") == 0 || \
	strcmp(arg[0], "exit") == 0)
		return (1);
	return (0);
}
