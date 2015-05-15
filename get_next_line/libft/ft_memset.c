/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:05:38 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/05 11:49:54 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*bprime;

	i = 0;
	bprime = b;
	while (i < len)
	{
		bprime[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
