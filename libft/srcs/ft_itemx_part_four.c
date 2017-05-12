/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemx_part_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:55:00 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:55:03 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_itemx_large3(int *tab, char *str, int n)
{
	int j;

	n = 0;
	j = LARGE - PRECIS;
	if (FLD == 1)
		j = j - 2;
	while (n < j)
	{
		str[n] = ' ';
		n++;
	}
	return (str);
}

char		*ft_itemx_large2(int *tab, char *str, char *str3, char var)
{
	int n;

	n = TEMP;
	str3 = (char *)ft_memalloc(sizeof(char) * n);
	n--;
	if (FLZ == 1 && FLM == 0)
		var = '0';
	while (n >= 0)
	{
		str3[n] = var;
		n--;
	}
	if (FLM == 1)
		str = ft_strjoin(str, str3);
	else
		str = ft_strjoin(str3, str);
	free(str3);
	if (FLZ == 1 && FLM == 0 && PRECIS > 0)
		str = ft_itemx_large3(tab, str, n);
	return (str);
}

char		*ft_itemx_large(int *tab, char *str)
{
	char	*str3;
	int		n;
	char	var;

	var = ' ';
	str3 = NULL;
	if (LARGE > (int)ft_strlen(str))
	{
		n = LARGE - (int)ft_strlen(str);
		if (FLP == 1 || FLS == 1)
			n--;
		TEMP = n;
		if (n > 0)
			str = ft_itemx_large2(tab, str, str3, var);
	}
	return (str);
}

static char	**ft_altstr(char **alt)
{
	alt[0] = (char*)ft_memalloc(sizeof(char) * 3);
	alt[1] = (char*)ft_memalloc(sizeof(char) * 2);
	alt[2] = (char*)ft_memalloc(sizeof(char) * 2);
	if (alt[0] != NULL && alt[1] != NULL && alt[2] != NULL)
	{
		alt[0][0] = '0';
		alt[0][1] = 'x';
		alt[1][0] = '+';
		alt[2][0] = ' ';
	}
	return (alt);
}

char		*ft_itemx_flags(int *tab, char *str)
{
	char	**altstr;

	altstr = (char**)ft_memalloc(sizeof(char*) * 3);
	altstr = ft_altstr(altstr);
	if (altstr)
	{
		if (FLD == 1 && ft_strcmp(str, "0") != 0)
			str = ft_strjoin(altstr[0], str);
		return (str);
	}
	return (str);
}
