/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:55:43 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:47 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_special(const char *restrict format, va_list el, int *tab)
{
	int j;

	j = tab[2];
	if (format[j] == 's')
		tab[0] = ft_items_global(el, tab, 1);
	else if (format[j] == 'p')
		tab[0] = ft_itemp_global(el, tab, 1);
	if (format[j] == 'd' || format[j] == 'i')
		tab[0] = ft_itemdi_global(el, tab, 1);
	else if (format[j] == 'S')
		tab[0] = ft_items_global(el, tab, 2);
	else if (format[j] == 'D')
		ft_itemdi_global(el, tab, 2);
	else if (format[j] == 'o')
		tab[0] = ft_itemo_global(el, tab, 1);
	else
		tab[0] = ft_special2(format, el, tab, j);
	return (tab[0]);
}

int	ft_special2(const char *restrict format, va_list el, int *tab, int j)
{
	if (format[j] == 'O')
		tab[0] = ft_itemo_global(el, tab, 2);
	else if (format[j] == 'u')
		tab[0] = ft_itemu_global(el, tab, 1);
	else if (format[j] == 'U')
		tab[0] = ft_itemu_global(el, tab, 2);
	else if (format[j] == 'x')
		tab[0] = ft_itemx_global(el, tab, 1);
	else if (format[j] == 'X')
		tab[0] = ft_itemgx_global(el, tab, 1);
	else if (format[j] == 'c')
		tab[0] = ft_itemc_global(el, tab, 1);
	else if (format[j] == 'C')
		tab[0] = ft_itemc_global(el, tab, 2);
	else if (format[j] == 'b')
		tab[0] = ft_itemb_global(el, tab, 1);
	else if (format[j] == 'B')
		tab[0] = ft_itemb_global(el, tab, 2);
	return (tab[0]);
}

int	ft_percent(int i)
{
	write(1, "%", 1);
	i++;
	return (i);
}
