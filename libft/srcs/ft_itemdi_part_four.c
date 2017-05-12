/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemdi_part_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:12 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:50:14 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	**ft_altstrdi(char **alt)
{
	alt[0] = (char*)ft_memalloc(sizeof(char) * 2);
	alt[1] = (char*)ft_memalloc(sizeof(char) * 2);
	alt[2] = (char*)ft_memalloc(sizeof(char) * 2);
	if (alt[0] != NULL && alt[1] != NULL && alt[2] != NULL)
	{
		alt[0][0] = '0';
		alt[1][0] = '+';
		alt[2][0] = ' ';
	}
	return (alt);
}

char		*ft_itemdi_flags(int *tab, char *str)
{
	char	**altstr;

	altstr = (char**)ft_memalloc(sizeof(char*) * 3);
	altstr = ft_altstrdi(altstr);
	if (altstr)
	{
		if (FLD == 1)
			str = ft_strjoin(altstr[0], str);
		if (FLP == 1 && str[0] != '-')
			str = ft_strjoin(altstr[1], str);
		else if (FLS == 1 && str[0] != '-')
			str = ft_strjoin(altstr[2], str);
		free(altstr);
		return (str);
	}
	return (str);
}

int			ft_itemdi_l(va_list el, int *tab)
{
	int				count;
	long int		arg;
	int				c;
	char			*str;

	arg = va_arg(el, long int);
	arg = (long long int)arg;
	c = ft_length_itoa_sll(arg, 10);
	str = ft_itoa_base_sll(arg, 10, c);
	if (arg < 0)
		PRECIS++;
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	str = ft_itemdi_flags(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkdister(str, FLZ, FLM);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
