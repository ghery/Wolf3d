/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itemp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:07:02 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:52:29 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_itemp_large3(int *tab, char *str, int n)
{
	int j;

	n = 0;
	j = LARGE - 2 - PRECIS;
	if (FLD == 1)
		j = j - 2;
	while (n < j)
	{
		str[n] = ' ';
		n++;
	}
	return (str);
}

static char		*ft_itemp_large2(int *tab, char *str, char *str3, char var)
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
		str = ft_itemp_large3(tab, str, n);
	return (str);
}

static char		*ft_itemp_large(int *tab, char *str)
{
	char	*str3;
	int		n;
	char	var;

	var = ' ';
	str3 = NULL;
	if ((LARGE - 2) > (int)ft_strlen(str))
	{
		n = (LARGE - 2) - (int)ft_strlen(str);
		if (FLP == 1 || FLS == 1)
			n--;
		TEMP = n;
		if (n > 0)
			str = ft_itemp_large2(tab, str, str3, var);
	}
	return (str);
}

static char		*mayday(char *str, va_list el, int i, unsigned long long arg)
{
	int		c;
	void	*primo;

	primo = va_arg(el, void *);
	if (primo == NULL)
	{
		str = (char *)ft_memalloc(sizeof(char) * 4);
		str = "0\0";
	}
	else
	{
		arg = (unsigned long long int)primo;
		i = 0;
		c = ft_length_itoa_xull(arg, 16);
		str = ft_itoa_base_xull(arg, 16, c);
	}
	return (str);
}

int				ft_itemp_global(va_list el, int *tab, int i)
{
	int						count;
	unsigned long long int	arg;
	char					*str;

	str = NULL;
	arg = 0;
	str = mayday(str, el, i, arg);
	if (LARGE - 2 > 0)
		str = ft_itemp_large(tab, str);
	str = ft_strjoin("0x", str);
	if (PRECIS == 0 && arg == 0)
	{
		ft_putstr("0x");
		count = tab[0] + 2;
	}
	else
	{
		ft_putstr(str);
		count = (tab[0] + ft_strlen(str));
	}
	return (count);
}
