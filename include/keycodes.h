/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keycodes.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 19:27:08 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 20:23:23 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

/*
** MLX internal
*/
enum MLX_KEYCODES
{
	MLXKEY_ESC = 65307
};
#define ClientMessage 33
#define NoEventMask 0L

/*
** RT rules
*/
#define RULE_RESOLUTION	"R"
#define RULE_SPHERE		"sp"
#define RULE_PLANE		"pl"
#define RULE_SQUARE 	"sq"
#define RULE_CYLINDER	"cy"
#define RULE_TRIANGLE	"tr"

#define	DOUBLE_MAX 9999999999.0

#endif
