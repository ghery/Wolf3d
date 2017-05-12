/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:45:36 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:45:41 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	total;
	int minus;

	c = 0;
	total = 0;
	minus = 1;
	while ((str[c] == ' ') || (str[c] == '\n') || (str[c] == '	') ||
			(str[c] == '\t') || (str[c] == '\r') || (str[c] == '\v') ||
			(str[c] == '\f'))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			minus = -1;
		c++;
	}
	while ((str[c] >= '0') && (str[c] <= '9'))
	{
		total = total * 10;
		total = total + (str[c] - 48);
		c++;
	}
	return (total * minus);
}
