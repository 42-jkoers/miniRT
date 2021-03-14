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

// static void	push_lines(t_arr **arr, int fd)
// {
// 	int		msg;
// 	char	*read;

// 	*arr = NULL;
// 	while (true)
// 	{
// 		msg = ft_get_next_line(fd, &read);
// 		if (msg == -1)
// 		{
// 			ft_arr_free(*arr, free);
// 			break ;
// 		}
// 		if (msg == 0)
// 		{
// 			ft_arr_push(arr, read);
// 			break ;
// 		}
// 		if (msg == 1)
// 			ft_arr_push(arr, read);
// 	}
// }

// char	**ft_split_file(const char *filename, size_t *num_lines)
// {
// 	int		fd;
// 	t_arr	*arr;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	push_lines(&arr, fd);
// 	return ((char **)ft_arr_concat(arr, num_lines));
// }

char	**ft_split_file(const char *filename, size_t *num_lines)
{
	char	*content;
	char	**split;

	content = ft_readfile(filename);
	if (content == NULL)
		return (NULL);
	split = ft_split_length(content, '\n', num_lines);
	free(content);
	return (split);
}
