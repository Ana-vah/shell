/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:39:48 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/16 13:03:09 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	check_pipe(char *input, t_meta *meta)
{
	int		i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
			meta->pipe = TOKEN_PIPE;
		i++;
	}
	return (0);
}
