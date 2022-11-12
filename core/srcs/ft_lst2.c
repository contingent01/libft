/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:25:00 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/24 12:33:42 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Clear the list and free it
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmpnext;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmpnext = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = tmpnext;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

void	ft_lstdel(t_list **alst, t_list *lst, void (*del)(void *))
{
	if (!alst || !*alst || !lst)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	else
		*alst = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	ft_lstdelone(lst, del);
}
