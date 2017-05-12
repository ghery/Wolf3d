/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:35:23 by ghery             #+#    #+#             */
/*   Updated: 2016/11/24 13:40:32 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sidecooy(t_param *p)
{
	if (p->ray.dir.y < 0)
	{
		p->ray.step.y = -1;
		p->ray.side_coo.y = (p->ray.pos.y - p->ray.map.y)\
							* p->ray.delta_coo.y;
		p->ray.colorew = 0;
	}
	else
	{
		p->ray.step.y = 1;
		p->ray.side_coo.y = (p->ray.map.y + 1.0 - p->ray.pos.y)\
							* p->ray.delta_coo.y;
		p->ray.colorew = 1;
	}
}

void	colorsky(t_param *p, int x, int y)
{
	(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 255;
	(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 123;
	(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 0;
}

void	color_floor(t_param *p, int x, int y)
{
	(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 140;
	(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 140;
	(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 140;
}
