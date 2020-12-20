/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_distance.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/25 23:32:39 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/26 10:19:45 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "ft_math.h"

int64_t	distance(int64_t x1, int64_t y1, int64_t x2, int64_t y2)
{
    int64_t dX = (x2 - x1) * (x2 - x1);
    int64_t dY = (y2 - y1) * (y2 - y1);
    int64_t distance = sqrt(dX + dY);
    return (distance);
}
