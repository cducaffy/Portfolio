/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:49:16 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/26 15:21:28 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	n += '0';
	return (n);
}

static int		ft_sizelen(int n, int *size)
{
	int		i;
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	i = 1;
	*size = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		*size *= 10;
		i++;
	}
	return (i + neg);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			size;
	int			len;
	int			i;

	len = ft_sizelen(n, &size);
	if ((str = ft_strnew(len)))
	{
		i = 0;
		if (n < 0)
		{
			str[i] = '-';
			n = -n;
			i++;
		}
		while (i < len)
		{
			str[i] = ft_abs((n / size) % 10);
			size /= 10;
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
