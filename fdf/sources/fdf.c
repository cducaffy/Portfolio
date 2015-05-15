/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 14:07:34 by cducaffy          #+#    #+#             */
/*   Updated: 2015/04/28 15:49:23 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

char	***ft_readmap(char *file)
{
	char	***tab;
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map not found\n");
		exit (0);
	}
	tab = malloc(sizeof(char *) * 500);
	i = 0;
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strsplit(line, ' ');
		i++;
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		ft_error("usage : ./fdf file");
	e.map = ft_readmap(argv[1]);
	if (!(e.mlx = mlx_init()))
		ft_error("Fail to init mlx");
	if (!(e.win = mlx_new_window(e.mlx, IMG_X, IMG_Y, "fdf")))
		ft_error("Fail to create Mlx New Window");
	e.zoom = 20;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (EXIT_SUCCESS);
}
