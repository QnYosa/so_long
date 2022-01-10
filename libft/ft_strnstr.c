/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:13:44 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/30 15:38:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return (s1);
	if (n == 0)
		return (NULL);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i < n && s1[i + j])
		{
			if (s1[i + j] && s2[j + 1] == 0 && i + j < n)
				return (&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
