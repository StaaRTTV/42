/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:23:08 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/03 17:28:54 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printstring(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_printchar(*str);
		str++;
	}
}