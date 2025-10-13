#include "fractol.h"

double  map(double unscaled_num,
            double new_min,
            double new_max,
            double old_max)
{
    return (new_max - new_min) * unscaled_num / old_max + new_min;
}

t_complex   square_complex(t_complex z)
{
    t_complex res;

    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * z.x * z.y;
    return (res);
    temp_x = (z.x * z.x) - (z.y * z.y);
    y = 2 * z.x * z.y;
    z.x = temp_x;
    z.x += c.x;
    z.y += c.y;
    i++;
}

t_complex   sum_complex(t_complex z, t_complex c)
{
    t_complex res;

    res.x = z.x + c.x;
    res.y = z.y + c.y;
    return (res);
}