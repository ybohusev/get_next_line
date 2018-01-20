/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:54:12 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/06 17:54:17 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		mem_size(int n)
{
	int		i;
	int		temp;

	temp = n;
	i = 1;
	while (temp / 10 != 0)
	{
		i++;
		temp = temp / 10;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

extern	char	*ft_itoa(int n)
{
	long int		temp;
	char			*str;
	int				i;

	i = mem_size(n);
	temp = n;
	str = (char*)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (temp < 0)
		temp = temp * -1;
	while (--i >= 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
