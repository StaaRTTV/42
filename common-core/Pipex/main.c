/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:13:52 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/23 18:11:57 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	int	filefd[2];
	pid_t	pid;

	if (argc != 5)
		return(ft_pipex_error(SYNTHAX_ERROR));
	if (pipe(filefd) == -1)
		return(ft_pipex_error(PIPE_ERROR));
	pid = fork();
	if (pid == -1)
		return(ft_print_error(FORK_ERROR));
	if (pid == 0)
		ft_child(argv, envp, filefd);
	ft_parent(argv, envp, filefd);
	return (0);
}