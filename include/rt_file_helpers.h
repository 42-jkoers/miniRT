/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file_helpers.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 16:54:50 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/06 00:29:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FILE_HELPERS_H
# define RT_FILE_HELPERS_H

# include "gui.h"
# include "constants.h"

long	strtonum_clamp(char *str, char end, long min, long max);
double	strtodbl_clamp(char *str, char end, double min, double max);
char	**split_clamp(char *line, size_t should_be_n);
void	set_point(t_vec3 *origin, char *str);
void	set_color(t_rgb *color, char *str);
int		rgbtoint(t_rgb *rgb);
void	verbose(char *str);
void	trace(char *str);

#endif
