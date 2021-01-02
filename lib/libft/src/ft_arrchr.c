/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/31 12:52:50 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/31 13:06:21 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

ssize_t	ft_arrchr(char **arr, char *search)
{
	size_t	i;

	if (arr == NULL)
		return (-1);
	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], search) == 0)
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	ft_arrchrn(char **arr, char *search, size_t search_len)
{
	size_t	i;

	if (arr == NULL)
		return (-1);
	i = 0;
	while (arr[i])
	{
		if (ft_strncmp(arr[i], search, search_len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	ft_arrnchr(char **arr, size_t arr_len, char *search)
{
	size_t	i;

	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < arr_len)
	{
		if (ft_strcmp(arr[i], search) == 0)
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	ft_arrnchrn(char **arr, size_t arr_len, char *search, size_t search_len)
{
	size_t	i;

	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < arr_len)
	{
		if (ft_strncmp(arr[i], search, search_len) == 0)
			return (i);
		i++;
	}
	return (-1);
}
