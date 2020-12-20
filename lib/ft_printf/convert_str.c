/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/30 17:46:28 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	do_percent(t_special *sp, char *format)
{
	if (APPLE)
	{
		if (sp->field_width > 1 && sp->flag[(int)'0'])
		{
			sp->res = ft_numtostr_precision_u(1, sp->field_width);
			if (sp->res != NULL)
				sp->res[sp->field_width - 1] = '%';
			sp->len = sp->field_width;
			sp->free = true;
		}
		else
		{
			sp->res = format;
			sp->len = 1;
			sp->free = false;
		}
	}
	else
	{
		sp->field_width = -1;
		sp->precision = -1;
		sp->res = format;
		sp->len = 1;
		sp->free = false;
	}
}

void	c(t_special *sp, int c)
{
	char	c1;

	c1 = (char)((unsigned char)c);
	sp->res = &c1;
	sp->len = 1;
	sp->free = false;
}

void	s(t_special *sp, char *s)
{
	if (s == NULL)
	{
		sp->res = ft_strdup("(null)");
		if (sp->precision != -1 && sp->precision < (long)ft_strlen(sp->res))
			sp->len = APPLE ? sp->precision : 0;
		else
			sp->len = ft_strlen(sp->res);
		sp->free = true;
		return ;
	}
	sp->res = s;
	sp->len = ft_strlen(s);
	if (sp->precision != -1 && (long)sp->len > sp->precision)
		sp->len = (size_t)sp->precision;
	sp->free = false;
}

void	invalid(t_special *sp, char *percent, char *format)
{
	sp->field_width = -1;
	sp->precision = -1;
	sp->res = percent;
	sp->len = (size_t)ft_max(format - percent, 0);
	if (format[0] != '\0')
		sp->len += 1;
	sp->free = false;
}
