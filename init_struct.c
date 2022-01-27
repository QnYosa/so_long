/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:42:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/25 23:53:40 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	init_struct(int argc, char **argv)
{
	t_vars	g;

	g.fd = 0;
	g.ac = argc;
	g.av = argv;
	g.width = 0;
	g.steps = 0;
	g.map = NULL;
	g.height = 0;
	g.nb_lines = 0;
	g.data.player_x = -1;
	g.data.player_y = -1;
	g.data.win_ptr = NULL;
	g.data.mlx_ptr = NULL;
	g.data.mlx_win = NULL;
	g.image[0].img = NULL;
	g.image[1].img = NULL;
	g.image[2].img = NULL;
	g.image[3].img = NULL;
	g.image[4].img = NULL;
	g.data.collectibles = 0;
	return (g);
}
