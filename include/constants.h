/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 19:27:08 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/31 00:36:12 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#ifndef CONSTANTS_H
# define CONSTANTS_H
# include <X11/keysymdef.h>
# include <X11/keysym.h>

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

typedef enum	s_msg
{
	SUCCESS,
	ERR_MALLOC,
	ERR_MLXINIT,
	ERR_RT_NOTFOUND,
	ERR_RT_EMPTY,
	ERR_RT_INVALID,
	ERR_RT_BADRULE,
	ERR_RT_NUMARGS,
	ERR_RT_BADVALUE,
	ERR_RT_UNKNOWN_RULE,
	ERR_RT_UNEXPECTED_CHAR,
	ERR_RT_UNEXPECTED_EOL,
	ERR_CANVAS_CREATEIMG,
	ERR_MLX_INIT,
	ERR_WINDOW_CREATE,
	MSG_LAST
}				e_msg;

static const char *g_joppe_strerror[MSG_LAST] =
{
	"Done\n",
	"Malloc failed\n",
	"Failed to init mlx\n",
	"Rt file not found\n",
	"Rt file is empty\n",
	"Rt file is invalid\n",
	"Rt rule is invalid\n"
	"Rt rule has wrong number of arguments\n",
	"Rt rule has illegal value\n",
	"Unknow rt rule\n",
	"Unexpected character\n",
	"Unexpected end of line\n",
	"Failed to create mlx image for canvas\n",
	"Mlx init failed\n",
	"Cannot create window\n"
};

#endif
