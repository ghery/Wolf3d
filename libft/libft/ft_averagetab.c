/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_averagetab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:45:46 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:45:50 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/../includes/libft.h"

int	ft_averagetab(int *tab, int length)
{
	int i;
	int max;

	i = 0;
	max = tab[0];
	if (tab == NULL)
		return ((int)NULL);
	while (i < length)
	{
		max = max + tab[i];
		i++;
	}
	return (max / i);
}
