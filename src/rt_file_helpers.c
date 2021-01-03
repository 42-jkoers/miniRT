/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file_helpers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 16:53:53 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/03 13:31:00 by jkoers        ########   odam.nl         */
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

e_msg	rt_unexpected_char(char got, char expected)
{
	printf("Expected <%c>, got <%c>\n", got, expected); // illegal
	return (ERR_RT_UNEXPECTED_CHAR);
}

e_msg	strtonum_clamp(long *result, char *str, char end, long min, long max)
{
	size_t	i;
	long	num;
	
	if (str[0] == '\0')
		return (rt_unexpected_char(str[0], '\0'));
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		return (rt_unexpected_char(str[i], end));
	num = ft_strtonum(str);
	if (num > max || num < min)
	{
		printf("double %li not in range %li - %li", num, min, max); // illegal
		return (ERR_RT_BADVALUE);
	}
	*result = num;
	return (SUCCESS);	
}

e_msg	strtodbl_clamp(double *result,
	char *str, char end, double min, double max)
{
	size_t	i;
	double	num;
	
	if (str[0] == '\0')
		return (rt_unexpected_char(str[0], '\0'));
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.') // is a double without a . allowed?
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		return (rt_unexpected_char(str[i], end));
	num = ft_strtodbl(str);
	if (num > max || num < min)
	{
		printf("double %lf not in range [%lf - %lf]", num, min, max); // illegal
		return (ERR_RT_BADVALUE);
	}
	*result = num;
	return (SUCCESS);
}

e_msg	split_clamp(char ***result, char *line, size_t should_be_n)
{
	size_t	n_params;
	char	**params;

	*result = NULL;
	params = ft_split_length(line, ' ', &n_params);
	if (params == NULL)
		return (ERR_MALLOC);
	if (n_params != should_be_n)
	{
		ft_free_until_null_char(params);
		printf("Wrong number of args, expected %lu, got %lu\n",
			should_be_n, n_params); // illegal
		return (ERR_RT_NUMARGS);
	}
	*result = params;
	return (SUCCESS);
}

e_msg	set_point(t_point *origin, char *str)
{
	if (ft_strcount(str, ',') != 2)
		return (ERR_RT_NUMARGS);
	if (strtodbl_clamp(&origin->x, str, ',', DOUBLE_MIN, DOUBLE_MAX) != SUCCESS)
		return (ERR_RT_BADVALUE);
	str = ft_strchr(str, ',') + 1;
	if (strtodbl_clamp(&origin->y, str, ',', DOUBLE_MIN, DOUBLE_MAX) != SUCCESS)
		return (ERR_RT_BADVALUE);
	str = ft_strchr(str, ',') + 1;
	return (strtodbl_clamp(&origin->z, str, '\0', DOUBLE_MIN, DOUBLE_MAX));
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
