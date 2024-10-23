/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:47:00 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/23 17:53:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;
	int		i;

	data.nbr_movement = 0;
	i = 0;
	data.mlx = mlx_init();
	map(&data);
	data.win = mlx_new_window(data.mlx, (data.winsize_x * 32), \
							(data.winsize_y * 32), "so_long");
	wall_frame(&data, i);
	put_sprite(&data);
	data.current_frame = 0;
	mlx_loop_hook(data.mlx, update, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	i = 0;
	while (i < NUM_FRAMES)
	{
		mlx_destroy_image(data.mlx, data.frames[i]);
		i++;
	}
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}
