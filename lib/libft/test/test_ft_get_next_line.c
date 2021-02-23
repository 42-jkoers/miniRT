/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_get_next_line.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 13:22:23 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 13:46:04 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test/test_ft_get_next_line.c", O_RDONLY);
	while (ft_get_next_line(fd, &line) == 1)
		free(line);
	close(fd);
	return (0);
}
