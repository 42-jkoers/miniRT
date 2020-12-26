/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 18:30:13 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 12:50:25 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_memdup(void *src, size_t n)
{
	void	*dup;

	if (src == NULL)
		return (NULL);
	dup = malloc(n);
	if (dup != NULL)
		ft_memcpy(dup, src, n);
	return (dup);
}
