/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:32:28 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/25 09:27:33 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_fractal
{
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	x1_max;
	long double	x2_max;
	long double	y1_max;
	long double	y2_max;
	long double	zoom_x;
	long double	zoom_y;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	i;
	long double zoom;
	int			type;
	int			 imax;
}				t_fractal;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	void		*mlx;
	void		*win;
	t_fractal	*fractal;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_data;

void	pixel_put(t_data *data, int x, int y, int color);
void	ft_print_mandelbrot(t_data *data, t_fractal *fractal);
void	ft_init_mandelbrot(t_data *data, t_fractal *fractal);
void	ft_upkey(t_data *data);
void	ft_downkey(t_data *data);
void	ft_rightkey(t_data *data);
void	ft_leftkey(t_data *data);
void	ft_clear(t_data *data);
void	ft_color(t_data *data, int i, int j);
void	ft_mousezoom(t_data *data);
void	ft_mouseunzoom(t_data *data);
void	ft_init_julia(t_data *data, t_fractal *fractal);
void	ft_print_julia(t_data *data, t_fractal *fractal);
int		ft_mlxkey(int keycode, t_data *data);
int		ft_mlxmouse(int keycode, int x, int y, t_data *data);
int		init(t_data *data);




#endif
