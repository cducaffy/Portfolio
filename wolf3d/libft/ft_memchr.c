/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:00:08 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/10 15:15:33 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sprime;

	sprime = s;
	while (n > 0)
	{
		if (*sprime == (char)c)
		{
			return ((void *)sprime);
		}
		sprime++;
		n--;
	}
	return (NULL);
}
