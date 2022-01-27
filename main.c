/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:48:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/27 19:48:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

void	game_running(t_vars *g)
{
	find_player_position(g, &g->data.player_x, &g->data.player_y);
	mlx_loop_hook(g->data.mlx_ptr, &handle_input, g);
	mlx_key_hook(g->data.win_ptr, &handle_input, g);
	mlx_hook(g->data.win_ptr, KeyPress, KeyPressMask, \
	&handle_keypress, g);
	mlx_hook(g->data.win_ptr, 33, 131072, &end_game, g);
	mlx_loop(g->data.mlx_ptr);
}

int	points_points(char *str)
{
	int	point;
	int	i;

	point = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			point++;
		if (point > 1)
		{
			printf("fc\n");
			exit(0);
		}
	}
	return (1);
}

int	points(char *str)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	i = 0;
	while (str[i] != '.')
		i++;
	if (str[i - 1] == '/')
		return (0);
	if (ft_strncmp(&str[len - 4], ".ber", 4) != 0)
	{
		printf("fc\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	g;
	int		i;

	i = -1;
	if (argc != 2 || !points(argv[1]) || !points_points(argv[1]))
		return (0);
	g = init_struct(argc, argv);
	test_image(&g);
	if (!parse_and_check_errors(&g))
		return (free_pre_game(&g));
	g.data.mlx_ptr = mlx_init();
	if (g.data.mlx_ptr == NULL)
		return (free_pre_game(&g));
	xpm_to_image(&g);
	if (size_window(&g) < 0)
		return (0);
	dress_table(&g);
	close(g.fd);
	game_running(&g);
	return (0);
}
