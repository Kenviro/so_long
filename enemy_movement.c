/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:30:17 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 11:18:59 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_enemy(t_data *data)
{
	data->map[data->pose_y_enemy][data->pose_x_enemy] = '0';
	data->map[data->pose_y_enemy][data->pose_x_enemy - 1] = 'B';
}

void	down_enemy(t_data *data)
{
	data->map[data->pose_y_enemy][data->pose_x_enemy] = '0';
	data->map[data->pose_y_enemy + 1][data->pose_x_enemy] = 'B';
}

void	right_enemy(t_data *data)
{
	data->map[data->pose_y_enemy][data->pose_x_enemy] = '0';
	data->map[data->pose_y_enemy][data->pose_x_enemy + 1] = 'B';
}

void	up_enemy(t_data *data)
{
	data->map[data->pose_y_enemy][data->pose_x_enemy] = '0';
	data->map[data->pose_y_enemy - 1][data->pose_x_enemy] = 'B';
}

int	is_that_valid(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1' || data->map[y][x] == 'E' || \
			data->map[y][x] == 'C')
		return (0);
	return (1);
}
