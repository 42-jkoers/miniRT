/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_arr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <joppe@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/15 22:57:36 by joppe         #+#    #+#                 */
/*   Updated: 2020/10/25 15:11:30 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "ft_array.h"
#include "ft_memory.h"

void	ft_rev(void *arr, uint64_t item_size, uint64_t len)
{
	uint8_t		*a;
	uint8_t		left[item_size];
	uint64_t	left_i;
	uint64_t	right_i;

	if (len <= 1 || item_size == 0)
		return ;
	a = arr;
	left_i = 0;
	right_i = (len - 1) * item_size;
	while (left_i < right_i)
	{
		ft_memcpy(left, a + left_i, item_size);
		ft_memcpy(a + left_i, a + right_i, item_size);
		ft_memcpy(a + left_i, left, item_size);
		left_i += item_size;
		right_i -= item_size;
	}
}
