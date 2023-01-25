/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:43:57 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 09:27:56 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_init_julia(t_data *data, t_fractal *fractal)
{
	fractal->x1_max = -1;
	fractal->x2_max = 1;
	fractal->y1_max = -1.2;
	fractal->y2_max = 1.2;
	fractal->x1 = fractal->x1_max;
	fractal->x2 = fractal->x2_max;
	fractal->y1 = fractal->y1_max;
	fractal->y2 = fractal->y2_max;
	fractal->zoom = 300;
	fractal->imax = 200;
	fractal->type = 1;
	data->x = (fractal->x2 - fractal->x1) * fractal->zoom;
	data->y = (fractal->y2 - fractal->y1) * fractal->zoom;
}

void	ft_print_julia(t_data *data, t_fractal *fractal)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	j = 0;
	ft_clear(data);
	while (i < data->x)
	{
		while (j < data->y)
		{
			fractal->c_r = 0.29;
			fractal->c_i = 0.015;
			fractal->z_r = i / fractal->zoom + fractal->x1;
			fractal->z_i = j / fractal->zoom + fractal->y1;
			fractal->i = 0;
			while (exp2(fractal->z_r) + exp2(fractal->z_i) < 4
				&& fractal->i < fractal->imax)
			{
				temp = fractal->z_r;
				fractal->z_r = (fractal->z_r * fractal->z_r)
					- (fractal->z_i * fractal->z_i) + fractal->c_r;
				fractal->z_i = 2 * fractal->z_i * temp + fractal->c_i;
				fractal->i += 1;
			}
			ft_color(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
