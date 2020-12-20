/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_padstart.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 15:05:45 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/18 23:19:52 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_padstart(char **str, size_t target_len, char pad)
{
	char	*res;
	size_t	strlen;

	strlen = ft_strlen(*str);
	if (strlen >= target_len)
		return ;
	res = malloc((target_len + 1) * sizeof(char));
	if (res == NULL)
		return ;
	ft_memset(res, pad, (target_len - strlen) * sizeof(char));
	ft_memcpy(res + (target_len - strlen), *str, strlen * sizeof(char));
	res[target_len] = '\0';
	free(*str);
	*str = res;
}
