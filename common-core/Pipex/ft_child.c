/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:06:46 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/25 19:33:44 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void free_cmd(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i] != NULL)
    {
        free(cmd[i]);
        i++;
    }
    free(cmd);
}
void	child_1(int *filefd, char **argv, char **envp)
{
	int	infile_fd;
	char	**cmd1;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		error_handler("error opening input file");
	if(dup2(infile_fd, STDIN_FILENO) == -1)
		error_handler("dup2 infile_fd failed");
	if (dup2(filefd[1], STDOUT_FILENO) == -1)
		error_handler("dup2 filefd[1] failed");
	close(filefd[0]);
	close(filefd[1]);
	close(infile_fd);

	cmd1 = ft_split(argv[2], ' ');
	if (cmd1 == NULL)
		error_handler("ft_split failed");
	if (execve(cmd1[0], cmd1, envp) == -1)
	{
		free_cmd(cmd1);
		error_handler("Command 1 failed");
	}
}

void	parent(int *filefd, char **argv, char **envp)
{
	int	outfile_fd;
	char	**cmd2;

	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		error_handler("error opening input file");
	if(dup2(filefd[0], STDIN_FILENO) == -1)
		error_handler("dup2 filefd[0] failed");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		error_handler("dup2 outtfile_fd failed");
	close(filefd[0]);
	close(filefd[1]);
	close(outfile_fd);

	cmd2 = ft_split(argv[3], ' ');
	if (execve(cmd2[0], cmd2, envp) == -1)
	{
		free_cmd(cmd2);
		error_handler("Command 2 failed");
	}
	execve(cmd2[0], cmd2, envp);
	error_handler("Command 2 failed");
}
