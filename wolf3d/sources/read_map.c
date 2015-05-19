/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:42:03 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 14:42:04 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			load_map(char *path, int worldmap[MAP_WIDTH][MAP_HEIGHT])
{
	char	buf[MAP_WIDTH * MAP_HEIGHT * 2];
	int		i[4];

	i[1] = 0;
	i[2] = 0;
	if ((i[3] = open(path, O_RDONLY)) == -1)
		ft_error("Map not found\n");
	if (read(i[3], buf, MAP_WIDTH * MAP_HEIGHT * 2) !=
		(MAP_WIDTH * MAP_HEIGHT * 2))
		ft_error("Fail to read the map");
	while (i[1] < MAP_HEIGHT)
	{
		i[0] = 0;
		while (i[0] < MAP_WIDTH)
		{
			if (ft_isdigit(buf[i[2]]) == 0)
				ft_error("Map not well formated");
			worldmap[i[0]][i[1]] = buf[i[2]] - '0';
			i[0]++;
			i[2] += 2;
		}
		i[1]++;
	}
	close(i[3]);
	return (0);
}
