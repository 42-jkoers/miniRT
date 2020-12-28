/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 13:47:29 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 21:44:03 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FILE_H
# define RT_FILE_H

# include "gui.h"

void	set_rt(t_gui *gui, const char *rt_filename);
long	strtonum(t_gui *gui, char *str, char end, long min, long max);

#endif
