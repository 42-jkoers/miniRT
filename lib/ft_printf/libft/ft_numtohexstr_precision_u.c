/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtohexstr_precision_u.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/26 17:09:21 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

char	*ft_numtohexstr_precision_u(unsigned long num, bool lowercase, \
									bool prefix, size_t min_len)
{
	size_t		numlen;
	char		*result;
	const char	up[] = "0123456789ABCDEF";
	const char	lo[] = "0123456789abcdef";
	size_t		offset;

	offset = prefix ? 2 : 0;
	numlen = ft_max_u(ft_numlen_u(num, 16), min_len);
	result = malloc((numlen + offset + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (prefix)
		ft_strncpy(result, "0x", 2);
	result[numlen + offset] = '\0';
	while (numlen > 0)
	{
		numlen--;
		result[numlen + offset] = lowercase ? lo[num % 16] : up[num % 16];
		num /= 16;
	}
	return (result);
}
