/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 18:54:03 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 18:59:02 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strcount(char *str, char search)
{
	size_t	n;

	if (str == NULL)
		return (0);
	n = 0;
	while (*str != '\0')
	{
		if (*str == search)
			n++;
		str++;
	}
	return (n);
}
