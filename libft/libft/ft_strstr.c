/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:57:39 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:57:42 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while ((s2[j]) && (s2[j] == s1[i]))
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char*)s1 + (i - j));
			i = i - (j - 1);
		}
		i++;
	}
	return (NULL);
}
