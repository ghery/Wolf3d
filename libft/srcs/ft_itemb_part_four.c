/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemb_part_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:49:38 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:49:41 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_itemb_l(va_list el, int *tab)
{
	int				count;
	unsigned long	arg;
	int				c;
	char			*str;

	arg = va_arg(el, unsigned long);
	c = ft_length_itoa_xull(arg, 2);
	str = ft_itoa_base_xull(arg, 2, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemo_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1 && FLD != 1)
		count = tab[0];
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
