/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 18:16:05 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/07 18:16:05 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

/*
** README
** This the settings file for the miniRT project.
** After changing a setting you of course have to recompile with make re
** answer to.
*/

/*
** Bool: Enable verbose logging? :boolean
*/
# define VERBOSE 0

/*
** Allow non-normalized direction vector in .rt file? :boolean
** The vector will still be normalized before internal use.
*/
# define ALLOW_ABNORMAL_DIR 0

/*
** When reading the rt file, only allow a window resolution that is <= than the
** display resolution? :boolean
** This max resolution is always ignored when exporting a bmp file.
*/
# define MAX_WINDOW_SIZE 0

/*
** Count rules to check for duplicates or missing? :boolean
** For example: when enabled the R (resolution) rule can only exist once
*/
# define COUNT_RULES 1

/*
** Allow comments (line prefixed by #) .rt file? :boolean
*/
# define ALLOW_RT_COMMENTS 1

/*
** Fulfill stupid assignment requirements? :boolean
*/
# define STUPID 0

# define NEXT_CAMERA_KEY 0x0063

/*
** Enable multithreading? :boolean
*/
# define ENABLE_MULTITHREADING 1

/*
** What number of threads should the program use? :unsigned int [1 n]
*/
# define THREADS 7

/*
**  :boolean
*/
# define DISABLE_ANTI_ALIASING 1

/*
**  :unsigned int --> 1, 4, 16, 32, ect
*/
# define ANTI_ALIASING_LEVEL 4

#endif
