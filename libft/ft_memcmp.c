/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:37:30 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/01 22:38:01 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
void	test(const char *str1, const char *str2, size_t t)
{
	int	rc;

	rc = ft_memcmp(str1, str2, t);
	for(size_t n = 0; n < t; ++n) putchar(str1[n]);
	if (rc == 0)
		printf(" equal ");
	else if (rc < 0)
		printf(" precedes ");
	else if (rc > 0)
		printf(" follows ");
	for (size_t n = 0; n < t; ++n) putchar(str2[n]);
	printf("\n");
}

int main(void)
{
	char a1[] = "abc";
	char a2[] = "abd";

	test(a1, a2, sizeof a1);
	test(a2, a1, sizeof a1);
	test(a1, a1, sizeof a1);
}
*/
