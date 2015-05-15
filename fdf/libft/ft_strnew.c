/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:22 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/06 16:53:52 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
