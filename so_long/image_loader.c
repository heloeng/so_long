#include "so_long.h"

static void	*f(t_data *data, char *file, int *width, int *height)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(data->mlx, file, width, height);
	if (!tmp)
	{
		ft_printf("Error\nInvalid image(s).\n");
		cleanup_game_resources(data);
		exit(EXIT_SUCCESS);
		return (NULL);
	}
	return (tmp);
}

static void	p_mlx_put_image_to_window(t_data *data, void *ptr, int i, int line)
{
	mlx_put_image_to_window(data->mlx, data->window, ptr,
		(i * 48), (line * 48));
}

int	load_game_images(t_data *data)
{
	data->img_0 = f(data, "./images/obstacle.xpm", &(data->w), &(data->h));
	data->img_1 = f(data, "./images/floor.xpm", &(data->w), &(data->h));
	data->img_c = f(data, "./images/collec.xpm", &(data->w), &(data->h));
	data->img_e = f(data, "./images/exit_open.xpm", &(data->w), &(data->h));
	data->img_z = f(data, "./images/exit_open.xpm", &(data->w), &(data->h));
	data->img_s = f(data, "./images/floor.xpm", &(data->w), &(data->h));
	data->img_p = f(data, "./images/player.xpm", &(data->w), &(data->h));
	data->img_u_p = f(data, "./images/player.xpm", &(data->w), &(data->h));
	data->img_l_p = f(data, "./images/player.xpm", &(data->w), &(data->h));
	data->img_d_p = f(data, "./images/player.xpm", &(data->w), &(data->h));
	data->img_r_p = f(data, "./images/player.xpm", &(data->w), &(data->h));
	data->img_dig = f(data, "./images/collec.xpm", &(data->w), &(data->h));
	return (0);
}

void	sl_player_images(t_data *data, int line, int i)
{
	if (data->map[line][i] == 'Z')
		p_mlx_put_image_to_window(data, data->img_z, i, line);
	if (data->map[line][i] == 'D')
		p_mlx_put_image_to_window(data, data->img_dig, i, line);
	if (data->direction == 0 && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_p, i, line);
	if (data->direction == UP && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_u_p, i, line);
	if (data->direction == LEFT && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_l_p, i, line);
	if (data->direction == DOWN && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_d_p, i, line);
	if (data->direction == RIGHT && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_r_p, i, line);
}

int	render_map_images(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[0][i] == '1')
				p_mlx_put_image_to_window(data, data->img_s, i, 0);
			if (data->map[line][i] == '1')
				p_mlx_put_image_to_window(data, data->img_1, i, line);
			if (data->map[line][i] == '0')
				p_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->c_count > 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->c_count == 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_e, i, line);
			if (data->map[line][i] == 'C')
				p_mlx_put_image_to_window(data, data->img_c, i, line);
			sl_player_images(data, line, i);
		}
	}
	return (0);
}
