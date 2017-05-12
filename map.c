/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:10:29 by ghery             #+#    #+#             */
/*   Updated: 2017/01/07 17:00:23 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		map3(t_map *map)
{
	map->map[11][7] = 1;
	map->map[11][8] = 1;
	map->map[11][9] = 1;
	map->map[11][10] = 1;
	map->map[11][11] = 1;
	map->map[11][12] = 1;
	map->map[11][13] = 1;
	map->map[12][3] = 1;
	map->map[13][2] = 1;
	map->map[13][3] = 1;
	map->map[13][4] = 1;
	map->map[14][5] = 1;
	map->map[14][6] = 1;
	map->map[14][7] = 1;
	map->map[14][8] = 1;
	map->map[14][9] = 1;
	map->map[14][11] = 1;
}

static void		map2(t_map *map)
{
	map->map[5][11] = 1;
	map->map[5][12] = 1;
	map->map[5][13] = 1;
	map->map[6][3] = 1;
	map->map[6][11] = 1;
	map->map[7][0] = 1;
	map->map[7][1] = 1;
	map->map[7][3] = 1;
	map->map[8][3] = 1;
	map->map[8][4] = 1;
	map->map[8][5] = 1;
	map->map[8][6] = 1;
	map->map[8][7] = 1;
	map->map[8][8] = 1;
	map->map[8][9] = 1;
	map->map[8][10] = 1;
	map->map[8][12] = 1;
	map->map[8][13] = 1;
	map->map[9][3] = 1;
	map->map[10][3] = 1;
	map->map[11][6] = 1;
	map3(map);
}

static void		map1(t_map *map)
{
	map->map[2][7] = 1;
	map->map[3][1] = 1;
	map->map[3][3] = 1;
	map->map[3][4] = 1;
	map->map[3][5] = 1;
	map->map[3][6] = 1;
	map->map[3][7] = 1;
	map->map[3][8] = 1;
	map->map[3][9] = 1;
	map->map[3][10] = 1;
	map->map[3][11] = 1;
	map->map[3][13] = 1;
	map->map[5][1] = 1;
	map->map[5][2] = 1;
	map->map[5][3] = 1;
	map->map[5][4] = 1;
	map->map[5][7] = 1;
	map->map[5][8] = 1;
	map->map[5][9] = 1;
	map->map[5][10] = 1;
	map2(map);
}

void			map(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < map->sizex)
	{
		while (y < map->sizey)
		{
			if (x == 0 || x == map->sizex - 1 || y == 0 || y == map->sizey - 1)
				map->map[x][y] = 1;
			else
				map->map[x][y] = 0;
			y++;
		}
		y = 0;
		x++;
	}
	map1(map);
}
