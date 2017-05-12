/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:52:28 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:52:30 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_putnbr2(unsigned int n)
{
	if (n >= 10)
		ft_putnbr2(n / 10);
	ft_putchar((n % 10) + '0');
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr2(-n);
	}
	else
		ft_putnbr2(n);
}
