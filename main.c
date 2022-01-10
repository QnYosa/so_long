/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:48:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/10 19:54:09 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

// int	handle_no_event(void *data)
// {
// 	/* This function needs to exist, but it is useless for the moment */
// 	return ((int)data);
// }

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	g;

	init_parse(&g, argc, argv);
	parsing_maestro(&g);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "closing_window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (-1);
	}
	printf("%d\n", g.hola);
	// mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	// mlx_key_hook(data.win_ptr, &handle_input, &data);
	// mlx_loop(data.mlx_ptr);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
	return (0);
}
