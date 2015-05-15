/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:30:21 by cducaffy          #+#    #+#             */
/*   Updated: 2014/11/20 16:53:04 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lstnext;

	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		lstnext = lst->next;
		f(lst);
		lst = lstnext;
	}
}
