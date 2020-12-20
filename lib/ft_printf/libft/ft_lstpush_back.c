/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpush_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 13:46:44 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/04 01:17:41 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **lst, void *content)
{
	if (lst == NULL || *lst == NULL)
		*lst = ft_lstnew(content);
	else
		(ft_lstlast(*lst))->next = ft_lstnew(content);
}
