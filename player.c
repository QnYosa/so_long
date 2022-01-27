/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:46:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/27 19:14:38 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_vars *g, int *x, int *y)
{
	while (g->map[++(*y)])
	{
		*x = -1;
		while (g->map[*y][++(*x)])
		{
			if (g->map[*y][(*x)] == 'P')
				return ;
		}
	}
	return ;
}

int	exit_allowed(t_vars *g)
{
	if (g->map[g->data.player_y][g->data.player_x] \
	== 'E' && g->data.collectibles == 0)
		return (1);
	return (0);
}

int	next_is_wall_or_exit(t_vars *g, int x, int y)
{
	if (g->map[y][x] == '1')
		return (0);
	if (g->map[y][x] == 'E' && g->data.collectibles != 0)
		return (0);
	return (1);
}

int	is_collectible(t_vars *g, int x, int y)
{
	if (g->map[y][x] == 'C')
	{
		g->map[y][x] = '0';
		return (1);
	}
	return (0);
}
