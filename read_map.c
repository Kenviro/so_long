/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:52:48 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 10:40:03 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_loop(t_data *data, int array[2], char *temp, \
						int lines_allocated)
{
	while (temp != NULL)
	{
		if (data->y >= lines_allocated)
		{
			lines_allocated *= 2;
			data->map = realloc(data->map, lines_allocated * sizeof(char *));
			if (!data->map)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		data->map[data->y] = ft_strdup(temp);
		if (!data->map[data->y])
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		free(temp);
		data->y++;
		temp = get_next_line(array[0]);
	}
	data->map[data->y] = NULL;
	close(array[0]);
}

int	map_choice(t_data *data)
{
	int		map_open;
	char	*map;

	map_open = 0;
	if (data->filename != NULL)
		map_open = open(data->filename, O_RDONLY);
	else if (data->levelnbr <= 4)
	{
		map = malloc(10 * sizeof(char));
		ft_strcpy(map, "level");
		ft_strcat(map, ft_itoa(data->levelnbr));
		ft_strcat(map, ".ber");
		map_open = open(map, O_RDONLY);
		free (map);
	}
	else
	{
		ft_putstr_fd("Final level reached, Congrats!", 1);
		free_ressources(data);
		exit(EXIT_SUCCESS);
	}
	return (map_open);
}

void	read_map(t_data *data)
{
	char	*temp;
	int		array[2];
	int		lines_allocated;

	lines_allocated = 5000;
	array[0] = map_choice(data);
	temp = get_next_line(array[0]);
	if (array[0] == -1)
	{
		perror("Error opening .ber file");
		exit(EXIT_FAILURE);
	}
	data->map = malloc(lines_allocated * sizeof(char *));
	if (!data->map)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	data->y = 0;
	read_map_loop(data, array, temp, lines_allocated);
}
