/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 14:12:50 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 13:13:03 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split_file(const char *filename, size_t *num_lines)
{
	char		*read;
	int			fd;
	t_arr		*arr;

	fd = open((char *)filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	arr = NULL;
	while (ft_get_next_line(fd, &read) == 1)
	{
		if (ft_arr_push(&arr, read) == NULL)
		{
			ft_arr_free(arr, free);
			read = NULL;
			*num_lines = 0;
		}
	}
	close(fd);
	return ((char **)ft_arr_concat(arr, num_lines));
}
