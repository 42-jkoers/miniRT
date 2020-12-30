/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file_helpers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 16:53:53 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/31 00:45:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "shapes.h"
#include "constants.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

e_msg	strtonum_clamp(long *result, char *str, char end, long min, long max)
{
	size_t	i;
	long	num;
	
	if (str[0] == '\0')
		return (ERR_RT_UNEXPECTED_CHAR);
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		return (ERR_RT_UNEXPECTED_CHAR);
	num = ft_strtonum(str);
	if (num > max || num < min)
		return (ERR_RT_BADVALUE);
	*result = num;
	return (SUCCESS);	
}

e_msg	strtodbl_clamp(double *result, char *str, char end, double min, double max)
{
	size_t	i;
	double	num;
	
	if (str[0] == '\0')
		return (ERR_RT_UNEXPECTED_CHAR);
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.') // is a double without a . allowed?
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		return (ERR_RT_UNEXPECTED_CHAR);
	num = ft_strtodbl(str);
	if (num > max || num < min)
		return (ERR_RT_BADVALUE);
	*result = num;
	return (SUCCESS);
}

e_msg	split_clamp(char ***result, char *line, size_t should_be_n)
{
	size_t	n_params;
	char	**params;

	params = ft_split_length(line, ' ', &n_params);
	if (params == NULL)
		return (ERR_MALLOC);
	if (n_params != should_be_n)
	{
		ft_free_until_null_char(params);
		return (ERR_RT_NUMARGS);
	}
	*result = params;
	return (SUCCESS);
}

e_msg	set_point(t_point *origin, char *str)
{
	if (ft_strcount(str, ',') != 2)
		return (ERR_RT_NUMARGS);
	if (strtodbl_clamp(&origin->x, str, ',', 0.0, DOUBLE_MAX) != SUCCESS)
		return (ERR_RT_BADVALUE);
	str = ft_strchr(str, ',') + 1;
	if (strtodbl_clamp(&origin->y, str, ',', 0.0, DOUBLE_MAX) != SUCCESS)
		return (ERR_RT_BADVALUE);
	str = ft_strchr(str, ',') + 1;
	return (strtodbl_clamp(&origin->z, str, '\0', 0.0, DOUBLE_MAX));
}

e_msg	set_color(t_rgb *color, char *str)
{
	if (ft_strcount(str, ',') != 2)
		return (ERR_RT_NUMARGS);
	if (strtonum_clamp((long *)(&color->r), str, ',', 0, 255) != SUCCESS)
		return (ERR_RT_BADVALUE);
	str = ft_strchr(str, ',') + 1;
	if (strtonum_clamp((long *)(&color->g), str, ',', 0, 255) != SUCCESS)
		return (ERR_RT_BADVALUE);
	str = ft_strchr(str, ',') + 1;
	return (strtonum_clamp((long *)(&color->b), str, '\0', 0, 255));
}

int		rgbtoint(t_rgb *rgb)
{
	int res;
	
	res = 0;
	res |= (int)(rgb->r) << 16;
	res |= (int)(rgb->g) << 8;
	res |= (int)(rgb->b) << 0;
	return (res);
}
