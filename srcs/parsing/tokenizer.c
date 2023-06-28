/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:30:02 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/16 13:46:37 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	init_tokenizer(t_tokenizer *t, int len)
{
	t->tokens = malloc((len + 1) * sizeof(char *));
	t->current_token = malloc((len + 1) * sizeof(char));
	t->current_token_len = 0;
	t->token_count = 0;
	t->quote_char = '\0';
}

char	**tokenizer(char *user_input)
{
	int			len;
	t_tokenizer	t;
	int			i;

	len = strlen(user_input);
	init_tokenizer(&t, len);
	i = 0;
	while (i <= len)
	{
		if (user_input[i] == ' ')
		{
			if (t.quote_char != '\0')
				handle_others(user_input[i], &t);
			else
				handle_space(&t);
		}
		else if (user_input[i] == '\'' || user_input[i] == '\"')
			handle_quote(user_input[i], &t);
		else if (user_input[i] == '>' || user_input[i] == '<' || \
				user_input[i] == '|')
			handle_meta(user_input[i], &t);
		else if (user_input[i] == '\0')
		{
			if (t.current_token_len > 0)
				end_token(&t);
		}
		else
		{
			handle_others(user_input[i], &t);
		}
		i++;
	}
	t.tokens[t.token_count] = NULL;
	return (t.tokens);
}
