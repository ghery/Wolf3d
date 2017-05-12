/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:49:57 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:49:59 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_itemc_next(int *tab, char c)
{
	char	*s;

	s = (char *)ft_memalloc(sizeof(char) * (LARGE + 1));
	LARGE--;
	LU = LARGE;
	while (LARGE >= 0)
	{
		if (FLZ == 1 && FLM != 1)
			s[LARGE] = '0';
		else
			s[LARGE] = ' ';
		LARGE--;
	}
	if (FLM == 1)
		s[0] = c;
	else
	{
		s[LU] = c;
		if (s[LU + 1])
			s[LU + 1] = '\0';
	}
	ft_putstr(s);
}

int			ft_itemc(va_list el, int *tab)
{
	int		count;
	char	c;

	count = tab[0];
	count = count + 1;
	if (LARGE > 1)
		count = (count + LARGE - 1);
	c = (char)va_arg(el, int);
	if (LARGE > 1)
		ft_itemc_next(tab, c);
	else
		ft_putchar(c);
	return (count);
}
