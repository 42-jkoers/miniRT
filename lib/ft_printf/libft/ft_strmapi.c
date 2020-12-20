/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:09:27 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/02 12:41:29 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	size_t			s_len;
	unsigned int	i;

	s_len = ft_strlen((char *)s);
	new_s = malloc((s_len + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	new_s[s_len] = '\0';
	i = 0;
	while (i < s_len)
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	return (new_s);
}
