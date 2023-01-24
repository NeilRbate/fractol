/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:55 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/24 10:29:19 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	t_fractal	*fractal;

	if (argc < 2)
		return (ft_putendl_fd("Too few args !", 2), -1);
	data = malloc(sizeof(*data));
	fractal = malloc(sizeof(*fractal));
	data->fractal = fractal;
	ft_init_mandelbrot(data, fractal);
	if (init(data) != 0)
		return (1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		ft_print_mandelbrot(data, fractal);
	mlx_key_hook(data->win, ft_mlxkey, data);
	mlx_mouse_hook(data->win, ft_mlxmouse, data);
	mlx_loop(data->mlx);
	return (0);
}
