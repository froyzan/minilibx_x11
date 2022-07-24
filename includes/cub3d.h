/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:54:37 by psafflow          #+#    #+#             */
/*   Updated: 2020/09/22 21:43:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "structs.h"
# include "keycodes.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>

# define M_UP 0x00001
# define M_DOWN 0x00002
# define M_LEFT 0x00004
# define M_RIGHT 0x00008
# define M_STRLE 0x00010
# define M_STRRI 0x00020

# define PARSER_R 0x00001
# define PARSER_NO 0x00002
# define PARSER_SO 0x00004
# define PARSER_EA 0x00008
# define PARSER_WE 0x00010
# define PARSER_S 0x00020
# define PARSER_F 0x00040
# define PARSER_C 0x00080
# define PARSER_MAP 0x00100
# define PARSER_SPR 0x00200
# define PARSER_BUF 0x00400
# define PARSER_DOOR 0x00800
# define PARSER_IMG 0x01000
# define PARSER_WIN 0x02000

int		build_sprite_tables(t_map *map, t_params *tmp);
int		char_in_str(const char *s, int c);
void	count_sprites(t_map *map);
void	draw_sprite_bis(t_params *p, int x);
void	draw_sprite(t_params *params, t_frame *f, int x);
void	draw_wall(t_params *params, int x, t_frame *f);
int		event_kbd_press(int keycode, t_params *params);
int		event_kbd_release(int keycode, t_params *params);
void	exit_free(t_params *tmp, int quit);
int		exit_hook(t_params *params);
void	exit_msg(t_params *tmp, char *msg);
void	fill_sprite_table(t_map *map);
void	flood_fill(t_params *tmp, int x, int y);
void	free_tab(char **tab, int size);
int		ft_bufferstate(t_params *params, int x, int y);
int		getcolor(t_color color);
int		getwallpixelcolor(t_params *p, t_image *img, t_frame *f, t_wall *w);
void	get_sprite_dist(t_params *p);
void	get_sprite_pos(t_params *p);
void	get_step_and_sidedist(t_params *params, t_frame *f);
void	get_wall_data(t_params *params, t_frame *f, int x);
void	get_wall_values(t_wall *w, t_image *img, t_frame *f, t_params *params);
int		getpixelcolor(t_image *img, int x, int y);
void	init_player(t_params *tmp);
void	init_sprite(t_sprite *sprite, int i, int j, int tex);
int		main_loop(t_params *params);
void	move_player(t_params *params);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
int		open_fd(t_params *tmp, char *path);
int		parse_color(t_params *tmp, char *line);
int		parse_error(char *msg);
int		parse_error_detail(t_params *tmp, char *line);
void	parse_fd(t_params *tmp, int fd);
int		parse_map(t_params *tmp, char *line);
int		parse_resolution(t_params *tmp, char *line);
int		parse_texture(t_params *tmp, char *line);
void	perform_analysis(t_params *params, t_frame *f);
void	player_rotate_left(t_params *params);
void	player_rotate_right(t_params *params);
void	prepare_map(t_params *tmp);
void	prepare_new_ray(t_params *params, t_frame *f, int x);
void	put_sprite_to_img(t_params *p, t_spr_cast *s, int x, int y);
void	quit(t_params *params);
void	quit_msg(t_params *params, char *str);
int		reachable(char **tab, int y, int x);
int		render_frame(t_params *p);
int		render_single_frame(t_params *p);
int		save_screenshot(t_params *params);
void	set_mlx_hooks(t_params *p);
void	checkline(t_params *params, int x, t_frame f);
void	checkline_ceil(t_params *p, int x, int y, int drawend);
void	checkline_floor(t_params *p, int x, int y, int drawend);

#endif
