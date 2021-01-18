/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 16:53:53 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:15:10 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_rt.h"
#include "constants.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>

long	strtonum_clamp(char *str, char end, long min, long max)
{
	size_t	i;
	long	num;
	
	if (str[0] == '\0')
		exit_char(str[0], '\0');
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		exit_char(str[i], end);
	num = ft_strtonum(str);
	if (num > max || num < min)
		exit_range(num, min, max);
	return (num);	
}

double	strtodbl_clamp(char *str, char end, double min, double max)
{
	size_t	i;
	double	num;
	
	if (str[0] == '\0')
		exit_char(str[0], '\0');
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.') // is a double without a . allowed?
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		exit_char(str[i], end);
	num = ft_strtodbl(str);
	if (num > max || num < min)
		exit_ranged(num, min, max);
	return (num);
}

char	**split_clamp(char *line, size_t should_be_n)
{
	size_t	n_params;
	char	**params;
	
	params = ft_split_length(line, ' ', &n_params);
	if (params == NULL)
		exit_e("malloc");
	if (n_params != should_be_n)
		exit_range(n_params, should_be_n, should_be_n);		
	return (params);
}
