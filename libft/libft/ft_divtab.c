/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:46:58 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:47:03 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	*ft_divtab(const int c)
{
	int i;
	int b;
	int j;
	int *k;

	j = 0;
	i = 1;
	b = c / 2;
	k = (int *)malloc(sizeof(int) * ft_divcount(c));
	while (i <= b)
	{
		if (c % i == 0)
		{
			k[j] = i;
			j++;
		}
		i++;
	}
	if (c != 1)
	{
		k[j] = c;
	}
	return (k);
}
