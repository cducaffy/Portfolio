/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:49:44 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:49:45 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		mlx_cut_two(t_env *e, t_pt *pt1, t_drawdata data)
{
	data.i = 1;
	data.cumul = data.dy / 2;
	while (data.i <= data.dy)
	{
		data.y += data.yinc;
		data.cumul += data.dx;
		if (data.cumul >= data.dy)
		{
			data.cumul -= data.dy;
			data.x += data.xinc;
		}
		put_pixel(data.x, data.y, pt1->color, &e->img);
		data.i++;
	}
}

void		mlx_cut_one(t_env *e, t_pt *pt1, t_drawdata data)
{
	data.cumul = data.dx / 2;
	while (data.i <= data.dx)
	{
		data.x += data.xinc;
		data.cumul += data.dy;
		if (data.cumul >= data.dx)
		{
			data.cumul -= data.dx;
			data.y += data.yinc;
		}
		put_pixel(data.x, data.y, pt1->color, &e->img);
		data.i++;
	}
}

void		mlx_line_put(t_env *e, t_pt *pt1, t_pt *pt2)
{
	t_drawdata data;

	data.x = pt1->x;
	data.y = pt1->y;
	data.i = 1;
	data.dx = pt2->x - pt1->x;
	data.dy = pt2->y - pt1->y;
	data.xinc = (data.dx > 0 ? 1 : -1);
	data.yinc = (data.dy > 0 ? 1 : -1);
	data.dx = abs(data.dx);
	data.dy = abs(data.dy);
	put_pixel(data.x, data.y, pt1->color, &e->img);
	if (data.dx > data.dy)
	{
		mlx_cut_one(e, pt1, data);
	}
	else
	{
		mlx_cut_two(e, pt1, data);
	}
}
