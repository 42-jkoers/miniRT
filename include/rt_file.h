/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 13:47:29 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/30 18:59:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FILE_H
# define RT_FILE_H

# include "gui.h"
# include "constants.h"

e_msg	parse_rt(char *rt_filename, t_gui *gui);

#endif
