/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:49:33 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/06 13:23:51 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

static t_command	*malloc_command(void)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
	{
		perror("malloc");
		exit(1);
	}
	return (cmd);
}

t_command	*init_cmd(t_command *cmd, char **env, char *user_input)
{
	cmd = malloc_command();
	cmd->env = env;
	cmd->raw_input = ft_strdup(user_input);
	cmd->quote_pos_arg = 0;
	cmd->arg_count = 0;
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->meta = init_cmd_meta();
	return (cmd);
}

t_command	*parser(char *user_input, char **env)
{
	t_command	*cmd;
	char		**tokens;
	int			token_count;

	cmd = NULL;
	cmd = init_cmd(cmd, env, user_input);
	if (check_meta(user_input, cmd) == 0)
	{
		tokens = tokenizer(user_input);
		token_count = 0;
		while (tokens[token_count] != NULL)
		{
			printf("from parser [%s]\n", tokens[token_count]);
			token_count++;
		}
		handle_redirection(cmd, tokens, token_count);
		for(int i = 0; i < token_count; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		printf("[%d]\n", TOKEN_DBL_QUOTE);
		printf("[%d]\n", TOKEN_SGL_INPUT);
		printf("arg_count = %d\n", cmd->arg_count);
		printf("squotes = %d\n", cmd->meta->sgl_quote);
		printf("dquotes = %d\n", cmd->meta->dbl_quote);
		printf("input_redir = %d\n", cmd->meta->input_redir);
		printf("output_redir = %d\n", cmd->meta->output_redir);
		printf("quote_pos_arg = %d\n", cmd->quote_pos_arg);
		printf("input_file = %s\n", cmd->input_file);
		printf("output_file = %s\n", cmd->output_file);
		return (cmd);
	}
	return (NULL);
}
