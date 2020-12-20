/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtobase_u.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/02 12:34:14 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_numtobase_u(unsigned long num, char *base)
{
	size_t			numlen;
	unsigned long	base_n;
	char			*result;

	base_n = (unsigned long)ft_strlen(base);
	numlen = ft_numlen_u(num, base_n);
	result = malloc((numlen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[numlen] = '\0';
	while (numlen > 0)
	{
		numlen--;
		result[numlen] = (char)(base[num % base_n]);
		num /= base_n;
	}
	return (result);
}
