/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:04:03 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/13 12:31:31 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mandelbrot(t_data *data, t_fractal *fractal)
{
	fractal->x1 = -2.1;
	fractal->x2 = 0.6;
	fractal->y1 = -1.2;
	fractal->y2 = 1.2;
	fractal->zoom = 380;
	fractal->imax = 1000;
	data->x = (fractal->x2 - fractal->x1) * fractal->zoom;
	data->y = (fractal->y2 - fractal->y1) * fractal->zoom;
	fractal->zoom_x = data->x / (fractal->x2 - fractal->x1);
	fractal->zoom_y = data->y / (fractal->y2 - fractal->y1);
}

void	sum(t_fractal *fractal)
{
	float	temp;

	temp = fractal->z_r;
	fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i * fractal->z_i) + fractal->c_r;
	fractal->z_i = 2 * fractal->z_i * temp + fractal->c_i;
	fractal->i += 1;
	
}
void	print_mandelbrot(t_data *data, t_fractal *fractal)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->x)
	{
		while (j < data->y)
		{
			fractal->c_r = i / fractal->zoom_x + fractal->x1;
			fractal->c_i = j / fractal->zoom_y + fractal->y1;
			fractal->z_r = 0;
			fractal->z_i = 0;
			fractal->i = 0;
			sum(fractal);
			while (((fractal->z_r * fractal->z_r) + (fractal->z_i * fractal->z_i)) < 4 && fractal->i < fractal->imax)
				sum(fractal);
			if (fractal->i == fractal->imax)
				pixel_put(data, i, j, 0x00330066);
			else if (fractal->i > fractal->imax / 2)
				pixel_put(data, i, j, 0x000000FF);
			else
				pixel_put(data, i, j, 0x00660066);
			j++;
		}
		i++;
		j = 0;
	}
}
