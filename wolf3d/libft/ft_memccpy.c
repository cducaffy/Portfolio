/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:01:03 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/06 13:34:38 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dstprime;
	char			*srcprime;

	dstprime = (char *)dst;
	srcprime = (char *)src;
	while (*srcprime != c && n > 0)
	{
		*dstprime = *srcprime;
		dstprime++;
		srcprime++;
		n--;
	}
	if (*srcprime == c && n > 0)
	{
		*dstprime = *srcprime;
		dstprime++;
		return (dstprime);
	}
	else
		return (NULL);
}
