/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:47:44 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/03 17:38:41 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*elem;

	if (!lst || !f)
		return ;
	elem = lst;
	while (elem != NULL)
	{
		(*f)(elem->content);
		elem = elem->next;
	}
}
