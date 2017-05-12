/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:50:39 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:50:43 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	temp = (void *)malloc(sizeof(src[0]) * len);
	if (temp == NULL)
		return (NULL);
	temp = ft_memcpy(temp, src, len);
	dst = ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
