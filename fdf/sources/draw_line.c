/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:21:31 by cducaffy          #+#    #+#             */
/*   Updated: 2015/02/04 13:21:33 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

void		mlx_cut_two(t_env *e, t_pos *pt1, t_data data)
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
		mlx_pixel_put(e->mlx, e->win, data.x, data.y, pt1->color);
		data.i++;
	}
}

void		mlx_cut_one(t_env *e, t_pos *pt1, t_data data)
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
		mlx_pixel_put(e->mlx, e->win, data.x, data.y, pt1->color);
		data.i++;
	}
}

void		mlx_line_put(t_env *e, t_pos *pt1, t_pos *pt2)
{
	t_data data;

	data.x = pt1->x;
	data.y = pt1->y;
	data.i = 1;
	data.dx = pt2->x - pt1->x;
	data.dy = pt2->y - pt1->y;
	data.xinc = (data.dx > 0 ? 1 : -1);
	data.yinc = (data.dy > 0 ? 1 : -1);
	data.dx = ABS(data.dx);
	data.dy = ABS(data.dy);
	mlx_pixel_put(e->mlx, e->win, data.x, data.y, pt1->color);
	if (data.dx > data.dy)
	{
		mlx_cut_one(e, pt1, data);
	}
	else
	{
		mlx_cut_two(e, pt1, data);
	}
}
