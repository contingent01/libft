/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:30:43 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/09 19:40:34 by mdkhissi         ###   ########.fr       */
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
	new->prev = NULL;
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
		new->prev = p;
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
		tmp->prev = new;
		new->next = tmp;
	}
}
