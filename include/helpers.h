/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:59:25 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/20 22:11:22 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

typedef struct	s_rgb
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_rgb;

void	exit_error(const char *format, ...);
int 	rgbtoint(t_rgb *rgb);

#endif
