/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:38 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 13:52:06 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	slen(int n)
{
	int	i;

	if (n == 0)
		return (2);
	i = 2;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ifneg(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = slen(n);
	ptr = (char *)malloc(sizeof(char) * j);
	if (!ptr)
		return (NULL);
	if (n == 0)
	{
		ptr[i++] = '0';
		ptr[i] = '\0';
		return (ptr);
	}
	if (n < 0)
		ptr[i++] = '-';
	ptr[--j] = '\0';
	while (n >= 10 || n <= -10)
	{
		ptr[--j] = ifneg(n % 10) + '0';
		n = n / 10;
	}
	ptr[--j] = ifneg(n) + '0';
	return (ptr);
}

/*int main ()
{
	printf("%d", slen(-400));
}*/
