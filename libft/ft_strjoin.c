/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:13:39 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/14 17:58:16 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	if (s1)
		free(s1);
	return (str);
}
