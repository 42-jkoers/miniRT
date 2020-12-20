/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_numlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:41:03 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/01 00:17:56 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("%lu 4\n", ft_numlen(1000, 10));
	printf("%lu 8\n", ft_numlen(255, 2));
	printf("%lu 3\n", ft_numlen(4, 2));
	printf("%lu 1\n", ft_numlen(0, 2));
	printf("\n");
	printf("%lu 4\n", ft_numlen(-123, 10));
	printf("%lu 9\n", ft_numlen(-255, 2));
	printf("%lu 4\n", ft_numlen(-4, 2));
	printf("%lu 1\n", ft_numlen(-0, 2));
	printf("\n");
	printf("%lu 3\n", ft_numlen(-255, 16));
	printf("%lu 2\n", ft_numlen(255, 16));
	printf("%lu 1\n", ft_numlen(0, 16));
	return (0);
}
