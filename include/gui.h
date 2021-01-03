/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:16 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/03 00:35:32 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "../lib/libft/include/libft.h"
# include "constants.h"
# include "rt_file_helpers.h"

typedef struct  s_canvas
{
    void        *mlx_img;
    char        *data;
    int         bpp;
    int         line_length;
    int         byte_order;
}               t_canvas;

typedef struct	s_ambient
{
	double		brightness;
	t_rgb		color;
}				t_ambient;

typedef struct	s_camera
{
	t_point		origin;
	t_point		orientation;
	double		fov;
}				t_camera;

typedef struct	s_light
{
	t_point		origin;
	t_point		orientation;
	double		brightness;
	t_rgb		color;
}				t_light;

typedef struct	s_gui
{
	void			*mlx;
	void			*window;
	unsigned long	x_size;
	unsigned long	y_size;
	t_ambient		ambient;
	t_arr_voidp		*cameras;
	t_arr_voidp		*lights;
	t_arr_voidp		*shapes;
	t_canvas		canvas;
}				t_gui;

t_gui	*gui_init(char *rt_filename);
void	gui_write_canvas(t_gui *gui);
void	gui_set_pixel(t_gui *gui, unsigned long x, unsigned long y, int color);

#endif
