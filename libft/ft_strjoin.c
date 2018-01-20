/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:22:57 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/15 18:22:59 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	int		i;
	char	*strcon;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strcon = (char*)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (strcon == NULL)
		return (NULL);
	while (s1[i])
		strcon[k++] = s1[i++];
	i = 0;
	while (s2[i])
		strcon[k++] = s2[i++];
	strcon[k] = '\0';
	return (strcon);
}
