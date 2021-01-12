/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 14:14:39 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:19:48 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

#include "constants.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>

static const size_t	g_header_size = 54;

static size_t		bmp_size(size_t x, size_t y)
{
	if ((x * 3) % 4 != 0)
		x = x + 4 - ((x * 3) % 4);
	return (g_header_size + (3 * y * x));
}

/*
** HEADER
** Position | Hex	| Description
** 00		| 00	| TYPE OF BMP FILE
** 02		| 02	| TOTAL SIZE OF FILE
** 06-08	| 06-08	| RESERVED TO SIGN
** 10		| 0A	| HEADER SIZE
** 14		| 0E	| HEADER INFOS SIZE
** 18		| 12	| WIDTH OF IMG (PX)
** 22		| 16	| HEIGHT OF IMG (PX)
** 26		| 1A	| NUMBER OF PLANS
** 28		| 1C	| BITS PER PIXELS (1 - 4 - 8 - 24)
** 30		| 1E	| COMPRESSION TYPE
** 34		| 22	| SIZE OF IMG
** 38		| 26	| RES X PX PER METER
** 42		| 2A	| RES Y PX PER METER
** 46		| 2E	| NB OF USED COLOR (0 = MAX)
** 50		| 32	| NB OF INDEX OF COLOR (0 = ALL)
*/

static void			header(
	uint8_t *buf, uint32_t x, uint32_t y, uint32_t file_size)
{
	*((uint8_t *)&buf[0]) = (uint8_t)0x42;
	*((uint8_t *)&buf[1]) = (uint8_t)0x4D;
	*((uint32_t *)&buf[2]) = (uint32_t)file_size;
	*((uint32_t *)&buf[10]) = (uint32_t)g_header_size;
	*((uint32_t *)&buf[14]) = (uint32_t)0x28;
	*((uint32_t *)&buf[18]) = (uint32_t)x;
	*((uint32_t *)&buf[22]) = (uint32_t)y;
	*((uint16_t *)&buf[26]) = (uint16_t)0x01;
	*((uint16_t *)&buf[28]) = (uint16_t)0x18;
}

static void			write_image(uint8_t *buf, const t_gui *gui)
{
	unsigned long	buf_i;
	unsigned long	x;
	unsigned long	y;

	buf_i = g_header_size;
	y = gui->y_resolution;
	while (y > 0)
	{
		y--;
		x = 0;
		while (x < gui->x_resolution)
		{
			ft_memcpy(buf + buf_i, gui_get_pixel_data(gui, x, y), 3);
			buf_i += 3;
			x++;
		}
		if ((gui->x_resolution * 3) % 4 != 0)
			buf_i += 4 - (gui->x_resolution * 3) % 4;
	}
}

int				save_bmp(const t_gui *gui)
{
	uint8_t	*buf;
	int		fd;
	size_t	file_size;

	fd = open("scene.bmp", O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		return (-1);
	file_size = bmp_size(gui->x_resolution, gui->y_resolution);
	buf = ft_calloc(1, file_size);
	if (buf == NULL)
		exit_e("malloc");
	header(buf, gui->x_resolution, gui->y_resolution, file_size);
	write_image(buf, gui);
	if (write(fd, buf, file_size) != (ssize_t)file_size)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	if (close(fd) < 0)
		return (-1);
	return (0);
}
