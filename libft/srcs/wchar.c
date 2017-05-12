/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:01:43 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:50 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int		pow_two(int i)
{
	int		pow;

	pow = 1;
	while (i > 0)
	{
		pow *= 2;
		i--;
	}
	return (pow);
}

static	char	*binary_print(unsigned int nb)
{
	int		i;
	char	*bin;
	int		j;
	int		c;

	i = 21;
	j = 0;
	bin = (char*)ft_memalloc((sizeof(char)) * 22);
	bin[21] = '\0';
	while (i >= 0)
	{
		c = pow_two(i);
		if ((int)nb >= c)
		{
			bin[j] = '1';
			nb -= c;
		}
		else
			bin[j] = '0';
		j++;
		i--;
	}
	return (bin);
}

int				binary_nb(unsigned int nb)
{
	int		i;
	int		j;
	int		k;
	char	*bin;

	i = 0;
	k = 0;
	j = 0;
	bin = binary_print(nb);
	while (i <= 21)
	{
		if (bin[i] == '1' || k == 1)
		{
			k = 1;
			j++;
		}
		i++;
	}
	return (j);
}

int				ft_wchar(unsigned int v)
{
	int				i;
	unsigned char	octet;

	octet = '\0';
	i = 2;
	if (binary_nb(v) <= 7)
	{
		octet = v;
		write(1, &octet, 1);
		i = 1;
	}
	else if (binary_nb(v) <= 11)
		ft_mask_one(v, octet);
	else if (binary_nb(v) <= 16)
	{
		ft_mask_two(v, octet);
		i = 3;
	}
	else
	{
		ft_mask_three(v, octet);
		i = 4;
	}
	return (i);
}
