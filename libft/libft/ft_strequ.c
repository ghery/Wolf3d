/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:54:32 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:54:35 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return ((int)(NULL));
	while (s1[i] && s2[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			if ((s1[i] != s2[i]) && (s1[i] != (s2[i] + 32)))
				return (0);
		}
		else if (s1[i] >= 'a' && s1[i] <= 'z')
		{
			if ((s1[i] != s2[i]) && (s1[i] != (s2[i] - 32)))
				return (0);
		}
		else if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((size_t)i == ft_strlen(s1) && (size_t)i == ft_strlen(s2))
		return (1);
	return (0);
}
