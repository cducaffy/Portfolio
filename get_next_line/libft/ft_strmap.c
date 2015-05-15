/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:27:40 by cducaffy          #+#    #+#             */
/*   Updated: 2015/03/25 14:58:41 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*s1;
	char		*scp;

	if (!s || !f)
		return (NULL);
	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	scp = s1;
	while (*s1)
	{
		*s1 = f(*s1);
		s1++;
	}
	s1 = NULL;
	return (scp);
}
