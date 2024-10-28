/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:42 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/28 15:35:46 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tester1(t_data *data)
{
	int	len;
	int	len_test;
	int	y;

	y = 0;
	len = ft_strlen_solong(data->map[y]);
	while (data->map[y] != NULL)
	{
		len_test = ft_strlen_solong(data->map[y]);
		if (len_test != len)
			return (1);
		y++;
	}
	return (0);
}

int	tester2(t_data *data)
{
	int	variable[4];

	variable[0] = 0;
	variable[1] = 0;
	variable[3] = 0;
	data->collectibles = 0;
	while (data->map[variable[1]])
	{
		variable[2] = 0;
		while (data->map[variable[1]][variable[2]] != '\0')
		{
			if (data->map[variable[1]][variable[2]] == 'E')
				variable[0]++;
			else if (data->map[variable[1]][variable[2]] == 'P')
				variable[3]++;
			else if (data->map[variable[1]][variable[2]] == 'C')
				data->collectibles++;
			variable[2]++;
		}
		variable[1]++;
	}
	if (variable[0] != 1 || data->collectibles == 0 || variable[3] != 1)
		return (1);
	return (0);
}

int	tester3(t_data *data)
{
	int	y;
	int	x;
	int	len;
	int	height;

	y = 0;
	x = 0;
	height = 0;
	len = ft_strlen_solong(data->map[0]);
	while (data->map[height] != NULL)
		height++;
	while (x < len)
	{
		if (data->map[0][x] != '1' || data->map[height - 1][x] != '1')
			return (1);
		x++;
	}
	while (y < height)
	{
		if (data->map[y][0] != '1' || data->map[y][len - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

void	map(t_data *data)
{
	int	test;

	read_map(data);
	test = tester1(data);
	if (test == 0)
		test = tester2(data);
	if (test == 0)
		test = tester3(data);
	if (test == 0)
		test = other_letter(data);
	data->winsize_x = ft_strlen_solong(data->map[0]);
	data->winsize_y = 0;
	while (data->map[data->winsize_y] != NULL)
		data->winsize_y++;
	if (test == 0)
		test = are_all_collectibles(data);
	if (test == 0)
		test = is_exit_accessible(data);
	if (test == 1)
	{
		perror("Error\nInvalid map.");
		exit(EXIT_FAILURE);
	}
}
