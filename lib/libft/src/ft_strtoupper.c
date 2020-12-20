/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:58:59 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 13:06:03 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtoupper(char *s)
{
	while (*s != '\0')
	{
		*s = (char)ft_toupper((int)*s);
		s++;
	}
}
