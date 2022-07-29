#include "../../includes/cub3d.h"

static void	destroy_images(t_params *tmp)
{
	if (tmp->parser & PARSER_NO)
		mlx_destroy_image(tmp->vars.mlx, tmp->north.img);
	if (tmp->parser & PARSER_SO)
		mlx_destroy_image(tmp->vars.mlx, tmp->south.img);
	if (tmp->parser & PARSER_EA)
		mlx_destroy_image(tmp->vars.mlx, tmp->east.img);
	if (tmp->parser & PARSER_WE)
		mlx_destroy_image(tmp->vars.mlx, tmp->west.img);
	if (tmp->parser & PARSER_S)
		mlx_destroy_image(tmp->vars.mlx, tmp->sprite.img);
}

static void	free_allocated_tables(t_params *params)
{
	if (params->parser & PARSER_SPR)
	{
		free(params->map.s_order);
		free(params->map.s_dist);
		free(params->map.sprite);
	}
	if (params->parser & PARSER_BUF)
	{
		free(params->spritebuffer);
		free(params->zbuffer);
	}
}

void		exit_free(t_params *tmp, int quit)
{
	destroy_images(tmp);
	if (tmp->parser & PARSER_MAP)
		free_tab(tmp->map.tab, tmp->map.size.y);
	if (tmp->parser & PARSER_SPR)
	{
		free(tmp->map.s_order);
		free(tmp->map.s_dist);
		free(tmp->map.sprite);
	}
	if (tmp->parser & PARSER_BUF)
	{
		free(tmp->spritebuffer);
		free(tmp->zbuffer);
	}
	free(tmp->vars.mlx);
	if (quit)
		exit(EXIT_FAILURE);
}

void		quit(t_params *params)
{
	destroy_images(params);
	if (params->parser & PARSER_IMG)
		mlx_destroy_image(params->vars.mlx, params->img.img);
	if (params->parser & PARSER_MAP)
		free_tab(params->map.tab, params->map.size.y);
	free_allocated_tables(params);
	if (!(params->captureframe) || (params->parser & PARSER_WIN))
		mlx_destroy_window(params->vars.mlx, params->vars.win);
	mlx_destroy_display(params->vars.mlx);
	free(params->vars.mlx);
	exit(EXIT_SUCCESS);
}

void		quit_msg(t_params *params, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	quit(params);
}
