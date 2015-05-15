/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:38:00 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/04 14:25:07 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		j;

	j = 0;
	dup = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	else
	{
		while (s1[j] != '\0')
		{
			dup[j] = s1[j];
			j++;
		}
	}
	dup[j] = '\0';
	return (dup);
}
