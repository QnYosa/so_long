/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:48:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/20 23:24:07 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
#include <X11/X.h>

int	handle_no_event(void *g)
{
	/* This function needs to exist, but it is useless for the moment */
	// return ((int)g);
	(void)g;
	return (5);
}




int	check_errors(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	if (!error_messages_parser(walls(g->map, i)) || !right_number_pce(g->map))
		return (0);
	return (1);
}

int	check_file(char *file)
{
	if (open(file, O_RDONLY) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		return (0);
	init_struct(&g, argc, argv);
	if (!parse_and_check_errors(&g))
		return (-1);
	g.window.mlx_ptr = mlx_init();
	if (g.window.mlx_ptr == NULL)
		return (-1);
	g.window.win_ptr = mlx_new_window(g.window.mlx_ptr, 600, 300, "Yu Yu Hakusho");
	g.img.img = mlx_new_image(g.window.mlx_ptr, 600, 300);
	if (g.window.win_ptr == NULL)
	{
		free(g.window.win_ptr);
		return (-1);
	}
	// img.addr = mlx_get_g_addr(img.img, &img.bits_per_pixel, \
	// &img.line_length, &img.endian);
	mlx_loop_hook(g.window.mlx_ptr, &handle_no_event, &g.window);
	mlx_hook(g.window.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &g.window);
	mlx_hook(g.window.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &g.window);
	mlx_key_hook(g.window.win_ptr, &handle_input, &g.window);
	mlx_loop(g.window.mlx_ptr);
	mlx_destroy_display(g.window.mlx_ptr);
	mlx_destroy_window(g.window.mlx_ptr, g.window.win_ptr);
	free(g.window.win_ptr);
	free(g.window.mlx_ptr);
	free(g.img.img);
	free_d_tab(g.map);
	g.map = NULL;
	return (0);
}
