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
#include <string.h>
#include <errno.h>

void	time_render(t_gui *gui)
{
	clock_t tic = clock();
	render(gui);
	clock_t toc = clock();
	printf("render in: %lf s\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}

int		main(int argc, const char *argv[])
{
	t_gui	*gui;

	if (argc == 3 && ft_strcmp((char *)argv[2], "--save") == 0)
	{
		gui = gui_init(argv[1], false);
		time_render(gui);
		if (save_bmp(gui) != 0)
			exit_e(strerror(errno));
		exit_success(gui);
	}
	else if (argc == 2)
	{
		gui = gui_init(argv[1], true);
		exit_success(gui);
	}
	else
		printf("Invalid args\n");
	return (0);
}
