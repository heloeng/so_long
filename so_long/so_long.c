/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:18:14 by helde-so          #+#    #+#             */
/*   Updated: 2025/04/21 11:18:15 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_start(t_data data)
{
	if (check_map_errors(data) == TRUE)
		return (free_map_data(&data), exit(EXIT_FAILURE), TRUE);
	if (validate_map_characters(data) == TRUE)
		return (exit(EXIT_FAILURE), TRUE);
	copy_map_data(&data);
	count_collectibles(&data);
	if (check_valid_path(&data) == TRUE)
		return (free_map_dataall(&data), exit(EXIT_FAILURE), TRUE);
	free_map_datacpy(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_map_data(&data), free(data.mlx), 0);
	locate_player_and_exit(&data);
	data.window = mlx_new_window(data.mlx, data.nb_char * 48, data.nb_line * 48,
			"Trilha Limpa - Jogo da Mochileira");
	if (!data.window)
		return (0);
	load_game_images(&data);
	render_map_images(&data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &process_key_input, &data);
	mlx_hook(data.window, ClientMessage, 0, &end_game, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc != 2)
		return (ft_printf("Error\nYou need a map file in the 1st argument.\n"));
	if (is_valid_extension(arv[1]) == TRUE)
		return (ft_printf("Error\nNot a \".ber\" file.\n"), TRUE);
	ft_bzero(&data, sizeof(t_data));
	data.map = load_map_from_file(&data, arv[1]);
	if (!data.map)
		return (0);
	sl_start(data);
	return (0);
}
