/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:31:18 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/03 17:32:10 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		elem = ft_lstlast(*alst);
		elem->next = new;
	}
	else
		*alst = new;
}
