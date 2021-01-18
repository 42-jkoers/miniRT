/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 16:39:11 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 14:29:00 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "practice.h"
#include "ray.h"
#include "vector.h"

#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	t_gui *gui;

	setvbuf(stdout, NULL, _IONBF, 0);
	gui = gui_init("rt/standard.rt", false);

	clock_t tic = clock(); 
	render(gui);
	clock_t toc = clock();
	printf("render in: %lf s\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	if (save_bmp(gui) != 0)
		exit_errno("Can't create bmp");
	// log_vec3("cam", gui->camera->origin);
	// mlx_loop(gui->mlx);
	exit_success(gui);
	return (0);
}
