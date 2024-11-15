/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:02 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 11:39:27 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ressources(t_data *data)
{
	data->y = 0;
	data->x = 0;
	data->pose_y_char = 0;
	data->pose_x_char = 0;
	data->pose_x_enemy = 0;
	data->pose_y_enemy = 0;
	data->enemy_nbr = 0;
	data->did_lose = 0;
	data->current_frame = 0;
	data->map = NULL;
	data->winsize_x = 0;
	data->winsize_y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->win = NULL;
	data->mlx = NULL;
}

void	next_level(t_data *data)
{
	data->levelnbr++;
	data->frozen = 0;
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	free_ressources(data);
	data->mlx = mlx_init();
	map(data);
	data->win = mlx_new_window(data->mlx, (data->winsize_x * 32), \
						(data->winsize_y * 32), "so_long");
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_ressources(data);
	exit(0);
}

int	count_enemy(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'B')
			{
				data->pose_x_enemy = x;
				data->pose_y_enemy = y;
				data->enemy_nbr++;
			}
			if (data->enemy_nbr > 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	enemy(t_data *data)
{
	int	x;
	int	y;
	int	enemy;

	enemy = count_enemy(data);
	if (enemy == 1)
		return (1);
	y = 0;
	x = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'P')
				if (data->map[y][x + 1] == 'B' || data->map[y][x - 1] == 'B' \
					|| data->map[y + 1][x] == 'B' || data->map[y - 1][x] == 'B')
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
