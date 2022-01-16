/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:18:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/16 19:23:23 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_messages_read_file(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("Error\nEmpty_file\n", 2);
		return (0);
	}
	return (1);
}

int	file_reader(t_game *g, int fd)
{
	char	buf[2];
	char	*txt;
	int		i;

	i = 0;
	txt = ft_strdup("");
	if (!txt)
		return (0);
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = 0;
		txt = ft_strjoin(txt, buf);
		i++;
	}
	if (!error_messages_read_file(i))
		return (0);
	g->map = ft_split(txt, '\n');
	if (!g->map)
	{
		free(txt);
		return (0);
	}
	free(txt);
	return (1);
}

int	init_parse(t_game *g)
{
	int	fd;

	fd = open(g->av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (!file_reader(g, fd))
		return (0);
	return (1);
}

int	parse_and_check_errors(t_game *g)
{
	if (!init_parse(g) || !check_errors(g))
		return (0);
	return (1);
}
