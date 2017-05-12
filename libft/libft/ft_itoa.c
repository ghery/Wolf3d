/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:48:22 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:48:32 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*inttop(char *nb)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 12);
	if (tab == NULL)
		return (NULL);
	tab = "-2147483648";
	nb = (char*)malloc(sizeof(char) * 12);
	if (nb == NULL)
		return (NULL);
	nb = ft_strcpy(nb, tab);
	return (nb);
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		j;

	i = 1;
	j = 0;
	nb = NULL;
	if (n == -2147483648)
	{
		return (inttop(nb));
	}
	if (n < 0)
	{
		i++;
		j++;
		n = -n;
	}
	i += ft_powerten(n);
	nb = (char *)malloc(sizeof(char) * i);
	if (nb != NULL)
		return (ft_nb_generator(n, i, j, nb));
	return (NULL);
}
