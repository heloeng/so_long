
#include "so_long.h"

void	count_collectibles(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->e_count = 1;
	data->c_count = 0;
	data->p_count = 0;
	data->c_count_t = 0;
	while (data->map[line] && data->map_copy[line])
	{
		i = 0;
		while (data->map[line][i] && data->map_copy[line][i])
		{
			if (data->map[line][i] == 'C')
				data->c_count++;
			if (data->map_copy[line][i] == 'C')
				data->c_count_t++;
			i++;
		}
		line++;
	}
}

void	display_score(t_data *data)
{
	if (data->p_count == 1)
		ft_printf("You did %d move.\n", data->p_count);
	else
		ft_printf("You did %d moves.\n", data->p_count);
}

int	exit_game(t_data *data)
{
	if (data->c_count == 0)
	{
		ft_printf("Finished with %d moves!\n", data->p_count + 1);
		cleanup_game_resources(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	end_game(t_data *data)
{
	ft_printf("So long!\n");
	cleanup_game_resources(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	process_key_input(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("So long!\n");
		cleanup_game_resources(data);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_w)
		move_up(data);
	else if (key == XK_a)
		move_left(data);
	else if (key == XK_s)
		move_down(data);
	else if (key == XK_d)
		move_right(data);
	return (0);
}
