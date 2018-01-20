/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:36:30 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/04 18:36:31 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;
	char	*srct;

	srct = (char*)src;
	lensrc = ft_strlen(srct);
	lendst = ft_strlen(dst);
	if (lendst > size)
		lensrc += size;
	else
		lensrc += lendst;
	lendst = size - lendst - 1;
	if ((int)lendst <= 0)
		lendst = 0;
	ft_strncat(dst, srct, lendst);
	return (lensrc);
}
