/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:47:00 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/24 18:23:46 by ktintim-         ###   ########.fr       */
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

void	frames(t_data *data, int i)
{
	wall_frame(data, i);
	exit_frame(data, i);
	put_sprite(data);
	found_exit(data);
}

void	loop(t_data *data)
{
	mlx_loop_hook(data->mlx, update, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	data.filename = argv[1];
	if (argc != 2)
	{
		perror("Map not specified.");
		return (0);
	}
	data.nbr_movement = 0;
	data.mlx = mlx_init();
	printf("%s\n");
	map(&data);
	data.win = mlx_new_window(data.mlx, (data.winsize_x * 32), \
							(data.winsize_y * 32), "so_long");
	frames(&data, i);
	data.current_frame = 0;
	loop(&data);
	i = 0;
	while (i < NUM_FRAMES)
	{
		mlx_destroy_image(data.mlx, data.frames[i]);
		i++;
	}
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}
