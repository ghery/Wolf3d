/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:55:34 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:37 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*ft_flags(const char *restrict format, int *tab)
{
	int j;

	j = TJ;
	if (format[j] == '-')
		FLM = 1;
	if (format[j] == '+')
		FLP = 1;
	if (format[j] == ' ')
		FLS = 1;
	if (format[j] == '#')
		FLD = 1;
	if (format[j] == '0')
		FLZ = 1;
	return (tab);
}

int	*ft_check_mod(int *tab, char mod1, char mod2)
{
	if (mod1 == 'h')
	{
		if (mod2 == 'h')
			MODHH = 1;
		else
			MODH = 1;
	}
	else if (mod1 == 'l')
	{
		if (mod2 == 'l')
			MODLL = 1;
		else
			MODL = 1;
	}
	else if (mod1 == 'j')
		MODJ = 1;
	else if (mod1 == 'z')
		MODZ = 1;
	return (tab);
}

int	*tab_to_zero(int *tab)
{
	FLP = 0;
	FLM = 0;
	FLS = 0;
	FLD = 0;
	FLZ = 0;
	LARGE = 0;
	PRECIS = -2;
	MODL = 0;
	MODLL = 0;
	MODH = 0;
	MODHH = 0;
	MODJ = 0;
	MODZ = 0;
	return (tab);
}

int	*ft_printf2(const char *restrict format, va_list el, int *tab)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	tab[0] = 0;
	i = tab[1];
	j = i + 1;
	tab[2] = j;
	tab = tab_to_zero(tab);
	tab = ft_format(&j, format, tab);
	tab = ft_format2(&j, format, tab);
	tab = ft_format3(&j, format, tab, el);
	tab = ft_format4(&j, format, tab, el);
	tab = ft_format5(&j, format, tab);
	tab = ft_format6(&j, format, tab, i);
	tab = ft_format7(j, format, tab, el);
	return (tab);
}
