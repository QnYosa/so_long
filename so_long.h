/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/16 17:01:01 by dyoula           ###   ########.fr       */
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

typedef struct s_game
{
	int		ac;
	char	**av;
	char	**map;
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

#endif