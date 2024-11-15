/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_loose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:17:04 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 11:22:42 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	did_loose_left(t_data *data)
{
	int	text_width;

	text_width = ft_strlen("You Lost, Press ESC to exit") * 8;
	if (data->pose_y_char == data->pose_y_enemy \
		&& (data->pose_x_char - 1) == data->pose_x_enemy)
	{
		data->did_lose = 1;
		mlx_string_put(data->mlx, data->win, \
					((data->winsize_x * 32) / 2) - \
					(text_width / 2), (data->winsize_y * 32) / 2, \
					0xFFA500, "You Lost, Press ESC to exit");
	}
}

void	did_loose_down(t_data *data)
{
	int	text_width;

	text_width = ft_strlen("You Lost, Press ESC to exit") * 8;
	if ((data->pose_y_char + 1) == data->pose_y_enemy \
		&& data->pose_x_char == data->pose_x_enemy)
	{
		data->did_lose = 1;
		mlx_string_put(data->mlx, data->win, \
					((data->winsize_x * 32) / 2) - \
					(text_width / 2), (data->winsize_y * 32) / 2, \
					0xFFA500, "You Lost, Press ESC to exit");
	}
}

void	did_loose_right(t_data *data)
{
	int	text_width;

	text_width = ft_strlen("You Lost, Press ESC to exit") * 8;
	if (data->pose_y_char == data->pose_y_enemy \
		&& (data->pose_x_char + 1) == data->pose_x_enemy)
	{
		data->did_lose = 1;
		mlx_string_put(data->mlx, data->win, \
					((data->winsize_x * 32) / 2) - \
					(text_width / 2), (data->winsize_y * 32) / 2, \
					0xFFA500, "You Lost, Press ESC to exit");
	}
}

void	did_loose_up(t_data *data)
{
	int	text_width;

	text_width = ft_strlen("You Lost, Press ESC to exit") * 8;
	if ((data->pose_y_char - 1) == data->pose_y_enemy \
		&& data->pose_x_char == data->pose_x_enemy)
	{
		data->did_lose = 1;
		mlx_string_put(data->mlx, data->win, \
					((data->winsize_x * 32) / 2) - \
					(text_width / 2), (data->winsize_y * 32) / 2, \
					0xFFA500, "You Lost, Press ESC to exit");
	}
}
