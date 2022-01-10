/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/10 19:58:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/keysym.h>

typedef struct s_game
{
	int		ac;
	char	**av;
	int		hola;
}	t_game;

int	init_parse(t_game *g, int argc, char **argv);
int	parsing_maestro(t_game *g);

#endif