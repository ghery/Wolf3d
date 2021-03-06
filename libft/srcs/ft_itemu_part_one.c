/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemu_part_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:54:33 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:54:37 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_itemu_ll(va_list el, int *tab)
{
	int						count;
	unsigned long long int	arg;
	int						c;
	char					*str;

	arg = va_arg(el, unsigned long long int);
	c = ft_length_itoa_xull(arg, 10);
	str = ft_itoa_base_xull(arg, 10, c);
	if (PRECIS > 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int		ft_itemu_h(va_list el, int *tab)
{
	int						count;
	unsigned short int		arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = (unsigned short int)va_arg(el, unsigned int);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 10);
	str = ft_itoa_base_xull(arg2, 10, c);
	if (PRECIS > 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int		ft_itemu(va_list el, int *tab)
{
	int						count;
	unsigned int			arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = va_arg(el, unsigned int);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 10);
	str = ft_itoa_base_xull(arg2, 10, c);
	if (PRECIS > 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
