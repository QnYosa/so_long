/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:10:54 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/26 00:07:46 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_d_tab(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
}

int	end_game(t_vars *g)
{
	free_d_tab(g->map);
	free(g->map);
	close(g->fd);
	mlx_destroy_image(g->data.mlx_ptr, g->image[0].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[1].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[2].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[3].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[4].img);
	mlx_destroy_window(g->data.mlx_ptr, g->data.win_ptr);
	mlx_destroy_display(g->data.mlx_ptr);
	free(g->data.mlx_ptr);
	g->map = NULL;
	exit(-1);
	return (1);
}

int	free_pre_game(t_vars *g)
{
	mlx_destroy_image(g->data.mlx_ptr, g->image[0].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[1].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[2].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[3].img);
	mlx_destroy_image(g->data.mlx_ptr, g->image[4].img);
	free_d_tab(g->map);
	free(g->map);
	g->map = NULL;
	return (-1);
}
