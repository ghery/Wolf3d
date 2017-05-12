/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:50:01 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:50:03 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	while (i <= size)
	{
		mem[i] = 0;
		i++;
	}
	return (void *)(mem);
}
