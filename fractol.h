#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"

//# include <mlx.h>
# include <stdlib.h>
# include <unistd.h> 
# include <math.h> 

# define WIDTH 1024
# define HEIGHT 768

typedef struct s_data
{
    void *mlx;
    void *win;
    int width;
    int height;
}   t_data;

#endif