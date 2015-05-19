/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:36:52 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 14:36:53 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int main(int argc, char **argv)
{
	t_env	e;
	t_img	img;

	if (argc != 2)
		ft_error("usage : ./wolf3d file");
	load_map(argv[1], e.worldmap);
	setup(&e);
	if (!(e.mlx = mlx_init()))
		ft_error("Fail to init mlx");
	if (!(e.win = mlx_new_window(e.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "wolf3d")))
		ft_error("Fail to create Mlx New Window");
	img = create_img(e.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	e.img = img;
	mlx_hook(e.win, 2, 1L << 0, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
