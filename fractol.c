/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:01:10 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/10/16 16:01:11 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    t_fractal fractal;

    if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
        || (4 == ac && !ft_strncmp(av[1], "julia", 5)))
    {
        fractal.name = av[1];
        if (4 == ac)
        {
            fractal.julia_x = ft_atof(av[2]);
            fractal.julia_y = ft_atof(av[3]);
        }
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx);
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}
