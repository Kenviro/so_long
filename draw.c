/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:02:22 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/15 11:30:40 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_character(t_data *data)
{
	data->img_char = mlx_xpm_file_to_image(data->mlx, \
									"char_right.xpm", &(int){0}, &(int){0});
	if (!data->img_char)
	{
		perror("Error loading character image");
		return ;
	}
}

void	put_cat(t_data *data)
{
	data->img_enemy = mlx_xpm_file_to_image(data->mlx, \
									"enemy.xpm", &(int){0}, &(int){0});
	if (!data->img_enemy)
	{
		perror("Error loading character image");
		return ;
	}
}

void	put_pig(t_data *data)
{
	data->img_pig = mlx_xpm_file_to_image(data->mlx, \
									"pig.xpm", &(int){0}, &(int){0});
	if (!data->img_pig)
	{
		perror("Error loading character image");
		return ;
	}
}

void	put_ground(t_data *data)
{
	data->img_ground = mlx_xpm_file_to_image(data->mlx, \
									"ground.xpm", &(int){0}, &(int){0});
	if (!data->img_ground)
	{
		perror("Error loading character image");
		return ;
	}
}

void	put_sprite(t_data *data)
{
	put_character(data);
	put_cat(data);
	put_pig(data);
	put_ground(data);
}
