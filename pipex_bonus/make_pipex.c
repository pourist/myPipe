/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:56:05 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 13:58:31 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

void	make_file(t_bpipex *pipex, char *delimiter)
{
	char	*buff;
	int		fd;

	fd = open("here_doc", O_CREAT | O_WRONLY, 0777);
	if (fd < 0)
		free_error("Failed to make the file \n", pipex);
	while (1)
	{
		write(1, "here_doc> ", 10);
		buff = get_next_line(0);
		if (buff == NULL)
			free_error("gnl fail", pipex);
		if (ft_strncmp(delimiter, buff, ft_strlen(buff) - 1) == 0)
			if (buff[ft_strlen(buff) - 1] == '\n')
				if (ft_strlen(delimiter) == ft_strlen(buff) - 1)
					break ;
		write(fd, buff, ft_strlen(buff));
		free(buff);
	}
	free(buff);
	close(fd);
}

t_bpipex	*make_pipex(int argc, char **argv, char **envp)
{
	t_bpipex	*pipex;

	pipex = (t_bpipex *)malloc(sizeof(t_bpipex));
	if (!pipex)
		fail_error("Memory allocation failed.\n");
	pipex->envp = envp;
	pipex->paths = find_env(envp);
	if (!pipex->paths)
		free_error("Error paths\n", pipex);
	pipex->the_path = NULL;
	pipex->cmnd = NULL;
	pipex->pipe = NULL;
	if (!ft_strncmp("here_doc", argv[1], 9))
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
	pipex->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);
	if (pipex->file2 < 0)
		free_error("zsh: no such file or directory: \n", pipex);
	pipex->cmnds_num = argc - 3 - pipex->here_doc;
	pipex->pipe_num = (pipex->cmnds_num - 1) * 2;
	return (pipex);
}

void	make_the_pipes(t_bpipex *pipex)
{
	int			i;

	i = 0;
	pipex->pipe = (int *)malloc(sizeof(int) * pipex->pipe_num); 
	while (i < pipex->cmnds_num - 1)
	{
		if (pipe(pipex->pipe + (2 * i)) < 0)
			free_error("pipe failed", pipex);
		i++;
	}
}

t_bpipex	*setup_pipex(int argc, char **argv, char **envp)
{
	t_bpipex	*pipex;

	if (argc < 5)
		fail_error("Too few arguments: infile cmd1 cmd2 .. cmdn outfile\n");
	pipex = make_pipex(argc, argv, envp);
	if (pipex->here_doc == 1)
	{
		if (argc < 6)
			free_error("Insufficient arguments with 'here_doc'\n", pipex);
		make_file(pipex, argv[2]);
		pipex->file1 = open("here_doc", O_RDONLY, 0777);
		if (pipex->file1 < 0)
		{
			unlink("here_doc");
			free_error("here_doc Error.\n", pipex);
		}
	}
	else
	{
		pipex->file1 = open(argv[1], O_RDONLY, 0777);
		if (pipex->file1 < 0)
			infile_error(pipex, argv[1]);
	}
	make_the_pipes(pipex);
	return (pipex);
}
