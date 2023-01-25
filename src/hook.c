/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:16:08 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 14:07:39 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->fractal);
	free(data);
	exit(EXIT_SUCCESS);
}

int	ft_mlxkey(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close(data);
	else if (keycode == 126)
		ft_upkey(data);
	else if (keycode == 125)
		ft_downkey(data);
	else if (keycode == 123)
		ft_leftkey(data);
	else if (keycode == 124)
		ft_rightkey(data);
	return (0);
}

int	ft_mlxmouse(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 5)
		ft_mousezoom(data);
	if (keycode == 4)
		ft_mouseunzoom(data);
	return (0);
}
