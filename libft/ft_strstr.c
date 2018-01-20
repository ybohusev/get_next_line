/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:32:46 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/10 19:32:48 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	char	*need;

	hay = (char*)haystack;
	need = (char*)needle;
	if (ft_strlen(need) == 0)
		return (hay);
	while (ft_strlen(hay) >= ft_strlen(need))
	{
		if (!ft_memcmp(hay, need, ft_strlen(need)))
			return (hay);
		hay++;
	}
	return (NULL);
}
