/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:54:00 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/30 14:14:06 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof (char) * s_len + 1);
	if (!str)
		return (NULL);
	while (s[i] && i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char func(unsigned int i, char c)
{
	char	str;

	str = c - 32;
	return (str);
}
int	main(void)
{
	char	*s = "let's go strmapi";
	char	*str;

	str = ft_strmapi(s, *func);
	printf("%s", str);
}
*/
