/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:54:07 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/03 17:25:28 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*startlst;
	t_list	*newlst;

	newlst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		startlst = ft_lstnew((f)(lst->content));
		if (!startlst)
		{
			ft_lstclear(&startlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, startlst);
		lst = lst->next;
	}
	return (newlst);
}
