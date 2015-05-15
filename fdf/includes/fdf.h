/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:23:01 by cducaffy          #+#    #+#             */
/*   Updated: 2015/04/28 20:25:46 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <libft.h>

# define IMG_X 800
# define IMG_Y 600
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define BROWNSUP 0xAE8964
# define BROWN 0x582900
# define GREENSUP 0x1B4F08
# define GREEN 0x3A9D23
# define BLUESUP 0x0000FF
# define BLUE 0x0F056B

# define K_ESC 65307

# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_data
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;

}				t_data;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	char	***map;
	int		zoom;
}				t_env;

typedef	struct	s_pos
{
	int x;
	int y;
	int color;
}				t_pos;

int				get_next_line(int const fd, char **line);
void			mlx_line_put(t_env *e, t_pos *pt1, t_pos *pt2);
void			ft_printmap(char ***map);
void			ft_error(char *str);
void			draw_hor(t_env *e, t_pos pos, int i, int j);
void			draw_vert(t_env *e, t_pos pos, int i, int j);
void			ft_draw(t_env *e);
t_pos			ft_set_pos(int x, int y);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);

#endif
