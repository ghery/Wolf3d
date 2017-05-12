/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemgx_part_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:51:20 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:51:23 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*make_the_str_gx(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char*)ft_memalloc(sizeof(char) * 17);
	while (i < 10)
	{
		str[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		str[i] = 'A' + j;
		i++;
		j++;
	}
	return (str);
}

char	*fitgx(unsigned long long int value, int base, char *str, int c)
{
	int		end;
	char	*str2;

	str2 = make_the_str_gx(str);
	end = 0;
	c--;
	str[c] = '\0';
	c--;
	while (c >= end)
	{
		str[c] = str2[value % base];
		value = value / base;
		c--;
	}
	free(str2);
	return (str);
}

char	*ft_itoa_base_gxull(unsigned long long int value, int base, int c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * c);
	if (str != NULL)
		str = fitgx(value, base, str, c);
	return (str);
}
