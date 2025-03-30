/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:05:15 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/05/24 16:34:09 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;
	size_t	j;

	j = 0;
	i = ft_strlen(s);
	if (!s)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	while (s[j] != '\0')
	{
		ptr[j] = f(j, s[j]);
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
