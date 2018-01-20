/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:52:47 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/21 14:52:49 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*elem;
	t_list	*next;

	if (*alst == NULL)
		return ;
	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		ft_lstdelone(&elem, del);
		elem = next;
	}
	*alst = NULL;
}
