#include "so_long.h"

void	free_game_images(t_data *data)
{
	if (data->img_s)
		mlx_destroy_image(data->mlx, data->img_s);
	if (data->img_0)
		mlx_destroy_image(data->mlx, data->img_0);
	if (data->img_1)
		mlx_destroy_image(data->mlx, data->img_1);
	if (data->img_e)
		mlx_destroy_image(data->mlx, data->img_e);
	if (data->img_z)
		mlx_destroy_image(data->mlx, data->img_z);
	if (data->img_c)
		mlx_destroy_image(data->mlx, data->img_c);
	if (data->img_p)
		mlx_destroy_image(data->mlx, data->img_p);
	if (data->img_u_p)
		mlx_destroy_image(data->mlx, data->img_u_p);
	if (data->img_l_p)
		mlx_destroy_image(data->mlx, data->img_l_p);
	if (data->img_d_p)
		mlx_destroy_image(data->mlx, data->img_d_p);
	if (data->img_r_p)
		mlx_destroy_image(data->mlx, data->img_r_p);
	if (data->img_dig)
		mlx_destroy_image(data->mlx, data->img_dig);
}

void	free_map_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_map_datacpy(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_copy[i])
		free(data->map_copy[i++]);
	free(data->map_copy);
}

void	free_map_dataall(t_data *data)
{
	free_map_data(data);
	free_map_datacpy(data);
}

void	cleanup_game_resources(t_data *data)
{
	if (data)
	{
		free_map_data(data);
		free_game_images(data);
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		data->window = 0;
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
