/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:04 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/05/24 14:12:31 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *) s + i);
	while (--i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
	}
	return (NULL);
}
