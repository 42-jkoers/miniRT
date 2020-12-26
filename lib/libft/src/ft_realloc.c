/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <joppe@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 13:48:36 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/23 13:32:17 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_realloc(void *ptr, size_t orig_len, size_t new_len)
{
	void *new_ptr;

	if (new_len == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_len));
	if (orig_len == new_len)
		return (ptr);
	new_ptr = malloc(new_len);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, orig_len);
	free(ptr);
	return (new_ptr);
}
