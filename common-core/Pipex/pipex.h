/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:55:41 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/23 18:06:18 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include "../printf/ft_printf.h"

# define SYNTHAX_ERROR 1
# define PIPE_ERROR 2
# define FORK_ERROR 3

void	ft_pipex_error(int error);

#endif