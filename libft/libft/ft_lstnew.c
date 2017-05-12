/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:49:45 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:49:50 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = NULL;
	new = (t_list*)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		if (content != NULL)
		{
			new->content = ft_memalloc(content_size);
			if (new->content != NULL)
				ft_memcpy(new->content, content, content_size);
		}
		if (content != NULL)
			new->content_size = content_size;
	}
	return (new);
}
