/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createfilename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:24:42 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/25 14:15:11 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_filename(char *filename, int index)
{
	char	index_str[3];

	ft_strcpy(filename, "Frames/frame");
	if (index < 10)
	{
		index_str[0] = '0' + index;
		index_str[1] = '\0';
	}
	else
	{
		index_str[0] = '0' + (index / 10);
		index_str[1] = '0' + (index % 10);
		index_str[2] = '\0';
	}
	ft_strcat(filename, index_str);
	ft_strcat(filename, ".xpm");
}

void	create_filename_exit(char *filename, int index)
{
	char	index_str[3];

	ft_strcpy(filename, "portal_frame/frame");
	if (index < 10)
	{
		index_str[0] = '0' + index;
		index_str[1] = '\0';
	}
	else
	{
		index_str[0] = '0' + (index / 10);
		index_str[1] = '0' + (index % 10);
		index_str[2] = '\0';
	}
	ft_strcat(filename, index_str);
	ft_strcat(filename, ".xpm");
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->winsize_y * 32)
	{
		x = 0;
		while (x < data->winsize_x * 32)
		{
			mlx_put_image_to_window(data->mlx, data->win, \
									data->img_ground, x, y);
			x += 32;
		}
		y += 32;
	}
}
