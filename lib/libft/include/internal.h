/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   internal.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 23:01:34 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/25 18:01:20 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include <stddef.h>
# include <unistd.h>

/*
** ft_get_next_line
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct		s_buf
{
	char			*data;
	ssize_t			size;
	ssize_t			start;
	struct s_buf	*next;
}					t_buf;
void				*ft_memcpy(void *dest, void *src, size_t n);
void				shift(t_buf **fd);
t_buf				*new_buf(size_t size);

/*
** ft_arr_ family
*/
# ifndef ARR_DEFAULT_SIZE
#  define ARR_DEFAULT_SIZE 10
# endif

#endif
