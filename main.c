/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:56:49 by ghery             #+#    #+#             */
/*   Updated: 2017/01/07 17:02:40 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init(t_param *p)
{
	p->width = 1280;
	p->hight = 720;
	p->player.pos.x = 2;
	p->player.pos.y = 3;
	p->player.fov = 60;
	p->map.sizegrid = 64;
	p->player.dir.x = -1;
	p->player.dir.y = 0;
	p->player.plane.x = 0;
	p->player.plane.y = 0.66;
	p->player.movespeed = 0.15;
	p->player.rotspeed = 0.11;
	p->oldx = 0;
}

int			main(void)
{
	t_param	p;
	int		x;

	init(&p);
	x = 0;
	p.map.sizex = 15;
	p.map.sizey = 15;
	p.map.map = (int **)ft_memalloc(sizeof(int *) * p.map.sizex);
	while (x < p.map.sizex)
	{
		p.map.map[x] = (int *)ft_memalloc(sizeof(int) * p.map.sizey);
		x++;
	}
	map(&p.map);
	wolf(p);
	return (0);
}
