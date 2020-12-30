/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file_helpers.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 16:54:50 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/31 00:29:06 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FILE_HELPERS_H
# define RT_FILE_HELPERS_H

# include "gui.h"
# include "constants.h"

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
}				t_point;

e_msg	strtonum_clamp(long *result, char *str, char end, long min, long max);
e_msg	strtodbl_clamp(double *result, char *str, char end, double min, double max);
e_msg	split_clamp(char ***result, char *line, size_t should_be_n);
e_msg	set_point(t_point *origin, char *str);
e_msg	set_color(t_rgb *color, char *str);
int		rgbtoint(t_rgb *rgb);

#endif
