/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:48:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/16 18:43:07 by dyoula           ###   ########.fr       */
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

int	check_errors(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	printf("max = %d\n", i);
	if (!error_messages_parser(walls(g->map, i)) || !right_number_pce(g->map))
		return (0);
	// if (!playable(g->map))
	// 	return (0);
	printf("yo\n");
	return (1);
}

int	check_file(char *file)
{
	if (open(file, O_RDONLY) == -1)
	{
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	g;

	if (argc != 2)
		return (0);
	init_struct(&g, argc, argv);
	printf("Tribal\n");
	if (!parse_and_check_errors(&g))
		return (-1);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "closing_window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (-1);
	}
	// mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	// mlx_key_hook(data.win_ptr, &handle_input, &data);
	// mlx_loop(data.mlx_ptr);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
	return (0);
}
