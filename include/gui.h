/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:16 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 18:59:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

typedef struct  s_canvas {
    void        *mlx_img;
    char        *data;
    int         bpp;
    int         line_length;
    int         byte_order;
}               t_canvas;

typedef struct		s_gui
{
	void			*mlx;
	void			*window;
	unsigned long	x_size;
	unsigned long	y_size;
	unsigned long	fov_deg;
	t_canvas		canvas;
}					t_gui;

t_gui	*gui_init(char *rt_filename);
void	gui_write_canvas(t_gui *gui);
void	gui_set_pixel(t_gui *gui, unsigned long x, unsigned long y, int color);

#endif
