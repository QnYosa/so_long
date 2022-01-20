/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/20 23:26:29 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/keysym.h>


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	int		ac;
	char	**av;
	char	**map;
	int		nb_lines;
	void	*mlx_win;
	t_data	window;
	t_data	img;
	t_data	data;
}	t_game;

int		parse_and_check_errors(t_game *g);
int		right_number_pce(char **map);
int		walls(char **map, int max);

/*	error messages	*/
int		error_messages_game(int tab[3]);
int		error_messages_parser(int n);

/*	init_struct */
void	init_struct(t_game *g, int argc, char **argv);

/*	errors	*/
int		check_errors(t_game *g);

/*	utils.c		*/
int		is_part(char c);

/*	Leaks.c */
void	free_d_tab(char **map);

/*	handles.c */
int		handle_input(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_keypress(int keysym, t_data *data);

#endif