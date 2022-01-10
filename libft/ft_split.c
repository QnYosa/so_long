/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:02:20 by dyoula            #+#    #+#             */
/*   Updated: 2021/12/14 19:02:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}

static int	size_word(char *s, char c)
{
	int		count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static int	count_words(char *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && *s)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	char	*flag;
	int		nb_words;
	int		index;

	if (!s)
		return (NULL);
	flag = (char *)s;
	nb_words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	split[nb_words] = NULL;
	index = -1;
	while (++index < nb_words)
	{
		while (*flag == c)
			flag++;
		split[index] = (char *)malloc(sizeof(char) * (size_word(flag, c) + 1));
		if (!split[index])
			return (free_split(split, index));
		ft_strlcpy(split[index], flag, size_word(flag, c) + 1);
		flag += (size_word(flag, c) + 1);
	}
	return (split);
}
