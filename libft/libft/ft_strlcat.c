/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:55:19 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:55:24 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (size > len)
	{
		while (i < (size - len - 1))
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
		return (ft_strlen(src) + len);
	}
	return (ft_strlen(src) + size);
}
