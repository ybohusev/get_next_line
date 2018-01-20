/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:11:56 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/09 16:11:57 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*temp_str;
	int				is_ch;
	unsigned char	ch;

	ch = (unsigned char)c;
	is_ch = 0;
	temp_str = (char*)str;
	while (*temp_str)
	{
		if (*temp_str == ch)
		{
			is_ch = 1;
			break ;
		}
		temp_str++;
	}
	if (is_ch == 0 && ch != '\0')
		return (NULL);
	return (temp_str);
}
