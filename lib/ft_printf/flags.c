/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:39:47 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/30 17:46:55 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

static size_t	set_flags(t_special *sp, char *format)
{
	const char	*flags = "0-";
	size_t		i;

	i = 0;
	while (flags[i])
	{
		sp->flag[(int)flags[i]] = false;
		i++;
	}
	i = 0;
	while (ft_includes((char *)flags, format[i]))
	{
		sp->flag[(int)format[i]] = true;
		i++;
	}
	if (sp->flag[(int)'-'])
		sp->flag[(int)'0'] = false;
	return (i);
}

/*
** Range -1 --> MAX
** Sets -1 if unknown
** When "%.s" field_width = unknown
** When "%*s" * = field width
*/

static size_t	set_field_width(t_special *sp, va_list ap, char *format)
{
	size_t	i;

	sp->field_width = -1;
	if (format[0] == '*')
	{
		sp->field_width = (long)(va_arg(ap, int));
		if (sp->field_width < 0)
		{
			sp->field_width = -(sp->field_width);
			sp->flag[(int)'-'] = true;
			sp->flag[(int)'0'] = false;
		}
		return (1);
	}
	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i != 0)
		sp->field_width = (long)ft_strtonum_u(format);
	return (i);
}

/*
** Range -1 --> MAX
** Sets -1 if unknown
** When "%.s" precision = 0
** precision < 0 ? precision = unknown
*/

static size_t	set_precision(t_special *sp, va_list ap, char *format)
{
	size_t i;

	sp->precision = -1;
	if (format[0] != '.')
		return (0);
	if (format[1] == '*')
	{
		sp->precision = ft_max((long)(va_arg(ap, int)), -1);
		return (2);
	}
	i = 1;
	while (ft_isdigit(format[i]))
		i++;
	sp->precision = ft_strtonum(format + 1);
	sp->flag[(int)'0'] = false;
	return (i);
}

static size_t	set_res(t_special *sp, va_list ap, char *percent, char *format)
{
	if (format[0] == '%')
		do_percent(sp, format);
	else if (format[0] == 'c')
		c(sp, va_arg(ap, int));
	else if (format[0] == 's')
		s(sp, va_arg(ap, char *));
	else if (format[0] == 'p')
		p(sp, va_arg(ap, void *));
	else if (format[0] == 'i' || format[0] == 'd')
		i(sp, va_arg(ap, int));
	else if (format[0] == 'u')
		u(sp, va_arg(ap, unsigned int));
	else if (format[0] == 'x' || format[0] == 'X')
		x(sp, va_arg(ap, unsigned int), format[0] == 'X');
	else
		invalid(sp, percent, format);
	return (format[0] == '\0' ? 0 : 1);
}

/*
** Returns length of all flags and percent (%-5d) --> 4
*/

size_t			set_special(t_special *sp, va_list ap, char *percent)
{
	size_t	len;

	len = 1;
	len += set_flags(sp, percent + len);
	len += set_field_width(sp, ap, percent + len);
	len += set_precision(sp, ap, percent + len);
	len += set_res(sp, ap, percent, percent + len);
	return (len);
}

/*
** void	print_special(t_special *sp)
** {
** 	printf("\n");
** 	printf("Flag 0      %i\n", sp->flag[(int)'0']);
** 	printf("Flag -      %i\n", sp->flag[(int)'-']);
** 	printf("field_width %li\n", sp->field_width);
** 	printf("precision   %li\n", sp->precision);
** }
*/
