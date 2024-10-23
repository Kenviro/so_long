/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:54:02 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/23 17:52:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	construct_map(t_data *data)
{
	while (data->map[data->y] != NULL)
	{
		data->x = 0;
		while (data->map[data->y][data->x] != '\0' \
				&& data->map[data->y][data->x] != '\n')
		{
			if (data->map[data->y][data->x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
						data->frames[data->current_frame], data->x * 32, data->y * 32);
			if (data->map[data->y][data->x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, \
										data->img_char, data->x * 32, data->y * 32);
				data->pose_y_char = data->y;
				data->pose_x_char = data->x;
			}
			if (data->map[data->y][data->x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img_pig, \
									data->x * 32, data->y * 32);
			data->x++;
		}
		data->y++;
	}
}

void	render_frame(t_data *data)
{
	char	*movement;

	data->y = 0;
	mlx_clear_window(data->mlx, data->win);
	draw_background(data);
	construct_map(data);
	movement = ft_itoa(data->nbr_movement);
	mlx_string_put(data->mlx, data->win, 15, 15, 0xFFFFFF, movement);
	free (movement);
}

int	update(t_data *data)
{
	data->current_frame = (data->current_frame + 1) % NUM_FRAMES;
	render_frame(data);
	return (0);
}

int	wall_frame(t_data *data, int i)
{
	char	filename[20];

	while (i < NUM_FRAMES)
	{
		create_filename(filename, i);
		data->frames[i] = mlx_xpm_file_to_image(data->mlx, \
											filename, &(int){0}, &(int){0});
		if (!data->frames[i])
		{
			perror("Error loading wall image");
			return (1);
		}
		i++;
	}
	return (0);
}
