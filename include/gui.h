/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:16 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/20 19:47:48 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct		s_gui
{
	void			*mlx;
	void			*window;
	unsigned long	x_size;
	unsigned long	y_size;
	unsigned long	fov_deg;
}					t_gui;

t_gui	init_gui(void);
void	destroy_gui(t_gui *gui);

#endif
