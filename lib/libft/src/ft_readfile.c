/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 18:49:52 by jkoers        #+#    #+#                 */
/*   Updated: 2021/03/12 18:49:52 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal.h"
#include <fcntl.h>
#include <stdlib.h>

char	*ft_readfile(const char *filename)
{
	t_readbuf	buf;
	int			fd;
	ssize_t		read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ft_buf_init(&buf, BUFFER_SIZE, fd);
	while (true)
	{
		read = ft_buf_read(&buf);
		if (read < 0)
		{
			ft_buf_free(&buf);
			return (NULL);
		}
		if (read == 0)
			break ;
	}
	return (ft_buf_merge(&buf));
}
