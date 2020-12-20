/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:06:44 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/27 23:26:28 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	joined = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (joined != NULL)
	{
		ft_memcpy(joined, (char *)s1, s1_len * sizeof(char));
		ft_memcpy(joined + s1_len, (char *)s2, (s2_len + 1) * sizeof(char));
	}
	return (joined);
}
