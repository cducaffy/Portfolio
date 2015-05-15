/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:31:36 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/26 15:18:40 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_check(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	char		*r;
	char		*start;
	char		*end;

	if (!s)
		return (NULL);
	start = (char *)s;
	if (*start == '\0')
		return (ft_strnew(1));
	while (ft_check(*start))
		start++;
	if (*start == '\0')
		return (ft_strnew(1));
	end = (start + (ft_strlen(start) - 1));
	while (ft_check(*end))
		end--;
	r = ft_strsub(s, (start - s), (size_t)((end - start) + 1));
	return (r);
}
