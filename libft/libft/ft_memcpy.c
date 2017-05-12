/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:50:26 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:50:30 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	const char		*src2;

	dst2 = dst;
	src2 = src;
	i = 0;
	while (i < n)
	{
		*dst2++ = *src2++;
		i++;
	}
	return (dst);
}
