/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:07:14 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 14:17:14 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_ressources(data);
		exit(0);
	}
	up_keycode(keycode, data);
	left_keycode(keycode, data);
	down_keycode(keycode, data);
	right_keycode(keycode, data);
	enter_keycode(keycode, data, 0);
	render_frame(data);
	return (0);
}

int	ft_strlen_solong(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	other_letter(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && \
				data->map[y][x] != 'P' && data->map[y][x] != 'C' && \
				data->map[y][x] != 'E' && data->map[y][x] != 'B')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	calculate_distance(int x1, int y1, int x2, int y2)
{
	return (abs(x2 - x1) + abs(y2 - y1));
}
