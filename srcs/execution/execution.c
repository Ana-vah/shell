/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:10:24 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/10 07:41:43 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	exec_cmd(char *cmd_path, char **cmd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
	{
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

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

int	execution(t_command *command, t_env_list *env_list)
{
	t_command	*cmd;
	char		*path;
	char		**paths;
	char		*cmd_path;

	cmd = command;
	path = get_env_value(env_list->head, "PATH");
	paths = ft_split(path, ':');
	cmd_path = NULL;
	cmd_path = path_control(cmd_path, paths, cmd);
	if (check_builtins(cmd) == 1)
	{
		if (cmd->input_file || cmd->output_file)
			exec_builtin_with_redirection(cmd, env_list);
		else
			exec_builtin(cmd, env_list);
	}
	else if (cmd->input_file || cmd->output_file)
		exec_cmd_with_redirection(cmd_path, cmd->args, \
		cmd->input_file, cmd->output_file);
	else
		exec_cmd(cmd_path, cmd->args);
	free_paths(paths);
	return (0);
}
