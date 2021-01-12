/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file_helpers.c                                  :+:    :+:            */
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

void	set_point(t_vec3 *origin, char *str)
{
	if (ft_strcount(str, ',') != 2)
		exit_e("Wrong number of args in point");
	origin->x = strtodbl_clamp(str, ',', DOUBLE_MIN, DOUBLE_MAX);
	str = ft_strchr(str, ',') + 1;
	origin->y = strtodbl_clamp(str, ',', DOUBLE_MIN, DOUBLE_MAX);
	str = ft_strchr(str, ',') + 1;
	origin->z = strtodbl_clamp(str, '\0', DOUBLE_MIN, DOUBLE_MAX);
}

void	set_color(t_rgb *color, char *str)
{
	if (ft_strcount(str, ',') != 2)
		exit_e("Wrong number of args in color");
	color->r = (unsigned char)strtonum_clamp(str, ',', 0, 255);
	str = ft_strchr(str, ',') + 1;
	color->g = (unsigned char)strtonum_clamp(str, ',', 0, 255);
	str = ft_strchr(str, ',') + 1;
	color->b = (unsigned char)strtonum_clamp(str, '\0', 0, 255);
}
