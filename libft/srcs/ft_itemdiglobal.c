/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemdiglobal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:30 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:50:32 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_itemdi_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODLL == 1)
			tab[0] = ft_itemdi_ll(el, tab);
		else if (MODL == 1)
			tab[0] = ft_itemdi_l(el, tab);
		else if (MODHH == 1)
			tab[0] = ft_itemdi_hh(el, tab);
		else if (MODH == 1)
			tab[0] = ft_itemdi_h(el, tab);
		else if (MODJ == 1)
			tab[0] = ft_itemdi_j(el, tab);
		else if (MODZ == 1)
			tab[0] = ft_itemdi_z(el, tab);
		else
			tab[0] = ft_itemdi(el, tab);
	}
	else
		tab[0] = ft_itemdi_l(el, tab);
	return (tab[0]);
}

int		ft_itemu_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODLL == 1)
			tab[0] = ft_itemu_ll(el, tab);
		else if (MODL == 1)
			tab[0] = ft_itemu_l(el, tab);
		else if (MODHH == 1)
			tab[0] = ft_itemu_hh(el, tab);
		else if (MODH == 1)
			tab[0] = ft_itemu_h(el, tab);
		else if (MODJ == 1)
			tab[0] = ft_itemu_j(el, tab);
		else if (MODZ == 1)
			tab[0] = ft_itemu_z(el, tab);
		else
			tab[0] = ft_itemu(el, tab);
	}
	else
		tab[0] = ft_itemu_l(el, tab);
	return (tab[0]);
}

int		ft_itemo_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODLL == 1)
			tab[0] = ft_itemo_ll(el, tab);
		else if (MODL == 1)
			tab[0] = ft_itemo_l(el, tab);
		else if (MODHH == 1)
			tab[0] = ft_itemo_hh(el, tab);
		else if (MODH == 1)
			tab[0] = ft_itemo_h(el, tab);
		else if (MODJ == 1)
			tab[0] = ft_itemo_j(el, tab);
		else if (MODZ == 1)
			tab[0] = ft_itemo_z(el, tab);
		else
			tab[0] = ft_itemo(el, tab);
	}
	else
		tab[0] = ft_itemo_l(el, tab);
	return (tab[0]);
}

int		ft_itemx_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODLL == 1)
			tab[0] = ft_itemx_ll(el, tab);
		else if (MODL == 1)
			tab[0] = ft_itemx_l(el, tab);
		else if (MODHH == 1)
			tab[0] = ft_itemx_hh(el, tab);
		else if (MODH == 1)
			tab[0] = ft_itemx_h(el, tab);
		else if (MODJ == 1)
			tab[0] = ft_itemx_j(el, tab);
		else if (MODZ == 1)
			tab[0] = ft_itemx_z(el, tab);
		else
			tab[0] = ft_itemx(el, tab);
	}
	else
		tab[0] = ft_itemx_l(el, tab);
	return (tab[0]);
}

int		ft_itemgx_global(va_list el, int *tab, int i)
{
	if (i == 1)
	{
		if (MODLL == 1)
			tab[0] = ft_itemgx_ll(el, tab);
		else if (MODL == 1)
			tab[0] = ft_itemgx_l(el, tab);
		else if (MODHH == 1)
			tab[0] = ft_itemgx_hh(el, tab);
		else if (MODH == 1)
			tab[0] = ft_itemgx_h(el, tab);
		else if (MODJ == 1)
			tab[0] = ft_itemgx_j(el, tab);
		else if (MODZ == 1)
			tab[0] = ft_itemgx_z(el, tab);
		else
			tab[0] = ft_itemgx(el, tab);
	}
	else
		tab[0] = ft_itemgx_l(el, tab);
	return (tab[0]);
}
