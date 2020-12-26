/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arr_voidp2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:59:18 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 16:21:47 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal.h"
#include <stdlib.h>
#include <stddef.h>

void		ft_arr_voidp_free(t_arr_voidp *arr, void (*del)(void *))
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

void		ft_arr_voidp_shift(t_arr_voidp **arr, void (*del)(void *))
{
	if (arr == NULL || *arr == NULL || (*arr)->length == 0)
		return ;
	if (del && (*arr)->table[(*arr)->start_i] != NULL)
		del((*arr)->table[(*arr)->start_i]);
	(*arr)->start_i += 1;
	(*arr)->length -= 1;
}

void		ft_arr_voidp_pop(t_arr_voidp **arr, void (*del)(void *))
{
	if (arr == NULL || *arr == NULL || (*arr)->length == 0)
		return ;
	if (del && (*arr)->table[(*arr)->length - 1] != NULL)
		del((*arr)->table[(*arr)->length - 1]);
	(*arr)->length -= 1;
}

void		**ft_arr_voidp_concat(t_arr_voidp *arr, size_t *length)
{
	void	**res;

	if (arr == NULL || arr->length == 0)
	{
		*length = 0;
		return (NULL);
	}
	*length = arr->length;
	res = ft_memdup(arr->table + arr->start_i, arr->length * sizeof(void *));
	ft_arr_voidp_free(arr, NULL);
	return (res);
}
