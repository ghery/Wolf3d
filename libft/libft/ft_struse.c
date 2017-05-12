/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:58:17 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:58:21 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_struse(char const *s, unsigned int start, size_t len)
{
	char	*use;
	size_t	i;

	use = NULL;
	if (s != NULL)
	{
		use = (char *)malloc(sizeof(char) * (len + 1));
		i = 0;
		if (use != NULL)
		{
			while (i < len && s[start + i])
			{
				use[i] = s[start + i];
				i++;
			}
			use[i] = '\0';
		}
	}
	return (use);
}
