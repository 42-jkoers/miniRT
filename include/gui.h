/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:16 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/05 20:47:23 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "../lib/libft/include/libft.h"
# include "constants.h"
# include "rt_file_helpers.h"

t_gui	*gui_init(char *rt_filename);
void	gui_write_canvas(t_gui *gui);
void	gui_set_pixel(t_gui *gui, unsigned long x, unsigned long y, int color);

#endif
