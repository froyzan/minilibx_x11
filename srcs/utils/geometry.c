#include "../../includes/cub3d.h"

void	checkline_floor(t_params *p, int x, int y, int drawend)
{
	int	color;

	color = getcolor(p->floor);
	while (y < drawend)
	{
		if (!(ft_bufferstate(p, x, y)))
			my_mlx_pixel_put(&p->img, x, y, color);
		y++;
	}
}

void	checkline_ceil(t_params *p, int x, int y, int drawend)
{
	int	color;

	color = getcolor(p->ceil);
	while (y < drawend)
	{
		if (!(ft_bufferstate(p, x, y)))
			my_mlx_pixel_put(&p->img, x, y, color);
		y++;
	}
}

void	checkline(t_params *params, int x, t_frame f)
{
	while (f.drawstart <= f.drawend)
	{
		if (!(ft_bufferstate(params, x, f.drawstart)))
			my_mlx_pixel_put(&params->img, x, f.drawstart, f.color);
		f.drawstart++;
	}
}

int		ft_bufferstate(t_params *p, int x, int y)
{
	if (x >= 0 && x < p->w && y >= 0 && y < p->h)
		return (*(char*)(p->spritebuffer + ((x + y * p->w))));
	else
		return (1);
}
