/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:42:01 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/15 22:22:48 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* premiere ligne = que des 1 
** toujours la meme len **
** un seul personnage sinon on quit (seul truc unique)**
** doit commencer et se terminer par un 1 **
** s'assurer qu'il n'y a que des caracteres autorises **
** compter les nombres d'elements **
*/
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
		if (i == 0 || i == max)
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
		ft_putstr_fd("floor ? roof ?\n", 2);
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

int	check_errors(t_game *g)
{
	int	i;

	i = -1;
	while (g->map[++i])
		i++;
	printf("max = %d\n", i);
	if (!error_messages_parser(walls(g->map, i)))
		return (0);
	printf("yo\n");
	return (1);
}
