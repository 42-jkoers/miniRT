/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/30 17:03:34 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

static ssize_t	write_result(t_special *sp, int fd)
{
	ssize_t written;
	long	padding;

	if (sp->len > 0 &&
		sp->flag[(int)'-'] &&
		write(fd, sp->res, sp->len) != (ssize_t)sp->len)
		return (-1);
	padding = ft_max(sp->field_width - (long)sp->len, 0);
	written = (ssize_t)padding;
	while (padding > 0)
	{
		padding--;
		if (write(fd, " ", 1) != 1)
			return (-1);
	}
	if (sp->len > 0 &&
		!sp->flag[(int)'-'] &&
		write(fd, sp->res, sp->len) != (ssize_t)sp->len)
		return (-1);
	written += (ssize_t)sp->len;
	return (written);
}

/*
** Returns length of all flags and percent (%-5d) --> 4
** Returns -1 on error
*/

static size_t	do_special(char *percent, va_list ap, ssize_t *total, int fd)
{
	t_special	sp;
	size_t		conversion_len;
	ssize_t		written;

	conversion_len = set_special(&sp, ap, percent);
	if (sp.len > 0 && sp.res == NULL)
	{
		*total = -1;
		return (0);
	}
	written = write_result(&sp, fd);
	*total = written == -1 ? -1 : *total + written;
	if (sp.free)
		free(sp.res);
	return (conversion_len);
}

static ssize_t	print(char *format, va_list ap, int fd)
{
	char		*percent;
	ssize_t		total_written;
	ssize_t		remainder;

	percent = ft_strchr(format, '%');
	total_written = 0;
	while (percent && total_written != -1)
	{
		remainder = (ssize_t)(percent - format);
		if (remainder > 0 && write(fd, format, remainder) != remainder)
			return (-1);
		total_written += remainder;
		format = percent + do_special(percent, ap, &total_written, fd);
		percent = ft_strchr(format, '%');
	}
	remainder = ft_strlen(format);
	if (remainder > 0 && write(fd, format, remainder) != remainder)
		return (-1);
	total_written += remainder;
	return (total_written);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		len;

	va_start(ap, format);
	len = print((char *)format, ap, 1);
	va_end(ap);
	return ((int)len);
}
