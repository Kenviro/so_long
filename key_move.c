/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:07:18 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/28 10:52:09 by ktintim-         ###   ########.fr       */
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
			free(data->img_char);
			data->img_char = mlx_xpm_file_to_image(data->mlx, "char_left.xpm", \
									&(int){0}, &(int){0});
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
			free(data->img_char);
			data->img_char = mlx_xpm_file_to_image(data->mlx, "char_right.xpm", \
									&(int){0}, &(int){0});
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
			if (data->filename == NULL)
			{
				next_level(data);
				frames(data, 0);
				loop_main(data);
				while (i < NUM_FRAMES)
				{
					mlx_destroy_image(data->mlx, data->frames[i]);
					i++;
				}
			}
			else
			{
				ft_putstr_fd("Congrats! You have completed the level.", 1);
				free_ressources(data);
				exit(EXIT_SUCCESS);
			}
		}
	}
}
