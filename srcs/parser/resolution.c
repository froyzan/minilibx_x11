#include "../../includes/cub3d.h"

static int	num_len(char *str)
{
	int	i;

	i = 0;
	while (*str && (*str == ' ' || *str == '\t'))
	{
		str++;
		i++;
	}
	while (*str >= '0' && *str <= '9')
	{
		str++;
		i++;
	}
	return (i);
}

static int	ft_atoi_basic(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (result < 2000)
		{
			result *= 10;
			result += str[i] - 48;
		}
		i++;
	}
	if (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (result);
		return (0);
	}
	return (result);
}

int			parse_resolution(t_params *tmp, char *line)
{
	line += 2;
	if (!(tmp->w = ft_atoi_basic(line)))
	{
		parse_error("'R \033[1;31mnumber\033[0;0m number'");
		return (0);
	}
	line += num_len(line);
	if (!(tmp->h = ft_atoi_basic(line)))
	{
		parse_error("'R number \033[1;31mnumber\033[0;0m'");
		return (0);
	}
	tmp->parser |= PARSER_R;
	line += num_len(line);
	if (*line != '\0' && tmp->w && tmp->h)
	{
		parse_error("Wrong number of arguments: '\033[1;31mR\033[0;0m'");
		return (0);
	}
	tmp->w = (tmp->w > 1920 ? 1920 : tmp->w);
	tmp->h = (tmp->h > 1080 ? 1080 : tmp->h);
	return (1);
}
