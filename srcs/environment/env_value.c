/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:30:09 by vdescamp          #+#    #+#             */
/*   Updated: 2023/04/26 09:40:21 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

char	*get_env_value(t_env *env_list, char *var_name)
{
	t_env	*current;

	current = env_list;
	while (current != NULL)
	{
		if (ft_strncmp(current->var, var_name, ft_strlen(var_name)) == 0 \
		&& current->var[ft_strlen(var_name)] == '=')
			return (current->var + ft_strlen(var_name) + 1);
		current = current->next;
	}
	return (NULL);
}
