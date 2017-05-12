/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemu_part_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:54:42 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:54:45 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_itemu_hh(va_list el, int *tab)
{
	int						count;
	unsigned char			arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = (unsigned char)va_arg(el, int);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 10);
	str = ft_itoa_base_xull(arg2, 10, c);
	if (PRECIS > 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemu_flags(str);
	if (PRECIS == 0 && arg == 0)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int			ft_itemu_z(va_list el, int *tab)
{
	int						count;
	size_t					arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = va_arg(el, size_t);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 10);
	str = ft_itoa_base_xull(arg2, 10, c);
	if (PRECIS > 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemu_flags(str);
	if (PRECIS == 0 && arg == 0)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int			ft_itemu_j(va_list el, int *tab)
{
	int						count;
	uintmax_t				arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = va_arg(el, uintmax_t);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 10);
	str = ft_itoa_base_xull(arg2, 10, c);
	if (PRECIS > 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemu_flags(str);
	if (PRECIS == 0 && arg == 0)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
