/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:13:52 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/27 13:51:20 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(const int argc, char **argv, char **envp)
{
	int		filefd[2];
	pid_t	pid;

	if (argc != 5)
		error_handler("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(filefd) == -1)
		error_handler("Pipe error\n");
	pid = fork();
	if (pid == -1)
		error_handler("First fork error\n");
	if (pid == 0)
		child_1(filefd, argv, envp);
	waitpid(pid, NULL, 0);
	parent(filefd, argv, envp);
	return (0);
}
