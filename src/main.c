/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:55 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 13:11:19 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mandelbrot(t_data *data, t_fractal *fractal)
{
	ft_init_mandelbrot(data, fractal);
	init(data);
	ft_print_mandelbrot(data, fractal);
}

void	ft_julia(t_data *data, t_fractal *fractal)
{
	ft_init_julia(data, fractal);
	init(data);
	ft_print_julia(data, fractal);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_fractal	*fractal;
	int			ret;

	data = malloc(sizeof(*data));
	fractal = malloc(sizeof(*fractal));
	data->fractal = fractal;
	ret = ft_argctl(data, argc, argv);
	if (ret < 0)
	{
		free(data->fractal);
		free(data);
		return (-1);
	}
	else if (ret == 0)
		ft_mandelbrot(data, fractal);
	else if (ret == 1)
		ft_julia(data, fractal);
	mlx_key_hook(data->win, ft_mlxkey, data);
	mlx_mouse_hook(data->win, ft_mlxmouse, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
	return (0);
}
