/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:16 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/17 13:03:34 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "constants.h"

t_gui	*gui_init(const char *rt_filename, bool create_window);
char	*gui_get_pixel_data(const t_gui *gui, unsigned x, unsigned y);
void	gui_set_pixel(t_gui *gui, unsigned x, unsigned y, t_rgb color);
t_rgb	gui_get_pixel(t_gui *gui, unsigned x, unsigned y);
void	gui_write_canvas(t_gui *gui);
void	gui_display_scene(t_gui *gui);
void	gui_render_next_camera(t_gui *gui);
void	exit_success(t_gui *gui);
int		save_bmp(const t_gui *gui);

#endif
