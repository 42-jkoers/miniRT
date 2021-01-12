/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 16:39:11 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 13:51:56 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "practice.h"
#include "ray.h"

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int		main(void)
{
	t_gui *gui;

	gui = gui_init("rt/standard.rt", WINDOW);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t tic = clock(); 
	render(gui);
	clock_t toc = clock();
	printf("render in: %lf\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	if (save_bmp(gui) != 0)
		exit_errno("Failed to create bmp file");
	exit_success(gui);
	return (0);
}
