/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:55 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/13 12:38:22 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#define WIDTH 700
#define HEIGHT 700
#include <stdio.h>
int	mlxclose(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		printf("escape\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
		exit(EXIT_SUCCESS);
	return (0);
}

int	mlxmouse(int keycode, int x, int y, t_data *data)
{
	(void)data;
	(void)x;
	(void)y;
	if (keycode == 5)
		printf("%i\n", keycode);
	else
		printf("%i\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars		*vars;
	t_data		*data;
	t_fractal	*fractal;

	vars = malloc(sizeof(*vars));
	data = malloc(sizeof(*data));
	fractal = malloc(sizeof(*fractal));
	init_mandelbrot(data, fractal);
	if (init(vars, data) != 0)
		return (1);
	print_mandelbrot(data, fractal);
	mlx_key_hook(vars->win, mlxclose, vars);
	mlx_mouse_hook(vars->win, mlxmouse, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	mlx_loop(vars->mlx);
	return (0);
}
