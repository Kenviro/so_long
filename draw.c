/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:02:22 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/23 13:58:12 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_character(t_data *data)
{
	data->img_char = mlx_xpm_file_to_image(data->mlx, \
									"character.xpm", &(int){0}, &(int){0});
	if (!data->img_char)
	{
		perror("Error loading character image");
		return ;
	}
}

void	put_drake(t_data *data)
{
	data->img_drake = mlx_xpm_file_to_image(data->mlx, \
									"Drake.xpm", &(int){0}, &(int){0});
	if (!data->img_drake)
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
	put_drake(data);
	put_pig(data);
	put_ground(data);
}
