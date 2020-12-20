/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_includes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 18:43:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/04 18:46:43 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ft_includes(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}
