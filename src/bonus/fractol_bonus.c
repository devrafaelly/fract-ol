/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:00:02 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 16:00:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	usage(void)
{
	ft_putendl_fd("╔═══════════════════════════════════════════╗", 1);
	ft_putendl_fd("║         Usage: ./fractol <fractal>        ║", 1);
	ft_putendl_fd("╚═══════════════════════════════════════════╝", 1);
	ft_putendl_fd("╔═══════════════════════════════════════════╗", 1);
	ft_putendl_fd("║      Usage: ./fractol_bonus <fractal>     ║", 1);
	ft_putendl_fd("╚═══════════════════════════════════════════╝", 1);
	ft_putendl_fd("            ╔════════════════════╗           ", 1);
	ft_putendl_fd("╔═══════════╣ Available fractals ╠══════════╗", 1);
	ft_putendl_fd("║           ╚════════════════════╝          ║", 1);
	ft_putendl_fd("║                 mandelbrot                ║", 1);
	ft_putendl_fd("║                julia [x, y]               ║", 1);
	ft_putendl_fd("║                    ship                   ║", 1);
	ft_putendl_fd("║                  tricorn                  ║", 1);
	ft_putendl_fd("╠═══════════════════════════════════════════╣", 1);
	ft_putendl_fd("║             Julia Set Examples            ║", 1);
	ft_putendl_fd("║                                           ║", 1);
	ft_putendl_fd("║ ./fractol julia -0.4 0.6       (Spider)   ║", 1);
	ft_putendl_fd("║ ./fractol julia 0.285 0.01     (Spiral)   ║", 1);
	ft_putendl_fd("║ ./fractol julia -0.835 -0.2321 (Rabbit)   ║", 1);
	ft_putendl_fd("║ ./fractol julia -0.7269 0.1889 (Dragon)   ║", 1);
	ft_putendl_fd("║ ./fractol julia -0.8 0.156     (Dendrite) ║", 1);
	ft_putendl_fd("╚═══════════════════════════════════════════╝", 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if (ac < 2)
		return (usage());
	fractal.name = av[1];
	if (!ft_strncmp(av[1], "mandelbrot", 10))
		fractal.type = MANDELBROT;
	else if (!ft_strncmp(av[1], "ship", 4))
        	fractal.type = SHIP;
	else if (!ft_strncmp(av[1], "tricorn", 5))
		fractal.type = TRICORN;
	else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
	{
		fractal.type = JULIA;
		fractal.julia_x = ft_atof(av[2]);
		fractal.julia_y = ft_atof(av[3]);
	}
	else
		return (usage());
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
