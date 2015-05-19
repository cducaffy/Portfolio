/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:29:37 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:29:38 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		key_up(t_env *e)
{
	if (e->worldmap[(int)(e->pos.posx + e->pos.dirx * MOVESPEED)]
		[(int)e->pos.posy] == 0)
		e->pos.posx += e->pos.dirx * MOVESPEED;
	if (e->worldmap[(int)e->pos.posx]
		[(int)(e->pos.posy + e->pos.diry * MOVESPEED)] == 0)
		e->pos.posy += e->pos.diry * MOVESPEED;
}

void		key_down(t_env *e)
{
	if (e->worldmap[(int)(e->pos.posx - e->pos.dirx * MOVESPEED)]
		[(int)e->pos.posy] == 0)
		e->pos.posx -= e->pos.dirx * MOVESPEED;
	if (e->worldmap[(int)e->pos.posx]
		[(int)(e->pos.posy - e->pos.diry * MOVESPEED)] == 0)
		e->pos.posy -= e->pos.diry * MOVESPEED;
}

void		key_right(t_env *e, double olddirx, double oldplanex)
{
	olddirx = e->pos.dirx;
	e->pos.dirx = e->pos.dirx * cos(-ROTSPEED) - e->pos.diry * sin(-ROTSPEED);
	e->pos.diry = olddirx * sin(-ROTSPEED) + e->pos.diry * cos(-ROTSPEED);
	oldplanex = e->pos.planex;
	e->pos.planex = e->pos.planex * cos(-ROTSPEED)
		- e->pos.planey * sin(-ROTSPEED);
	e->pos.planey = oldplanex * sin(-ROTSPEED) + e->pos.planey * cos(-ROTSPEED);
}

void		key_left(t_env *e, double olddirx, double oldplanex)
{
	olddirx = e->pos.dirx;
	e->pos.dirx = e->pos.dirx * cos(ROTSPEED) - e->pos.diry * sin(ROTSPEED);
	e->pos.diry = olddirx * sin(ROTSPEED) + e->pos.diry * cos(ROTSPEED);
	oldplanex = e->pos.planex;
	e->pos.planex = e->pos.planex * cos(ROTSPEED)
		- e->pos.planey * sin(ROTSPEED);
	e->pos.planey = oldplanex * sin(ROTSPEED) + e->pos.planey * cos(ROTSPEED);
}
