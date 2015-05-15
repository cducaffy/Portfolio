/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:46:27 by cducaffy          #+#    #+#             */
/*   Updated: 2015/03/25 14:58:56 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	char			*scp;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	scp = s1;
	while (*s1)
	{
		*s1 = f(i++, *s1);
		s1++;
	}
	s1 = NULL;
	return (scp);
}
