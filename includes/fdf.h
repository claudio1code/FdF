/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:08:50 by clados-s          #+#    #+#             */
/*   Updated: 2025/10/01 14:03:19 by clados-s         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_squad(t_data *img, int x0, int y0, int width, int height);

#endif