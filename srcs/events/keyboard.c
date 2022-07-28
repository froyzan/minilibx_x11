#include "../../includes/cub3d.h"

void	set_mlx_hooks(t_params *p)
{
	mlx_do_key_autorepeaton(p->vars.mlx);
	mlx_hook(p->vars.win, 2, (1L << 0), event_kbd_press, p);
	mlx_hook(p->vars.win, 3, (1L << 1), event_kbd_release, p);
	mlx_hook(p->vars.win, 17, (1L << 17), exit_hook, p);
}

int		event_kbd_press(int keycode, t_params *params)
{
	if (keycode == K_UP || keycode == K_W)
		params->move |= M_UP;
	else if (keycode == K_DOWN || keycode == K_S)
		params->move |= M_DOWN;
	else if (keycode == K_LEFT)
		params->move |= M_LEFT;
	else if (keycode == K_RIGHT)
		params->move |= M_RIGHT;
	else if (keycode == K_A)
		params->move |= M_STRLE;
	else if (keycode == K_D)
		params->move |= M_STRRI;
	else if (keycode == K_ESC)
		quit(params);
	return (1);
}

int		event_kbd_release(int keycode, t_params *params)
{
	if (keycode == K_UP || keycode == K_W)
		params->move &= ~M_UP;
	else if (keycode == K_DOWN || keycode == K_S)
		params->move &= ~M_DOWN;
	else if (keycode == K_LEFT)
		params->move &= ~M_LEFT;
	else if (keycode == K_RIGHT)
		params->move &= ~M_RIGHT;
	else if (keycode == K_A)
		params->move &= ~M_STRLE;
	else if (keycode == K_D)
		params->move &= ~M_STRRI;
	return (1);
}

int		exit_hook(t_params *params)
{
	quit(params);
	return (1);
}
