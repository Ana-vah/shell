/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:33:13 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/22 17:48:33 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)b;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	b = (void *)s;
	return (b);
}
/*
int	main(void)
{
	char	b[100] = "If it works i'll be very happy and go to sleep.";

	printf("\n Before : %s", b);
	ft_memset(b + 10, '@', 5 * sizeof(char));
	printf("\n After : %s", b);
}
*/
