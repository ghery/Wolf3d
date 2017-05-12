/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemdi_part_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:18 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:50:21 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_checkdister2(char *str, int i)
{
	while (str[i] != '\0' && !(str[i] <= '9' && str[i] >= '0'))
		i++;
	if (str[i] != '\0')
	{
		i--;
		if (str[i] != '-')
			str[i] = '+';
		if (str[0] != '+')
			str[0] = ' ';
		if (str[i] == '+' && str[0] == '+' && i != 0)
		{
			str[0] = ' ';
		}
	}
	while (str[i] != '\0' && str[i] != '-')
		i++;
	if (str[i] == '-')
	{
		str[i] = '0';
		str[0] = '-';
	}
	return (str);
}

char		*ft_checkdister(char *str, int flz, int flm)
{
	int i;

	i = 0;
	if (str[0] == '0' && flz != 189)
	{
		while (str[i] != '\0' && str[i] != '-')
			i++;
		if (str[i] == '-')
		{
			str[i] = '0';
			str[0] = '-';
		}
	}
	i = 0;
	if (str[0] == '+' && flm != 189)
		ft_checkdister2(str, i);
	return (str);
}

static char	*strmin(int c, long long int arg)
{
	char *str;

	str = NULL;
	if (arg < -9223372036854775807)
	{
		str = (char *)ft_memalloc(sizeof(char) * 21);
		str = "-9223372036854775808";
	}
	else
	{
		c = ft_length_itoa_sll(arg, 10);
		str = ft_itoa_base_sll(arg, 10, c);
	}
	return (str);
}

int			ft_itemdi_ll(va_list el, int *tab)
{
	int						count;
	long long int			arg;
	int						c;
	char					*str;

	c = 0;
	arg = va_arg(el, long long int);
	str = strmin(c, arg);
	if (arg < 0)
		PRECIS++;
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemdi_flags(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		ft_putstr(ft_checkdister(str, FLZ, FLM));
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int			ft_itemdi(va_list el, int *tab)
{
	int						count;
	int						arg;
	long long int			arg2;
	int						c;
	char					*str;

	arg = va_arg(el, int);
	arg2 = (long long int)arg;
	c = ft_length_itoa_sll(arg2, 10);
	str = ft_itoa_base_sll(arg2, 10, c);
	if (arg2 < 0)
		PRECIS++;
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemdi_flags(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		ft_putstr(ft_checkdister(str, FLZ, FLM));
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
