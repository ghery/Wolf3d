/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:31:18 by ghery             #+#    #+#             */
/*   Updated: 2016/11/23 14:25:48 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	mouse_next(t_param *p, double olddir, double oldplane)
{
	olddir = p->player.dir.x;
	p->player.dir.x = p->player.dir.x * cos(p->player.rotspeed)\
						- p->player.dir.y * sin(p->player.rotspeed);
	p->player.dir.y = olddir * sin(p->player.rotspeed)\
						+ p->player.dir.y * cos(p->player.rotspeed);
	oldplane = p->player.plane.x;
	p->player.plane.x = p->player.plane.x * cos(p->player.rotspeed)\
						- p->player.plane.y * sin(p->player.rotspeed);
	p->player.plane.y = oldplane * sin(p->player.rotspeed)\
						+ p->player.plane.y * cos(p->player.rotspeed);
}

int			mouse_bend(int x, int y, t_param *p)
{
	double	olddir;
	double	oldplane;

	olddir = 0.0;
	oldplane = 0.0;
	if (x > p->oldx)
	{
		olddir = p->player.dir.x;
		p->player.dir.x = p->player.dir.x * cos(-p->player.rotspeed) -\
							p->player.dir.y * sin(-p->player.rotspeed);
		p->player.dir.y = olddir * sin(p->player.rotspeed * -1) +\
							p->player.dir.y * cos(-p->player.rotspeed);
		oldplane = p->player.plane.x;
		p->player.plane.x = p->player.plane.x * cos(-p->player.rotspeed) -\
							p->player.plane.y * sin(-p->player.rotspeed);
		p->player.plane.y = oldplane * sin(-p->player.rotspeed) +\
							p->player.plane.y * cos(-p->player.rotspeed);
	}
	else if (x < p->oldx)
		mouse_next(p, olddir, oldplane);
	p->oldx = x;
	y = 0;
	ray_cast(p);
	return (0);
}

static void	key_back(t_param *p)
{
	if (p->map.map[(int)(p->player.pos.x - p->player.dir.x\
					* p->player.movespeed)][(int)(p->player.pos.y)] != 1)
		p->player.pos.x = p->player.pos.x -\
					(p->player.dir.x * p->player.movespeed);
	if (p->map.map[(int)(p->player.pos.x)][(int)(p->player.pos.y -\
					p->player.dir.y * p->player.movespeed)] != 1)
		p->player.pos.y = p->player.pos.y -\
					(p->player.dir.y * p->player.movespeed);
}

int			key_bend(int keycode, t_param *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	else if (keycode == 13)
	{
		if (p->map.map[(int)(p->player.pos.x + p->player.dir.x\
					* p->player.movespeed)][(int)(p->player.pos.y)] != 1)
			p->player.pos.x = p->player.pos.x +\
					(p->player.dir.x * p->player.movespeed);
		if (p->map.map[(int)(p->player.pos.x)][(int)(p->player.pos.y +\
					p->player.dir.y * p->player.movespeed)] != 1)
			p->player.pos.y = p->player.pos.y +\
					(p->player.dir.y * p->player.movespeed);
	}
	else if (keycode == 1)
		key_back(p);
	ray_cast(p);
	return (0);
}
