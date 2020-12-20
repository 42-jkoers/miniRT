/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:30:56 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/02 12:42:12 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*s;
	unsigned int	chars_before;
	unsigned int	chars_after;
	size_t			len;
	size_t			trimmed_len;

	s = (char *)s1;
	chars_before = 0;
	while (ft_strchr((char *)set, s[chars_before]) != NULL)
		chars_before++;
	len = ft_strlen(s + chars_before) + chars_before;
	chars_after = 0;
	while (ft_strchr((char *)set, s[len - chars_after]) != NULL)
		chars_after++;
	trimmed_len = len - chars_before - chars_after;
	return (ft_substr(s, chars_before, trimmed_len + 1));
}
