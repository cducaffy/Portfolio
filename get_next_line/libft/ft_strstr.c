/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:46 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/10 16:33:45 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen((char*)s2) == 0)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != 0 && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *)&(s1[i]));
		i++;
	}
	return (NULL);
}
