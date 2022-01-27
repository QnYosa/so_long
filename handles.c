/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:23:20 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/26 00:21:27 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_vars *g)
{
	if (keysym == XK_Escape)
		end_game(g);
	return (0);
}

int	handle_input(int keysym, t_vars *g)
{
	if (keysym == XK_Escape)
		end_game(g);
	else if (keysym == DOWN)
		move_maestro(g, DOWN);
	else if (keysym == LEFT)
		move_maestro(g, LEFT);
	else if (keysym == UP)
		move_maestro(g, UP);
	else if (keysym == RIGHT)
		move_maestro(g, RIGHT);
	return (0);
}
