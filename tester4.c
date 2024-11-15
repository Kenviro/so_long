/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:32:44 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/14 11:05:02 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	found_character(t_data *data)
{
	data->y = 0;
	while (data->map[data->y] != NULL)
	{
		data->x = 0;
		while (data->map[data->y][data->x] != '\0' \
				&& data->map[data->y][data->x] != '\n')
		{
			if (data->map[data->y][data->x] == 'P')
			{
				data->pose_x_char = data->x;
				data->pose_y_char = data->y;
			}
			data->x++;
		}
		data->y++;
	}
}

int	count_accessible_collectibles(t_data *data, int x, int y, int *visited)
{
	int	count;

	count = 0;
	if (x < 0 || y < 0 || x >= data->winsize_x || y >= data->winsize_y)
		return (0);
	if (data->map[y][x] == '1' || data->map[y][x] == 'E' || \
								visited[y * data->winsize_x + x])
		return (0);
	if (data->map[y][x] == 'C')
	{
		visited[y * data->winsize_x + x] = 1;
		count = 1;
	}
	visited[y * data->winsize_x + x] = 1;
	count += count_accessible_collectibles(data, x + 1, y, visited);
	count += count_accessible_collectibles(data, x - 1, y, visited);
	count += count_accessible_collectibles(data, x, y + 1, visited);
	count += count_accessible_collectibles(data, x, y - 1, visited);
	return (count);
}

int	are_all_collectibles(t_data *data)
{
	int	*visited;
	int	count;

	visited = ft_calloc(data->winsize_x * data->winsize_y, sizeof(int));
	if (!visited)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	found_character(data);
	count = count_accessible_collectibles(data, data->pose_x_char, \
										data->pose_y_char, visited);
	free (visited);
	if (count == data->collectibles)
		return (0);
	return (1);
}

int	found_accessible_exit(t_data *data, int x, int y, int *visited)
{
	if (x < 0 || y < 0 || x >= data->winsize_x || y >= data->winsize_y)
		return (1);
	if (data->map[y][x] == '1' || data->map[y][x] == 'B' || \
			visited[y * data->winsize_x + x])
		return (1);
	if (data->map[y][x] == 'E')
		return (0);
	visited[y * data->winsize_x + x] = 1;
	if (found_accessible_exit(data, x + 1, y, visited) == 0 || \
		found_accessible_exit(data, x - 1, y, visited) == 0 || \
		found_accessible_exit(data, x, y + 1, visited) == 0 || \
		found_accessible_exit(data, x, y - 1, visited) == 0)
	{
		return (0);
	}
	return (1);
}

int	is_exit_accessible(t_data *data)
{
	int	*visited;
	int	result;

	visited = ft_calloc(data->winsize_x * data->winsize_y, sizeof(int));
	if (!visited)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	result = found_accessible_exit(data, data->pose_x_char, \
								data->pose_y_char, visited);
	free(visited);
	return (result);
}
