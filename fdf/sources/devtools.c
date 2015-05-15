/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devtools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:33:23 by cducaffy          #+#    #+#             */
/*   Updated: 2015/02/04 13:33:42 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

void	ft_printmap(char ***map)
{
	int x;
	int	y;

	x = 0;
	while (map[x] != '\0')
	{
		ft_putstr("x = ");
		ft_putnbr(x + 1);
		ft_putchar('\n');
		y = 0;
		while (map[x][y] != '\0')
		{
			ft_putnbr(y + 1);
			ft_putstr("/");
			ft_putnbr(ft_atoi(map[x][y]));
			ft_putstr(" - ");
			y++;
		}
		x++;
		ft_putchar('\n');
	}
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}
