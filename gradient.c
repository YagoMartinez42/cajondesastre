/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:17:54 by samartin          #+#    #+#             */
/*   Updated: 2023/03/13 14:39:49 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

void	pix_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_by_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

unsigned int	ft_abs(long n)
{
	if (n < 0)
		return ((unsigned int)(n * -1));
	else
		return ((unsigned int)n);
}

/**
 * It takes two colors and a value between 0 and x_max, and returns a color that is a linear
 * interpolation between the two colors.
 * 
 * @param x the current x position.
 * @param x_max the width of the window.
 * @param col1 The color of the starting side of the gradient.
 * @param col2 The color of the ending side of the gradient.
 * 
 * @return The color of the pixel.
 */
int	set_color(int x, int x_max, int col1, int col2)
{
	unsigned char	cmp1[3];
	unsigned char	cmp2[3];
	int			i;

	i = 3;
	while (--i >= 0)
	{
		cmp1[2 - i] = (unsigned char)((col1 & (0xFF << (i * 8))) >> (i * 8));
		cmp2[2 - i] = (unsigned char)((col2 & (0xFF << (i * 8))) >> (i * 8));
	}
	i = 3;
	while (--i >= 0)
	{
		if (cmp1[i] != cmp2[i])
			cmp1[i] += ((cmp2[i] - cmp1[i]) * ((float)x / (float)x_max));
	}
	col1 = (int)((cmp1[0] * 0x010000) + (cmp1[1] * 0x000100) + (cmp1[2]));
	return (col1);
}

/**
 * It draws a gradient from left to right, from one color to another
 * 
 * @param data the data structure that contains the image and the window
 * @param x_max the width of the gradient
 * @param y_max the height of the gradient
 * @param col_left the color of the left side of the gradient
 * @param col_right the color of the right side of the gradient
 */
void	draw_gradient(t_data *data, unsigned int x_max, unsigned int y_max,
		int col_left, int col_right)
{
	unsigned int x;
	unsigned int y;
	int color;

	x = 0;
	y = 0;
	while (x < x_max)
	{
		color = set_color(x, x_max, col_left, col_right);
		y = 0;
		while (y < y_max)
		{
			pix_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 450, "Horizontal gradient");
	img.img = mlx_new_image(vars.mlx, 800, 450);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_gradient(&img, 800, 450, 0xBB4444, 0x44DD66);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, close_by_x, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
