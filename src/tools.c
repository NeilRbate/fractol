/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:21:34 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 07:27:43 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x, data->y, "Fractol");
	return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_clear(t_data *data)
{	
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, data->x, data->y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	ft_color(t_data *data, int i, int j)
{
	if (data->fractal->i == data->fractal->imax)
		pixel_put(data, i, j, 0x00330044);
	else
		pixel_put(data, i, j, data->fractal->i * 1000/data->fractal->imax);
}
