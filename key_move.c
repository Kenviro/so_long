/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:07:18 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/25 17:38:01 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_keycode(int keycode, t_data *data)
{
	if (keycode == 0)
	{
		if (data->map[data->pose_y_char][data->pose_x_char - 1] != '1' && \
			(data->map[data->pose_y_char][data->pose_x_char - 1] != 'E' \
			|| count_item(data) == 0))
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char][data->pose_x_char - 1] = 'P';
			data->pose_x_char = data->pose_x_char - 1;
			data->nbr_movement++;
		}
	}
}

void	down_keycode(int keycode, t_data *data)
{
	if (keycode == 1)
	{
		if (data->map[data->pose_y_char + 1][data->pose_x_char] != '1' && \
			(data->map[data->pose_y_char + 1][data->pose_x_char] != 'E' \
			|| count_item(data) == 0))
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char + 1][data->pose_x_char] = 'P';
			data->pose_y_char = data->pose_y_char + 1;
			data->nbr_movement++;
		}
	}
}

void	right_keycode(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		if (data->map[data->pose_y_char][data->pose_x_char + 1] != '1' && \
			(data->map[data->pose_y_char][data->pose_x_char + 1] != 'E' \
			|| count_item(data) == 0))
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char][data->pose_x_char + 1] = 'P';
			data->pose_x_char = data->pose_x_char + 1;
			data->nbr_movement++;
		}
	}
}

void	up_keycode(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		if (data->map[data->pose_y_char - 1][data->pose_x_char] != '1' && \
			(data->map[data->pose_y_char - 1][data->pose_x_char] != 'E' \
			|| count_item(data) == 0))
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char - 1][data->pose_x_char] = 'P';
			data->pose_y_char = data->pose_y_char - 1;
			data->nbr_movement++;
		}
	}
}

void	enter_keycode(int keycode, t_data *data, int i)
{
	if (keycode == 36)
	{
		if (data->frozen == 1)
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
			frames(data, 0);
			loop(data);
			while (i < NUM_FRAMES)
			{
				mlx_destroy_image(data->mlx, data->frames[i]);
				i++;
			}
		}
	}
}
