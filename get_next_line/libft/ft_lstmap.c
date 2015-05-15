/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:57:00 by cducaffy          #+#    #+#             */
/*   Updated: 2015/04/21 12:57:02 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*dest;

	dest = NULL;
	if (lst != NULL)
		dest = ft_lstnew(lst->content, lst->content_size);
	if (!dest)
		return (NULL);
	dest = f(dest);
	if (lst->next)
		dest->next = ft_lstmap(lst->next, f);
	return (dest);
}
