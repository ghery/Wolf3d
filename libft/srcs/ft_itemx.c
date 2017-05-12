/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:54:50 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:54:57 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_find_itoa2(char **str, int *c, int *end)
{
	char	*str2;

	str2 = (char *)ft_memalloc(17);
	str2 = "0123456789abcdef\0";
	c--;
	*str[*c] = '\0';
	c--;
	*end = 0;
	return (str2);
}

static char	*ft_find_itoa(int value, int base, char *str, int c)
{
	unsigned int	safe;
	int				end;
	char			*str2;

	str2 = ft_find_itoa2(&str, &c, &end);
	if (base == 10 && value < 0)
	{
		str[0] = '-';
		end++;
		safe = -value;
	}
	else
	{
		if (value >= 0)
			safe = value;
		else
			safe = -value;
	}
	while (c >= end)
	{
		str[c] = str2[safe % base];
		safe = safe / base;
		c--;
	}
	return (str);
}

static int	ft_length_itoa(int value, int base)
{
	int				k;
	unsigned int	safe;

	k = 1;
	if (value == 0)
		k++;
	if (base == 10 && value < 0)
	{
		k++;
		safe = -value;
	}
	else
	{
		if (value >= 0)
			safe = value;
		else
			safe = -value;
	}
	while (safe % base > 0 || safe / base > 0)
	{
		k++;
		safe = safe / base;
	}
	return (k);
}

static char	*ft_itoa_base(int value, int base, int c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * c);
	str = ft_find_itoa(value, base, str, c);
	return (str);
}

int			ft_itemx(va_list el, int *tab)
{
	int		count;
	int		hex;
	int		c;
	char	*str;

	hex = va_arg(el, int);
	c = ft_length_itoa(hex, 16);
	count = (tab[0] + c) - 1;
	str = ft_itoa_base(hex, 16, c);
	ft_putstr(str);
	return (count);
}
