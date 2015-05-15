/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:32:39 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/10 14:41:50 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	unsigned char *memoire;

	if (size == 0)
		return (NULL);
	memoire = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!(memoire))
		return (NULL);
	while (size > 0)
	{
		*((unsigned char *)memoire + size) = 0;
		size--;
	}
	return (memoire);
}
