/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:10:41 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/13 17:10:43 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*freshmem;

	freshmem = (void*)malloc(size);
	if (freshmem == NULL)
		return (NULL);
	ft_bzero(freshmem, size);
	return (freshmem);
}
