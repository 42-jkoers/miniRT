/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtostr_precision_u.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/26 17:10:01 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_numtostr_precision_u(unsigned long num, size_t min_len)
{
	char	*res;
	size_t	numlen;

	numlen = ft_max_u(ft_numlen_u(num, 10), min_len);
	res = malloc((numlen + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[numlen] = '\0';
	while (numlen > 0)
	{
		numlen--;
		res[numlen] = (char)(num % 10) + '0';
		num /= 10;
	}
	return (res);
}
