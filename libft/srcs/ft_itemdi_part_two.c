/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemdi_part_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:24 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:50:27 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_itemdi_hh(va_list el, int *tab)
{
	int						count;
	char					arg;
	long long int			arg2;
	int						c;
	char					*str;

	arg = (char)va_arg(el, int);
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

int			ft_itemdi_z(va_list el, int *tab)
{
	int						count;
	ssize_t					arg;
	long long int			arg2;
	int						c;
	char					*str;

	arg = va_arg(el, ssize_t);
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

int			ft_itemdi_j(va_list el, int *tab)
{
	int						count;
	intmax_t				arg;
	long long int			arg2;
	int						c;
	char					*str;

	arg = va_arg(el, intmax_t);
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

int			ft_itemdi_h(va_list el, int *tab)
{
	int						count;
	short int				arg;
	long long int			arg2;
	int						c;
	char					*str;

	arg = (short int)va_arg(el, int);
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

int			ft_length_itoa_sll(long long int value, int base)
{
	int				k;
	long long int	safe;

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
