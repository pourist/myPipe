/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:14:47 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/05/22 16:11:05 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		while (n-- > 0)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	else
	{
		i = n + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
		return (dest);
	}
}
