#include "so_long.h"

int	is_valid_extension(char *filename)
{
	char	*ber;

	if (!filename)
		return (TRUE);
	ber = ft_strrchr(filename, '.');
	if (!ber || ft_strncmp(ber, ".ber\0", 5))
		return (TRUE);
	return (FALSE);
}

int	validate_map_characters(t_data data)
{
	int	line;
	int	i;

	line = 0;
	while (data.map[line])
	{
		i = 0;
		while (data.map[line][i])
		{
			if (data.map[line][i] != '0' && data.map[line][i] != '1'
				&& data.map[line][i] != 'E' && data.map[line][i] != 'C'
				&& data.map[line][i] != 'P' && data.map[line][i] != '\n')
				return (free_map_data(&data),
					ft_printf("Error\nInvalid char(s).\n"), TRUE);
			i++;
		}
		line++;
	}
	return (FALSE);
}

int	sl_char_errors_2(int count_exit, int count_coll, int count_play)
{
	if (count_exit != 1 || count_coll < 1 || count_play != 1)
	{
		ft_printf("Error\n");
		if (count_exit < 1)
			ft_printf("No exit found.\n");
		if (count_exit > 1)
			ft_printf("Can't put more than 1 exit.\n");
		if (count_coll < 1)
			ft_printf("No collectible found.\n");
		if (count_play > 1)
			ft_printf("Can't put more than 1 player.\n");
		if (count_play < 1)
			ft_printf("No player found.\n");
		return (TRUE);
	}
	else
		return (FALSE);
}

int	sl_char_errors_1(t_data data)
{
	int	count[3];
	int	line;
	int	i;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	line = -1;
	while (data.map[++line])
	{
		i = -1;
		while (data.map[line][++i])
		{
			if (data.map[line][i] == 'E')
				count[0]++;
			if (data.map[line][i] == 'C')
				count[1]++;
			if (data.map[line][i] == 'P')
				count[2]++;
		}
	}
	if (sl_char_errors_2(count[0], count[1], count[2]) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	check_map_errors(t_data data)
{
	int	line;
	int	i;

	if (!data.map)
		return (1);
	if (sl_char_errors_1(data) == TRUE)
		return (TRUE);
	line = -1;
	while (data.map[++line])
	{
		if (ft_line_len(data.map[line]) != ft_line_len(data.map[0]))
			return (ft_printf("Error\nNot rectangular.\n"), TRUE);
		i = -1;
		while (data.map[line][++i])
		{
			if ((data.map[0][i] != '1' && data.map[0][i] != '\n')
				|| (data.map[data.nb_line - 1][i] != '1'
					&& data.map[data.nb_line - 1][i] != '\n'
					&& data.map[data.nb_line - 1][i] != '\0') ||
					(data.map[line][0] != '1'
					|| data.map[line][ft_line_len(data.map[line]) - 1] != '1'))
				return (ft_printf("Error\nInvalid walls.\n"), TRUE);
		}
	}
	return (FALSE);
}
