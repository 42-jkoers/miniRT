/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_arr.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 12:18:35 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 12:36:05 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_arr	*arr;
	size_t	i;

	arr = NULL;
	i = 0;
	while (i < 2)
	{
		ft_arr_push(&arr, (void *)ft_strdup("hello\n"));
		ft_arr_shift(&arr, free);
		i++;
	}
	printf("length %lu\n", arr->length);
	printf("size %lu\n", arr->size);
	ft_arr_push(&arr, (void *)ft_strdup("hello\n"));
	ft_putstr((char *)ft_arr_get(arr, arr->length - 1));
	ft_arr_free(arr, free);
	return (0);
}
