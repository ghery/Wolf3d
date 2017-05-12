/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_items.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:52:33 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 14:52:35 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_items_next(int *tab, int *len, char *s)
{
	int		diff;
	char	*t;

	diff = LARGE - *len;
	t = (char *)ft_memalloc(sizeof(char) * diff);
	diff--;
	while (diff >= 0 && t)
	{
		if (FLZ == 1 && FLM != 1)
			t[diff] = '0';
		else
			t[diff] = ' ';
		diff--;
	}
	if (FLM == 1)
		s = ft_strjoin(s, t);
	else
		s = ft_strjoin(t, s);
	*len = LARGE;
	free(t);
	return (s);
}

int			ft_items(va_list el, int *tab)
{
	int		count;
	char	*s;
	int		len;

	count = tab[0];
	s = (char *)va_arg(el, int*);
	if (s == NULL)
		s = case_null();
	len = (ft_strlen(s));
	if (PRECIS > 0)
		if (len > PRECIS)
		{
			s = ft_strsub(s, 0, PRECIS);
			len = PRECIS;
		}
	if (LARGE != 0 && len < LARGE)
		s = ft_items_next(tab, &len, s);
	ft_putstr(s);
	count = count + len;
	return (count);
}

static char	*ft_items_special_next(int *tab, int *len, char *s)
{
	int		diff;
	char	*t;

	diff = LARGE - *len;
	t = (char *)ft_memalloc(sizeof(char) * diff);
	diff--;
	while (diff >= 0 && t)
	{
		if (FLZ == 1 && FLM != 1)
			t[diff] = '0';
		else
			t[diff] = ' ';
		diff--;
	}
	if (FLM == 1)
		s = ft_strjoin(s, t);
	else
		s = ft_strjoin(t, s);
	*len = LARGE;
	free(t);
	return (s);
}

int			ft_items_special(char *s, int *tab)
{
	int		count;
	int		len;

	count = tab[0];
	len = (ft_strlen(s));
	if (PRECIS > 0)
		if (len > PRECIS)
		{
			s = ft_strsub(s, 0, PRECIS);
			len = PRECIS;
		}
	if (LARGE != 0 && len < LARGE)
		s = ft_items_special_next(tab, &len, s);
	ft_putstr(s);
	count = count + len;
	return (count);
}
