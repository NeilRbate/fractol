/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:57:33 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 09:28:05 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mousezoom(t_data *data)
{
	if (data->fractal->type == 0)
		data->fractal->zoom *= 1.1;
	if (data->fractal->imax > 1)
		data->fractal->imax *= 1.1;
	data->fractal->x1 /= 1.1;
	data->fractal->x2 *= 1.1;
	data->fractal->y1 /= 1.1;
	data->fractal->y2 *= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	if (data->fractal->type == 0)
		ft_print_mandelbrot(data, data->fractal);
}

void	ft_mouseunzoom(t_data *data)
{
	if (data->fractal->type == 0 && data->fractal->zoom > 10)
		data->fractal->zoom /= 1.1;
	if (data->fractal->imax > 10)
		data->fractal->imax /= 1.1;
	data->fractal->x1 *= 1.1;
	data->fractal->x2 /= 1.1;
	data->fractal->y1 *= 1.1;
	data->fractal->y2 /= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	if (data->fractal->type == 0)
		ft_print_mandelbrot(data, data->fractal);
}
