/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:17:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/05 15:44:36 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void			ft_itoa_buf(int n, char *buf)
{
	unsigned long	len;
	unsigned long	is_negative;

	len = (unsigned long)ft_numlen(n, 10);
	is_negative = (unsigned long)(n < 0 ? 1 : 0);
	if (is_negative)
		buf[0] = '-';
	buf[len] = '\0';
	while (len > is_negative)
	{
		len--;
		buf[len] = (char)(ft_abs(n % 10) + '0');
		n /= 10;
	}
}

void				ft_putnbr_fd(int n, int fd)
{
	char buf[22];

	ft_itoa_buf(n, buf);
	ft_putstr_fd(buf, fd);
}
