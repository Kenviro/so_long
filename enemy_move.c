/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:31:32 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/19 11:09:34 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_move
{
	int	dx;
	int	dy;
	int	distance;
}	t_move;

void	enemy_map(t_data *data)
{
	if (data->frozen != 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img_enemy, data->x * 32, data->y * 32);
		data->pose_y_enemy = data->y;
		data->pose_x_enemy = data->x;
	}
}

void	sort_moves_by_distance(t_move moves[], int num_moves)
{
	t_move	temp;
	int		i;
	int		j;

	i = 0;
	while (i < num_moves - 1)
	{
		j = 0;
		while (j < num_moves - i - 1)
		{
			if (moves[j].distance > moves[j + 1].distance)
			{
				temp = moves[j];
				moves[j] = moves[j + 1];
				moves[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	enemy_move(t_data *data, t_move moves[4], int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		new_x = data->pose_x_enemy + moves[i].dx;
		new_y = data->pose_y_enemy + moves[i].dy;
		if (is_that_valid(data, new_x, new_y))
		{
			if (moves[i].dx == 1 && moves[i].dy == 0)
				right_enemy(data);
			else if (moves[i].dx == -1 && moves[i].dy == 0)
				left_enemy(data);
			else if (moves[i].dx == 0 && moves[i].dy == 1)
				down_enemy(data);
			else if (moves[i].dx == 0 && moves[i].dy == -1)
				up_enemy(data);
			data->pose_x_enemy = new_x;
			data->pose_y_enemy = new_y;
			break ;
		}
		i++;
	}
}

void	move_enemy_towards_player(t_data *data)
{
	int		new_x;
	int		new_y;
	t_move	moves[4];

	new_x = 0;
	new_y = 0;
	moves[0].dx = 1;
	moves[0].dy = 0;
	moves[0].distance = calculate_distance(data->pose_x_enemy + 1, \
		data->pose_y_enemy, data->pose_x_char, data->pose_y_char);
	moves[1].dx = -1;
	moves[1].dy = 0;
	moves[1].distance = calculate_distance(data->pose_x_enemy - 1, \
		data->pose_y_enemy, data->pose_x_char, data->pose_y_char);
	moves[2].dx = 0;
	moves[2].dy = 1;
	moves[2].distance = calculate_distance(data->pose_x_enemy, \
		data->pose_y_enemy + 1, data->pose_x_char, data->pose_y_char);
	moves[3].dx = 0;
	moves[3].dy = -1;
	moves[3].distance = calculate_distance(data->pose_x_enemy, \
		data->pose_y_enemy - 1, data->pose_x_char, data->pose_y_char);
	sort_moves_by_distance(moves, 4);
	enemy_move(data, moves, new_x, new_y);
}
