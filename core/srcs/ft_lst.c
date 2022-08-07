/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:30:43 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 16:31:50 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate a new t_list element
** then copy content into it.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	if (!content)
		new->content = NULL;
	else
		new->content = content;
	new->next = NULL;
	return (new);
}

/*
** If the list is empty,
** call ft_lstadd_front(),
** else, call call ft_lstlast()
** then link it with the the new element
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	if (!alst || !new)
		return ;
	if (!*alst)
		ft_lstadd_front(alst, new);
	else
	{
		p = ft_lstlast(*alst);
		p->next = new;
	}
}

/*
** if the list is empty
** the first pointer is linked to the new,
** if the list was empty, that'all,
** else, save the first element in $tmp,
** make new as first element,
** then $tmp as next element.
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		*alst = new;
		new->next = tmp;
	}
}

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
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}
