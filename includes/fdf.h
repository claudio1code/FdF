/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:08:50 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/02 11:06:51 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define KEY_ESC 65307
# define SIZEWD 1920
# define SIZEHE 1080

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}t_fdf;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_squad(t_img *img, int x0, int y0, int width, int height);
int		handle_key_press(int keycode, t_fdf *fdf);

#endif