/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:55:41 by gpochon           #+#    #+#             */
/*   Updated: 2025/01/13 11:28:15 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

void	error_handler(const char *name);
void	free_cmd(char **cmd);
void	child_1(int *filefd, char **argv, char **envp);
void	parent(int *filefd, char **argv, char **envp);
char	*ft_path(char *cmd, char **envp);

#endif
