#include "../../includes/cub3d.h"

static void	player_strafe_left(t_params *params, double speed)
{
	double olddirx;
	double olddiry;

	olddirx = params->dir.x;
	olddiry = params->dir.y;
	params->dir.x = params->dir.y;
	params->dir.y = -olddirx;
	params->pos.x += params->dir.x * speed;
	params->pos.y += params->dir.y * speed;
	params->dir.x = olddirx;
	params->dir.y = olddiry;
}

static void	player_strafe_right(t_params *params, double speed)
{
	double olddirx;
	double olddiry;

	olddirx = params->dir.x;
	olddiry = params->dir.y;
	params->dir.x = -params->dir.y;
	params->dir.y = olddirx;
	params->pos.x += params->dir.x * speed;
	params->pos.y += params->dir.y * speed;
	params->dir.x = olddirx;
	params->dir.y = olddiry;
}

static void	player_move_forward(t_params *params, double speed)
{
	params->pos.x += params->dir.x * speed;
	params->pos.y += params->dir.y * speed;
}

static void	player_move_backward(t_params *params, double speed)
{
	params->pos.x -= params->dir.x * speed;
	params->pos.y -= params->dir.y * speed;
}

void		move_player(t_params *params)
{
	double	speed;

	speed = params->movespeed;
	if (params->move & M_LEFT)
		player_rotate_left(params);
	if (params->move & M_RIGHT)
		player_rotate_right(params);
	if (params->move & M_UP)
		player_move_forward(params, speed * 0.5);
	if (params->move & M_DOWN)
		player_move_backward(params, speed * 0.5);
	if (params->move & M_STRLE)
		player_strafe_left(params, speed * 0.5);
	if (params->move & M_STRRI)
		player_strafe_right(params, speed * 0.5);
}
