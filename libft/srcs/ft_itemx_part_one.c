/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemx_part_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:55:05 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:10 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*checking_f(char *str, int length)
{
	int x;

	x = ft_strlen(str);
	if (x > length && (str[0] == 'f' || str[0] == 'F'))
	{
		str = ft_strsub(str, (x - length), length);
	}
	return (str);
}

char	*ft_checkgxster(char *str, int flz)
{
	int i;

	i = 0;
	if (str[0] == '0' && flz == 1 && str[1] != '\0')
	{
		while (str[i] != '\0' && str[i] != 'X')
			i++;
		if (str[i] == 'X')
		{
			str[i] = '0';
			str[1] = 'X';
		}
	}
	i = 0;
	return (str);
}

char	*ft_checkxster(char *str, int flz)
{
	int i;

	i = 0;
	if (str[0] == '0' && flz == 1 && str[1] != '\0')
	{
		while (str[i] != '\0' && str[i] != 'x')
			i++;
		if (str[i] == 'x')
		{
			str[i] = '0';
			str[1] = 'x';
		}
	}
	i = 0;
	return (str);
}

int		ft_itemx_ll(va_list el, int *tab)
{
	int						count;
	unsigned long long int	arg;
	int						c;
	char					*str;

	arg = va_arg(el, unsigned long long int);
	c = ft_length_itoa_xull(arg, 16);
	str = ft_itoa_base_xull(arg, 16, c);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemx_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkxster(str, FLZ);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}

int		ft_itemx(va_list el, int *tab)
{
	int						count;
	unsigned int			arg;
	unsigned long long int	arg2;
	int						c;
	char					*str;

	arg = va_arg(el, unsigned int);
	arg2 = (unsigned long long int)arg;
	c = ft_length_itoa_xull(arg2, 16);
	str = ft_itoa_base_xull(arg2, 16, c);
	str = checking_f(str, 8);
	if (PRECIS >= 0)
		str = ft_itemx_precis_xull(tab, str, c);
	str = ft_itemx_flags(tab, str);
	if (LARGE > 0)
		str = ft_itemx_large(tab, str);
	if (PRECIS == 0 && arg == 0 && LARGE < 1)
		count = tab[0];
	else
	{
		str = ft_checkxster(str, FLZ);
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
