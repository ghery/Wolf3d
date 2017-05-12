/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diese.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:57:50 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:49:30 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_diese(int *tab)
{
	int li;

	li = 0;
	if (LARGE > 1)
	{
		if (FLM == 1)
			ft_putchar('%');
		while (li < (LARGE - 1))
		{
			if (FLZ == 1 && FLM != 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			li++;
		}
		if (FLM != 1)
			ft_putchar('%');
		return (tab[0] + LARGE);
	}
	ft_putchar('%');
	return (tab[0] + 1);
}

int	ft_diese_test(char format)
{
	if (format == 's' || format == 'S' || format == 'p' ||\
			format == 'D' || format == 'i' || format == 'o' ||\
			format == 'O' || format == 'u' || format == 'U' ||\
			format == 'x' || format == 'X' || format == 'c' ||\
			format == 'C' || format == 'd' || format == 'b' ||\
			format == 'B' || format == '%')
		return (0);
	else if (format == '-' || format == '+' || format == ' ' ||\
			format == '#' || format == '0')
		return (1);
	else if (format == '\n' || format == '\0')
		return (0);
	else if (format >= '0' && format <= '9')
		return (1);
	else if (format == '.' && format == '*')
		return (1);
	else
		return (0);
}

int	ft_diese_test2(char format)
{
	if (format == 's' || format == 'S' || format == 'p' ||\
			format == 'D' || format == 'i' || format == 'o' ||\
			format == 'O' || format == 'u' || format == 'U' ||\
			format == 'x' || format == 'X' || format == 'c' ||\
			format == 'C' || format == 'd' || format == 'b' ||\
			format == 'B' || format == '%')
		return (0);
	else if (format == '-' || format == '+' || format == ' ' ||\
			format == '#' || format == '0')
		return (0);
	else if (format == '\n' || format == '\0')
		return (1);
	else if (format >= '0' && format <= '9')
		return (0);
	else if (format == '.' && format == '*')
		return (0);
	else
		return (1);
}
