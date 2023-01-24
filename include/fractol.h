/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:32:28 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/24 11:24:54 by jbarbate         ###   ########.fr       */
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
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		i;
	int		zoom;
	int		imax;
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
void	ft_sumdata(t_data *data);
void	ft_zoom(t_data *data);
void	ft_unzoom(t_data *data);
void	ft_clear(t_data *data);
void	ft_color(t_data *data, int i, int j);
void	ft_summousedata(t_data *data, int x, int y);
void	ft_mousezoom(t_data *data, int i, int j);
void	ft_mouseunzoom(t_data *data, int i, int j);
int		ft_mlxkey(int keycode, t_data *data);
int		ft_mlxmouse(int keycode, int x, int y, t_data *data);
int		init(t_data *data);




#endif
