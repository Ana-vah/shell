/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:02:41 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/02 13:04:13 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof (t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
