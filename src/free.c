/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:00:50 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 14:01:58 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_s(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
}

void	free_bonus(t_bpipex *pipex)
{
	if (pipex->cmnd)
		free_s(pipex->cmnd);
	if (pipex->the_path)
		free(pipex->the_path);
	if (pipex->paths)
		free_s(pipex->paths);
	if (pipex->here_doc == 1)
		unlink("here_doc");
	if (pipex->pipe)
		free(pipex->pipe);
	free(pipex);
}
