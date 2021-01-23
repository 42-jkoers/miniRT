/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file_set.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 15:43:37 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 15:43:37 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_rt.h"
#include "constants.h"
#include "../lib/libft/include/libft.h"
#include "vector.h"
#include <stdlib.h>

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

void	set_orientation(t_vec3 *orientation, char *str)
{
	double len;

	if (ft_strcount(str, ',') != 2)
		exit_e("Wrong number of args in orientation");
	orientation->x = strtodbl_clamp(str, ',', -1.0, 1.0);
	str = ft_strchr(str, ',') + 1;
	orientation->y = strtodbl_clamp(str, ',', -1.0, 1.0);
	str = ft_strchr(str, ',') + 1;
	orientation->z = strtodbl_clamp(str, '\0', -1.0, 1.0);
	if (!ALLOW_ABNORMAL_DIR)
	{
		len = length(*orientation);
		if (len < 0.99999 || len > 1.00001)
			exit_e("Orientation vector is not normalized");
	}
	normalize(orientation); // ???
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
