/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:53:45 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/14 18:02:02 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long int nbr)
{
	int					i;
	unsigned int		j;

	i = 1;
	j = 1;
	while (nbr / i > 9)
	{
		i *= 10;
		j++;
	}
	return (j);
}

static int	divider(long int nbr)
{
	int		i;

	i = 1;
	while (nbr / i > 9)
		i *= 10;
	return (i);
}

static void	filler(char *str, int div, long int nbr, int minus)
{
	int		i;
	int		neg;
	int		length;

	length = len(nbr);
	neg = 1;
	if (minus == 2)
	{
		i = 0;
		str[0] = '-';
		neg = 0;
	}
	else
		i = -1;
	while (++i <= length - neg)
	{
		if (nbr < 10)
			str[i] = '0' + nbr;
		str[i] = '0' + nbr / div;
		nbr %= div;
		div /= 10;
	}
	str[i] = 0;
}

char	*ft_itoa(int n)
{
	int				minus;
	int				length;
	int				div;
	char			*str;
	long int		nb;

	nb = n;
	if (nb < 0)
	{
		minus = 2;
		nb *= -1;
	}
	else
		minus = 1;
	div = divider(nb);
	length = len(nb);
	str = (char *)malloc(sizeof(char) * (length + minus));
	if (!str)
		return (NULL);
	filler(str, div, nb, minus);
	return (str);
}
