/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:02:41 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/04 19:39:28 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
/*
int main()
{
    char dst[] = "flip";
    char src[] = "********";

    printf("avant ft_memcpy : %s\n", dst);

    ft_memcpy(dst, src, 4);

	printf("apres ft_memcpy : %s", dst);
    return 0;
}
*/
