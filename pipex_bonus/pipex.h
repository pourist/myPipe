/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:02:17 by ppour-ba          #+#    #+#             */
/*   Updated: 2023/11/06 14:04:17 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_bonus
{
	int		here_doc;
	int		file1;
	int		file2;
	char	**envp;
	char	**cmnd;
	char	*the_path;
	int		cmnds_num;
	int		pipe_num;
	int		*pipe;
	char	**paths;
}	t_bpipex;

//make pipex
void		make_file(t_bpipex *pipex, char *delimiter);
t_bpipex	*make_pipex(int argc, char **argv, char **envp);
t_bpipex	*setup_pipex(int argc, char **argv, char **envp);

//free
void		free_s(char **cmds);
void		free_bonus(t_bpipex *pipex);
//error
void		infile_error(t_bpipex *pipex, char *file);
void		cmd_error(t_bpipex *pipex, char *cm);
void		fail_error(char *error);
void		free_error(char *error, t_bpipex *pipex);

#endif
