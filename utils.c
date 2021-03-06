/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:35:24 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/22 21:16:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_part(char c)
{
	int			i;
	static char	tab[] = "01PCE";

	i = -1;
	while (tab[++i])
		if (tab[i] != c)
			return (0);
	return (1);
}

int	size_d_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
