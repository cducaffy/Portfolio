/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:23:15 by cducaffy          #+#    #+#             */
/*   Updated: 2015/05/14 14:23:17 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <math.h>

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 750

# define MOVESPEED 0.4
# define ROTSPEED 0.2

# define X_START 10.0
# define Y_START 10.0

# define RGB_RED 0xFF0000
# define RGB_WHITE 0xFFFFFF
# define RGB_BROWN 0x582900
# define RGB_GREEN 0x3A9D23
# define RGB_BLUE 0x0F056B
# define RGB_YELLOW 0xF6DC12

typedef	struct	s_pt
{
	int x;
	int y;
	int color;
}				t_pt;

typedef struct	s_drawdata
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
}				t_drawdata;

typedef struct	s_data
{
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
}				t_data;

typedef struct	s_pos
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_pos;

typedef struct	s_img
{
	void		*img_p;
	char		*img;
	int			line;
	int			column;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			worldmap[MAP_WIDTH][MAP_HEIGHT];
	t_pos		pos;
	t_data		data;
	t_img		img;
}				t_env;

int				load_map(char *path, int worldmap[MAP_WIDTH][MAP_HEIGHT]);
void			setup(t_env *e);
void			set_data(t_env *e, t_data *d, int x);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
void			key_up(t_env *e);
void			key_down(t_env *e);
void			key_right(t_env *e, double olddirx, double oldplanex);
void			key_left(t_env *e, double olddirx, double oldplanex);
void			ft_error(char *str);
void			mlx_cut_one(t_env *e, t_pt *pt1, t_drawdata data);
void			mlx_cut_two(t_env *e, t_pt *pt1, t_drawdata data);
void			mlx_line_put(t_env *e, t_pt *pt1, t_pt *pt2);
int				wall_color(t_data *d);
void			ft_cleanscreen(t_env *e);
void			ft_wolf(t_env *e);
t_img			create_img(void *mlx, int width, int height);
void			put_pixel(int x, int y, int color, t_img *img);

#endif
