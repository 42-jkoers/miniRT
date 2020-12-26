/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_2d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 14:24:44 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/25 18:21:25 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_2d(void **arr, size_t length)
{
	if (arr == NULL)
		return ;
	while (length > 0)
	{
		length--;
		if (arr[length])
			free(arr[length]);
	}
	free(arr);
}
