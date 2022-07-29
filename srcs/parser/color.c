#include "../../includes/cub3d.h"

static int	rgb_string_to_int(char **str)
{
	int	result;

	result = 0;
	while (**str == ' ' || **str == '\t')
		*str += 1;
	if (**str == ',')
		*str += 1;
	while (**str == ' ' || **str == '\t')
		*str += 1;
	if (!(ft_isdigit(**str)))
		return (-1);
	while (ft_isdigit(**str))
	{
		result *= 10;
		result += **str - 48;
		*str += 1;
	}
	return (result > 255 ? -1 : result);
}

int			parse_color(t_params *tmp, char *line)
{
	t_color	*color;

	if (!ft_strncmp(line, "F ", 2) && (tmp->parser |= PARSER_F))
		color = &tmp->floor;
	else
	{
		tmp->parser |= PARSER_C;
		color = &tmp->ceil;
	}
	line += 2;
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if ((color->r = rgb_string_to_int(&line)) < 0)
		return (parse_error("Syntax: '\033[1;31m0-255\033[0;0m 0-225 0-255'"));
	if ((color->g = rgb_string_to_int(&line)) < 0)
		return (parse_error("Syntax: '0-255 \033[1;31m0-255\033[0;0m 0-255'"));
	if ((color->b = rgb_string_to_int(&line)) < 0)
		return (parse_error("Syntax: '0-255 0-255 \033[1;31m0-255\033[0;0m'"));
	if (*line != '\0')
		return (parse_error("Wrong arguments: '\033[1;31mRGB\033[0;0m'"));
	return (1);
}
