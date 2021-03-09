/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quadratic.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ashishae <ashishae@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 19:25:07 by ashishae      #+#    #+#                 */
/*   Updated: 2020/01/17 18:58:45 by ashishae      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "quadratic.h"

void	swapf(double *a, double *b)
{
	double	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

bool	solve_quadratic(t_quadratic params, double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = pow(params.b, 2) - 4 * params.a * params.c;
	if (discr < 0)
		return (false);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.b / params.a;
		*x1 = -0.5 * params.b / params.a;
	}
	else
	{
		if (params.b > 0)
			q = -0.5 * (params.b + sqrt(discr));
		else
			q = -0.5 * (params.b - sqrt(discr));
		*x0 = q / params.a;
		*x1 = params.c / q;
	}
	if (*x0 > *x1)
		swapf(x0, x1);
	return (true);
}
