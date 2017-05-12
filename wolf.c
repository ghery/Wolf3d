/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:45:03 by ghery             #+#    #+#             */
/*   Updated: 2016/11/23 16:59:48 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	cross(int key, t_param *p)
{
	exit(0);
	p->width = 0;
	key = 2;
	return (0);
}

void		wolf(t_param p)
{
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.width, p.hight, "Wolf3D");
	ray_cast(&p);
	mlx_hook(p.win, 2, 1, key_bend, &p);
	mlx_hook(p.win, 6, 1, mouse_bend, &p);
	mlx_hook(p.win, 17, 1, cross, &p);
	mlx_loop(p.mlx);
}
