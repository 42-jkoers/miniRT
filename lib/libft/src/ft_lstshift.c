/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstshift.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:01:03 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/25 18:05:19 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstshift(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	next = (*lst)->next;
	if ((*lst)->content && del)
		del((*lst)->content);
	free(*lst);
	*lst = next;
}
