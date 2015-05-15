/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:29:11 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/10 17:48:35 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	char		*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (s1 > s2)
	{
		if (len == 0 || s1 == s2)
			return (s1);
		while (len--)
			s1[len] = s2[len];
		return (s1);
	}
	else
		return (ft_memcpy(dst, src, len));
}
