/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:13:20 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:13:21 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_pos(t_pos *pos)
{
	pos->posx = X_START;
	pos->posy = Y_START;
	pos->dirx = -1.0;
	pos->diry = 0.0;
	pos->planex = 0.0;
	pos->planey = 0.66;
}

void			setup(t_env *e)
{
	set_pos(&e->pos);
}

void			set_data(t_env *e, t_data *d, int x)
{
	d->camerax = 2 * x / (double)WINDOW_WIDTH - 1;
	d->rayposx = e->pos.posx;
	d->rayposy = e->pos.posy;
	d->raydirx = e->pos.dirx + e->pos.planex * d->camerax;
	d->raydiry = e->pos.diry + e->pos.planey * d->camerax;
	d->mapx = (int)d->rayposx;
	d->mapy = (int)d->rayposy;
	d->deltadistx = sqrt(1 + (d->raydiry * d->raydiry) /
		(d->raydirx * d->raydirx));
	d->deltadisty = sqrt(1 + (d->raydirx * d->raydirx) /
		(d->raydiry * d->raydiry));
	d->hit = 0;
}
