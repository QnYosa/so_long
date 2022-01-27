/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:31:19 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/25 18:12:56 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_pixels(t_vars *g)
{
	int	pix_x;
	int	pix_y;

	pix_x = g->data.player_x * 40;
	pix_y = g->data.player_y * 40;
	mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[1].img, pix_x, pix_y);
	return (1);
}

int	find_previous(t_vars *g, int x, int y)
{
	int	pix_x;
	int	pix_y;

	pix_x = x * 40;
	pix_y = y * 40;
	mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[3].img, pix_x, pix_y);
	return (1);
}

void	player_moved(int n, t_vars *g)
{
	if (n == UP)
	{
		find_pixels(g);
		find_previous(g, g->data.player_x, g->data.player_y + 1);
		return ;
	}
	else if (n == DOWN)
	{
		find_pixels(g);
		find_previous(g, g->data.player_x, g->data.player_y - 1);
		return ;
	}
	else if (n == LEFT)
	{
		find_pixels(g);
		find_previous(g, g->data.player_x + 1, g->data.player_y);
		return ;
	}
	else if (n == RIGHT)
	{
		find_pixels(g);
		find_previous(g, g->data.player_x - 1, g->data.player_y);
		return ;
	}
}
