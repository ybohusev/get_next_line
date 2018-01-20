/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:01:22 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/05 20:24:23 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	unsigned long long	res;
	int					i;
	int					is_negative;

	res = 0;
	is_negative = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		is_negative = -1;
		i++;
	}
	if (str[i] == '+' && is_negative == 1)
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48);
	if (res > 9223372036854775807 && is_negative == -1)
		return (0);
	if (res > 9223372036854775807)
		return (-1);
	return ((int)res * is_negative);
}
