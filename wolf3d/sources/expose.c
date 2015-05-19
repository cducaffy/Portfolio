/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:29:26 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:29:28 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_env *e)
{
	ft_wolf(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	double olddirx;
	double oldplanex;

	olddirx = 0.0;
	oldplanex = 0.0;
	if (keycode == 126)
		key_up(e);
	if (keycode == 125)
		key_down(e);
	if (keycode == 124)
		key_right(e, olddirx, oldplanex);
	if (keycode == 123)
		key_left(e, olddirx, oldplanex);
	if (keycode == 53)
		ft_error("Close");
	ft_wolf(e);
	return (0);
}
