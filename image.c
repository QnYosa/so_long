/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:31:19 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/26 00:24:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xpm_to_image(t_vars *g)
{
	g->image[0].img = mlx_xpm_file_to_image(g->data.mlx_ptr, WALL, \
	&g->image[0].img_width, &g->image[0].img_height);
	g->image[1].img = mlx_xpm_file_to_image(g->data.mlx_ptr, PLAYER, \
	&g->image[1].img_width, &g->image[1].img_height);
	g->image[2].img = mlx_xpm_file_to_image(g->data.mlx_ptr, \
	COLLECTIBLE, &g->image[2].img_width, &g->image[2].img_height);
	g->image[3].img = mlx_xpm_file_to_image(g->data.mlx_ptr, FLOOR, \
	&g->image[3].img_width, &g->image[3].img_height);
	g->image[4].img = mlx_xpm_file_to_image(g->data.mlx_ptr, EXIT, \
	&g->image[4].img_width, &g->image[4].img_height);
	return (1);
}

int	check_image(const char *filename, t_vars *g)
{
	g->fd = 0;
	g->fd = open(filename, O_RDONLY);
	if (g->fd > 0)
		close(g->fd);
	else
	{
		printf("No_texture named %s\n", filename);
		close(g->fd);
		exit(1);
	}
	return (1);
}

void	test_image(t_vars *g)
{
	check_image(WALL, g);
	check_image(EXIT, g);
	check_image(PLAYER, g);
	check_image(COLLECTIBLE, g);
	check_image(FLOOR, g);
}
