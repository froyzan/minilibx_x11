#include "../includes/cub3d.h"

int			main(int argc, char **argv)
{
	int		fd;
	char		*path;
	t_params	tmp;

	if (argc > 3 || argc == 1)
		return (parse_error("Wrong number of arguments."));
	ft_memset(&tmp, 0, sizeof(t_params));
	path = argv[1];
	fd = open_fd(&tmp, path);
	if (argc == 3)
	{
		if (!(ft_strncmp(argv[2], "--save", 6)) && ft_strlen(argv[2]) == 6)
			tmp.captureframe = 1;
		else
			return (parse_error("Wrong flags."));
	}
	if (!(tmp.vars.mlx = mlx_init()))
		return (parse_error("Can't connect to mlx."));
	parse_fd(&tmp, fd);
	if (tmp.parser == 0)
		exit_msg(&tmp, "Empty .cub File");
	prepare_map(&tmp);
	main_loop(&tmp);
	quit(&tmp);
	return (0);
}

int			open_fd(t_params *tmp, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4 || !(ft_strrchr(path, '.')))
		exit_msg(tmp, "Not a cub file.");
	if (ft_strncmp(ft_strrchr(path, '.'), ".cub", 4) == 0)
		fd = open(path, O_RDONLY);
	else
		exit_msg(tmp, "Not a cub file.");
	if (fd == -1)
	{
		perror("Error\nopen_fd");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int			main_loop(t_params *tmp)
{
	if (!(tmp->img.img = mlx_new_image(tmp->vars.mlx, tmp->w, tmp->h)))
		quit_msg(tmp, "mlx_new_image returned NULL.");
	tmp->parser |= PARSER_IMG;
	if (!(tmp->img.addr = mlx_get_data_addr(tmp->img.img,
		&(tmp->img.bpp), &(tmp->img.line_length), &(tmp->img.endian))))
		return (0);
	if (tmp->captureframe)
		return (render_single_frame(tmp));
	if (!(tmp->vars.win = mlx_new_window(tmp->vars.mlx, tmp->w, tmp->h,
	"cub3D")))
		quit_msg(tmp, "mlx_new_window returned NULL.");
	tmp->parser |= PARSER_WIN;
	set_mlx_hooks(tmp);
	mlx_loop_hook(tmp->vars.mlx, render_frame, tmp);
	mlx_loop(tmp->vars.mlx);
	return (1);
}

void		exit_msg(t_params *tmp, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit_free(tmp, 1);
}
