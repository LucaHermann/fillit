/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:57:11 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/30 00:17:05 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	if (alst && del)
	{
		while (*alst)
		{
			new = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = new;
		}
		(*alst) = NULL;
	}
}
