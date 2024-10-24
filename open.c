/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:42 by ktintim-          #+#    #+#             */
/*   Updated: 2024/10/24 18:57:17 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_data *data, const char *map_name)
{
	char	*temp;
	int		array[2];

	array[0] = open(map_name, O_RDONLY);
	if (array[0] == -1)
	{
		perror("Error opening .ber file");
		exit(EXIT_FAILURE);
	}
	data->y = 0;
	temp = get_next_line(array[0]);
	printf("temp: %s\n", temp);
	while (temp != NULL)
	{
		array[1] = ft_strlen(temp);
		printf("temp: %s\n", temp);
		data->map[data->y] = malloc((array[1] + 1) * sizeof(char));
		printf("temp: %s\n", temp);
		if (!data->map[data->y])
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		ft_strcpy(data->map[data->y], temp);
		data->y++;
		temp = get_next_line(array[0]);
	}
	printf("Map name: %s\n", map_name);
	data->map[data->y] = NULL;
	close(array[0]);
}

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
	int	variable[5];

	variable[0] = 0;
	variable[1] = 0;
	variable[2] = 0;
	variable[4] = 0;
	while (data->map[variable[2]])
	{
		variable[3] = 0;
		while (data->map[variable[2]][variable[3]] != '\0')
		{
			if (data->map[variable[2]][variable[3]] == 'E')
				variable[0]++;
			else if (data->map[variable[2]][variable[3]] == 'P')
				variable[4]++;
			else if (data->map[variable[2]][variable[3]] == 'C')
				variable[1]++;
			variable[3]++;
		}
		variable[2]++;
	}
	if (variable[0] != 1 || variable[1] == 0 || variable[4] != 1)
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

void	map(t_data *data, const char *map_name)
{
	int	test;

	printf("%s\n", map_name);
	read_map(data, map_name);
	test = tester1(data);
	if (test == 0)
		test = tester2(data);
	if (test == 0)
		test = tester3(data);
	if (test == 1)
	{
		perror("Error\nInvalid map.");
		exit(EXIT_FAILURE);
	}
	data->winsize_x = ft_strlen_solong(data->map[0]);
	data->winsize_y = 0;
	while (data->map[data->winsize_y] != NULL)
		data->winsize_y++;
}
