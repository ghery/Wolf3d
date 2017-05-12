/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:17 by ghery             #+#    #+#             */
/*   Updated: 2016/11/24 13:41:39 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	drawcalc(t_param *p)
{
	p->draw.linehight = (int)(p->hight / p->ray.wall_dist);
	p->draw.start = -p->draw.linehight / 2 + p->hight / 2;
	if (p->draw.start < 0)
		p->draw.start = 0;
	p->draw.end = p->draw.linehight / 2 + p->hight / 2;
	if (p->draw.end >= p->hight)
		p->draw.end = p->hight - 1;
}

static void	color_ew(t_param *p, int x, int y)
{
	if (p->ray.colorew % 2 == 1)
	{
		(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 0;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 255;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 253;
	}
	else
	{
		(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 120;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 0;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 50;
	}
}

static void	color_ns(t_param *p, int x, int y)
{
	if (p->ray.colorns % 2 == 1)
	{
		(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 255;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 0;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 0;
	}
	else
	{
		(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 0;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 0;
		(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 255;
	}
}

void		draw(t_param *p)
{
	int y;
	int	x;

	y = 0;
	x = p->draw.pixel.x;
	drawcalc(p);
	while (y < p->hight)
	{
		if (y < p->draw.start)
			colorsky(p, x, y);
		else if (y >= p->draw.start && y <= p->draw.end && p->ray.side == 1)
			color_ew(p, x, y);
		else if (y >= p->draw.start && y <= p->draw.end)
			color_ns(p, x, y);
		else if (y > p->draw.end)
			color_floor(p, x, y);
		y++;
	}
	p->draw.pixel.x = x + 1;
}
