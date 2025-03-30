/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:49:42 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/05/22 12:51:13 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_check(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	from;
	size_t	to;
	char	*ptr;
	size_t	i;

	i = 0;
	from = 0;
	while (s1[from] && ft_check(set, s1[from]))
		from++;
	to = ft_strlen(s1);
	while (from < to && ft_check(set, s1[to - 1]))
		to--;
	ptr = (char *)malloc(sizeof(s1[0]) * (to - from + 1));
	if (!ptr)
		return (NULL);
	while (from < to)
		ptr[i++] = s1[from++];
	ptr[i] = '\0';
	return (ptr);
}

/*int main ()
{
    char *s1 = "ado 2222i";
    char *set = "i2 ";
    printf("%s", ft_strtrim( s1,set) );
}*/
