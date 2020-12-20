/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtohexstr_u.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/12 00:06:38 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

char	*ft_numtohexstr_u(unsigned long num, bool lowercase, bool prefix)
{
	size_t		numlen;
	char		*result;
	const char	upper[] = "0123456789ABCDEF";
	const char	lower[] = "0123456789abcdef";

	numlen = ft_numlen_u(num, 16);
	result = malloc((numlen + (prefix ? 3 : 1)) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (prefix)
		ft_strncpy(result, "0x", 2);
	result[numlen] = '\0';
	while (numlen > 0)
	{
		numlen--;
		result[numlen + (prefix ? 2 : 0)] = \
			lowercase ? lower[num % 16] : upper[num % 16];
		num /= 16;
	}
	return (result);
}
