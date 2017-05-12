/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemscglobal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:52:39 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:52:42 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_items_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODL == 1)
			tab[0] = ft_itemgs(el, tab);
		else
			tab[0] = ft_items(el, tab);
	}
	else
		tab[0] = ft_itemgs(el, tab);
	return (tab[0]);
}

int	ft_itemc_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODL == 1)
			tab[0] = ft_itemgc(el, tab);
		else
			tab[0] = ft_itemc(el, tab);
	}
	else
		tab[0] = ft_itemgc(el, tab);
	return (tab[0]);
}

int	ft_itemb_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODLL == 1)
			tab[0] = ft_itemb_ll(el, tab);
		else if (MODL == 1)
			tab[0] = ft_itemb_l(el, tab);
		else if (MODHH == 1)
			tab[0] = ft_itemb_hh(el, tab);
		else if (MODH == 1)
			tab[0] = ft_itemb_h(el, tab);
		else if (MODJ == 1)
			tab[0] = ft_itemb_j(el, tab);
		else if (MODZ == 1)
			tab[0] = ft_itemb_z(el, tab);
		else
			tab[0] = ft_itemb(el, tab);
	}
	else
		tab[0] = ft_itemb_l(el, tab);
	return (tab[0]);
}
