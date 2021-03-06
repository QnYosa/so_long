/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:42:01 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/27 19:05:01 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls(char **map, int max)
{
	int	i;
	int	size;
	int	j;

	size = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) != size)
			return (-1);
		if (i == 0 || i == max - 1)
		{
			j = -1;
			while (map[i][++j])
				if (map[i][j] != '1')
					return (-2);
		}
		if ((map[i][0] != '1' || map[i][size - 1] != '1'))
			return (-3);
	}
	return (1);
}

int	error_messages_parser(int n)
{
	if (n == -1)
	{
		ft_putstr_fd("wrong size\n", 2);
		return (0);
	}
	else if (n == -2)
	{
		ft_putstr_fd("error\n Missing wall in floor or roof ?\n", 2);
		return (0);
	}
	else if (n == -3)
	{
		ft_putstr_fd("wall_missing", 2);
		return (0);
	}
	else
		return (1);
}

int	error_messages_game(int tab[3], t_vars *g)
{
	if (tab[0] != 1)
	{
		ft_putstr_fd("error\nOnly one player accepted\n", 2);
		free_d_tab(g->map);
		free(g->map);
		exit(0);
	}
	else if (tab[1] < 1)
	{
		ft_putstr_fd("error\nNo Collectibles\n", 2);
		free_d_tab(g->map);
		free(g->map);
		exit(0);
	}
	else if (tab[2] < 1)
	{
		ft_putstr_fd("error\nNo exit\n", 2);
		free_d_tab(g->map);
		free(g->map);
		exit(0);
	}
	return (1);
}

int	right_number_pce(char **map, t_vars *g)
{
	int	i;
	int	j;
	int	tab[3];

	i = -1;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				tab[0]++;
			else if (map[i][j] == 'C')
				tab[1]++;
			else if (map[i][j] == 'E')
				tab[2]++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (0);
		}
	}
	return (error_messages_game(tab, g));
}

int	forbidden_caracters(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!is_part(map[i][j]))
				return (0);
		}
	}
	return (1);
}
