/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:01:26 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/10/16 19:21:31 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  map(double unscaled_num, double new_min,
            double new_max, double old_max)
{
    return (new_max - new_min) * unscaled_num / old_max + new_min;
}

t_complex   square_complex(t_complex z)
{
    t_complex res;

    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * z.x * z.y;
    return (res);
}

t_complex   sum_complex(t_complex z, t_complex c)
{
    t_complex res;

    res.x = z.x + c.x;
    res.y = z.y + c.y;
    return (res);
}

double	ft_atof(const char *nptr)
{
	double	signal;
	double	res;
	double	div;

	signal = 1;
	res = 0.0;
	div = 1.0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - '0');
	if (*nptr == '.')
	{
        nptr++;
		while (*nptr >= '0' && *nptr <= '9')
			res += (*nptr++ - '0') / (div *= 10);
	}
	return (res * signal);
}
