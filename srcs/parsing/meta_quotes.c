/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:36:20 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/02 15:56:02 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

static bool	sgl_quote_status(bool sgl_quote, bool dbl_quote)
{
	if (dbl_quote == false)
	{
		if (sgl_quote == true)
			sgl_quote = false;
		else
			sgl_quote = true;
	}
	return (sgl_quote);
}

static bool	dbl_quote_status(bool dbl_quote, bool sgl_quote)
{
	if (sgl_quote == false)
	{
		if (dbl_quote == true)
			dbl_quote = false;
		else
			dbl_quote = true;
	}
	return (dbl_quote);
}

int	check_quotes(char *input, t_meta *meta)
{
	int		i;
	bool	sgl_quote;
	bool	dbl_quote;

	i = 0;
	sgl_quote = false;
	dbl_quote = false;
	while (input[i++] != '\0')
	{
		if (input[i] == 39)
		{
			sgl_quote = sgl_quote_status(sgl_quote, dbl_quote);
			if (sgl_quote == false)
				meta->sgl_quote = TOKEN_SGL_QUOTE;
		}
		else if (input[i] == 34)
		{
			dbl_quote = dbl_quote_status(dbl_quote, sgl_quote);
			if (dbl_quote == false)
				meta->dbl_quote = TOKEN_DBL_QUOTE;
		}
	}
	if (sgl_quote == true || dbl_quote == true)
	{
		printf(BRED"Error : check quotes\n"NC);
		return (-1);
	}
	return (0);
}
