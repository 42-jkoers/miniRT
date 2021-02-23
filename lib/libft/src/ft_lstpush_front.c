/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpush_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 13:46:01 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 13:50:31 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_front(t_list **lst, void *content)
{
	t_list	*old_front;

	old_front = *lst;
	*lst = ft_lstnew(content);
	(*lst)->next = old_front;
}
