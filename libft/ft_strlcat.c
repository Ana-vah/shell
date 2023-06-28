/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:17:39 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/26 01:20:09 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	if (dstsize > dstlen + 1)
	{
		while (src[i] != '\0' && dstlen + 1 + i < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int	main(void)
{
	char	str1[] = "123456";
	char	str2[] = "789";

	printf("%zu", ft_strlcat(str1, str2, 3));
}
*/
