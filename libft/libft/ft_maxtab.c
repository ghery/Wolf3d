/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:49:53 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:49:56 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_maxtab(int *tab, int length)
{
	int i;
	int max;

	i = 0;
	max = tab[0];
	if (tab == NULL)
		return ((int)NULL);
	while (i < length)
	{
		i++;
		if (tab[i] > tab[i - 1])
			max = tab[i];
	}
	return (max);
}
