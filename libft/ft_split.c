/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:36:45 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/06/02 13:13:56 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	snumber(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s[i])
		return (j);
	if (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

int	findend(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

void	tofree(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		ptr[i++] = NULL;
	}
	free(ptr);
	ptr = NULL;
	return ;
}

int	subptr(char const *s, char c, char **ptr)
{
	size_t	i;
	size_t	j;
	size_t	p;

	p = 0;
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = findend(s, c, i);
			ptr[p] = ft_substr(s, i, j);
			if (!ptr[p++])
			{
				tofree(ptr);
				return (0);
			}
			i += j;
		}
		else
			i++;
	}
	ptr[p] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * (snumber(s, c) + 1));
	if (!ptr || !s)
		return (NULL);
	if (!subptr(s, c, ptr))
		return (NULL);
	return (ptr);
}
