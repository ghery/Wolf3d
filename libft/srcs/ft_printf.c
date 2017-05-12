/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:55:27 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:30 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	int		i;
	int		count;
	int		*tab;
	va_list	el;

	i = -1;
	tab = (int *)ft_memalloc(sizeof(int) * 17);
	count = 0;
	va_start(el, format);
	while (format[++i] && (++count) != -3)
		if (format[i] == '%' && format[i + 1] == '%')
			i = ft_percent(i);
		else if (format[i] == '%')
		{
			tab[1] = i;
			tab = ft_printf2(format, el, tab);
			if (tab == NULL)
				return (-1);
			i = tab[1];
			count = count + tab[0];
		}
		else
			ft_putchar(format[i]);
	va_end(el);
	return (count);
}
