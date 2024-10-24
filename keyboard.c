/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:07:14 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/24 16:00:18 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_key(int keycode, t_data *data)
{
	if (keycode == 0)
	{
		if (data->map[data->pose_y_char][data->pose_x_char - 1] != '1' \
			&& data->map[data->pose_y_char][data->pose_x_char - 1] != 'E')
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char][data->pose_x_char - 1] = 'P';
			data->pose_x_char = data->pose_x_char - 1;
		}
	}
}

void	left_down_right(int keycode, t_data *data)
{
	left_key(keycode, data);
	if (keycode == 1)
	{
		if (data->map[data->pose_y_char + 1][data->pose_x_char] != '1' \
			&& data->map[data->pose_y_char + 1][data->pose_x_char] != 'E')
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char + 1][data->pose_x_char] = 'P';
			data->pose_y_char = data->pose_y_char + 1;
		}
	}
	else if (keycode == 2)
	{
		if (data->map[data->pose_y_char][data->pose_x_char + 1] != '1' \
			&& data->map[data->pose_y_char][data->pose_x_char + 1] != 'E')
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char][data->pose_x_char + 1] = 'P';
			data->pose_x_char = data->pose_x_char + 1;
		}
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 13)
	{
		if (data->map[data->pose_y_char - 1][data->pose_x_char] != '1' \
			&& data->map[data->pose_y_char - 1][data->pose_x_char] != 'E')
		{
			data->map[data->pose_y_char][data->pose_x_char] = '0';
			data->map[data->pose_y_char - 1][data->pose_x_char] = 'P';
			data->pose_y_char = data->pose_y_char - 1;
		}
	}
	left_down_right(keycode, data);
	render_frame(data);
	data->nbr_movement++;
	return (0);
}

int	ft_strlen_solong(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
