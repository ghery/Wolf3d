/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:50:50 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:50:55 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*case_null(void)
{
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * 7);
	str = "(null)\0";
	return (str);
}

static int	ft_itemgs_si(int *s, int len, int v)
{
	int	i;
	int	nb;

	i = 0;
	while (i <= len)
	{
		nb = binary_nb(s[i]);
		if (nb <= 7)
			v++;
		else if (nb <= 11)
			v += 2;
		else if (nb <= 16)
			v += 3;
		else
			v += 4;
		i++;
	}
	return (v);
}

static int	ft_itemgs_end(int *tab, int *s, int len, int count)
{
	int n;
	int	i;
	int v;

	n = 0;
	i = 0;
	v = 0;
	while (i <= len)
	{
		v = v + ft_wchar(s[i]);
		i++;
	}
	if (LARGE > 1)
	{
		while (n < (LARGE - (v - 1)))
		{
			ft_putchar(' ');
			n++;
		}
		count = tab[0] + LARGE;
	}
	else
		count = tab[0] + len;
	return (count);
}

static int	ft_itemgs_next(int *tab, int *s, int len, int count)
{
	int n;
	int	i;
	int v;

	n = 0;
	i = 0;
	v = 0;
	if (LARGE > 1 && FLM != 1)
	{
		v = ft_itemgs_si(s, len, v);
		while (n < (LARGE - (v - 1)))
		{
			ft_putchar(' ');
			n++;
		}
		count = tab[0] + LARGE;
		while (i <= len)
		{
			ft_wchar(s[i]);
			i++;
		}
	}
	else
		count = ft_itemgs_end(tab, s, len, count);
	return (count);
}

int			ft_itemgs(va_list el, int *tab)
{
	int		count;
	int		*s;
	int		len;
	int		diff;
	char	*str;

	diff = 0;
	count = tab[0];
	s = va_arg(el, int*);
	if (s == NULL)
	{
		str = case_null();
		count = ft_items_special(str, tab);
	}
	else
	{
		len = 0;
		while (s[len] != (int)NULL)
			len++;
		count = ft_itemgs_next(tab, s, len, count);
	}
	return (count);
}
