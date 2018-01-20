/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:11:08 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/10 20:11:10 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*need;
	size_t	i;

	i = 0;
	hay = (char*)haystack;
	need = (char*)needle;
	if (ft_strlen(need) == 0)
		return (hay);
	while (ft_strlen(hay) >= ft_strlen(need) && \
		(size_t)ft_strlen(need) + i <= len)
	{
		if (!ft_memcmp(hay, need, ft_strlen(need)))
			return (hay);
		hay++;
		i++;
	}
	return (NULL);
}
