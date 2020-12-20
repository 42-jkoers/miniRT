/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:58:39 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 01:22:07 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_leftover;

	s_leftover = ft_strlen((char *)s);
	if (s_leftover <= start)
		return (ft_strdup(""));
	s_leftover -= start;
	if (s_leftover < len)
		len = s_leftover;
	return (ft_strndup((char *)s + start, len));
}
