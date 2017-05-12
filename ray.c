/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:17:57 by ghery             #+#    #+#             */
/*   Updated: 2016/11/24 14:27:42 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	sidecoox(t_param *p)
{
	if (p->ray.dir.x < 0)
	{
		p->ray.step.x = -1;
		p->ray.side_coo.x = (p->ray.pos.x - p->ray.map.x)\
							* p->ray.delta_coo.x;
		p->ray.colorns = 1;
	}
	else
	{
		p->ray.step.x = 1;
		p->ray.side_coo.x = (p->ray.map.x + 1.0 - p->ray.pos.x)\
							* p->ray.delta_coo.x;
		p->ray.colorns = 0;
	}
}

static void	ray(t_param *p)
{
	while (p->ray.hit == 0)
	{
		if (p->ray.side_coo.x < p->ray.side_coo.y)
		{
			p->ray.side_coo.x = p->ray.side_coo.x + p->ray.delta_coo.x;
			p->ray.map.x = p->ray.map.x + p->ray.step.x;
			p->ray.side = 0;
		}
		else
		{
			p->ray.side_coo.y = p->ray.side_coo.y + p->ray.delta_coo.y;
			p->ray.map.y = p->ray.map.y + p->ray.step.y;
			p->ray.side = 1;
		}
		if (p->map.map[p->ray.map.x][p->ray.map.y] == 1)
			p->ray.hit = 1;
	}
}

static void	proj_dist(t_param *p)
{
	if (p->ray.side == 0)
	{
		p->ray.wall_dist = (p->ray.map.x - p->ray.pos.x +\
				(1 - p->ray.step.x) / 2) / p->ray.dir.x;
	}
	else
	{
		p->ray.wall_dist = (p->ray.map.y - p->ray.pos.y +\
				(1 - p->ray.step.y) / 2) / p->ray.dir.y;
	}
}

static void	rayinit(t_param *p, int i)
{
	p->player.cam = (2 * i) / ((double)(p->width)) - 1;
	p->ray.pos.x = p->player.pos.x;
	p->ray.pos.y = p->player.pos.y;
	p->ray.dir.x = p->player.dir.x + (p->player.plane.x * p->player.cam);
	p->ray.dir.y = p->player.dir.y + (p->player.plane.y * p->player.cam);
	p->ray.map.x = (int)(p->ray.pos.x);
	p->ray.map.y = (int)(p->ray.pos.y);
}

void		ray_cast(t_param *p)
{
	int		i;

	i = 0;
	p->img = mlx_new_image(p->mlx, p->width, p->hight);
	p->draw.pixel.x = 0;
	p->draw.pixel.y = 0;
	while (i < p->width)
	{
		rayinit(p, i);
		p->ray.delta_coo.x = sqrt(1 + (p->ray.dir.y * p->ray.dir.y)\
				/ (p->ray.dir.x * p->ray.dir.x));
		p->ray.delta_coo.y = sqrt(1 + (p->ray.dir.x * p->ray.dir.x)\
				/ (p->ray.dir.y * p->ray.dir.y));
		p->ray.hit = 0;
		sidecoox(p);
		sidecooy(p);
		ray(p);
		proj_dist(p);
		draw(p);
		i++;
	}
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}
