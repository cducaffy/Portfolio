/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:48:10 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:48:11 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int			wall_color(t_data *d)
{
	int color;

	if (d->side == 0 && d->raydirx > 0)
		color = RGB_RED;
	else if (d->side == 0 && d->raydirx < 0)
		color = RGB_GREEN;
	else if (d->side == 1 && d->raydiry < 0)
		color = RGB_WHITE;
	else if (d->side == 1 && d->raydiry > 0)
		color = RGB_YELLOW;
	else
		color = 0xFFFFFF;
	return (color);
}

void		ft_cleanscreen(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < (WINDOW_HEIGHT / 2))
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			put_pixel(j, i, RGB_BLUE, &e->img);
			j++;
		}
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			put_pixel(j, i, RGB_BROWN, &e->img);
			j++;
		}
		i++;
	}
}
