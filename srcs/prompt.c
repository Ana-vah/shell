/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:30:09 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/16 13:59:06 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	free_command(t_command	*cmd)
{
	int	i;

	if (cmd)
	{
		i = 0;
		free(cmd->raw_input);
		cmd->raw_input = NULL;
		if (cmd->args)
		{
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				cmd->args[i] = NULL;
				i++;
			}
			free(cmd->args);
			cmd->args = NULL;
		}
		free(cmd);
	}
}

int	prompt(char *input, char **env, t_env_list *env_list)
{
	t_command	*cmd;

	while (1)
	{
		input = readline(BRED"Oneye"BYELLOW"@MiniShell $> "NC);
		add_history(input);
		printf(BGREEN"%s\n"NC, input);
		if (input[0] == '\0')
			continue ;
		cmd = parser(input, env);
		printf("cmd->meta->pipe = %d\n", cmd->meta->pipe);
		free(input);
		if (cmd == NULL)
			continue ;
		if (cmd->meta->pipe == TOKEN_PIPE)
		{
			printf("PIPE\n");
			execute_with_pipe(cmd, cmd->tokens);
		}
		else
			execution(cmd, env_list);
		free_command(cmd);
	}
	return (0);
}
