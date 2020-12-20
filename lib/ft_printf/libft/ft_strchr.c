/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:43:05 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/27 23:00:50 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

char	*ft_strchr(char *str, char c)
{
	while (true)
	{
		if (*str == c)
			return (str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
}
