/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:53:24 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/06/16 12:14:43 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_next(char *stat)
{
	char	*next;
	char	*temp;

	if (!ft_strchr(stat, '\n'))
	{
		free(stat);
		return (ft_strdup(""));
	}
	temp = ft_strchr(stat, '\n') + 1;
	if (temp[0] == '\0' || !temp)
	{
		free(stat);
		return (NULL);
	}
	next = ft_strdup(temp);
	free(stat);
	return (next);
}

char	*ft_new_line(char *stat)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	new_line = (char *)malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_line[j] = stat[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*ft_free(char *stat, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stat, buffer);
	free(stat);
	return (temp);
}

char	*first_line(int fd, char *stat)
{
	char	*buffer;
	int		i;

	if (!stat)
		stat = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (i > 0 && !ft_strchr(stat, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buffer);
			if (i < 0 || stat[0] == '\0')
			{
				free(stat);
				return (NULL);
			}
			return (stat);
		}
		buffer[i] = '\0';
		stat = ft_free(stat, buffer);
	}
	free(buffer);
	return (stat);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*stat;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = first_line(fd, stat);
	if (!stat || stat[0] == '\0')
		return (NULL);
	new_line = ft_new_line(stat);
	stat = ft_next(stat);
	return (new_line);
}
