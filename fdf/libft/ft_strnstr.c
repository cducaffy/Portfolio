/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:50:17 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/12 14:57:12 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (ft_strlen((char*)s2) == 0)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != 0 && s1[i + j] == s2[j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)&(s1[i]));
		i++;
	}
	return (NULL);
}
