/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:07:34 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/24 16:07:13 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_item(t_data *data)
{
	int	item;
	int	temp_y;
	int	temp_x;

	item = 0;
	temp_x = 0;
	temp_y = 0;
	item = 0;
	while (data->map[temp_y] != NULL)
	{
		temp_x = 0;
		while (data->map[temp_y][temp_x] != '\0' \
				&& data->map[temp_y][temp_x] != '\n')
		{
			if (data->map[temp_y][temp_x] == 'C')
				item++;
			temp_x++;
		}
		temp_y++;
	}
	return (item);
}

void	put_exit(t_data *data)
{
	int	item;

	item = count_item(data);
	if (item == 0)
		draw_exit(data);
	else
		draw_close_exit(data);
}

int	exit_frame(t_data *data, int i)
{
	char	filename[25];

	while (i < NUM_FRAMES)
	{
		create_filename_exit(filename, i);
		data->exit_frame[i] = mlx_xpm_file_to_image(data->mlx, \
											filename, &(int){0}, &(int){0});
		if (!data->exit_frame[i])
		{
			perror("Error loading exit image");
			exit (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

void	draw_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, \
		data->exit_frame[data->current_frame], \
		data->exit_x * 32, data->exit_y * 32);
}

void	draw_close_exit(t_data *data)
{
	data->img_chest = mlx_xpm_file_to_image(data->mlx, \
									"close_door.xpm", &(int){0}, &(int){0});
	if (!data->img_chest)
	{
		perror("Error loading character image");
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img_chest, data->exit_x * 32, data->exit_y * 32);
}
