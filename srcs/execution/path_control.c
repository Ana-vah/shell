/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:38:10 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/06 12:44:30 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	printf("%s: command not found\n", cmd);
	return (NULL);
}

char	*check_acces(char *cmd_path)
{
	if (access(cmd_path, X_OK) == 0)
		return (cmd_path);
	else
	{
		printf("%s: command not found\n", cmd_path);
		return (NULL);
	}
}

char	*path_control(char *cmd_path, char **paths, t_command *cmd)
{
	int	i;

	if (cmd->args[0][0] == '/')
		cmd_path = check_acces(cmd->args[0]);
	else
	{
		i = 0;
		while (paths[i++])
			paths[i] = ft_strjoin(paths[i], "/");
		cmd_path = get_cmd_path(paths, cmd->args[0]);
	}
	return (cmd_path);
}
