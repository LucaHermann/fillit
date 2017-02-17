/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:11:40 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/23 02:42:36 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	q;

	i = 0;
	q = 0;
	i = ft_strnlen(dst, size);
	len = i;
	while (src[q] && i < size - 1)
	{
		dst[i] = src[q];
		i++;
		q++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
