#include "so_long.h"

void	move_up(t_data *data)
{
	data->direction = UP;
	if (data->map[data->p_line - 1][data->p_char] != '1')
	{
		if ((data->map[data->p_line - 1][data->p_char] == 'Z'
			|| data->map[data->p_line - 1][data->p_char] == 'E'))
			exit_game(data);
		if (data->map[data->p_line - 1][data->p_char] == 'C')
		{
			data->c_count--;
			if (data->c_count == 0)
			{
				if (data->map[data->e_line][data->e_char] == 'D')
					data->map[data->e_line][data->e_char] = 'Z';
				if (data->map[data->e_line][data->e_char] == '0')
					data->map[data->e_line][data->e_char] = 'E';
			}
		}
		data->p_line--;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line + 1][data->p_char] = '0';
		data->p_count++;
		render_map_images(data);
		display_score(data);
	}
}

void	move_left(t_data *data)
{
	data->direction = LEFT;
	if (data->map[data->p_line][data->p_char - 1] != '1')
	{
		if ((data->map[data->p_line][data->p_char - 1] == 'Z'
			|| data->map[data->p_line][data->p_char - 1] == 'E'))
			exit_game(data);
		if (data->map[data->p_line][data->p_char - 1] == 'C')
		{
			data->c_count--;
			if (data->c_count == 0)
			{
				if (data->map[data->e_line][data->e_char] == 'D')
					data->map[data->e_line][data->e_char] = 'Z';
				if (data->map[data->e_line][data->e_char] == '0')
					data->map[data->e_line][data->e_char] = 'E';
			}
		}
		data->p_char--;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line][data->p_char + 1] = '0';
		data->p_count++;
		render_map_images(data);
		display_score(data);
	}
}

void	move_down(t_data *data)
{
	data->direction = DOWN;
	if (data->map[data->p_line + 1][data->p_char] != '1')
	{
		if ((data->map[data->p_line + 1][data->p_char] == 'Z'
			|| data->map[data->p_line + 1][data->p_char] == 'E'))
			exit_game(data);
		if (data->map[data->p_line + 1][data->p_char] == 'C')
		{
			data->c_count--;
			if (data->c_count == 0)
			{
				if (data->map[data->e_line][data->e_char] == 'D')
					data->map[data->e_line][data->e_char] = 'Z';
				if (data->map[data->e_line][data->e_char] == '0')
					data->map[data->e_line][data->e_char] = 'E';
			}
		}
		data->p_line++;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line - 1][data->p_char] = '0';
		data->p_count++;
		render_map_images(data);
		display_score(data);
	}
}

void	move_right(t_data *data)
{
	data->direction = RIGHT;
	if (data->map[data->p_line][data->p_char + 1] != '1')
	{
		if ((data->map[data->p_line][data->p_char + 1] == 'Z'
			|| data->map[data->p_line][data->p_char + 1] == 'E'))
			exit_game(data);
		if (data->map[data->p_line][data->p_char + 1] == 'C')
		{
			data->c_count--;
			if (data->c_count == 0)
			{
				if (data->map[data->e_line][data->e_char] == 'D')
					data->map[data->e_line][data->e_char] = 'Z';
				if (data->map[data->e_line][data->e_char] == '0')
					data->map[data->e_line][data->e_char] = 'E';
			}
		}
		data->p_char++;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line][data->p_char - 1] = '0';
		data->p_count++;
		render_map_images(data);
		display_score(data);
	}
}
