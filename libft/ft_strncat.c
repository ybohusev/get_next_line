/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:31:51 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/04 17:31:53 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*srct;
	int		destlen;
	size_t	i;

	i = 0;
	srct = (char*)src;
	destlen = ft_strlen(dest);
	while (i < n)
	{
		dest[destlen] = srct[i];
		destlen++;
		i++;
		if (srct[i] == '\0')
			break ;
	}
	dest[destlen] = '\0';
	return (dest);
}
