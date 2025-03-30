/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:53:42 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 14:00:19 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_set(int r, int w, t_bpipex	*pipex)
{
	if (dup2(r, 0) == -1 || dup2(w, 1) == -1)
		free_error("Dup2 failed\n", pipex);
}

void	close_pipes(t_bpipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_num))
		close(pipex->pipe[i++]);
}

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*temp;
	char	*p;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		p = ft_strjoin(temp, cmd);
		free(temp);
		if (access(p, X_OK) == 0)
			return (p);
		free(p);
		i++;
	}
	return (NULL);
}

void	child(int i, t_bpipex	*pipex, char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (i == 0)
			dup_set(pipex->file1, pipex->pipe[1], pipex);
		else if (i == pipex->cmnds_num - 1)
			dup_set(pipex->pipe[(i * 2) - 2], pipex->file2, pipex);
		else
			dup_set(pipex->pipe[(i * 2) - 2], pipex->pipe[(i * 2) + 1], pipex);
		close_pipes(pipex);
		pipex->cmnd = ft_split(argv[i + 2 + pipex->here_doc], ' ');
		if (!pipex->cmnd[0])
			cmd_error(pipex, argv[i + 2 + pipex->here_doc]);
		pipex->the_path = find_path(pipex->paths, pipex->cmnd[0]);
		if (!pipex->the_path)
			cmd_error(pipex, argv[i + 2 + pipex->here_doc]);
		execve(pipex->the_path, pipex->cmnd, pipex->envp);
		free_error("Child Failed", pipex);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_bpipex	*pipex;
	int			i;
	int			w;

	pipex = setup_pipex(argc, argv, envp);
	i = 0;
	while (i < pipex->cmnds_num)
		child(i++, pipex, argv);
	close_pipes(pipex);
	close(pipex->file1);
	close(pipex->file2);
	w = 0;
	while (w++ < pipex->cmnds_num)
		waitpid(-1, NULL, 0);
	free_bonus(pipex);
	return (0);
}
