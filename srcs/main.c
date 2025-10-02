/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:09:52 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/02 11:18:47 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || y < 0) || (x > SIZEWD || y > SIZEHE))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_fdf	fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "FdF");
	fdf.img.img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img_ptr, &fdf.img.bits_per_pixel,
			&fdf.img.line_length, &fdf.img.endian);
	draw_squad(&fdf.img, 700, 700, 500, 500);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img_ptr, 0, 0);
	mlx_key_hook(fdf.mlx_ptr, handle_key_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
