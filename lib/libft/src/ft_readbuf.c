/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_buf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 21:39:17 by jkoers        #+#    #+#                 */
/*   Updated: 2021/03/12 21:39:17 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal.h"
#include <stdlib.h>

#define STARTBLOCKS 64

void	ft_buf_init(t_readbuf *buf, size_t block_size, int fd)
{
	buf->blocks = malloc(STARTBLOCKS * sizeof(t_block));
	buf->block_size = block_size;
	buf->n_blocks = 0;
	buf->size = 0;
	buf->fd = fd;
}

static void	buf_grow(t_readbuf *buf)
{
	buf->blocks = ft_realloc(
			buf->blocks,
			buf->n_blocks * sizeof(t_block),
			buf->n_blocks * 2 * sizeof(t_block));
}

// @return bytes read by std::read()

ssize_t	ft_buf_read(t_readbuf *buf)
{
	t_block	*current;

	if (buf->n_blocks >= STARTBLOCKS && is_power_of_2u(buf->n_blocks))
		buf_grow(buf);
	current = &buf->blocks[buf->n_blocks];
	current->content = ft_malloc(buf->block_size);
	current->written = read(buf->fd, current->content, buf->block_size);
	if (current->written > 0)
		buf->size += current->written;
	buf->n_blocks += 1;
	return (current->written);
}

char	*ft_buf_merge(t_readbuf	*buf)
{
	char	*merged;
	size_t	i;
	size_t	offset;
	t_block	*curr;

	merged = ft_malloc(buf->size + 1);
	i = 0;
	offset = 0;
	while (i < buf->n_blocks)
	{
		curr = &buf->blocks[i];
		if (curr->written > 0)
		{
			ft_memcpy(merged + offset, curr->content, curr->written);
			offset += curr->written;
		}
		i++;
	}
	merged[buf->size] = '\0';
	ft_buf_free(buf);
	return (merged);
}

void	ft_buf_free(t_readbuf *buf)
{
	if (buf == NULL || buf->blocks == NULL)
		return ;
	while (buf->n_blocks > 0)
	{
		buf->n_blocks -= 1;
		free(buf->blocks[buf->n_blocks].content);
	}
	free(buf->blocks);
	close(buf->fd);
	buf->blocks = NULL;
}
