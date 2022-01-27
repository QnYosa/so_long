/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/27 18:39:27 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/keysym.h>

# define SO_LONG_H
# define MLX_ERROR -1

# define NAME "Yu Yu Hakusho"
# define WALL "images/carre_bleu.xpm"
# define PLAYER "images/jaune.xpm"
# define COLLECTIBLE "images/r_pale.xpm"
# define FLOOR "images/gris.xpm"
# define EXIT "images/vert.xpm"

# define LEFT 'a'
# define UP 'w'
# define RIGHT 'd'
# define DOWN 's'

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*adress;
	int		bpp;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*win_ptr;
	int		player_x;
	int		player_y;
	int		collectibles;
}	t_data;

typedef struct s_vars
{
	int		ac;
	char	**av;
	char	**map;
	int		nb_lines;
	int		width;
	int		height;
	int		steps;
	int		fd;
	t_data	window;
	t_data	img;
	t_data	data;
	t_img	image[5];
}	t_vars;

int		parse_and_check_errors(t_vars *g);
int		right_number_pce(char **map, t_vars *g);
int		walls(char **map, int max);

/*	error messages	*/
int		error_messages_game(int tab[3], t_vars *g);
int		error_messages_parser(int n);

/*	init_struct */
t_vars	init_struct(int argc, char **argv);

/*	errors	*/
int		check_errors(t_vars *g);

/*	errors.c	*/
int		check_file(char *file);
int		check_errors(t_vars *g);

/*	utils.c		*/
int		is_part(char c);
int		size_d_tab(char **map);

/*	Leaks.c */
void	free_d_tab(char **map);
int		end_game(t_vars *g);
int		free_pre_game(t_vars *g);

/*	handles.c */
int		handle_input(int keysym, t_vars *g);
int		handle_keypress(int keysym,	t_vars *g);

/*	pixel.c	*/
int		encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);

/*	window.c	*/
int		size_window(t_vars *g);

/*	dress_map.c	*/
int		dress_table(t_vars *g);
/*	player.c	*/
void	find_player_position(t_vars *g, int *x, int *y);
int		exit_allowed(t_vars *g);
int		next_is_wall_or_exit(t_vars *g, int x, int y);
int		is_collectible(t_vars *g, int x, int y);

/*	move.c	*/
int		move_maestro(t_vars *g, int n);

/*	move_img.c	*/
void	player_moved(int n, t_vars *g);

/*	image.c		*/
void	test_image(t_vars *g);
int		check_image(const char *filename, t_vars *g);
int		xpm_to_image(t_vars *g);

#endif