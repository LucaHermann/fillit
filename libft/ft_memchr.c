/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:18:10 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/20 14:25:06 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char c1;

	c1 = (unsigned char)c;
	s = (unsigned char *)src;
	while (n != '\0')
	{
		if (*s != c1)
			s++;
		else
			return (s);
		n--;
	}
	return (NULL);
}
