/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:37:28 by cducaffy          #+#    #+#             */
/*   Updated: 2015/04/28 20:21:15 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

t_pos	ft_set_pos(int x, int y)
{
	t_pos	p;

	p.x = x;
	p.y = y;
	return (p);
}

int		choose_color(int i)
{
	if (i < -20)
		return (BLUE);
	else if (i < 0 && i >= -20)
		return (BLUESUP);
	else if (i < 5 && i >= 0)
		return (GREEN);
	else if (i < 10 && i >= 5)
		return (GREENSUP);
	else if (i < 15 && i >= 10)
		return (BROWN);
	else if (i < 25 && i >= 15)
		return (BROWNSUP);
	else
		return (WHITE);
}

void	draw_hor(t_env *e, t_pos pos, int i, int j)
{
	t_pos	pos2;

	if ((e->map)[i + 1] != NULL && (e->map)[i + 1][j] != NULL)
	{
		pos2 = ft_set_pos(300 - (i - j + 1) * e->zoom, 120 - (i + j + 1)
			* -13 - ft_atoi((e->map)[i + 1][j]));
		pos.color = choose_color(ft_atoi((e->map)[i][j]));
		mlx_line_put(e, &pos, &pos2);
		if (ft_atoi((e->map)[i][j]) != 0 || ft_atoi((e->map)[i + 1][j]) != 0)
		{
			pos.color = choose_color(ft_atoi((e->map)[i][j]));
			mlx_line_put(e, &pos, &pos2);
		}
	}
}

void	draw_vert(t_env *e, t_pos pos, int i, int j)
{
	t_pos	pos2;

	if ((e->map)[i][j + 1] != NULL)
	{
		pos2 = ft_set_pos(pos.x + e->zoom, 120 - (i + j + 1)
			* -13 - ft_atoi((e->map)[i][j + 1]));
		pos.color = choose_color(ft_atoi((e->map)[i][j]));
		mlx_line_put(e, &pos, &pos2);
		if (ft_atoi((e->map)[i][j]) != 0 || ft_atoi((e->map)[i][j + 1]) != 0)
		{
			mlx_line_put(e, &pos, &pos2);
			pos.color = choose_color(ft_atoi((e->map)[i][j]));
		}
	}
}

void	ft_draw(t_env *e)
{
	t_pos	pos;
	int		i;
	int		j;

	i = 0;
	while ((e->map)[i] != NULL)
	{
		j = 0;
		while ((e->map)[i][j] != NULL)
		{
			pos = ft_set_pos(300 - (i - j) * e->zoom, (120 - (i + j)
				* -13 - ft_atoi((e->map)[i][j])));
			if ((e->map)[i][j] != NULL)
				draw_vert(e, pos, i, j);
			if ((e->map)[i])
				draw_hor(e, pos, i, j);
			j++;
		}
		i++;
	}
}
