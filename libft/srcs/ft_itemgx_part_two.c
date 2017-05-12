/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemgx_part_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:51:26 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:51:29 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_itemgx_hh(va_list el, int *tab)
{
	int						count;
	unsigned char			arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = (unsigned char)va_arg(el, unsigned int);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 16);
	str = ft_itoa_base_gxull(arg2, 16, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemgx_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkgxster(str, FLZ);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int			ft_itemgx_z(va_list el, int *tab)
{
	int						count;
	size_t					arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = va_arg(el, size_t);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 16);
	str = ft_itoa_base_gxull(arg2, 16, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemgx_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkgxster(str, FLZ);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int			ft_itemgx_j(va_list el, int *tab)
{
	int						count;
	uintmax_t				arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = va_arg(el, uintmax_t);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 16);
	str = ft_itoa_base_gxull(arg2, 16, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemgx_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkgxster(str, FLZ);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
