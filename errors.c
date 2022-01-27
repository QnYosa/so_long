/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:13:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/27 18:44:21 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_vars *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	if (!error_messages_parser(walls(g->map, i)) \
	|| !right_number_pce(g->map, g))
	{
		free_d_tab(g->map);
		free(g->map);
		exit(0);
	}
	return (1);
}

int	check_file(char *file)
{
	if (open(file, O_RDONLY) == -1)
		return (0);
	return (1);
}
