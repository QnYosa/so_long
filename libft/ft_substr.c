/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:13:58 by dyoula            #+#    #+#             */
/*   Updated: 2021/05/30 16:12:06 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		substring = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		substring = (char *)malloc(sizeof(char) * len + 1);
	if (!(substring))
		return (NULL);
	i = -1;
	while (s[start + (++i)] && (i < len))
		substring[i] = s[start + i];
	substring[i] = 0;
	return (substring);
}
