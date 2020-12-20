/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_padend.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 15:05:45 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/18 23:19:57 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	ft_padend(char **str, size_t target_len, char pad)
{
	char	*res;
	size_t	strlen;

	strlen = ft_strlen(*str);
	if (strlen >= target_len)
		return ;
	res = malloc((target_len + 1) * sizeof(char));
	if (res == NULL)
		return ;
	ft_memcpy(res, *str, strlen * sizeof(char));
	ft_memset(res + strlen, pad, (target_len - strlen) * sizeof(char));
	res[target_len] = '\0';
	free(*str);
	*str = res;
}
