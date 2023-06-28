/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:49 by vdescamp          #+#    #+#             */
/*   Updated: 2023/05/18 11:42:34 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

/*chdir()-> If successful, chdir() changes the
working directory and returns 0.*/
void	cd_builtin(char	**args)
{
	char	*home;

	if (args[1])
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	else
	{
		home = getenv("HOME");
		if (home)
		{
			if (chdir(home) != 0)
				perror("cd");
		}
		else
			printf("cd: HOME not set\n");
	}
}
