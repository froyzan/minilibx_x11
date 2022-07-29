#include "../../includes/cub3d.h"

int			render_frame(t_params *p)
{
	t_frame	f;
	int		x;

	x = 0;
	get_sprite_dist(p);
	get_sprite_pos(p);
	ft_memset(p->spritebuffer, 0, sizeof(char) * p->w * p->h);
	while (x < p->w)
	{
		prepare_new_ray(p, &f, x);
		perform_analysis(p, &f);
		get_wall_data(p, &f, x);
		draw_sprite(p, &f, x);
		x++;
	}
	move_player(p);
	mlx_put_image_to_window(p->vars.mlx, p->vars.win, p->img.img, 0, 0);
	return (1);
}

int			render_single_frame(t_params *p)
{
	t_frame	f;
	int		x;

	x = 0;
	get_sprite_dist(p);
	get_sprite_pos(p);
	ft_memset(p->spritebuffer, 0, sizeof(char) * p->w * p->h);
	while (x < p->w)
	{
		prepare_new_ray(p, &f, x);
		perform_analysis(p, &f);
		get_wall_data(p, &f, x);
		draw_sprite(p, &f, x);
		x++;
	}
	if (save_screenshot(p))
		perror("Error\nsave_screenshot");
	return (1);
}
