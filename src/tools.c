/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:21:34 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/13 12:41:13 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x, data->y, "Fractol");
	data->img = mlx_new_image(data->mlx, data->x, data->y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
