/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:44:38 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/08 15:41:16 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_strset(char *str, char c, size_t n)
{
	while (n > 0)
	{
		n--;
		str[n] = c;
	}
}
