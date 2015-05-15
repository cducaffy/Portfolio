/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:26:45 by cducaffy          #+#    #+#             */
/*   Updated: 2015/02/03 17:26:47 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#define BUFF_SIZE 4096

int	ft_replace_chartonull(char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			s[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str = "";
	char		*buf;
	int			ret;

	if (fd < 1 || !(line))
		return (-1);
	*line = ft_strdup("\n");
	ret = BUFF_SIZE;
	while (ft_replace_chartonull(str, '\n') != 1 && ret == BUFF_SIZE)
	{
		buf = (char *)malloc(sizeof(char) * (BUFF_SIZE) + 1);
		if (buf == NULL)
			return (-1);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		str = ft_strjoin((char const *)str, buf);
		free(buf);
	}
	*line = ft_strdup(str);
	ft_replace_chartonull(*line, '\n');
	str = str + ft_strlen(*line) + 1;
	if (ret != BUFF_SIZE && **line == 0 && *str == 0)
		return (0);
	return (1);
}
