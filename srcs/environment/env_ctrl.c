/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 06:57:13 by vdescamp          #+#    #+#             */
/*   Updated: 2023/04/26 11:06:20 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

// static void	print_list(t_env_list *env_list)
// {
// 	t_env	*list;

// 	list = env_list->head;
// 	if (list == NULL)
// 		printf("NULL\n");
// 	while (list)
// 	{
// 		printf("%s\n", list->var);
// 		list = list->next;
// 	}
// }

static void	add_tail(t_env_list *env_list, char *var)
{
	t_env	*ptr;
	t_env	*new_node;

	ptr = env_list->head;
	new_node = (t_env *)malloc(sizeof(t_env));
	if (new_node == NULL)
	{
		perror("malloc");
		return ;
	}
	new_node->var = var;
	new_node->next = NULL;
	if (ptr == NULL)
	{
		env_list->head = new_node;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}
}

t_env_list	dup_env(char **env)
{
	t_env_list	env_list;
	int			i;

	env_list.head = NULL;
	i = 0;
	while (env[i])
	{
		add_tail(&env_list, ft_strdup(env[i]));
		i++;
	}
	//print_list(&env_list);
	return (env_list);
}
