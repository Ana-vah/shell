/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:36:53 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/22 17:45:04 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(unsigned char *)s + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "ABCDEFG";
	char	*ps = ft_memchr(str,'F',strlen(str));

	if (ps != NULL)
		printf ("search character found:  %s\n", ps);
	else
		printf ("search character not found\n");
	return (0);
}
*/
