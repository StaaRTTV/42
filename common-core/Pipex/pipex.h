/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:55:41 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/24 14:50:44 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

# define SYNTHAX_ERROR 2
# define PIPE_ERROR 3
# define FORK_ERROR 4

void	ft_pipex_error(int error);

#endif