/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 00:48:57 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/31 13:41:41 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	**current;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	current = &(head->next);
	while (lst != NULL)
	{
		*current = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		current = &((*current)->next);
	}
	return (head);
}
