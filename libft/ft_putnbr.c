/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:02:23 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/06 16:02:24 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int temp;

	temp = n;
	if (temp < 0)
	{
		ft_putchar('-');
		temp = temp * -1;
	}
	if (temp / 10 != 0)
		ft_putnbr(temp / 10);
	ft_putchar(temp % 10 + 48);
	return ;
}
