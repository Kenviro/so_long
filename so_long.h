/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:47:19 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/06 14:37:14 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define NUM_FRAMES 30
# define FRAME_RATE 30
# define BUFFER_SIZE 1234

# include "minilibx_opengl/mlx.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_char;
	void	*img_drake;
	void	*img_pig;
	void	*img_ground;
	void	*img_chest;
	void	*frames[NUM_FRAMES];
	void	*exit_frame[NUM_FRAMES];
	int		pose_y_char;
	int		pose_x_char;
	int		current_frame;
	int		x;
	int		y;
	int		nbr_movement;
	int		winsize_y;
	int		winsize_x;
	int		exit_y;
	int		exit_x;
	int		frozen;
	int		levelnbr;
	int		collectibles;
	char	*filename;
	char	**map;
}	t_data;

int		main(int argc, char **argv);
void	up_keycode(int keycode, t_data *data);
void	left_keycode(int keycode, t_data *data);
void	down_keycode(int keycode, t_data *data);
void	right_keycode(int keycode, t_data *data);
void	enter_keycode(int keycode, t_data *data, int i);
void	put_wall(t_data *data, int x, int y);
void	create_filename(char *filename, int index);
void	create_filename_exit(char *filename, int index);
void	render_frame(t_data *data);
void	put_character(t_data *data);
void	map(t_data *data);
void	frames(t_data *data, int i);
void	loop_main(t_data *data);
void	construct_map(t_data *data);
void	draw_exit(t_data *data);
void	free_ressources(t_data *data);
int		wall_frame(t_data *data, int i);
int		update(t_data *data);
int		key_hook(int keycode, t_data *data);
int		ft_strlen_solong(const char *str);
int		exit_frame(t_data *data, int i);
int		count_item(t_data *data);;
void	put_drake(t_data *data);
void	put_pig(t_data *data);
void	put_sprite(t_data *data);
void	put_exit(t_data *data);
void	draw_background(t_data *data);
void	draw_close_exit(t_data *data);
void	read_map(t_data *data);
char	*get_next_line(int fd);
void	end_game(t_data *data);
void	next_level(t_data *data);
int		close_window(t_data *data);
int		are_all_collectibles(t_data *data);
int		is_exit_accessible(t_data *data);
int		other_letter(t_data *data);

#endif
