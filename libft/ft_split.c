/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:52:05 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/03 15:25:48 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || !s[i])
				count++;
		}
	}
	return (count);
}

static char	put_str(char const *s, char *sub_str, int j, int str_len)
{
	int	i;

	i = 0;
	while (str_len > 0)
	{
		sub_str[i] = s[j - str_len];
		i++;
		str_len--;
	}
	sub_str[i] = '\0';
	return (*sub_str);
}

static char	**find_str(char const *s, char c, char **main_str, int str_num)
{
	int	i;
	int	j;
	int	str_len;

	i = 0;
	j = 0;
	str_len = 0;
	while (s[j] && i < str_num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			str_len++;
		}
		main_str[i] = (char *)malloc(sizeof (char) * (str_len + 1));
		if (!main_str[i])
			return (NULL);
		put_str(s, main_str[i], j, str_len);
		str_len = 0;
		i++;
	}
	main_str[i] = 0;
	return (main_str);
}

char	**ft_split(char const *s, char c)
{
	int		str_num;
	char	**main_str;

	if (!s)
		return (0);
	str_num = count_strs(s, c);
	main_str = (char **)malloc(sizeof(char *) * (str_num + 1));
	if (!main_str)
		return (NULL);
	find_str(s, c, main_str, str_num);
	return (main_str);
}
/*
int	main(void)
{
	char				*s;
	char				c;
	char				**tab;
	unsigned int		i;

	s = "aa bbb aaa  bb  a ";
	c = ' ';
	i = 0;
	tab = ft_split(s, c);
	while (tab[i] != 0)
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
	return (0);
}
*/
