/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:09:05 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/06 13:24:57 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	input_redirection(t_command *cmd, char **tokens, int token_count, int *index)
{
	if (*index + 1 < token_count)
	{
		cmd->input_file = ft_strdup(tokens[*index + 1]);
		(*index)++;
	}
	else
	{
		fprintf(stderr, "Missing input file name after '<'\n");
		free(cmd->args);
		cmd->args = NULL;
	}
}

void	output_redirection(t_command *cmd, char **tokens, int token_count, int *index)
{
	if (*index + 1 < token_count)
	{
		cmd->output_file = ft_strdup(tokens[*index + 1]);
		(*index)++;
	}
	else
	{
		fprintf(stderr, "Missing output file name after '>'\n");
		free(cmd->args);
		cmd->args = NULL;
	}
}

void	handle_redirection(t_command *cmd, char **tokens, int token_count)
{
	int		i;
	int		j;
	char	**new_args;

	new_args = malloc(sizeof(char *) * token_count + 1);
	if (!new_args)
	{
		perror("malloc");
		exit(1);
	}
	i = 0;
	j = 0;
	while (i < token_count)
	{
		if (ft_strcmp(tokens[i], "<") == 0)
			input_redirection(cmd, tokens, token_count, &i);
		else if (ft_strcmp(tokens[i], ">") == 0)
			output_redirection(cmd, tokens, token_count, &i);
		else
			new_args[j++] = ft_strdup(tokens[i]);
		i++;
	}
	new_args[j] = NULL;
	j = 0;
	while (new_args[j] != NULL)
		printf("new_args---->[%s]\n", new_args[j++]);
	free(cmd->args);
	cmd->args = new_args;
}
