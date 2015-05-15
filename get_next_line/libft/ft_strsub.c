/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:54:02 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/07 13:57:09 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = ft_strnew(len + 1);
	if (!dst || !s)
		return (NULL);
	ft_strncpy(dst, (s + start), len);
	return (dst);
}
