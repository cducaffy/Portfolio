/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:43:46 by cducaffy          #+#    #+#             */
/*   Updated: 2015/04/27 13:51:19 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

int		expose_hook(t_env *e)
{
	ft_draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)*e;
	if (keycode == 53)
		ft_error("Close");
	return (0);
}
