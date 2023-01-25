/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:04:03 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 09:21:01 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_init_mandelbrot(t_data *data, t_fractal *fractal)
{
	fractal->x1_max = -2.1;
	fractal->x2_max = 0.6;
	fractal->y1_max = -1.2;
	fractal->y2_max = 1.2;
	fractal->x1 = fractal->x1_max;
	fractal->x2 = fractal->x2_max;
	fractal->y1 = fractal->y1_max;
	fractal->y2 = fractal->y2_max;
	fractal->zoom = 300;
	fractal->imax = 20;
	fractal->type = 0;
	data->x = (fractal->x2 - fractal->x1) * fractal->zoom;
	data->y = (fractal->y2 - fractal->y1) * fractal->zoom;
}

void	ft_fractal(t_fractal *fractal, int i, int j)
{
	fractal->c_r = i / fractal->zoom + fractal->x1;
	fractal->c_i = j / fractal->zoom + fractal->y1;
	fractal->z_r = 0;
	fractal->z_i = 0;
	fractal->i = 0;
}

void	ft_sumimaginary(t_fractal *fractal)
{
	double	temp;

	temp = fractal->z_r;
	fractal->z_r = (fractal->z_r * fractal->z_r)
		- (fractal->z_i * fractal->z_i) + fractal->c_r;
	fractal->z_i = 2 * fractal->z_i * temp + fractal->c_i;
	fractal->i += 1;
}

void	ft_print_mandelbrot(t_data *data, t_fractal *fractal)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_clear(data);
	while (i < data->x)
	{
		while (j < data->y)
		{
			ft_fractal(fractal, i, j);
			while (exp2(fractal->z_r) + exp2(fractal->z_i) < 4
				&& fractal->i < fractal->imax)
				ft_sumimaginary(fractal);
			ft_color(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
