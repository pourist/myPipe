/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:43:00 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/05/23 14:03:06 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;
	size_t	j;

	i = 0;
	dsize = ft_strlen(dst);
	j = dsize;
	ssize = ft_strlen(src);
	if (dsize >= size)
		return (ssize + size);
	if (size > 0)
	{
		while (src[i] && j < size - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	return (dsize + ssize);
}
