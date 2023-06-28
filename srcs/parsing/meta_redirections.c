/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:41:45 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/06 13:22:21 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	check_redirections(char *input, t_meta *meta)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '>' && input[i + 1] == '>')
		{
			i++;
			meta->output_redir = TOKEN_DBL_OUTPUT;
		}
		else if (input[i] == '<' && input[i + 1] == '<')
		{
			i++;
			meta->input_redir = TOKEN_DBL_INPUT;
		}
		else if (input[i] == '>')
			meta->output_redir = TOKEN_SGL_OUTPUT;
		else if (input[i] == '<')
			meta->input_redir = TOKEN_SGL_INPUT;
		i++;
	}
	return (0);
}
