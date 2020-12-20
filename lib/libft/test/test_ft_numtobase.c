/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_numtobase.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 18:40:38 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/01 18:58:43 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char *num;

	num = ft_numtobase(255, "01");
	ft_putstr_fd(num, 1);
	return (0);
}
