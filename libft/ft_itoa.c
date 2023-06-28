/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:54:16 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/03 16:46:12 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int			count;
	long int	i;

	i = n;
	count = 1;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 9)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*str_size(int str_len)
{
	return (malloc(sizeof(char) * (str_len + 1)));
	return (0);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			str_len;
	long int	nbr;

	nbr = n;
	str_len = count_digit(n);
	str = str_size(str_len);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	i = str_len - 1;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 10 && str[0] != '-')
		str[1] = nbr + '0';
	while (i >= 0 && nbr != 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[str_len] = '\0';
	return (str);
}
/*
int	main(void)
{
	int	n;

	n = -9;

	printf("%s", ft_itoa(n));
	return (0);
}
*/
