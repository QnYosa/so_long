/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:18:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/10 19:59:26 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_parse(t_game *g, int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open(g->av[1]);
	printf(" hola fd %d\n", fd);
	g->hola = 0;
	return (0);
}
