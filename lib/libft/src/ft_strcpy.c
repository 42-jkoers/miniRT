/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:03:37 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 02:03:44 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strcpy(char *dest, char *src)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	ft_memcpy(dest, src, (src_len + 1) * sizeof(char));
	return (dest);
}
