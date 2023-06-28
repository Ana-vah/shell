/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:30:36 by vdescamp          #+#    #+#             */
/*   Updated: 2023/05/18 11:21:32 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	env_builtin(t_env_list *env_list)
{
	t_env	*list;

	list = env_list->head;
	if (list == NULL)
		printf("NO ENV");
	while (list)
	{
		printf("%s\n", list->var);
		list = list->next;
	}
}
