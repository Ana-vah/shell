/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:21:25 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/03 17:33:25 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	elem = *lst;
	if (!lst || !del)
		return ;
	while (elem != NULL)
	{
		*lst = elem->next;
		(*del)(elem->content);
		free(elem);
		elem = *lst;
	}
}
