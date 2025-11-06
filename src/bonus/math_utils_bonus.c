/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:07:50 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 16:07:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	square_complex(t_complex z, t_fractal_type type)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	if (type == TRICORN)
		res.y = -res.y;
	return (res);
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;
	return (res);
}
