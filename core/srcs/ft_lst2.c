/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:32:35 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 16:33:15 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply f() to every item in the list
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	if (!lst || !f)
		return ;
	i = lst;
	while (i)
	{
		f(i->content);
		i = i->next;
	}
}


t_list	*ft_lstlast(t_list *lst)
{
	t_list	*i;

	if (!lst)
		return (NULL);
	i = lst;
	while (i->next != NULL)
		i = i->next;
	return (i);
}

/*
** Create a new list that have elements
** contents been changed by f()
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*i;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	i = new;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&i, tmp);
		i = i->next;
		lst = lst->next;
	}
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
