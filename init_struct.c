/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:42:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/20 23:12:54 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *g, int argc, char **argv)
{
	g->ac = argc;
	g->av = argv;
	g->map = NULL;
	g->nb_lines = 0;
}
