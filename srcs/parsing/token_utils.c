/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:05:19 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/02 15:37:07 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	end_token(t_tokenizer *t)
{
	t->current_token[t->current_token_len] = '\0';
	t->tokens[t->token_count++] = strdup(t->current_token);
	t->current_token_len = 0;
}

void	handle_quote(char user_char, t_tokenizer *t)
{
	if (t->quote_char == '\0')
	{
		t->quote_char = user_char;
	}
	else if (t->quote_char == user_char)
	{
		t->quote_char = '\0';
		end_token(t);
	}
}

void	handle_meta(char user_char, t_tokenizer *t)
{
	if (t->quote_char == '\0')
	{
		if (t->current_token_len > 0)
		{
			end_token(t);
		}
		t->current_token[0] = user_char;
		t->current_token[1] = '\0';
		t->tokens[t->token_count++] = strdup(t->current_token);
	}
}

void	handle_space(t_tokenizer *t)
{
	if (t->quote_char == '\0')
	{
		if (t->current_token_len > 0)
		{
			end_token(t);
		}
	}
}

void	handle_others(char user_char, t_tokenizer *t)
{
	if (user_char != ' ' || (t->quote_char != '\0' && user_char == ' '))
	{
		t->current_token[t->current_token_len] = user_char;
		(t->current_token_len)++;
	}
}
