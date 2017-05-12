/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:57:32 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:57:35 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	**split;
	char	*tmp;

	i = 0;
	k = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * ft_strnbw(s, c));
	if (split == NULL)
		return (NULL);
	while (j < ft_strnbw(s, c) && s[i])
	{
		i = k;
		while (s[i] && k < ft_strlen(s) && s[k] != c)
			k++;
		tmp = ft_struse(s, i, (k - i));
		if (tmp != NULL && k - i > 0)
			split[j++] = tmp;
		i++;
		k++;
	}
	split[j] = 0;
	return (split);
}
