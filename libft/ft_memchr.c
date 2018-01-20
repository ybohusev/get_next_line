/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:20:49 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/10 18:20:50 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str1;

	str1 = (unsigned char*)s;
	while (n--)
	{
		if (*str1 == (unsigned char)c)
			return (str1);
		str1++;
	}
	return (NULL);
}
