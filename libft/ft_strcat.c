/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:18:10 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/04 15:18:12 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*srct;
	int		destlen;

	srct = (char*)src;
	destlen = ft_strlen(dest);
	while (*srct)
	{
		dest[destlen] = *srct;
		destlen++;
		srct++;
	}
	dest[destlen] = '\0';
	return (dest);
}
