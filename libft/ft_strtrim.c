/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:41:34 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/18 12:41:36 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*copy_s;
	char	*str_s;
	int		end;

	str_s = (char*)s;
	if (s == NULL)
		return (NULL);
	while (*str_s == 32 || *str_s == 44 || *str_s == 9 || *str_s == 10)
		str_s++;
	end = ft_strlen(str_s);
	while ((str_s[end - 1] == 32 || str_s[end - 1] == 44 ||
		str_s[end - 1] == 9 || str_s[end - 1] == 10) && *str_s)
		end--;
	copy_s = (char*)malloc(end + 1);
	if (copy_s == NULL)
		return (NULL);
	ft_strncpy(copy_s, str_s, end);
	copy_s[end] = '\0';
	return (copy_s);
}
