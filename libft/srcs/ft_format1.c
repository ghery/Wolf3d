/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:45:40 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:49:32 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			*ft_format2(int *j, const char *restrict format, int *tab)
{
	if (format[*j] == ' ')
	{
		TJ = *j;
		tab = ft_flags(format, tab);
		while (format[*j] == ' ')
			*j += 1;
	}
	if (format[*j] == '0')
	{
		TJ = *j;
		tab = ft_flags(format, tab);
		while (format[*j] == '0')
			*j += 1;
	}
	while (format[*j] == '-' || format[*j] == '+' ||\
			format[*j] == ' ' || format[*j] == '#' || format[*j] == '0')
	{
		TJ = *j;
		tab = ft_flags(format, tab);
		*j += 1;
	}
	return (tab);
}

static int	*ft_format32(int *j, const char *restrict format, int *tab)
{
	int		m;
	char	*tmpl;

	tmpl = (char *)ft_memalloc(sizeof(char) * 30);
	m = 0;
	while (format[*j] >= '0' && format[*j] <= '9')
	{
		tmpl[m] = format[*j];
		m++;
		*j += 1;
	}
	if (tmpl[0] != '\0')
		LARGE = ft_atoi(tmpl);
	free(tmpl);
	return (tab);
}

int			*ft_format3(int *j, const char *restrict format, int *tab,\
		va_list el)
{
	if (format[*j] == ' ')
		while (format[*j] == ' ')
			*j += 1;
	if (format[*j] == '*')
	{
		LARGE = va_arg(el, int);
		*j += 1;
	}
	else
		ft_format32(j, format, tab);
	return (tab);
}

static int	*ft_format42(int *j, const char *restrict format, int *tab)
{
	int		n;
	char	*tmp;

	tmp = (char *)ft_memalloc(sizeof(char) * 30);
	n = 0;
	while (format[*j] >= '0' && format[*j] <= '9')
	{
		tmp[n] = format[*j];
		n++;
		*j += 1;
	}
	PRECIS = ft_atoi(tmp);
	free(tmp);
	return (tab);
}

int			*ft_format4(int *j, const char *restrict format, int *tab,\
		va_list el)
{
	if (format[*j] == '.')
	{
		PRECIS = -1;
		*j += 1;
	}
	if (PRECIS == -1 && format[*j] == '*')
	{
		PRECIS = va_arg(el, int);
		*j += 1;
	}
	else if (PRECIS == -1)
		ft_format42(j, format, tab);
	return (tab);
}
