/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:47:00 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 14:16:48 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	found_exit(t_data *data)
{
	data->y = 0;
	while (data->map[data->y] != NULL)
	{
		data->x = 0;
		while (data->map[data->y][data->x] != '\0' \
				&& data->map[data->y][data->x] != '\n')
		{
			if (data->map[data->y][data->x] == 'E')
			{
				data->exit_x = data->x;
				data->exit_y = data->y;
			}
			data->x++;
		}
		data->y++;
	}
}

void	end_game(t_data *data)
{
	if (data->pose_y_char == data->exit_y && data->pose_x_char == data->exit_x)
	{
		data->frozen = 1;
	}
}

void	frames(t_data *data, int i)
{
	wall_frame(data, i);
	exit_frame(data, i);
	put_sprite(data);
	found_exit(data);
}

void	loop_main(t_data *data)
{
	mlx_loop_hook(data->mlx, update, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	ft_bzero(&data, sizeof(t_data));
	if (argc == 2)
		data.filename = argv[1];
	else
		data.filename = NULL;
	data.levelnbr = 1;
	data.mlx = mlx_init();
	map(&data);
	data.win = mlx_new_window(data.mlx, (data.winsize_x * 32), \
							(data.winsize_y * 32), "so_long");
	frames(&data, i);
	loop_main(&data);
	i = 0;
	while (i < NUM_FRAMES)
	{
		mlx_destroy_image(data.mlx, data.frames[i]);
		i++;
	}
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}
