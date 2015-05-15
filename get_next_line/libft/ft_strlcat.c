/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:49:30 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/12 17:47:21 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_inc_counters(char **dst_copy, size_t *counter)
{
	while (**dst_copy != '\0' && *counter != 0)
	{
		(*counter)--;
		(*dst_copy)++;
	}
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_copy;
	const char	*src_copy;
	size_t		counter;
	size_t		dst_len;

	dst_copy = dst;
	src_copy = src;
	counter = size;
	ft_inc_counters(&dst_copy, &counter);
	dst_len = dst_copy - dst;
	counter = size - dst_len;
	if (counter == 0)
		return (ft_strlen(src_copy) + dst_len);
	while (*src_copy != '\0')
	{
		if (counter != 1)
		{
			*dst_copy = *src_copy;
			dst_copy++;
			counter--;
		}
		src_copy++;
	}
	*dst_copy = '\0';
	return ((src_copy - src) + dst_len);
}
