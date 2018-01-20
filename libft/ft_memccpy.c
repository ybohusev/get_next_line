/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:37:56 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/09 20:37:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dest;
	while (n--)
	{
		if (*str1 == (unsigned char)c)
		{
			*str2++ = *str1;
			return (str2);
		}
		*str2++ = *str1++;
	}
	return (NULL);
}
