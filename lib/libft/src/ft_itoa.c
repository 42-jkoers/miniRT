/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:26:18 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/05 15:46:38 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_itoa(int n)
{
	char			*res;
	unsigned int	len;
	unsigned int	is_negative;

	len = (unsigned int)ft_numlen(n, 10);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	is_negative = (unsigned long)(n < 0 ? 1 : 0);
	if (is_negative)
		res[0] = '-';
	res[len] = '\0';
	while (len > is_negative)
	{
		len--;
		res[len] = (char)(ft_abs(n % 10) + '0');
		n /= 10;
	}
	return (res);
}
