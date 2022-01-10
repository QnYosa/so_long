/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:13:53 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/30 17:14:51 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_part(char c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	char			*str;
	unsigned int	end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	while (is_part(*s1, set))
		s1++;
	while (s1[i])
		i++;
	i--;
	while (is_part(s1[i], set) && i >= 0)
		i--;
	end = i + 1;
	str = (char *)malloc(sizeof(char) * (end + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] && i < (int)end)
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
