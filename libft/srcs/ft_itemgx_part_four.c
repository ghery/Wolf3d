/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemgx_part_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:51:02 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:51:05 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	**ft_galtstr(char **alt)
{
	alt[0] = (char*)ft_memalloc(sizeof(char) * 3);
	alt[1] = (char*)ft_memalloc(sizeof(char) * 2);
	alt[2] = (char*)ft_memalloc(sizeof(char) * 2);
	if (alt[0] != NULL && alt[1] != NULL && alt[2] != NULL)
	{
		alt[0][0] = '0';
		alt[0][1] = 'X';
		alt[1][0] = '+';
		alt[2][0] = ' ';
	}
	return (alt);
}

char		*ft_itemgx_flags(int *tab, char *str)
{
	char	**altstr;

	altstr = (char**)ft_memalloc(sizeof(char*) * 3);
	altstr = ft_galtstr(altstr);
	if (altstr)
	{
		if (FLD == 1)
			str = ft_strjoin(altstr[0], str);
		free(altstr);
		return (str);
	}
	return (str);
}

int			ft_itemgx_l(va_list el, int *tab)
{
	int				count;
	unsigned long	arg;
	int				c;
	char			*str;

	arg = va_arg(el, unsigned long);
	c = ft_length_itoa_xull(arg, 16);
	str = ft_itoa_base_gxull(arg, 16, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemgx_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkgxster(str, FLZ);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
