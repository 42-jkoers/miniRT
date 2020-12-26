/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_split_file.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 18:35:24 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 13:20:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(void)
{
	char	**lines;
	size_t	i;
	size_t	num_lines;

	lines = ft_split_file("test/test_ft_split_file.c", &num_lines);
	if (lines == NULL)
	{
		ft_putstr("Failed\n");
		return (1);
	}
	i = 0;
	while (i < num_lines)
	{
		printf("> %s\n", lines[i]);
		i++;
	}
	ft_free_2d((void **)lines, i);
	return (0);
}
