/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:55:41 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/25 13:48:00 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

void	error_handler(const char *name);
void	child_1(int *filefd, char **argv, char **envp);
void	child_2(int *filefd, char **argv, char **envp);
char	**ft_split(char const *str, char c);

#endif