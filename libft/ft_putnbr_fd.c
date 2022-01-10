/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:10:16 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/31 14:08:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	print;

	number = n;
	if (number < 0)
	{
		number *= -1;
		write(fd, "-", 1);
	}
	print = '0' + number;
	if (number <= 9 && number >= 0)
		write(fd, &print, 1);
	else
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
}
