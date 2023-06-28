/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:53:14 by vdescamp          #+#    #+#             */
/*   Updated: 2023/04/26 11:07:04 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	header(void)
{
	printf(BRED"\n************************\n"NC);
	printf(BRED"*"GREEN"    MiniShell_1_0     "BRED"*\n"NC);
	printf(BRED"************************\n\n"NC);
}

int	main(int ac, char **av, char **env)
{
	char		*user_input;
	t_env_list	env_list;

	if (env == NULL)
		return (0);
	env_list = dup_env(env);
	(void)ac;
	(void)av;
	user_input = (char *)ft_calloc(sizeof(char), MAX_LINE);
	if (!user_input)
		perror("!Malloc");
	header();
	prompt(user_input, env, &env_list);
	free(user_input);
	return (0);
}
