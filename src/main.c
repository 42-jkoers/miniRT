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

#include "gui.h"
#include "constants.h"
#include "ray.h"
#include "../lib/libft/include/libft.h"
#include <string.h>
#include <errno.h>

int	main(int argc, const char *argv[])
{
	t_gui	gui;

	if (argc == 3 && ft_strcmp((char *)argv[2], "--save") == 0)
	{
		gui_init(&gui, argv[1], false);
		render(&gui);
		if (save_bmp(&gui) != 0)
			exit_e(strerror(errno));
		exit_success(&gui);
	}
	else if (argc == 2)
	{
		gui_init(&gui, argv[1], true);
		exit_success(&gui);
	}
	else
		exit_e("Usage: minirt [.rt file] [--save]\n");
	return (0);
}
