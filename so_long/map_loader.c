/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:17:53 by helde-so          #+#    #+#             */
/*   Updated: 2025/04/21 11:17:54 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	locate_player_and_exit(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	data->direction = 0;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == 'E')
			{
				data->e_line = line;
				data->e_char = i;
			}
			if (data->map[line][i] == 'P')
			{
				data->p_line = line;
				data->p_char = i;
			}
		}
	}
	return (0);
}

void	count_collectibles_line(t_data *data, int fd, char *filename)
{
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	data->nb_line = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->nb_line++;
		data->nb_char = ft_line_len(line);
		free(line);
	}
	close(fd);
}

char	**load_map_from_file(t_data *data, char *filename)
{
	int	fd;

	fd = 0;
	count_collectibles_line(data, fd, filename);
	if (!data->nb_line)
	{
		ft_printf("Error\nMap not found.\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->nb_line + 1));
	if (data->map == NULL)
		return (NULL);
	data->x = 0;
	while (TRUE)
	{
		data->map[data->x] = get_next_line(fd);
		if (data->map[data->x] == NULL)
			break ;
		data->x++;
	}
	close(fd);
	return (data->map);
}

char	**copy_map_data(t_data *data)
{
	char	**map_copy;
	int		i;

	i = -1;
	map_copy = malloc((data->nb_line + 1) * sizeof(char *));
	if (!map_copy)
	{
		data->map_copy = 0;
		return (0);
	}
	while (data->map[++i])
		map_copy[i] = ft_strdup(data->map[i]);
	map_copy[i] = 0;
	data->map_copy = map_copy;
	return (map_copy);
}
