/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:54:53 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:54:54 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			ft_calc_step_side(t_data *d)
{
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (d->rayposx - d->mapx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->mapx + 1.0 - d->rayposx) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (d->rayposy - d->mapy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->mapy + 1.0 - d->rayposy) * d->deltadisty;
	}
}

static void			ft_dda(t_env *e, t_data *d)
{
	while (d->hit == 0)
	{
		if (d->sidedistx < d->sidedisty)
		{
			d->sidedistx += d->deltadistx;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->sidedisty += d->deltadisty;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (e->worldmap[d->mapx][d->mapy] > 0)
			d->hit = 1;
	}
}

static void			ft_calc_dist(t_env *e, t_data *d, int x)
{
	t_pt	pt1;
	t_pt	pt2;

	pt1.x = 0;
	pt2.x = 0;
	pt1.y = 0;
	pt2.y = 0;
	if (d->side == 0)
		d->perpwalldist = fabs((d->mapx - d->rayposx + (1 - d->stepx) / 2)
			/ d->raydirx);
	else
		d->perpwalldist = fabs((d->mapy - d->rayposy + (1 - d->stepy) / 2)
			/ d->raydiry);
	d->lineheight = abs((int)(WINDOW_HEIGHT / d->perpwalldist));
	pt1.y = -d->lineheight / 2 + WINDOW_HEIGHT / 2;
	if (pt1.y < 0)
		pt1.y = 0;
	pt2.y = d->lineheight / 2 + WINDOW_HEIGHT / 2;
	if (pt2.y >= WINDOW_HEIGHT)
		pt2.y = WINDOW_HEIGHT - 1;
	pt1.x = x;
	pt2.x = x;
	pt1.color = wall_color(d);
	pt2.color = wall_color(d);
	mlx_line_put(e, &pt1, &pt2);
}

void				ft_wolf(t_env *e)
{
	t_data	d;
	int		x;

	ft_cleanscreen(e);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		set_data(e, &d, x);
		ft_calc_step_side(&d);
		ft_dda(e, &d);
		ft_calc_dist(e, &d, x);
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_p, 0, 0);
}
