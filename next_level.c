/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:02 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/28 11:16:27 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ressources(t_data *data)
{
	data->y = 0;
	data->x = 0;
	data->pose_y_char = 0;
	data->pose_x_char = 0;
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
