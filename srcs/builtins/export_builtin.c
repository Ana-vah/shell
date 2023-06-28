/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:30:57 by vdescamp          #+#    #+#             */
/*   Updated: 2023/05/18 11:51:02 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	update_env(t_env *env_list, char *name, char *value)
{
	while (env_list)
	{
		if (ft_strncmp(env_list->var, name, ft_strlen(name)) == 0
			&& env_list->var[ft_strlen(name)] == '=')
		{
			free(env_list->var);
			env_list->var = ft_strdup(value);
			return ;
		}
		env_list = env_list->next;
	}
}

void	add_env(t_env_list *env_list, char *arg)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	new_env->var = ft_strdup(arg);
	new_env->next = env_list->head;
	env_list->head = new_env;
}

void	export_builtin(char **args, t_env_list *env_list)
{
	char	*name;
	char	*value;

	if (args[1] == NULL)
	{
		env_builtin(env_list);
		return ;
	}
	name = ft_strtok(args[1], "=");
	value = ft_strtok(NULL, "=");
	if (value == NULL)
	{
		printf("export: usage: export VARNAME=VALUE\n");
		return ;
	}
	update_env(env_list->head, name, value);
	add_env(env_list, args[1]);
}
