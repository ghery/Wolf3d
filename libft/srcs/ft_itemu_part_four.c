/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemu_part_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:54:28 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:54:30 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_itemu_flags(char *str)
{
	return (str);
}

int			ft_itemu_l(va_list el, int *tab)
{
	int				count;
	unsigned long	arg;
	int				c;
	char			*str;

	arg = va_arg(el, unsigned long);
	arg = (unsigned long long)arg;
	c = ft_length_itoa_xull(arg, 10);
	str = ft_itoa_base_xull(arg, 10, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemu_flags(str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
