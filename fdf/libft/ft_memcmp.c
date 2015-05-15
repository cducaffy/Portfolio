/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:00:54 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/06 13:36:27 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1prime;
	const unsigned char		*s2prime;

	s1prime = s1;
	s2prime = s2;
	if (s1prime == NULL || s2prime == NULL)
		return (0);
	while (n-- != 0)
	{
		if (*s1prime != *s2prime)
		{
			return (*s1prime - *s2prime);
		}
		s1prime++;
		s2prime++;
	}
	return (0);
}
