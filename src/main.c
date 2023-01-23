/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:55 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/23 17:20:55 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	sumdata(t_data *data)
{
		data->x = (data->fractal->x2 - data->fractal->x1) * data->fractal->zoom;
		data->y = (data->fractal->y2 - data->fractal->y1) * data->fractal->zoom;
		data->fractal->zoom_x = data->x / (data->fractal->x2 - data->fractal->x1);
		data->fractal->zoom_y = data->y / (data->fractal->y2 - data->fractal->y1);
		mlx_destroy_image(data->mlx, data->img);
		print_mandelbrot(data, data->fractal);
}

int	mlxkey(int keycode, t_data *data)
{
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		printf("escape\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 126)
	{
		data->fractal->zoom *= 1.1;
		data->fractal->imax *= 1.1;
		data->fractal->x1 /= 1.1;
		data->fractal->x2 *= 1.1;
		data->fractal->y1 /= 1.1;
		data->fractal->y2 *= 1.1;
		sumdata(data);
	}
	else if (keycode == 125)
	{	
		data->fractal->zoom /= 1.1;
		data->fractal->imax /= 1.1;
		data->fractal->x1 *= 1.1;
		data->fractal->x2 /= 1.1;
		data->fractal->y1 *= 1.1;
		data->fractal->y2 /= 1.1;
		sumdata(data);
	}
	return (0);
}

int	mlxmouse(int keycode, int x, int y, t_data *data)
{
	(void)data;
	if (keycode == 5)
	{
		printf("x ->%i\n", x);
		printf("y ->%i\n", y);
		printf("%i\n", keycode);
	}
	if (keycode == 4)
	{
		printf("%i\n", keycode);
		printf("x ->%i\n", x);
		printf("y ->%i\n", y);
	}
	else
		printf("%i\n", keycode);
	return (0);
}

int	main(void)
{
	t_data		*data;
	t_fractal	*fractal;

	data = malloc(sizeof(*data));
	fractal = malloc(sizeof(*fractal));
	data->fractal = fractal;
	init_mandelbrot(data, fractal);
	if (init(data) != 0)
		return (1);
	print_mandelbrot(data, fractal);
	mlx_key_hook(data->win, mlxkey, data);
	mlx_mouse_hook(data->win, mlxmouse, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
	return (0);
}
