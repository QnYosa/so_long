/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dress_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:29:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/25 23:57:56 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_img_part_2(char c, t_vars *g, int x, int y)
{
	if (c == '0')
	{
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[3].img, x, y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[4].img, x, y);
	}
}

void	choose_img_part_1(char c, t_vars *g, int x, int y)
{
	if (c == '1')
	{
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[0].img, x, y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[1].img, x, y);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(g->data.mlx_ptr, g->data.win_ptr, \
		g->image[2].img, x, y);
		g->data.collectibles++;
	}
	else
		choose_img_part_2(c, g, x, y);
}

int	dress_table(t_vars *g)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (g->map[++i])
	{
		j = -1;
		x = 0;
		while (g->map[i][++j])
		{
			choose_img_part_1(g->map[i][j], g, x, y);
			x += 40;
		}
		y += 40;
	}
	return (0);
}
