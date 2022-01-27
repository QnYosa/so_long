/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:20:11 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/25 23:58:30 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_window(t_vars *g)
{
	g->height = 40 * size_d_tab(g->map);
	g->width = 40 * ft_strlen(g->map[0]);
	g->data.win_ptr = mlx_new_window(g->data.mlx_ptr, g->width, g->height, \
	NAME);
	if (g->data.win_ptr == NULL)
	{
		free(g->data.win_ptr);
		return (-1);
	}
	return (1);
}
