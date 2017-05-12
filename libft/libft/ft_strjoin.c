/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:55:04 by ghery             #+#    #+#             */
/*   Updated: 2016/06/08 12:54:16 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	j = 0;
	join = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		join = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) +
			ft_strlen(s2) + 1));
		if (join != NULL)
		{
			while (s1[++i])
				join[i] = s1[i];
			while (s2[j])
			{
				join[i + j] = s2[j];
				j++;
			}
		}
	}
	return (join);
}
