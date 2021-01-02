/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 19:27:08 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/02 22:44:32 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
# include <X11/keysymdef.h>
# include <X11/keysym.h>

# define VERBOSE 1

#define ClientMessage 33
#define NoEventMask 0L

/*
** RT rules
*/
typedef enum
{
	SHAPE_SPHERE,
	SHAPE_PLANE,
	SHAPE_SQUARE,
	SHAPE_CYLINDER,
	SHAPE_TRIANGLE,
	SHAPE_LAST
}	e_shape;

typedef enum
{
	RULE_SPHERE,
	RULE_PLANE,
	RULE_SQUARE,
	RULE_CYLINDER,
	RULE_TRIANGLE,
	RULE_RESOLUTION,
	RULE_LAST
}	e_rule;

extern char *g_rule_id[RULE_LAST];

extern char *g_rule_name[RULE_LAST];

#define	DOUBLE_MAX 9999999999.0

typedef enum	s_msg
{
	SUCCESS,
	ERR_USELESS,
	ERR_MALLOC,
	ERR_MLXINIT,
	ERR_RT_NOTFOUND,
	ERR_RT_EMPTY,
	ERR_RT_INVALID,
	BADRULE,
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

#endif
