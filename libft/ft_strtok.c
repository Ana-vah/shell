/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:20:24 by vdescamp          #+#    #+#             */
/*   Updated: 2023/03/23 11:38:47 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(char *str, const char *sep, char **lasts)
{
	char	*s;

	if (!str)
		str = *lasts;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str == '\0')
		return (NULL);
	s = str;
	while (*str && !ft_strchr(sep, *str))
		++str;
	if (*str)
		*str++ = '\0';
	*lasts = str;
	return (s);
}

char	*ft_strtok(char *str, const char *sep)
{
	static char		*ptr;

	return (ft_strtok_r(str, sep, &ptr));
}

/*
char	*ft_strtok(char *str, char *sepa)
{
	static char	*stock = NULL;
	char		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (i == 0 && *stock != sepa)
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == sepa)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock++;
	}
	return (ptr);
}
*/
