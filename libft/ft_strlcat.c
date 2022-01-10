/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:10:43 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/30 15:41:51 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	initial_length;
	size_t	i;

	initial_length = ft_strlen(dest);
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < initial_length)
		return (ft_strlen(src) + size);
	while (i + initial_length < size - 1 && src[i])
	{
		dest[i + initial_length] = src[i];
		i++;
	}
	dest[i + initial_length] = 0;
	return (initial_length + ft_strlen(src));
}
