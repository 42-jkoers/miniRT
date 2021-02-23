/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtostr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/08 01:55:45 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_numtostr(long num)
{
	char	*res;
	size_t	stop_at;
	size_t	numlen;

	numlen = ft_numlen(num, 10);
	res = malloc((numlen + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	stop_at = num < 0;
	if (num < 0)
		res[0] = '-';
	res[numlen] = '\0';
	while (numlen > stop_at)
	{
		numlen--;
		res[numlen] = (char)ft_abs(num % 10) + '0';
		num /= 10;
	}
	return (res);
}
