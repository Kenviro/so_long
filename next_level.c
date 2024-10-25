/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:02 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/25 17:44:51 by ktintim-         ###   ########.fr       */
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
