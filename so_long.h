/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/15 21:57:28 by dyoula           ###   ########.fr       */
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

/*	init_struct */
void	init_struct(t_game *g, int argc, char **argv);

/*	errors	*/
int		check_errors(t_game *g);

#endif