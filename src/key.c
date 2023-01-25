/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:55:11 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 09:31:11 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_downkey(t_data *data)
{
	data->fractal->y1 /= 1.1;
	data->fractal->y2 *= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	if (data->fractal->type == 0)
		ft_print_mandelbrot(data, data->fractal);
	else if (data->fractal->type == 1)
		ft_print_julia(data, data->fractal);
}

void	ft_upkey(t_data *data)
{
	data->fractal->y1 *= 1.1;
	data->fractal->y2 /= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	if (data->fractal->type == 0)
		ft_print_mandelbrot(data, data->fractal);
	else if (data->fractal->type == 1)
		ft_print_julia(data, data->fractal);
}

void	ft_leftkey(t_data *data)
{
	data->fractal->x1 *= 1.1;
	data->fractal->x2 /= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	if (data->fractal->type == 0)
		ft_print_mandelbrot(data, data->fractal);
	else if (data->fractal->type == 1)
		ft_print_julia(data, data->fractal);
}

void	ft_rightkey(t_data *data)
{
	data->fractal->x1 /= 1.1;
	data->fractal->x2 *= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	if (data->fractal->type == 0)
		ft_print_mandelbrot(data, data->fractal);
	else if (data->fractal->type == 1)
		ft_print_julia(data, data->fractal);
}
