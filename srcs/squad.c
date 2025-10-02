#include "fdf.h"
void	draw_squad(t_img *img, int x0, int y0, int width, int height)
{
	int i;
	int j;

	i = y0;
	while (i < y0 + height)
	{
		j = x0;
		while (j < x0 + width)
		{
			my_mlx_pixel_put(img, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}