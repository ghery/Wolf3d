/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemdi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:02 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:50:07 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long int	ft_find_itoa_sll2(long long int value)
{
	long long int	safe;

	safe = 0;
	if (value >= 0)
		safe = value;
	else
		safe = -value;
	return (safe);
}

static char				*ft_find_itoa_sll(long long int value, int base,\
		char *str, int c)
{
	long long int	safe;
	int				end;
	char			*str2;

	str2 = (char *)ft_memalloc(17);
	str2 = "0123456789abcdef\0";
	end = 0;
	c--;
	str[c] = '\0';
	c--;
	if (base == 10 && value < 0)
	{
		str[0] = '-';
		safe = -value;
		end++;
	}
	else
		safe = ft_find_itoa_sll2(value);
	while (c >= end)
	{
		str[c] = str2[safe % base];
		safe = safe / base;
		c--;
	}
	return (str);
}

char					*ft_itoa_base_sll(long long int value, int base, int c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * c);
	str = ft_find_itoa_sll(value, base, str, c);
	return (str);
}

static char				*ft_itemdi_old_next(int diff)
{
	char	*t;

	t = (char*)malloc(sizeof(char) * diff);
	diff--;
	while (diff >= 0)
	{
		t[diff] = ' ';
		diff--;
	}
	return (t);
}

int						ft_itemdi_old(va_list el, int *tab)
{
	int		count;
	int		di;
	int		diff;
	int		c;
	char	*str;

	count = tab[0];
	di = va_arg(el, int);
	c = ft_length_itoa_sll(di, 10);
	str = ft_itoa_base_sll(di, 10, c);
	c = ft_strlen(str);
	if (LARGE > c)
	{
		diff = LARGE - c;
		str = ft_strjoin(ft_itemdi_old_next(diff), str);
		c = LARGE;
	}
	ft_putstr(str);
	count = count + c;
	return (count);
}
