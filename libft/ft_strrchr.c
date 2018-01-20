/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:01:54 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/09 18:01:57 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*temp_str;
	int				is_ch;
	unsigned char	ch;

	ch = (unsigned char)c;
	is_ch = 0;
	temp_str = (char*)str;
	while (*temp_str)
		temp_str++;
	while (temp_str != str)
	{
		if (*temp_str == ch)
		{
			is_ch = 1;
			break ;
		}
		temp_str--;
	}
	if (is_ch == 0 && *temp_str != ch)
		return (NULL);
	return (temp_str);
}
