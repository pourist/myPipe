/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:00:40 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 14:06:23 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pass(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14)))
		i++;
	return (i);
}

int	patoi(char *numb, int i)
{
	int			sum;
	long int	ten;

	ten = 10;
	sum = numb [i - 1] - 48;
	while (i - 1 > 0)
	{
		sum = sum + (numb[i - 2] - 48) * ten;
		ten = ten * 10;
		i--;
	}
	return (sum);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		ng;
	char	numb[100];
	int		j;

	j = 0;
	ng = 1;
	numb[0] = '\0';
	i = pass(nptr);
	if (nptr[i] == '-')
	{
		ng = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] == '0' && nptr[i + 1] <= '9' && nptr[i + 1] >= '0')
		i++;
	while ((nptr[i] > 47 && nptr[i] < 58 && j < 20))
		numb[j++] = nptr[i++];
	numb[j] = '\0';
	if (numb[0] == '\0')
		return (0);
	return (ng * patoi(numb, j));
}
