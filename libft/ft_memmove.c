/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:04:00 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/25 23:48:56 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = dst;
	if (src == NULL && dst == NULL)
		return (0);
	if (dst < src)
	{
		while (i != len)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src++;
			i++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	return (d);
}
/*
int	main(void)
{
	char	dst[] = "flip";
	char	src[] = "********";

	printf("avant ft_memmove : %s\n", dst);
	ft_memmove(dst, src, 4);
	printf("apres ft_memmove : %s", dst);
	return (0);
}
*/
