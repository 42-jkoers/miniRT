/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 23:13:28 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/27 23:31:35 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	p = malloc(nmemb * size);
	if (p != NULL)
		ft_memset(p, 0, nmemb * size);
	return (p);
}
