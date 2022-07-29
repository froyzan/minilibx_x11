#include "../../includes/cub3d.h"

int			char_in_str(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

static char	**ft_tab_join(char **tab, const char *str, int size)
{
	char	**ptr;
	int		i;

	if (!str)
		return (tab);
	if (!(ptr = malloc(sizeof(char *) * (size + 1))))
		return (tab);
	i = 0;
	while (i < size)
	{
		ptr[i] = tab[i];
		i++;
	}
	if (!(ptr[i] = ft_strdup(str)))
	{
		free(ptr);
		return (tab);
	}
	free(tab);
	return (ptr);
}

static int	validate_map_line(t_map *map, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (char_in_str("NSEW", line[i]) && j == 0 &&
			map->start.x == 0 && map->start.y == 0)
		{
			map->start.x = i;
			map->start.y = map->size.y;
			j++;
		}
		else if (char_in_str("NSEW", line[i]))
			return (parse_error("More than one start point."));
		else if (!char_in_str(" 012", line[i]))
			return (parse_error("Unknown character, expected map."));
		i++;
	}
	return (1);
}

int			parse_map(t_params *tmp, char *line)
{
	t_map	*this;

	this = &tmp->map;
	if (!(validate_map_line(this, line)))
		return (0);
	if (tmp->parser == 255)
		if (!(this->tab = malloc(sizeof(char *) * 1)))
			return (parse_error("Map allocation error."));
	if (!(this->tab = ft_tab_join((char **)this->tab, line, this->size.y)))
		return (parse_error("Map Join allocation error."));
	tmp->parser |= PARSER_MAP;
	this->size.y++;
	if ((int)ft_strlen(line) > this->size.x)
		this->size.x = ft_strlen(line);
	return (1);
}
