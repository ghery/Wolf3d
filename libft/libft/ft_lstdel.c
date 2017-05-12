/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:49:03 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:49:13 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alist != NULL)
	{
		while (*alist != NULL)
		{
			tmp = NULL;
			if ((*alist)->next != NULL)
				tmp = (*alist)->next;
			ft_lstdelone(alist, del);
			*alist = tmp;
		}
		*alist = NULL;
	}
}
