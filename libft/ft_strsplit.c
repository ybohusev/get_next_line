/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:59:40 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/18 14:59:48 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char *s, char c)
{
	size_t		words;
	size_t		i;

	words = 0;
	i = 1;
	if ((s[0] != c && s[0] != '\0') || c == '\0')
		words++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static	char	**free_split(char **ap)
{
	size_t	i;

	i = 0;
	while (ap[i])
	{
		free(ap[i]);
		ap[i] = NULL;
		i++;
	}
	return (NULL);
}

extern	char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) *
		(count_words((char*)s, c) + 1))))
		return (NULL);
	while (k < count_words((char*)s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (!(split[k++] = ft_strsub((char*)s, j, i - j)))
			return (free_split(split));
	}
	split[k] = NULL;
	return (split);
}
