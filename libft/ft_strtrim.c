/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:59:14 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/28 22:25:28 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s1_cpy;

	s1_cpy = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		s1_cpy = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!s1_cpy)
			return (0);
		ft_strlcpy(s1_cpy, &s1[start], end - start + 1);
	}
	return (s1_cpy);
}
/*
int	main(void)
{
	char	s1[] = "zzjbjbzzzjkbjzzz";
	char	*set;
	set = "z";
	printf("%s", ft_strtrim(s1, set));
}
*/
