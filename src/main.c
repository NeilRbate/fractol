/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:55 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/12 14:25:38 by jbarbate         ###   ########.fr       */
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
	print_mandelbrot(vars, data, fractal);
	mlx_key_hook(vars->win, mlxclose, vars);
	mlx_loop(vars->mlx);
	return (0);
}
