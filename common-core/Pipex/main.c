/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:13:52 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/24 15:05:19 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	int	filefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_handler("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(filefd) == -1)
		error_handler("Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		error_handler("First fork error");
	if (pid1 == 0)
		child_1(filefd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_handler("Second fork error");
	if (pid2 == 0)
		child_2(filefd, argv, envp);
	close(filefd[0]);
	close(filefd[1]);
	return (EXIT_SUCCESS);
}