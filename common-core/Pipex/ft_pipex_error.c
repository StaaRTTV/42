/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:52:47 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/23 18:10:32 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_error(int error)
{
	ft_printf("Error :");
	if (error = SYNTHAX_ERROR)
	{
		ft_printf("The synthax is not correct.\n");
		ft_printf("The right synthax is : ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	if (error = PIPE_ERROR)
		ft_printf("Pipe failure\n");
	if (error = FORK_ERROR)
		ft_printf("The fork isn't forking\n");
}