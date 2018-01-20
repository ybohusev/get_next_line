/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:22:06 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/09 20:22:07 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	const unsigned char	*src;
	unsigned char		*dest;

	src = (unsigned char*)str2;
	dest = (unsigned char*)str1;
	while (n--)
		*dest++ = *src++;
	return (str1);
}
