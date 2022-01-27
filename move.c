/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:45:28 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/27 19:57:39 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_allowed(t_vars *g, int n)
{
	if (n == UP)
	{
		if (!next_is_wall_or_exit(g, g->data.player_x, g->data.player_y - 1))
			return (0);
	}
	else if (n == DOWN)
	{
		if (!next_is_wall_or_exit(g, g->data.player_x, g->data.player_y + 1))
			return (0);
	}
	else if (n == LEFT)
	{
		if (!next_is_wall_or_exit(g, g->data.player_x - 1, g->data.player_y))
			return (0);
	}
	else if (n == RIGHT)
	{
		if (!next_is_wall_or_exit(g, g->data.player_x + 1, g->data.player_y))
			return (0);
	}
	return (1);
}

int	change_position(t_vars *g, int n)
{
	if (n == UP)
		g->data.player_y--;
	else if (n == DOWN)
		g->data.player_y++;
	else if (n == LEFT)
		g->data.player_x--;
	else if (n == RIGHT)
		g->data.player_x++;
	return (1);
}

int	move_maestro(t_vars *g, int n)
{
	if (!move_allowed(g, n))
		return (0);
	g->steps++;
	change_position(g, n);
	if (is_collectible(g, g->data.player_x, g->data.player_y))
		g->data.collectibles--;
	printf("\E[H\E[2J");
	printf("steps = %d\n", g->steps);
	player_moved(n, g);
	if (exit_allowed(g))
	{
		end_game(g);
		exit(0);
	}
	return (1);
}
