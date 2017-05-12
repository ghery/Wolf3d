/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:45:59 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:49:34 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			*ft_format(int *j, const char *restrict format, int *tab)
{
	if (format[*j] == '0')
	{
		TJ = *j;
		tab = ft_flags(format, tab);
		while (format[*j] == '0')
			*j += 1;
	}
	return (tab);
}

int			*ft_format5(int *j, const char *restrict format, int *tab)
{
	while (format[*j] == '-' || format[*j] == '+' ||\
			format[*j] == ' ' || format[*j] == '#' || format[*j] == '0')
	{
		TJ = *j;
		tab = ft_flags(format, tab);
		*j += 1;
	}
	tab = ft_check_mod(tab, format[*j], format[*j + 1]);
	while ((format[*j] == 'l' || format[*j] == 'h' || format[*j] == 'j' ||\
				format[*j] == 'z') && format[*j] != '\0')
		*j += 1;
	while (format[*j] == '-' || format[*j] == '+' ||\
			format[*j] == ' ' || format[*j] == '#' || format[*j] == '0')
	{
		TJ = *j;
		tab = ft_flags(format, tab);
		*j += 1;
	}
	return (tab);
}

static int	*ft_format62(int *j, int count, int *tab,\
		const char *restrict format)
{
	if (format[*j + 1] == '\0')
	{
		tab[0] = count;
		*j -= 1;
		tab[1] = *j;
		tab[2] = *j;
	}
	else
	{
		tab[0] = count;
		*j -= 1;
		tab[1] = *j;
		tab[2] = *j;
	}
	return (tab);
}

int			*ft_format6(int *j, const char *restrict format, int *tab, int i)
{
	int count;

	count = 0;
	if (format[*j] == 's' || format[*j] == 'S' || format[*j] == 'p' ||\
			format[*j] == 'D' || format[*j] == 'i' || format[*j] == 'o' ||\
			format[*j] == 'O' || format[*j] == 'u' || format[*j] == 'U' ||\
			format[*j] == 'x' || format[*j] == 'X' || format[*j] == 'c' ||\
			format[*j] == 'C' || format[*j] == 'd' || format[*j] == '\0' ||\
			format[*j] == '%' || format[*j] == 'b' || format[*j] == 'B')
	{
		tab[0] = count;
		tab[1] = i;
		tab[2] = *j;
	}
	else
		tab = ft_format62(j, count, tab, format);
	return (tab);
}

int			*ft_format7(int j, const char *restrict format, int *tab,\
		va_list el)
{
	int count;

	count = 0;
	if (format[j] == '\0')
	{
		tab[1] = j - 1;
		tab[0]--;
		return (tab);
	}
	else if (format[j] == '%' && ft_diese_test2(format[j + 1]) == 1 &&\
			ft_diese_test(format[j - 1]) == 1)
		count = ft_diese(tab);
	else if (format[j] == 's' || format[j] == 'S' || format[j] == 'p' ||\
			format[j] == 'D' || format[j] == 'i' || format[j] == 'o' ||\
			format[j] == 'O' || format[j] == 'u' || format[j] == 'U' ||\
			format[j] == 'x' || format[j] == 'X' || format[j] == 'c' ||\
			format[j] == 'C' || format[j] == 'd' ||\
			format[j] == '%' || format[j] == 'b' || format[j] == 'B')
		count = ft_special(format, el, tab);
	tab[1] = j;
	tab[0] = count - 1;
	return (tab);
}
