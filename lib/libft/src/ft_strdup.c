/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:46:53 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/27 23:24:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(str) + 1;
	dup = malloc(size * sizeof(char));
	if (dup != NULL)
		ft_memcpy(dup, str, size * sizeof(char));
	return (dup);
}
