/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:02:39 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 16:02:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# include <stdlib.h>
# include <unistd.h> 
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Error: invalid input\n\tUsage: ./fractol mandelbrot\n\tUsage: ./fractol julia [param1] [param2]\n"

# define WIDTH 800
# define HEIGHT 800

# define SHIP_BLUE	0x00102030
# define SHIP_ORANGE	0xFFFF5500
# define MANDEL_BLUE	0x000764
# define MANDEL_GOLD	0xFFD700
# define JULIA_PURPLE	0x220044
# define JULIA_CIAN	0x33DDFF
# define SAF_RED	0xD62F27
# define SAF_PINK	0xFF9CA2
# define BLACK 		0x0A0015

typedef enum	e_fractal_type
{
	MANDELBROT,
	JULIA,
	SHIP,
	TRICORN
}	t_fractal_type;

typedef enum e_scheme
{
	SCHEME_1,
	SCHEME_2,
	SCHEME_3,
	SCHEME_4,
	SCHEME_TOTAL
}	t_scheme;

typedef struct	s_img_data
{
	void	*img_ptr;
	char	*pixel_ptr;
	int	bpp;
	int	width_bytes;
	int	endian;
	int	width_bits;
}	t_img_data;

typedef struct	s_fractal
{
	char			*name;
	void			*mlx;
	void			*win;

	t_img_data		*img;
	t_fractal_type	type;
	t_scheme		scheme;

	double			color_start;
	double			color_end;

	double			escape_value;
	int				definition;
	double			shift_x;
	double			shift_y;
	double			zoom;
	double			julia_x;
	double			julia_y;
}	t_fractal;

typedef struct	s_complex
{
	double	x;
	double	y;
}	t_complex;

void		fractal_render(t_fractal *fractal);
void		put_pixel(t_img_data *img, int x, int y, int color);

void		fractal_init(t_fractal *fractal);

double		map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	square_complex(t_complex z, t_fractal_type type);
t_complex	sum_complex(t_complex z, t_complex c);
double		ft_atof(const char *nptr);

int		close_handler(t_fractal *fractal);
int		key_handler(int keysym, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);

void		put_color(t_fractal *fractal, int i, int x, int y);

void		clean_up(t_fractal *fractal);

#endif