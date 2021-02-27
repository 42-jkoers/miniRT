/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quadratic.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashishae <ashishae@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 19:25:29 by ashishae      #+#    #+#                 */
/*   Updated: 2020/01/14 16:02:46 by ashishae      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRATIC_H
# define QUADRATIC_H
# include <math.h>

typedef struct s_qparams
{
	double	a;
	double	b;
	double	c;
}				t_quadratic;

void			swapf(double *a, double *b);
t_quadratic		quadratic(double a, double b, double c);
int				solve_quadratic(t_quadratic params, double *x0, double *x1);

#endif
