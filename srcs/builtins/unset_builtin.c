/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:11 by vdescamp          #+#    #+#             */
/*   Updated: 2023/05/18 11:22:23 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	unset_builtin(char *var_name, t_env_list *env_list)
{
	t_env	*current;
	t_env	*previous;

	current = env_list->head;
	previous = NULL;
	while (current)
	{
		if (ft_strncmp(current->var, var_name, ft_strlen(var_name)) == 0
			&& current->var[ft_strlen(var_name)] == '=')
		{
			if (previous == NULL)
				env_list->head = current->next;
			else
				previous->next = current->next;
			free(current->var);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
	printf("unset: %s: no such variable\n", var_name);
}
