/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:47:07 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:47:10 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_find_in_tab(int *tab, int c, int length)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab == NULL)
		return ((int)NULL);
	while (i < length)
	{
		if (tab[i] == c)
			j++;
		i++;
	}
	return (j);
}
