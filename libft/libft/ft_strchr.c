/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:53:22 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:53:24 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ts;

	i = 0;
	ts = (char *)s;
	while (ts[i])
	{
		if (ts[i] == (char)c)
			return (ts + i);
		i++;
	}
	if (ts[i] == (char)c)
		return (ts + i);
	return (NULL);
}
