/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:25:29 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/10 17:25:30 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	if (ps < pd)
	{
		pd += len;
		ps += len;
		while (len--)
			*(--pd) = *(--ps);
	}
	else
	{
		while (len--)
			*pd++ = *ps++;
	}
	return (dst);
}
