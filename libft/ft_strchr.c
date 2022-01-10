/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:10:25 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/31 14:07:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((char)c == str[i])
			return ((char *)&str[i]);
	if (c == 0)
		return ((char *)(str + i));
	return (0);
}
