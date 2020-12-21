/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 16:39:11 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/21 16:44:01 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "helpers.h"
#include "practice.h"

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int		main(void)
{
	t_gui gui;

	gui = init_gui();
	ft_printf("Init done\n");
	clock_t begin = clock();
	fill_random(&gui);
	printf("%f s\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	// mlx_loop(gui.mlx);
	// sleep(10);
	destroy_gui(&gui);
	return (0);
}
