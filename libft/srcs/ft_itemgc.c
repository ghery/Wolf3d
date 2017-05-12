/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemgc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:35 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 17:53:41 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_itemgc_next(va_list el, int *tab, int count, int n)
{
	ft_wchar(va_arg(el, int));
	if (LARGE > 1)
	{
		while (n < (LARGE - 2))
		{
			ft_putchar(' ');
			n++;
		}
		count = tab[0] + LARGE;
	}
	else
		count = tab[0] + 1;
	return (count);
}

int			ft_itemgc(va_list el, int *tab)
{
	int count;
	int n;

	n = 0;
	count = 0;
	if (LARGE > 1 && FLM != 1)
	{
		while (n < (LARGE - 2))
		{
			ft_putchar(' ');
			n++;
		}
		count = tab[0] + LARGE;
		ft_wchar(va_arg(el, int));
	}
	else
		count = ft_itemgc_next(el, tab, count, n);
	return (count);
}
