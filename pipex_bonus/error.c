/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:04:34 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 18:09:01 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fail_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit (1);
}

void	free_error(char *error, t_bpipex *pipex)
{
	free_bonus(pipex);
	write(2, error, ft_strlen(error));
	exit (1);
}

void	infile_error(t_bpipex *pipex, char *file)
{
	close(pipex->file2);
	write(2, "zsh: no such file or directory: ", 32);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
	free_bonus(pipex);
	exit(1);
}

void	cmd_error(t_bpipex *pipex, char *cm)
{
	close(pipex->file1);
	close(pipex->file2);
	if (!pipex->cmnd[0])
	{
		if (cm[0])
		{
			write(2, "zsh: command not found: ", 24);
		}
		else
			write(2, "zsh: permission denied: ", 24);
	}
	else
	{
		write(2, "zsh: command not found: ", 24);
		write(2, pipex->cmnd[0], ft_strlen(pipex->cmnd[0]));
	}
	free_error("\n", pipex);
}
