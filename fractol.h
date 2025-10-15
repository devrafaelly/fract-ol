#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"

//# include <mlx.h>
# include <stdlib.h>
# include <unistd.h> 
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Error: invalid input\n\tUsage: ./fractol mandelbrot\n\tUsage: ./fractol julia [param1] [param2]\n"

# define WIDTH 800
# define HEIGHT 800

# define FRACTAL_BLACK      0x0A0015
# define FRACTAL_PEACH      0xFFCBA4
# define FRACTAL_ROSE       0xFFB6C1
# define FRACTAL_PINK       0xFF69B4
# define FRACTAL_MAGENTA    0xFF00AA
# define FRACTAL_ORANGE     0xFFA07A
# define FRACTAL_YELLOW     0xFFFACD
# define FRACTAL_GOLD       0xFFD700
# define FRACTAL_LIME       0xBFFF00
# define FRACTAL_MINT       0x98FF98
# define FRACTAL_WHITE      0xFFFFFF

typedef struct s_fractal
{
    char    *name;
    void    *mlx;
    void    *win;
    t_img   *img;
    double  escape_value;
    int     definition;
    double  shift_x;
    double  shift_y;
    double  zoom;
    double  julia_x;
    double  julia_y;
}   t_fractal;

typedef struct s_img
{
    void *img_ptr;
    char *pixel_ptr;
    int bbp;
    int width_bytes;
    int endian;
    int width_bits;
}   t_img;

typedef struct s_complex
{
    double x;
    double y;
}   t_complex;

void        fractal_render(t_fractal *fractal);

void        fractal_init(t_fractal *fractal);

double      map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex   square_complex(t_complex z);
t_complex   sum_complex(t_complex z, t_complex c);
double	    ft_atof(const char *nptr);

int         close_handler(t_fractal *fractal);
int         key_handler(int keysym, t_fractal *fractal);
int         mouse_handler(int button, int x, int y, t_fractal *fractal);
int         julia_track(int x, int y, t_fractal *fractal);

void        clean_up(t_fractal *fractal);

#endif