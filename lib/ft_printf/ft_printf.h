/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 02:19:33 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/01 14:02:06 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# ifdef __APPLE__
#  define APPLE true
# else
#  define APPLE false
# endif

int					ft_printf(const char *format, ...);

// ft_printf("value = %05i", 42)
// value = 00042
/*
** This struct is assigned for every converstion (eg. %c), often defined as sp
** @param flag			This stores all flags at index. Access: sp.flag['-']
** @param field_width	-1 if unknown
** @param precision		-1 if unknown
** @param res			Pointer to the result of the conversion.
**						NULL when malloc fails.
**						Garbage if conversion has length 0.
** @param len			0 if there is no conversion to be done.
**						Number of chars to print from res
** @param free			If res should be freed after writing.
*/
typedef	struct		s_special
{
	bool			flag[127];
	long			field_width;
	long			precision;
	char			*res;
	size_t			len;
	bool			free;
}					t_special;

size_t				set_special(t_special *sp, va_list ap, char *percent);
void				do_percent(t_special *sp, char *format);
void				c(t_special *sp, int c);
void				s(t_special *sp, char *s);
void				i(t_special *sp, long i);
void				u(t_special *sp, unsigned long u);
void				x(t_special *sp, unsigned long x, bool uppercase);
void				p(t_special *sp, void *p);
void				invalid(t_special *sp, char *percent, char *format);

#endif
