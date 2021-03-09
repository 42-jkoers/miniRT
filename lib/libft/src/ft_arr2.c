/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arr2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:59:18 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 16:51:46 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_arr_free(t_arr *arr, void (*del)(void *))
{
	size_t		i;

	if (arr == NULL)
		return ;
	if (del != NULL)
	{
		i = 0;
		while (i < arr->length)
		{
			if (arr->table[arr->start_i + i] != NULL)
				del(arr->table[arr->start_i + i]);
			i++;
		}
	}
	free(arr->table);
	free(arr);
	arr = NULL;
}

void	ft_arr_shift(t_arr **arr, void (*del)(void *))
{
	if (arr == NULL || *arr == NULL || (*arr)->length == 0)
		return ;
	if (del && (*arr)->table[(*arr)->start_i] != NULL)
		del((*arr)->table[(*arr)->start_i]);
	(*arr)->start_i += 1;
	(*arr)->length -= 1;
}

void	ft_arr_pop(t_arr **arr, void (*del)(void *))
{
	if (arr == NULL || *arr == NULL || (*arr)->length == 0)
		return ;
	if (del && (*arr)->table[(*arr)->length - 1] != NULL)
		del((*arr)->table[(*arr)->length - 1]);
	(*arr)->length -= 1;
}

void	**ft_arr_concat(t_arr *arr, size_t *length)
{
	void	**res;

	if (arr == NULL || arr->length == 0)
	{
		*length = 0;
		return (NULL);
	}
	*length = arr->length;
	if (arr->start_i == 0 && arr->length < arr->size)
	{
		res = arr->table;
		res[arr->length] = NULL;
		free(arr);
		return (res);
	}
	res = malloc((arr->length + 1) * sizeof(void *));
	ft_memcpy(res, arr->table + arr->start_i, arr->length * sizeof(void *));
	res[arr->length] = NULL;
	ft_arr_free(arr, NULL);
	return (res);
}
