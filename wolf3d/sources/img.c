/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:27:53 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 15:27:55 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			put_pixel(int x, int y, int color, t_img *img)
{
	int			pixel;
	char		red;

	red = color / 65536;
	pixel = x * 4 + (y * img->column) * 4;
	img->img[pixel + 2] = red;
	img->img[pixel + 1] = (color - (red * 65536)) / 256;
	img->img[pixel] = (color - (red * 65536)) % 256;
}

t_img			create_img(void *mlx, int width, int height)
{
	t_img		img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	endian = 1;
	size_line = height * 4;
	bits_per_pixel = 8;
	img.column = width;
	img.line = height;
	img.img_p = mlx_new_image(mlx, width, height);
	img.img =
		mlx_get_data_addr(img.img_p, &bits_per_pixel, &size_line, &endian);
	return (img);
}
