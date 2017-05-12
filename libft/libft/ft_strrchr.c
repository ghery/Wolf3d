/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:57:23 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:57:26 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ts;

	ts = (char *)s;
	i = ft_strlen(ts);
	while (i >= 0)
	{
		if (s[i] == c)
			return (ts + i);
		i--;
	}
	return (NULL);
}
