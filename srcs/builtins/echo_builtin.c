/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:30:21 by vdescamp          #+#    #+#             */
/*   Updated: 2023/05/18 11:21:10 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	echo_builtin(char	**args)
{
	int		i;
	bool	new_line;

	i = 1;
	new_line = true;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		new_line = false;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
}
