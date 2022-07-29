#include "../../includes/cub3d.h"

void		free_tab(char **tab, int size)
{
	while (--size >= 0)
		free(tab[size]);
	free(tab);
}

int			reachable(char **tab, int y, int x)
{
	if (char_in_str("02", tab[y][x]))
		return (1);
	return (0);
}

static void	print_tab(char **a, t_icoord size)
{
	int i;
	int j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (a[i][j] == 'X')
				ft_putstr_fd("\033[1;31m", 1);
			else if (char_in_str("NSEW", a[i][j]))
				ft_putstr_fd("\033[1;32m", 1);
			else if (!reachable(a, i, j))
				ft_putstr_fd("\033[1;34m", 1);
			ft_putchar_fd(a[i][j], 1);
			ft_putstr_fd("\033[0;0m", 1);
			j++;
		}
		i++;
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
}

void		flood_fill(t_params *tmp, int x, int y)
{
	if (!(ft_strchr("NSEW", tmp->map.tmp[y][x])))
		tmp->map.tmp[y][x] = 'X';
	if (!(x) || !(y) || y == (tmp->map.size.y - 1) ||
		x == (tmp->map.size.x - 1))
	{
		ft_putendl_fd("Error\nMap is leaking.", 1);
		print_tab(tmp->map.tmp, tmp->map.size);
		free_tab(tmp->map.tmp, tmp->map.size.y);
		exit_free(tmp, 1);
	}
	if (y > 0 && reachable(tmp->map.tmp, y - 1, x))
		flood_fill(tmp, x, y - 1);
	if ((y < (tmp->map.size.y - 1)) && reachable(tmp->map.tmp, y + 1, x))
		flood_fill(tmp, x, y + 1);
	if ((x < (tmp->map.size.x - 1)) && reachable(tmp->map.tmp, y, x + 1))
		flood_fill(tmp, x + 1, y);
	if (x > 0 && reachable(tmp->map.tmp, y, x - 1))
		flood_fill(tmp, x - 1, y);
}
