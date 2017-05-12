/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemx_part_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:55:13 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:16 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*make_the_str_x(char *str)
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
		str[i] = 'a' + j;
		i++;
		j++;
	}
	return (str);
}

char	*fitxl(unsigned long long int value, int base, char *str, int c)
{
	int		end;
	char	*str2;

	str2 = make_the_str_x(str);
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

int		ft_length_itoa_xull(unsigned long long int value, int base)
{
	int k;

	k = 1;
	if (value == 0)
		k++;
	while (value % base > 0 || value / base > 0)
	{
		k++;
		value = value / base;
	}
	return (k);
}

char	*ft_itoa_base_xull(unsigned long long int value, int base, int c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * c);
	if (str != NULL)
		str = fitxl(value, base, str, c);
	return (str);
}

char	*ft_itemx_precis_xull(int *tab, char *str, int c)
{
	char	*str2;
	int		l;
	char	var;

	var = '0';
	l = 0;
	c = 0;
	if (ft_strlen(str) < (size_t)PRECIS)
	{
		l = PRECIS - ft_strlen(str);
		str2 = (char *)ft_memalloc(sizeof(char) * l);
		while (--l >= 0)
			str2[l] = var;
		str = ft_strjoin(str2, str);
		free(str2);
	}
	else if (PRECIS == 0 && ft_strlen(str) <= 1)
	{
		str2 = (char*)ft_memalloc(sizeof(char) * 1);
		str2 = "\0";
		str = NULL;
		free(str);
		return (str2);
	}
	return (str);
}
